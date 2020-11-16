import java.lang.NumberFormatException
import kotlin.math.pow
import java.lang.StringIndexOutOfBoundsException

abstract class Parser(expression: String) {
    private var expression: String
    protected var lastAnswer: Double
    protected var entries: ArrayList<String>

    init {
        this.expression = " " + // so the evaluate function won't get confused
                (if(checkExpression(expression)) expression else "")  +
                " " // LOL

        this.removeExtraSpaces()
        this.lastAnswer = 0.0
        this.entries = ArrayList(0)

    }

    abstract fun evaluate(): Double

    fun addEntry(entry: String) {
        this.expression += if (checkExpression(entry)) entry else ""

    }

    protected fun isNumber(number: String): Boolean {
        try{
            number.toDouble()
        } catch(nfe: NumberFormatException) {
            return false
        }

        return true
    }

    protected fun printWrongOps(): Boolean {
        if(!isNumberOfOperandsValid()) {
            println( (27).toChar() + "[31m" + "CHECK NUMBER OF OPERATORS!!")
            print( (27).toChar() + "[0m")

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

    protected fun isOperator(chr: String): Boolean {
        val op = chr[0]
        try{
            chr[1]

        } catch(sioobe: StringIndexOutOfBoundsException) {
            return op == '+' || op == '-' ||
                    op == '*' || op == '/' ||
                    op == '^'

        }

        return false
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
                ( chr.isDigit() || isOperator(chr.toString()) ||
                        chr == ' ' || chr == '.' )
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

    private fun isNumberOfOperandsValid(): Boolean {
        var operands = 0
        var operators = 0
        for (entry: String in this.entries) {
            if (isOperator(entry)) {
                operators++
            } else {
                operands++
            }
        }

        return operands == operators + 1
    }

    private fun removeExtraSpaces() {

        this.expression = this.expression.replace("\\s+".toRegex(), " ")
    }

}