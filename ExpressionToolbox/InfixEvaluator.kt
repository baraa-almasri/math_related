package ExpressionToolbox

class InfixEvaluator(expression: String) : Evaluator(expression, true) {
    private var converter: ExpressionConverter

    init {
        this.converter = ExpressionConverter
    }

    override fun evaluate(): Double {
        if (!this.expressionChecker.isInfix(this.entries)) {
            throw NotValidExpressionException("Check expression type!")
        }

        val postfix = (this.converter
            ).convertInfix2Postfix(this.expression)

        return PostfixEvaluator(postfix).evaluate()
    }


}
