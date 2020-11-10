import PrefixParser
import PostfixParser
import InfixParser

fun main() {

    var parser: Parser

    parser = InfixParser("3.14 + 2 - 3.14")
    println(parser.evaluate())

    //parser = PostfixParser("4 5 7 2 + - *")
    //parser = PostfixParser("4 2 3 5 1 - + * + *")
    //parser = PostfixParser("4 2 + 3 5 1 - * +")
    //parser = PostfixParser("5 7 + 6 2 - *")
    parser = PostfixParser("3 4 + 2 * 7 /")
    println(parser.evaluate())

    parser = PrefixParser("+ - 2 7 * 8 / 4 12")
    println(parser.evaluate())


}