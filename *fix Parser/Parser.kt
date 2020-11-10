import kotlin.math.pow

abstract class Parser(expression: String) {
    var expression: String = ""
        get() = field
        private set

    protected var lastAnswer: Double
    protected var entries: ArrayList<String>

    init {
        this.expression = (if(expression[0] == ' ') "" else " ") + // so the evaluate function won't get confused
                (if(checkExpression(expression)) expression else "")  +
                if(expression[expression.length-1] == ' ') "" else " " // LOL

        this.lastAnswer = 0.0
        this.entries = ArrayList(0)

    }

    abstract fun evaluate(): Double

    fun addEntry(entry: String) {
        this.expression += if (checkExpression(entry)) entry else ""

    }

    protected fun printWrongOps(): Boolean {
        if(!isNumberOfOperandsValid()) {
            println( (27).toChar() + "[31m" + "CHECK NUMBER OF OPERATORS!!")
            print( (27).toChar() + "[30m")

            return true
        }

        return false
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

    protected fun execOperator
            (rightOperand: Double, leftOperand: Double, op: Char)
            : Double {

        return when (op) {
            '+' -> rightOperand + leftOperand
            '-' -> rightOperand - leftOperand
            '*' -> rightOperand * leftOperand
            '/' -> rightOperand / leftOperand
            '^' -> rightOperand.pow(leftOperand)
            else -> 0.0
        }
    }

    protected fun isOperator(chr: Char): Boolean {

        return chr == '+' || chr == '-' ||
                chr == '*' || chr == '/' ||
                chr == '^'
    }

    private fun checkExpression(expression: String): Boolean {
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
                ( chr.isDigit() || isOperator(chr) ||
                        chr == ' ' || chr == '.')
        )
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

    protected fun isNumberOfOperandsValid(): Boolean {
        var operands = 0
        var operators = 0
        for(entry: String in this.entries) {
            if(isOperator(entry[0])) {
                operators++
            } else {
                operands++
            }
        }

        return operands == operators+1
    }
}