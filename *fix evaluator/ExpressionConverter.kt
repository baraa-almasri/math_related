import java.util.*

class ExpressionConverter(expression: String) {
    private var entries: ArrayList<String>

    init {
        this.entries = (Parser(expression)).entries
    }

    fun convertInfix2Postfix(): String {
        if (!ExpressionChecker.isInfix(this.entries)) {
            throw NotValidExpressionException("Check expression type")
        }

        val operators = Stack<Char>()
        var postfixExpression = ""
        for (entry: String in this.entries) {

            if (TermChecker.isNumber(entry)) {
                postfixExpression += " $entry"

            } else if (TermChecker.isOperator(entry)) {
                // push operator as its precedence
                if (!operators.empty()) {
                    if (getOperatorPrecedence(entry[0]) >
                        getOperatorPrecedence(operators.peek())) {

                        operators.push(entry[0])

                    } else if (getOperatorPrecedence(entry[0]) <
                        getOperatorPrecedence(operators.peek())) {

                        postfixExpression += " ${operators.peek()}"
                        operators.pop()
                        operators.push(entry[0])

                    } else {
                        postfixExpression += " ${operators.peek()}"
                        operators.pop()
                        operators.push(entry[0])

                    } // inner inner if

                } else {
                    operators.push(entry[0])
                } // inner if

            } else if (TermChecker.isParenth(entry)) {
                if (entry[0] == ')') {
                    while (!operators.empty()) {
                        postfixExpression += " ${operators.peek()}"
                        operators.pop()
                    }
                }
            }
        }

        return postfixExpression
    }

    private fun getOperatorPrecedence(op: Char): Int {

        return when (op) {
            '+' -> 1
            '-' -> 2
            '*' -> 3
            '/' -> 3
            '^' -> 5
            'p' -> 5
            else -> 0
        }
    }
}