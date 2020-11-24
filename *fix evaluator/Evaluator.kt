import kotlin.math.pow

abstract class Evaluator(expression: String) {
    protected var expression: String
    protected var entries: ArrayList<String>

    init {
        this.expression = (Expression(expression)).expression
        this.entries = (Parser(expression)).entries
    }

    abstract fun evaluate(): Double

    // add an entry to the expression string and update fields
    fun addEntry(entry: String) {
        this.expression += (Expression(entry)).expression + " "
        this.entries = (Parser(this.expression)).entries
    }

    protected fun execOperator(rightOperand: Double, leftOperand: Double, op: Char)
        : Double {

        return when (op) {
            '+' -> rightOperand + leftOperand
            '-' -> rightOperand - leftOperand
            '*' -> rightOperand * leftOperand
            '/' -> rightOperand / leftOperand
            'p' -> rightOperand.pow(leftOperand)
            else -> 0.0
        }
    }


}