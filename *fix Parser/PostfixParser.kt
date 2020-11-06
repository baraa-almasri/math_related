class PostfixParser(expression: String): Parser(expression) {
    // this one needs some modifications :)
    override fun evaluate(): Double {
        this.updateEntries()
        for (i in 0 until this.entries.size) {
            if (isOperator(this.entries[i][0])) {
                this.lastAnswer = execOperator(
                        this.entries[i - 2].toDouble(),
                        this.entries[i - 1].toDouble(),
                        this.entries[i][0]
                )
                this.entries[i] = this.lastAnswer.toString()

            }
        }
        this.entries.clear()

        return this.lastAnswer
    }

}