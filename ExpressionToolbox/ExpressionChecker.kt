package ExpressionToolbox

object ExpressionChecker {

    // expression type checkers

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

    // expression chars checkers

    fun isNumberOfParenthsValid(expression: String): Boolean {
        // TODO
        // try to use stack, stay scientific Jerry!
        var openParenths = 0
        var closeParenths = 0
        for (chr: Char in expression) {
            if (chr == '(') {
                openParenths++

            } else if (chr == ')') {
                closeParenths++
            }
        }

        return openParenths == closeParenths
    }

    fun isExpressionValid(expression: String): Boolean {
        for (chr: Char in expression) {
            if (!isCharValid(chr)) {
                return false
            }
        }

        return true
    }

    private fun isCharValid(chr: Char): Boolean {

        return (
            TermChecker.isNumber(chr.toString()) ||
                TermChecker.isOperator(chr.toString()) ||
                chr == ' ' ||
                chr == '.' ||
                chr == ')' ||
                chr == '('
            )
    }

}
