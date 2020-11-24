import java.util.*

class PostfixEvaluator(expression: String) : Evaluator(expression) {
    override fun evaluate(): Double {
        if (!ExpressionChecker.isPostfix(this.entries)) {
            throw NotValidExpressionException("Check expression type!")
        }

        val numbers = Stack<Double>()

        for (entry: String in this.entries) {
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