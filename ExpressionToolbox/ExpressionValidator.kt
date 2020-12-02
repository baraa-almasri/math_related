package ExpressionToolbox

class ExpressionValidator(expression: String) {
    private var expression: String

    init {
        this.expression = " $expression "
    }

    fun getValidatedExpression(): String {
        if (!isExpressionValid(this.expression) ||
            !isNumberOfParenthsValid(this.expression)) {
            throw NotValidExpressionException()
        }

        //this.removeExtraChars()
        // in the future blyat
        this.addSpaces()
        // re-remove additional shits caused by addSpaces
        this.removeExtraChars()

        return this.expression
    }

    private fun isExpressionValid(expression: String): Boolean {
        for (chr: Char in expression) {
            if (!isCharValid(chr)) {
                return false
            }
        }

        return true
    }

    private fun isNumberOfParenthsValid(expression: String): Boolean {
        var openParenths = 0
        var closeParenths = 0
        for (chr: Char in expression) {
            if (chr == '(') {
                openParenths++

            } else if (chr == ')') {
                closeParenths++
            }
        }

        return openParenths == closeParenths
    }

    private fun isCharValid(chr: Char): Boolean {

        return (
            TermChecker.isNumber(chr.toString()) ||
                TermChecker.isOperator(chr.toString()) ||
                chr == ' ' ||
                chr == '.' ||
                chr == ')' ||
                chr == '('
            )
    }

    private fun removeExtraChars() {
        this.expression = this.expression.replace("[+]+".toRegex(), "+")
        this.expression = this.expression.replace("[-][-]+".toRegex(), "- -")
        // process here blyat
        this.expression = this.expression.replace("[-]+".toRegex(), "-")
        this.expression = this.expression.replace("[*]+".toRegex(), "*")
        this.expression = this.expression.replace("[/]+".toRegex(), "/")
        this.expression = this.expression.replace("[p]+".toRegex(), "p")
        this.expression = this.expression.replace("\\s+".toRegex(), " ")
    }


    private fun processUnaryBinaryMinusSigns() {
        // for each +2 signs replace w/ - -x
        // for 1 sign replace w/ - x
        // now let the magic begin ;)

        for (chr: Char in this.expression) {

        }
    }

    // ONLY FOR INFIX SINCE IT CAN ACCEPT THIS KIND OF SHIT
    private fun addSpaces() {

        // match as many shit as possible
        for (i in 0..this.expression.length/2) {

            // match [\\d]+[-][\\d]+ and add a whitespaces between minus sign

            val matchedNumberMinusNumber: String? = try {
                "[\\d]+[-][\\d]+".toRegex().find(this.expression)!!.value
            } catch (npe: KotlinNullPointerException) {
                null
            }
            if (matchedNumberMinusNumber != null) {
                val numberBeforeMinus = matchedNumberMinusNumber.substring(0, matchedNumberMinusNumber.indexOf('-'))
                val numberAfterMinus = matchedNumberMinusNumber.substring(matchedNumberMinusNumber.indexOf('-')+1)

                this.expression =
                    this.expression.replace("[\\d]+[-][\\d]+".toRegex(), "$numberBeforeMinus - $numberAfterMinus")
            }

            // match [)][-][-][\d]+ and add a whitespaces between minus sign
            val matchedClosingParenthsMinusNumber: String? = try {
                "[)][-]+[\\d]+".toRegex().find(this.expression)!!.value
            } catch (npe: KotlinNullPointerException) {
                null
            }
            if (matchedClosingParenthsMinusNumber != null) {
                val numberAfterMinus = matchedClosingParenthsMinusNumber.substring(matchedClosingParenthsMinusNumber.lastIndexOf('-'))

                this.expression =
                    this.expression.replace("[)][-]+[\\d]+".toRegex(), " ) - $numberAfterMinus")
            }

            // match [)][+][-][\d]+ and add a whitespaces between minus sign
            val matchedClosingParenthsPlusNumber: String? = try {
                "[)][+]+[-]+[\\d]+".toRegex().find(this.expression)!!.value
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
                "[)][*]+[-]+[\\d]+".toRegex().find(this.expression)!!.value
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
                "[)][/]+[-]+[\\d]+".toRegex().find(this.expression)!!.value
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
                "[)][p]+[-]+[\\d]+".toRegex().find(this.expression)!!.value
            } catch (npe: KotlinNullPointerException) {
                null
            }
            if (matchedClosingParenthsPowNumber != null) {
                val numberAfterMinus = matchedClosingParenthsPowNumber.substring(matchedClosingParenthsPowNumber.lastIndexOf('-'))

                this.expression =
                    this.expression.replace("[)][p]+[-]+[\\d]+".toRegex(), " ) p $numberAfterMinus")
            }

            // match [(]+[-][\\d]+ and add a whitespaces between minus sign
            val matchedOpenParanthsMinusNumber: String? = try {
                "[(]+[-][\\d]+".toRegex().find(this.expression)!!.value
            } catch (npe: KotlinNullPointerException) {
                null
            }
            if (matchedOpenParanthsMinusNumber != null) {
                val numberAfterMinus = matchedOpenParanthsMinusNumber.substring(matchedNumberMinusNumber!!.indexOf('-'))

                this.expression =
                    this.expression.replace("[(]+[-][\\d]+".toRegex(), " ( - $numberAfterMinus ")
            }

            // match [\d]+[-] and add space between minus sign and the found digit
            var matchedNumberMinus: String? = ""
            try {
                matchedNumberMinus = "[\\d]+[-]".toRegex().find(this.expression)!!.value
                if (matchedNumberMinus != null) {
                    matchedNumberMinus = matchedNumberMinus.substring(0, matchedNumberMinus!!.length - 1)
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
            this.expression.replace("[+][-]".toRegex(), "+ -")
        this.expression =
            this.expression.replace("[*][-]".toRegex(), "* -")
        this.expression =
            this.expression.replace("[\\/][-]".toRegex(), "/ -")
        this.expression =
            this.expression.replace("[-][-]".toRegex(), "- -")
        this.expression =
            this.expression.replace("[p][-]".toRegex(), "p -")
        // redundant, will be removed :)
        this.expression =
            this.expression.replace("[)][-]".toRegex(), ") -")
        this.expression =
            this.expression.replace("[+]".toRegex(), " + ")
        this.expression =
            this.expression.replace("[*]".toRegex(), " * ")
        this.expression =
            this.expression.replace("[/]".toRegex(), " / ")
        this.expression =
            this.expression.replace("[p]".toRegex(), " p ")
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
