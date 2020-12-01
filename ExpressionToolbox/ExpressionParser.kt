package ExpressionToolbox

/*
 * use this class to get entries of an expression
 */

class ExpressionParser(expression: String) {
    private var validatedExpression: String
    private var entries: ArrayList<String>

    init {
        this.validatedExpression = (
            ExpressionValidator(expression)
            ).getValidatedExpression()

        this.entries = ArrayList()
    }

    fun getParsedExpression(): ArrayList<String> {
        this.updateEntries()

        return this.entries
    }

    private fun updateEntries() {
       this.entries =
           this.validatedExpression.substring(
               1, this.validatedExpression.length-1
           ).split(" ") as ArrayList<String>
    }


    fun areNumbersEntriesValid(): Boolean {

        for (entry: String in this.entries) {
            if (!TermChecker.isOperator(entry) ||
                !TermChecker.isParenth(entry) &&
                TermChecker.isNumber(entry)) {
                return true
            }
        }

        return false
    }

    fun isNumberOfOperandsValid(): Boolean {
        var operands = 0
        var operators = 0
        for (entry: String in this.entries) {
            if (TermChecker.isOperator(entry)) {
                operators++
            } else if (TermChecker.isNumber(entry)) {
                operands++
            }
        }

        return operands == operators + 1
    }

}
