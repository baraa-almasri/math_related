class InfixEvaluator(expression: String) : Evaluator(expression) {
    override fun evaluate(): Double {
        val operandsPrecedences = this.getOperatorsPrecedences()
        var lastAnswer = 0.0

        var i = 1
        while(i < this.entries.size-1){
            if (TermChecker.isOperator(this.entries[i]) &&
                    TermChecker.isNumber(this.entries[i+1]) &&
                    TermChecker.isNumber(this.entries[i-1]) &&
                    (getOperatorPrecedence(this.entries[i][0])
                      == operandsPrecedences.max())
            ) {
                operandsPrecedences.removeLast()
                lastAnswer = execOperator(
                        this.entries[i-1].toDouble(),
                        this.entries[i+1].toDouble(),
                        this.entries[i][0]
                )
                //this.this.entries[i + 1] = this.lastAnswer.toString()

                // make answer and other operand as operands to the next operand
                // IF THERE'S AN ANOTHER OPERAND
                if(this.entries.size > 3) {
                    this.entries[i-1] = lastAnswer.toString()
                    for(j in i until this.entries.size-2) {
                        this.entries[j] = this.entries[j+2]
                    } // lil for
                    i = 1
                    continue
                } // if
            }

            i++
        }
        // in case of multi calls
        this.entries.clear()

        return lastAnswer
    }

    // ok this shit is about to get heavy
    private fun getOperatorPrecedence(op: Char): Int {

        return when(op) {
            '+' -> 1
            '-' -> 1
            '*' -> 2
            '/' -> 2
            '^' -> 3
            else -> 0
        }
    }

    private fun getOperatorsPrecedences(): ArrayList<Int> {
        val operandsPrecedences = ArrayList<Int>()
        for(entry in this.entries) {
            if(TermChecker.isOperator(entry)) {
                operandsPrecedences.add(getOperatorPrecedence(entry[0]))
            }
        }
        operandsPrecedences.sort()

        return operandsPrecedences
    }

}
