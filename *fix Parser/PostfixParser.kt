class PostfixParser(expression: String): Parser(expression) {

    override fun evaluate(): Double {
        this.updateEntries()
        for (i in 0 until this.entries.size - 1) {
            if (isOperator(this.entries[i][0])) {
                this.lastAnswer = execOperator(
                        this.entries[i - 2].toDouble(),
                        this.entries[i - 1].toDouble(),
                        this.entries[i][0]
                )
                this.entries[i + 1] = this.lastAnswer.toString()

            }
        }
        this.entries.clear()

        return this.lastAnswer
    }

}