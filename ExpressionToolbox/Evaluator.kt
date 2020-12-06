package ExpressionToolbox

import kotlin.math.pow

abstract class Evaluator(expression: String, private var infix: Boolean) {
    protected var expression: String
    protected val entries: ArrayList<String>
    protected val expressionChecker: ExpressionChecker

    init {
        this.expression = (
            ExpressionValidator(expression, this.infix)
            ).getValidatedExpression()

        this.expressionChecker = ExpressionChecker
        this.entries =
            ExpressionParser(this.expression).getParsedExpression()
    }

    // the magical function
    abstract fun evaluate(): Double

    // set expression to new value of the SAME expression type
    fun replaceExpression(expression: String) {
        this.expression = (
            ExpressionValidator(expression, this.infix)
            ).getValidatedExpression()
    }

    // add an entry to the expression string and update fields
    fun addEntry(entry: String) {
        // check the added entry
        this.expression += (
            ExpressionValidator(entry, infix)
            ).getValidatedExpression() + " "

        this.entries.add(entry)
    }

    protected fun
        execOperator(rightOperand: Double, leftOperand: Double, op: Char): Double {

        return when (op) {
            '+' -> rightOperand + leftOperand
            '-' -> rightOperand - leftOperand
            '*' -> rightOperand * leftOperand
            '/' -> rightOperand / leftOperand
            '^' -> rightOperand.pow(leftOperand)
            else -> 0.0
        }
    }


}
