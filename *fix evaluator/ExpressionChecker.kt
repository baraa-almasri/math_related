object ExpressionChecker {
    fun isInfix(entries: ArrayList<String>): Boolean {
        return (
            (TermChecker.isNumber(entries.first()) ||
                TermChecker.isParenth(entries.first())
                ) &&
                (TermChecker.isNumber(entries.last()) ||
                    TermChecker.isParenth(entries.last())
                    )
            )
    }

    fun isPostfix(entries: ArrayList<String>): Boolean {
        return (
            TermChecker.isNumber(entries.first()) &&
                TermChecker.isOperator(entries.last())
            )
    }

    fun isPrefix(entries: ArrayList<String>): Boolean {
        return (
            TermChecker.isOperator(entries.first()) &&
                TermChecker.isNumber(entries.last())
            )
    }

}