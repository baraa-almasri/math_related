package ExpressionToolbox

import java.util.*

class PostfixEvaluator(expression: String) : Evaluator(expression, false) {
    override fun evaluate(): Double {
        if (!this.expressionChecker.isPostfix(this.entries)) {
            throw NotValidExpressionException("Check expression type!")
        }

        val numbers = Stack<Double>()

        for (entry in this.entries) {

            if (TermChecker.isNumber(entry)) {
                numbers.push(entry.toDouble())

            } else if (TermChecker.isOperator(entry)) {
                val secondOperand = numbers.peek()
                numbers.pop()
                val firstOperand = numbers.peek()
                numbers.pop()

                numbers.push(
                    execOperator(firstOperand, secondOperand, entry[0])
                )

            }
        }

        return numbers.peek()
    }
}
