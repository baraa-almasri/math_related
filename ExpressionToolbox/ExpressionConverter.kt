package ExpressionToolbox

import java.util.*

object ExpressionConverter {

    // pass a valid expression, it's not my fucking job to validated blyat!
    // use Expression validator :)
    fun convertPostfix2Infix(expression: String): String {
        var infix = ""
        val operands = Stack<String>()
        val entries =
            ExpressionParser(
                expression
            ).getParsedExpression()

        if (!ExpressionChecker.isPostfix(entries)) {
            throw NotValidExpressionException("Check expression type")
        }

        for (entry: String in entries) {
            if (TermChecker.isNumber(entry)) {
                operands.push(entry)

            } else if (TermChecker.isOperator(entry)) {
                val secondOperand = operands.peek()
                operands.pop()
                val firstOperand = operands.peek()
                operands.pop()
                operands.push("($firstOperand $entry $secondOperand)")
            }
        }


        return operands.peek()
    }

    fun convertInfix2Prefix(expression: String): String {
        // reverse the expression to process it as a postfix :) THIS IS TMP BLYAT
        val entries = (
            ExpressionParser(
                expression.replace("[)]".toRegex(), "#").replace("[(]".toRegex(), ")")
                    .replace("[#]".toRegex(), "(")
            )
            ).getParsedExpression()

        if (!ExpressionChecker.isInfix(entries)) {
            throw NotValidExpressionException("Check expression type")
        }

        if (!ExpressionChecker.isInfix(entries)) {
            throw NotValidExpressionException("Check expression type")
        }

        // convert the expression to postfix and return the reversed postfix
        return convertInfix2Postfix(
            expression
        ).reversed()
    }

    fun convertInfix2Postfix(expression: String): String {
        val entries = (
            ExpressionParser(" ( $expression ) ")
            ).getParsedExpression()

        if (!ExpressionChecker.isInfix(entries)) {
            throw NotValidExpressionException("Check expression type")
        }
        val operators = Stack<Char>()
        var postfixExpression = ""

        for (entry: String in entries) {
            if (TermChecker.isNumber(entry)) {
                postfixExpression += " $entry"

            } else if (TermChecker.isParenth(entry)) {
                if (entry == "(") {
                    operators.push(entry[0])

                } else if (entry == ")") {
                    postfixExpression += popStackUntilOpenParenthAndStoreInString(operators)
                }

            } else if (TermChecker.isOperator(entry)) {
                if (getOperatorPrecedence(entry[0]) >
                    getOperatorPrecedence(operators.peek())
                ) {
                    operators.push(entry[0])

                } else if (getOperatorPrecedence(entry[0]) <
                    getOperatorPrecedence(operators.peek())
                ) {

                    postfixExpression += " ${operators.peek()}"
                    operators.pop()

                    if (isStackTopAndPreTopSamePrecedence(operators) ||
                        (getOperatorPrecedence(entry[0]) ==
                            getOperatorPrecedence(operators.peek()))
                    ) {
                        postfixExpression += " ${operators.peek()}"
                        operators.pop()

                        operators.push(entry[0])

                        continue
                    }

                    operators.push(entry[0])

                } else if (getOperatorPrecedence(entry[0]) ==
                    getOperatorPrecedence(operators.peek())
                ) {

                    postfixExpression += " ${operators.peek()}"
                    operators.pop()
                    operators.push(entry[0])
                }
            }
        }

        return "$postfixExpression "
    }

    private fun isStackTopAndPreTopSamePrecedence(stk: Stack<Char>): Boolean {
        val tmp = Stack<Char>()
        tmp.addAll(stk)

        return try {
            val top = tmp.peek()
            tmp.pop()
            val preTop = tmp.peek()

            top == preTop
        } catch (ese: EmptyStackException) {
            false
        }
    }

    private fun popStackUntilOpenParenthAndStoreInString(stk: Stack<Char>): String {
        var stackData = ""

        while (stk.peek() != '(' && !stk.empty()) {
            if (stk.peek() != ')' || stk.peek() != ')') {
                stackData += " ${stk.peek()}"
            }
            stk.pop()
        }
        if (stk.peek() == '(') {
            stk.pop()
        }

        return stackData
    }

    private fun getOperatorPrecedence(op: Char): Int {

        return when (op) {
            '-' -> 1
            '+' -> 1
            '*' -> 3
            '/' -> 3
            '^' -> 4
            else -> 0
        }
    }
}
