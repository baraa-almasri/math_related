package ExpressionToolbox

import java.util.*

class ExpressionConverter {

    fun convertInfix2Prefix(expression: String): String {
        // reverse the expression to process it as a postfix :) THIS IS TMP BLYAT
        val entries = (
            ExpressionParser(
                expression.replace("[)]".toRegex(), "#").
                replace("[(]".toRegex(), ")").
                replace("[#]".toRegex(), "(")
            )
            ).getParsedExpression()

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
            ExpressionParser(" $expression ")
            ).getParsedExpression()

        if (!ExpressionChecker.isInfix(entries)) {
            throw NotValidExpressionException("Check expression type")
        }
        val operators = Stack<Char>()
        var postfixExpression = ""

        for(entry: String in entries) {
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
                    getOperatorPrecedence(operators.peek())) {


                    operators.push(entry[0])




                } else if (getOperatorPrecedence(entry[0]) <
                    getOperatorPrecedence(operators.peek())) {

                    postfixExpression += " ${operators.peek()}"
                    operators.pop()

                    if (isStackTopAndPreTopSamePrecedence(operators) ||
                        (getOperatorPrecedence(entry[0]) ==
                            getOperatorPrecedence(operators.peek())))
                    {
                        postfixExpression += " ${operators.peek()}"
                        //postfixExpression += " ${entry[0]}"
                        operators.pop()

                        operators.push(entry[0])

                        continue
                    }

                    operators.push(entry[0])

                } else if (getOperatorPrecedence(entry[0]) ==
                    getOperatorPrecedence(operators.peek())) {

                    postfixExpression += " ${entry[0]}"
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

        while ( stk.peek() != '(' && !stk.empty()) {
            if( stk.peek() != ')' || stk.peek() != ')' ) {
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
            '^' -> 5
            'p' -> 5
            else -> 0
        }
    }
}
