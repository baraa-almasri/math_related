import PrefixParser
import PostfixParser
import InfixParser

fun main() {

    var parser: InfixParser
    parser = InfixParser("3.14 + 2 - 3.14")
    println(parser.evaluate())


}