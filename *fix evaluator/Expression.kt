/*
 * use this class to get validated expression
 */

class Expression(expression: String) {
    var expression: String
        get() = field
        private set

    init {
        if(!isExpressionValid(expression)) {
            throw NotValidExpressionException()
        }

        this.expression = " " + // to parse properly blyat
                expression +
                " " // LOL

        this.removeExtraChars()
    }

    private fun isExpressionValid(expression: String): Boolean {
        for(chr: Char in expression) {
            if(!isCharValid(chr)) {
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
                chr == '.'  ||
                chr == ')' ||
                chr == '('
        )
    }

    private fun removeExtraChars() {
        this.expression = this.expression.replace("\\s+".toRegex(), " ")
        this.expression = this.expression.replace("[+]+".toRegex(), "+")
        this.expression = this.expression.replace("[-]+".toRegex(), "-")
        this.expression = this.expression.replace("[*]+".toRegex(), "*")
        this.expression = this.expression.replace("[/]+".toRegex(), "/")
        this.expression = this.expression.replace("[p]+".toRegex(), "p")
    }

}