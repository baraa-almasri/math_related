package ExpressionToolbox

import java.util.*

class PrefixEvaluator(expression: String) : Evaluator(expression) {
    override fun evaluate(): Double {
        if (!ExpressionChecker.isPrefix(
                this.parsedEntries.getParsedExpression()
            )) {
            throw NotValidExpressionException("Check expression type!")
        }
        this.panicIfSomethingIsWrong()

        val numbers = Stack<Double>()

        for (entry in
        this.parsedEntries.getParsedExpression().reversed()) {

            if (TermChecker.isNumber(entry)) {
                numbers.push(entry.toDouble())
            }
            if (TermChecker.isOperator(entry)) {
                val firstOperand = numbers.peek()
                numbers.pop()
                val secondOperand = numbers.peek()
                numbers.pop()

                numbers.push(
                    execOperator(firstOperand, secondOperand, entry[0])
                )

            }
        }


        return numbers.peek()
    }

}
