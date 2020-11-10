class PostfixParser(expression: String): Parser(expression) {
    override fun evaluate(): Double {
        this.updateEntries()
        if(printWrongOps()) {
            return 0.0
        }
        for (i in 0 until this.entries.size) {
            if (isOperator(this.entries[i][0])) {
                this.lastAnswer = execOperator(
                        this.entries[i - 2].toDouble(),
                        this.entries[i - 1].toDouble(),
                        this.entries[i][0]
                )
                // make answer and other operand as operands to the next operand
                // IF THERE'S AN ANOTHER OPERAND
                if(this.entries.size > 3) {
                    this.entries[i] = this.lastAnswer.toString()
                    for(j in (i-1) downTo 2) {
                        this.entries[j] = this.entries[j-2]
                    } // lil for
                } // if
            }// outer if
        } // for
        this.entries.clear()

        return this.lastAnswer
    }

}