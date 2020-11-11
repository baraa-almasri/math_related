class InfixParser(expression: String) : Parser(expression) {
    override fun evaluate(): Double {
        this.updateEntries()
        if(printWrongOps()) {
            return Double.MIN_VALUE
        }
        for (i in 0 until this.entries.size) {
            if (isOperator(this.entries[i])) {
                this.lastAnswer = execOperator(
                        this.entries[i - 1].toDouble(),
                        this.entries[i + 1].toDouble(),
                        this.entries[i][0]
                )
                this.entries[i + 1] = this.lastAnswer.toString()

            }
        }
        this.entries.clear()

        return this.lastAnswer
    }

}
