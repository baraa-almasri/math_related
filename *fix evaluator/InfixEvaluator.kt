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


}
