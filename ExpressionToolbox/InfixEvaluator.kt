package ExpressionToolbox

class InfixEvaluator(expression: String) : Evaluator(expression) {
    private var converter: ExpressionConverter
    init {
        this.converter = ExpressionConverter()
    }

    override fun evaluate(): Double {
        if (!ExpressionChecker.isInfix(
                this.parsedEntries.getParsedExpression()
            )) {
            throw NotValidExpressionException("Check expression type!")
        }
        this.panicIfSomethingIsWrong()

        val postfix = (ExpressionConverter()
            ).convertInfix2Postfix(" (${this.expression}) ")

        return PostfixEvaluator(postfix).evaluate()
    }


}
