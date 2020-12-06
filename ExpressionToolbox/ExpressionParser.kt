package ExpressionToolbox

/*
 * use this class to get entries of an expression
 */

class ExpressionParser(private var expression: String) {
    private var entries: ArrayList<String>

    init {
        this.entries = ArrayList()
    }

    fun getParsedExpression(): ArrayList<String> {
        this.updateEntries()
        this.throwIfSomethingIsWrong()

        return this.entries
    }

    private fun updateEntries() {
        // do you every hear of the tragedy of darth single line the idiot?
        // well he was a good programmer who shoves every statement in one line
        // then he modified a string then tried to get substring of the new string
        // then a big fat exception was thrown.
        // he died from the red impact but for us all to learn from his mistake press F to pray :(

        val entriesWOExtraSpaces =
            this.expression.replace("\\s+".toRegex(), " ")
        val entriesWOfrontAndBack =
            entriesWOExtraSpaces.substring(1, entriesWOExtraSpaces.length - 1 ) // so the first and last space won't be added as an entry

        this.entries =
            entriesWOfrontAndBack.split("\\s".toRegex()) as ArrayList<String>
    }

    private fun throwIfSomethingIsWrong() {
        if (!this.isNumberOfOperandsValid()) {
            throw WrongOperatorsException("Check Operators Count!")
        }
        if (!this.areNumbersEntriesValid()) {
            throw NotValidExpressionException("Check Numbers!")
        }
    }

    private fun areNumbersEntriesValid(): Boolean {

        for (entry: String in this.entries) {
            if (!TermChecker.isOperator(entry) &&
                !TermChecker.isParenth(entry) &&
                !TermChecker.isNumber(entry) ) {

                return false
            }
        }

        return true
    }

    private fun isNumberOfOperandsValid(): Boolean {
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
