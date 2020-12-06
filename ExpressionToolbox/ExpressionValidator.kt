package ExpressionToolbox

class ExpressionValidator(expression: String, private var infix: Boolean ) {
    private var expression: String
    private val expressionChecker: ExpressionChecker

    init {
        this.expression = " $expression "
        this.expressionChecker = ExpressionChecker
    }

    fun getValidatedExpression(): String {
        this.throwIfSomethingIsWrong()

        if (this.infix) { // only infix accepts this stuff
            this.addSpaces()
        }
        // re-remove additional shits caused by addSpaces
        this.removeExtraChars()

        return this.expression
    }

    private fun throwIfSomethingIsWrong() {
        if (!this.expressionChecker.isExpressionValid(this.expression) ||
            !this.expressionChecker.isNumberOfParenthsValid(this.expression)) {
            throw NotValidExpressionException()
        }
    }

    private fun removeExtraChars() {
        this.expression = this.expression.replace("[+]+".toRegex(), "+")
        this.expression = this.expression.replace("[-][-]+".toRegex(), "- -")
        this.expression = this.expression.replace("[-]+".toRegex(), "-")
        this.expression = this.expression.replace("[*]+".toRegex(), "*")
        this.expression = this.expression.replace("[/]+".toRegex(), "/")
        this.expression = this.expression.replace("[\\^]+".toRegex(), "^")
        this.expression = this.expression.replace("\\s+".toRegex(), " ")
    }

    // INFIX EXCLUSIVE!
    private fun addSpaces() {

        // match as many shit as possible
        for (i in 0..this.expression.length/2) {

            // match [\\d]+[-][\\d]+ and add a whitespaces between minus sign
            val matchedNumberMinusNumber: String? = try {
                "[\\d]+[-][\\d]+".toRegex().find(this.expression)?.value
            } catch (npe: KotlinNullPointerException) {
                null
            }
            if (matchedNumberMinusNumber != null) {
                val numberBeforeMinus = matchedNumberMinusNumber.substring(0, matchedNumberMinusNumber.indexOf('-'))
                val numberAfterMinus = matchedNumberMinusNumber.substring(matchedNumberMinusNumber.indexOf('-')+1)

                this.expression =
                    this.expression.replace("[\\d]+[-][\\d]+".toRegex(), "$numberBeforeMinus - $numberAfterMinus")
            }

            // same as above but to avoid user fuck-ups
            // match [\d]+[\s]+[-][\d]+ and add a whitespaces between minus sign
            val matchedNumberSpaceMinusNumber: String? = try {
                "[\\d]+[\\s]+[-][\\d]+".toRegex().find(this.expression)?.value
            } catch (npe: KotlinNullPointerException) {
                null
            }
            if (matchedNumberSpaceMinusNumber != null) {
                val numberBeforeMinus = matchedNumberSpaceMinusNumber.substring(0, matchedNumberSpaceMinusNumber.indexOf('-'))
                val numberAfterMinus = matchedNumberSpaceMinusNumber.substring(matchedNumberSpaceMinusNumber.indexOf('-')+1)

                this.expression =
                    this.expression.replace("[\\d]+[\\s]+[-][\\d]+".toRegex(), "$numberBeforeMinus - $numberAfterMinus")
            }

            // same as above but to avoid more user fuck-ups
            // match [\d]+[-][\s]+[\d]+ and add a whitespaces between minus sign
            val matchedNumberMinusSpaceNumber: String? = try {
                "[\\d]+[-][\\s]+[\\d]+".toRegex().find(this.expression)?.value
            } catch (npe: KotlinNullPointerException) {
                null
            }
            if (matchedNumberMinusSpaceNumber != null) {
                val numberBeforeMinus = matchedNumberMinusSpaceNumber.substring(0, matchedNumberMinusSpaceNumber.indexOf('-'))
                val numberAfterMinus = matchedNumberMinusSpaceNumber.substring(matchedNumberMinusSpaceNumber.indexOf('-')+1)

                this.expression =
                    this.expression.replace("[\\d]+[-][\\s]+[\\d]+".toRegex(), "$numberBeforeMinus - $numberAfterMinus")
            }

            // binary shit
            // match [)][-]+[\d]+ and add a whitespaces between minus sign
            val matchedClosingParenthsMinusNumber: String? = try {
                "[)][-][\\d]+".toRegex().find(this.expression)?.value
            } catch (npe: KotlinNullPointerException) {
                null
            }
            if (matchedClosingParenthsMinusNumber != null) {
                val numberAfterMinus = matchedClosingParenthsMinusNumber.substring(matchedClosingParenthsMinusNumber.lastIndexOf('-')+1)

                this.expression =
                    this.expression.replace("[)][-][\\d]+".toRegex(), " ) - $numberAfterMinus")
            }

            // match [)][-][-][\d]+ and add a whitespaces between minus sign
            val matchedClosingParenthsMinusMinusNumber: String? = try {
                "[)][-][-]+[\\d]+".toRegex().find(this.expression)?.value
            } catch (npe: KotlinNullPointerException) {
                null
            }
            if (matchedClosingParenthsMinusMinusNumber != null) {
                val numberAfterMinus = matchedClosingParenthsMinusMinusNumber.substring(matchedClosingParenthsMinusMinusNumber.lastIndexOf('-'))

                this.expression =
                    this.expression.replace("[)][-][-][\\d]+".toRegex(), " ) - $numberAfterMinus")
            }

            // match [)][+][-][\d]+ and add a whitespaces between minus sign
            val matchedClosingParenthsPlusNumber: String? = try {
                "[)][+]+[-]+[\\d]+".toRegex().find(this.expression)?.value
            } catch (npe: KotlinNullPointerException) {
                null
            }
            if (matchedClosingParenthsPlusNumber != null) {
                val numberAfterMinus = matchedClosingParenthsPlusNumber.substring(matchedClosingParenthsPlusNumber.lastIndexOf('-'))

                this.expression =
                    this.expression.replace("[)][+]+[-]+[\\d]+".toRegex(), " ) + $numberAfterMinus")
            }
            // match [)][*][-][\d]+ and add a whitespaces between minus sign
            val matchedClosingParenthsMultNumber: String? = try {
                "[)][*]+[-]+[\\d]+".toRegex().find(this.expression)?.value
            } catch (npe: KotlinNullPointerException) {
                null
            }
            if (matchedClosingParenthsMultNumber != null) {
                val numberAfterMinus = matchedClosingParenthsMultNumber.substring(matchedClosingParenthsMultNumber.lastIndexOf('-'))

                this.expression =
                    this.expression.replace("[)][*]+[-]+[\\d]+".toRegex(), " ) * $numberAfterMinus")
            }
            // match [)][/][-][\d]+ and add a whitespaces between minus sign
            val matchedClosingParenthsDivNumber: String? = try {
                "[)][/]+[-]+[\\d]+".toRegex().find(this.expression)?.value
            } catch (npe: KotlinNullPointerException) {
                null
            }
            if (matchedClosingParenthsDivNumber != null) {
                val numberAfterMinus = matchedClosingParenthsDivNumber.substring(matchedClosingParenthsDivNumber.lastIndexOf('-'))

                this.expression =
                    this.expression.replace("[)][/]+[-]+[\\d]+".toRegex(), " ) / $numberAfterMinus")
            }
            // match [)][p][-][\d]+ and add a whitespaces between minus sign
            val matchedClosingParenthsPowNumber: String? = try {
                "[)][\\^]+[-]+[\\d]+".toRegex().find(this.expression)?.value
            } catch (npe: KotlinNullPointerException) {
                null
            }
            if (matchedClosingParenthsPowNumber != null) {
                val numberAfterMinus = matchedClosingParenthsPowNumber.substring(matchedClosingParenthsPowNumber.lastIndexOf('-'))

                this.expression =
                    this.expression.replace("[)][\\^]+[-]+[\\d]+".toRegex(), " ) ^ $numberAfterMinus")
            }

            // match [(]+[-][\\d]+ and add a whitespaces between minus sign
            val matchedOpenParanthsMinusNumber: String? = try {
                "[(]+[-][\\d]+".toRegex().find(this.expression)?.value
            } catch (npe: KotlinNullPointerException) {
                null
            }
            if (matchedOpenParanthsMinusNumber != null) {
                val numberAfterMinus = matchedOpenParanthsMinusNumber.substring(matchedNumberMinusNumber?.indexOf('-') as Int)

                this.expression =
                    this.expression.replace("[(]+[-][\\d]+".toRegex(), " ( - $numberAfterMinus ")
            }

            // match [\d]+[-] and add space between minus sign and the found digit
            var matchedNumberMinus: String? = ""
            try {
                matchedNumberMinus = "[\\d]+[-]".toRegex().find(this.expression)?.value
                if (matchedNumberMinus != null) {
                    matchedNumberMinus = matchedNumberMinus.substring(0, matchedNumberMinus?.length - 1)
                }
            } catch (npe: KotlinNullPointerException) {
                matchedNumberMinus = null
            }


            if (matchedNumberMinus != null) {
                this.expression =
                    this.expression.replace("[\\d]+[-]".toRegex(), " $matchedNumberMinus - ")
            }//
        }
        ////////////////////////////
        this.expression =
            this.expression.replace("[+][-]+".toRegex(), "+ -")
        this.expression =
            this.expression.replace("[*][-]+".toRegex(), "* -")
        this.expression =
            this.expression.replace("[\\/][-]+".toRegex(), "/ -")
        this.expression =
            this.expression.replace("[-][-]".toRegex(), "- -")
        this.expression =
            this.expression.replace("[p][-]+".toRegex(), "p -")
        // redundant, will be removed :)
        this.expression =
            this.expression.replace("[)][-]+".toRegex(), ") -")
        this.expression =
            this.expression.replace("[+]".toRegex(), " + ")
        this.expression =
            this.expression.replace("[*]".toRegex(), " * ")
        this.expression =
            this.expression.replace("[/]".toRegex(), " / ")
        this.expression =
            this.expression.replace("[\\^]".toRegex(), " ^ ")
        // blyat
        this.expression =
            this.expression.replace("[-][ ]+[-]+".toRegex(), " - -")

        this.expression =
            this.expression.replace("[-][ ]+[-][(]".toRegex(), "- -1 * ( ")

        this.expression =
            this.expression.replace("[(]".toRegex(), " ( ")
        this.expression =
            this.expression.replace("[)]".toRegex(), " ) ")
    }

}
