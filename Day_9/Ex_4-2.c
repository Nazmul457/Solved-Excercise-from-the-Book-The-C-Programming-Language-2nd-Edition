#include <stdio.h>
#include <ctype.h>
double my_atof(char s[]);

/*****************************************************************************************************/
/* FUNCTION NAME : main																			                                         */
/*																								                                                   */																							     
/* INPUTS 	   :  none															    			                                       */
/*        																						                                               */
/* RETURN 	   : = 0	-- Success																                                     */
/*		  	     : < 0	-- Failed																                                       */
/*            																					                                             */
/* NOTES 	   :  calling the function my_atof with necessary parameters	     				                 */
/*****************************************************************************************************/

int main()
{
    char input1[] = "123.45e-6";
    double result1 = my_atof(input1);
    printf("Input: %s\n", input1);
    printf("Output: %.10f\n\n", result1);

    char input2[] = "2.71828e3";
    double result2 = my_atof(input2);
    printf("Input: %s\n", input2);
    printf("Output: %.10f\n\n", result2);

    char input3[] = "-9.8765E+2";
    double result3 = my_atof(input3);
    printf("Input: %s\n", input3);
    printf("Output: %.10f\n\n", result3);

    return 0;
}

/********************************************************************************************************/
/* FUNCTION NAME : my_atof																				                                      */
/*																								     	                                                */																							     
/* INPUTS 	   :  1. s[] -- the source string								 	     					                            */	     			    
/*        																						     	                                            */
/* RETURN 	   : double																		     		                                      */
/*            																					     	                                          */
/* NOTES 	   : implimenting a function my_atof to handle scientific notation of the form 123.45e-6	    */
/********************************************************************************************************/
double my_atof(char s[]) {
    double val, power;
    int i, sign, exp_sign, exponent;

    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;

    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
        i++;

    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    if (s[i] == '.')
        i++;

    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }

    if (s[i] == 'e' || s[i] == 'E')
        i++;

    exp_sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
        i++;

    for (exponent = 0; isdigit(s[i]); i++)
        exponent = 10 * exponent + (s[i] - '0');

    double exp_multiplier_pos = 1.0;
    double exp_multiplier_neg = 1.0;

    if(exp_sign==1){
        while (exponent > 0) {
            exp_multiplier_pos *= 10.0;
            exponent--;
        }
        return sign * val / power * exp_multiplier_pos;
    }
    if(exp_sign==-1) {
        while (exponent > 0) {
            exp_multiplier_neg /= 10.0;
            exponent--;
        }
        return sign * val / power * exp_multiplier_neg;
    }

}

