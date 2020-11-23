fun main() {

    var evaluator: Evaluator

    evaluator = InfixEvaluator(" 1 + 2 * 3 / 5 - 15")
    println(evaluator.evaluate())

    //parser = PostfixParser("4 5 7 2 + - *")
    //parser = PostfixParser("4 2 3 5 1 - + * + *")
    //parser = PostfixParser("4 2 + 3 5 1 - * +")
    //parser = PostfixParser("5 7 + 6 2 - *")
    evaluator = PostfixEvaluator("2 3 1 * + 9 -")
    println(evaluator.evaluate())

    //parser = PrefixParser("+ - 2 7 * 8 / 12 3")
    //evaluator = PrefixEvaluator("+ - 2 7 * 8 / 4 12")
    evaluator = PrefixEvaluator("- + 7 * 4 5 + 2 0")
    println(evaluator.evaluate())


}