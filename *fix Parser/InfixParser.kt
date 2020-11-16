import java.lang.NumberFormatException
import java.lang.reflect.Array

class InfixParser(expression: String) : Parser(expression) {
    override fun evaluate(): Double {
        this.updateEntries()
        val operandsPrecedences = this.getOperatorsPrecedences()

        if(printWrongOps()) {
            return Double.MIN_VALUE
        }
        //for (i in 1 until this.entries.size-1)
        var i = 1
        while(i < this.entries.size-1){
            if (isOperator(this.entries[i]) &&
                    isNumber(this.entries[i+1]) &&
                    isNumber(this.entries[i-1]) &&
                    (getOperatorPrecedence(this.entries[i][0])
                      == operandsPrecedences.max())
            ) {
                operandsPrecedences.removeLast()
                this.lastAnswer = execOperator(
                        this.entries[i-1].toDouble(),
                        this.entries[i+1].toDouble(),
                        this.entries[i][0]
                )
                //this.entries[i + 1] = this.lastAnswer.toString()

                // make answer and other operand as operands to the next operand
                // IF THERE'S AN ANOTHER OPERAND
                if(this.entries.size > 3) {
                    this.entries[i-1] = this.lastAnswer.toString()
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

        return this.lastAnswer
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
            if(isOperator(entry)) {
                operandsPrecedences.add(getOperatorPrecedence(entry[0]))
            }
        }
        operandsPrecedences.sort()

        return operandsPrecedences
    }

}
