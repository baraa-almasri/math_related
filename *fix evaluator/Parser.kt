/*
 * use this class to get entries of an expression
 */

class Parser(expression: String) {
    private var validatedExpression: String
    var entries: ArrayList<String>
        get() = field
        private set

    init {
        this.validatedExpression = (Expression(expression)).expression
        this.entries = ArrayList()

        this.updateEntries()
        if(!isNumberOfOperandsValid()) {
            throw WrongOperatorsException("Check operators count!")
        }
    }

    private fun updateEntries() {
        val spacesIndexes = getSpacesIndexes()
        for(index: Int in 0 until spacesIndexes.size - 1) {
            this.entries.add(
                this.validatedExpression.substring(
                    spacesIndexes[index] + 1,
                    spacesIndexes[index+1]
                )
            )
        }
    }

    private fun getSpacesIndexes(): ArrayList<Int> {
        val spacesIndex = ArrayList<Int>(0)
        for((index, chr) in this.validatedExpression.withIndex()) {
            if(chr == ' ') {
                spacesIndex.add(index)

            }
        }

        return spacesIndex
    }


    private fun isNumberOfOperandsValid(): Boolean {
        var operands = 0
        var operators = 0
        for (entry: String in this.entries) {
            if (TermChecker.isOperator(entry)) {
                operators++
            } else {
                operands++
            }
        }

        return operands == operators + 1
    }

}