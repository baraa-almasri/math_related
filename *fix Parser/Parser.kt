import kotlin.math.pow

abstract class Parser(expression: String) {
    protected var expression: String
    protected var lastAnswer: Double
    protected var entries: ArrayList<String>

    init {
        this.expression = " " + // so the evaluate function won't get confused
                (if(checkExpression(expression)) expression else "")  +
                " " // LOL

        this.lastAnswer = 0.0
        this.entries = ArrayList(0)

    }

    abstract fun evaluate(): Double

    fun addEntry(entry: String) {
        this.expression += if (checkExpression(entry)) entry else ""

    }

    private fun getSpacesIndexes(): ArrayList<Int> {
        val spacesIndex = ArrayList<Int>(0)
        for((index, chr) in this.expression.withIndex()) {
            if(chr == ' ') {
                spacesIndex.add(index)

            }
        }

        return spacesIndex
    }

    protected fun updateEntries() {
        val spacesIndexes = getSpacesIndexes()
        for(index: Int in 0 until spacesIndexes.size - 1) {
            this.entries.add(
                this.expression.substring(
                       spacesIndexes[index] + 1,
                       spacesIndexes[index+1]
                )
            )
        }
    }

    protected fun checkSameEquation(expression: String): Boolean {

        return false
    }

    protected fun checkExpression(expression: String): Boolean {
        for(chr: Char in expression) {
            if(!isCharValid(chr)) {
                return false
            }
        }

        return true
    }

     private fun isCharValid(chr: Char): Boolean {

        return (
                !(chr.isLowerCase() && chr.isUpperCase()) &&
                ( chr.isDigit() || isOperator(chr) || chr == ' '
                    || chr == '.'
                )
        )
    }

    protected fun execOperator
            (rightOperand: Double, leftOperand: Double, op: Char)
            : Double {

        return if(op == '+') rightOperand + leftOperand else
            if(op == '-') rightOperand - leftOperand else
            if(op == '*') rightOperand * leftOperand else
            if(op == '/') rightOperand / leftOperand else
            if(op == '^') rightOperand.pow(leftOperand) else 0.0
    }

    protected fun isOperator(chr: Char): Boolean {

        return chr == '+' || chr == '-' ||
                chr == '*' || chr == '/' ||
                chr == '^'
    }

}
