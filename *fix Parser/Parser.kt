import java.lang.NumberFormatException
import kotlin.math.pow
import java.lang.StringIndexOutOfBoundsException

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

        this.removeExtraSpaces()
        this.removeLastSpaces()
        this.lastAnswer = 0.0
        this.entries = ArrayList(0)

    }

    abstract fun evaluate(): Double

    fun addEntry(entry: String) {
        this.expression += if (checkExpression(entry)) entry else ""

    }

    protected fun removeExtraSpaces() {
        for(index in 0 until this.expression.length-1) {
            if(this.expression[index] == ' ' &&
                this.expression[index+1] == ' ')
            {
                this.expression =
                    this.expression.substring(0, index) + this.expression.substring(index+1)
                this.expression += " "
            }
        }
    }

    protected fun removeLastSpaces() {
        val lastSpaceIndex = this.expression.indexOf("  ")
        this.expression = this.expression.substring(0,
                if(lastSpaceIndex > -1) lastSpaceIndex+1 else this.expression.length
        )
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
}
