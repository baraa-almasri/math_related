class InfixEvaluator(expression: String) : Evaluator(expression) {
    override fun evaluate(): Double {
        if (!ExpressionChecker.isInfix(this.entries)) {
            throw NotValidExpressionException("Check expression type!")
        }

        val postfix = ExpressionConverter(
            " (${this.expression})"
        ).convertInfix2Postfix()

        return PostfixEvaluator(postfix).evaluate()
    }

    // ok this shit is about to get heavy
    private fun getOperatorPrecedence(op: Char): Int {

        return when (op) {
            '+' -> 1
            '-' -> 1
            '*' -> 2
            '/' -> 2
            '^' -> 3
            else -> 0
        }
    }

    private fun getOperatorsPrecedences(): ArrayList<Int> {
        val operandsPrecedences = ArrayList<Int>()
        for (entry in this.entries) {
            if (TermChecker.isOperator(entry)) {
                operandsPrecedences.add(getOperatorPrecedence(entry[0]))
            }
        }
        operandsPrecedences.sort()

        return operandsPrecedences
    }

}
