package ExpressionToolbox

import kotlin.math.pow

abstract class Evaluator(expression: String) {
    protected var expression: String
    protected var parsedEntries: ExpressionParser
    protected var expressionChecker: ExpressionChecker

    init {
        this.expression = (
            ExpressionValidator(expression)
            ).getValidatedExpression()

        this.expressionChecker = ExpressionChecker
        this.parsedEntries = ExpressionParser(expression)
    }

    abstract fun evaluate(): Double

    // add an entry to the expression string and update fields
    fun addEntry(entry: String) {
        this.expression += (
            ExpressionValidator(entry)
            ).getValidatedExpression() + " "

        this.parsedEntries = ExpressionParser(this.expression)
    }

    protected fun panicIfSomethingIsWrong() {
        if (!parsedEntries.isNumberOfOperandsValid()) {
            throw WrongOperatorsException("Check Operators Count!")
        }
        if (!parsedEntries.areNumbersEntriesValid()) {
            throw NotValidExpressionException("Check Numbers!")
        }
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
