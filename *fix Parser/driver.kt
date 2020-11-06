import PrefixParser
import PostfixParser
import InfixParser

fun main() {

    var parser: Parser
    parser = InfixParser("3.14 + 2 - 3.14")
    println(parser.evaluate())

    parser = PostfixParser("3 2 + 6 +")
    println(parser.evaluate())

    parser = PrefixParser("+ 2 3 - 6")
    println(parser.evaluate())


}