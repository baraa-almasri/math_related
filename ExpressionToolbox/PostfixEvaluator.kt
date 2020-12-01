package ExpressionToolbox

import java.util.*

class PostfixEvaluator(expression: String) : Evaluator(expression) {
    override fun evaluate(): Double {
        if (!ExpressionChecker.isPostfix(
                this.parsedEntries.getParsedExpression()
            )) {
            throw NotValidExpressionException("Check expression type!")
        }
        this.panicIfSomethingIsWrong()

        val numbers = Stack<Double>()

        for (entry: String in
        this.parsedEntries.getParsedExpression()) {

            if (TermChecker.isNumber(entry)) {
                numbers.push(entry.toDouble())
            }
            if (TermChecker.isOperator(entry)) {
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
