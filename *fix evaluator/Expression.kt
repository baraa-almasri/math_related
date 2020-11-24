/*
 * use this class to get validated expression
 */

class Expression(expression: String) {
    var expression: String
        private set

    init {
        if (!isExpressionValid(expression) ||
            !isNumberOfParenthsValid(expression)) {
            throw NotValidExpressionException()
        }

        this.expression = " " + // to parse properly blyat
            expression +
            " " // LOL

        this.removeExtraChars()
        this.addSpaces()
        // re-remove additional spaces caused by addSpaces
        this.removeExtraChars()
    }

    private fun isExpressionValid(expression: String): Boolean {
        for (chr: Char in expression) {
            if (!isCharValid(chr)) {
                return false
            }
        }

        return true
    }

    private fun isNumberOfParenthsValid(expression: String): Boolean {
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

    private fun removeExtraChars() {
        this.expression = this.expression.replace("\\s+".toRegex(), " ")
        this.expression = this.expression.replace("[+]+".toRegex(), "+")
        this.expression = this.expression.replace("[-][-]+".toRegex(), "-")
        this.expression = this.expression.replace("[*]+".toRegex(), "*")
        this.expression = this.expression.replace("[/]+".toRegex(), "/")
        this.expression = this.expression.replace("[p]+".toRegex(), "p")
    }

    // ONLY FOR INFIX SINCE IT CAN ACCEPT THIS KIND OF SHIT
    private fun addSpaces() {
        this.expression =
            this.expression.replace(
                "[-][\\d]+".toRegex(),
                " ${"[-][\\d]+".toRegex().find(this.expression)?.value.toString()} "
            )

        this.expression =
            this.expression.replace("[-]".toRegex(), " - ")
        this.expression =
            this.expression.replace("[+]".toRegex(), " + ")
        this.expression =
            this.expression.replace("[*]".toRegex(), " * ")
        this.expression =
            this.expression.replace("[/]".toRegex(), " / ")
        this.expression =
            this.expression.replace("[p]".toRegex(), " p ")
        this.expression =
            this.expression.replace("[(]".toRegex(), " ( ")
        this.expression =
            this.expression.replace("[)]".toRegex(), " ) ")
    }

}