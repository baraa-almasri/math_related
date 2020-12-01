package ExpressionToolbox

import java.util.*

fun main() {
    val read = Scanner(System.`in`)

    while (true) {
        print("Enter expression in infix notation: ")
        val infix = read.nextLine()
        val postfix = (ExpressionConverter()).convertInfix2Postfix("($infix)")
        val prefix = (ExpressionConverter()).convertInfix2Prefix("($infix)")
        println("postfix: $postfix")
        println("prefix: $prefix")
    }
}
