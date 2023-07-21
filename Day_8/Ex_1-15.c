#include <stdio.h>

/********************************************************************************************************/
/* FUNCTION NAME : temp_converter																		                                    */
/*																								     	                                                */																							     
/* INPUTS 	   :  1. argc -- the number of parameters provided to the main function				     	        */
/*       		      2. argv -- the pointer to the input string array of parameters            			    	*/
/*        																						     	                                            */
/* RETURN 	   : nothing																		     	                                      */
/*            																					     	                                          */
/* NOTES 	   : print Fahrenheit-Celsius and Celsius-Fahrenheit table using a function for conversion    */
/*				 for fahr = 0, 20, ..., 300 and celsius = 0, 20, ..., 300		       				                    */
/********************************************************************************************************/
void temp_converter() {
    int c;
    printf("Press 1 for Fahrenheit to Celsius Conversion Table....!\n");
    printf("Press 2 for Celsius to Fahrenheit Coversion Table....!\n");
    scanf("%d", &c);
    float i;
    switch(c) {
        case 1:
        printf("Fahrenheit\tCelsius\n");
        for(i=0; i<=300; i+=20){
            printf("%3.0f \t\t%6.1f\n", i, (5.0/9.0) * (i-32.0)); 
        }
        break;
        case 2:
        printf("Celsius\t\tFahrenheit\n");
        for(i=0; i<=300; i+=20){
            printf("%3.0f \t\t%6.1f\n", i, ((9.0/5.0)*i) + 32.0); 
        }
        break;
        default:
        	printf("Invalid input! Please enter a valid input(1 or 2).");
        	break;
    }
}

/*****************************************************************************************************/
/* FUNCTION NAME : main																			                                         */
/*																								                                                   */																							     
/* INPUTS 	   	: nothing    														 			                                       */
/*        																						                                               */
/* RETURN 	   : nothing																		                                         */
/*            																					                                             */
/* NOTES 	   : call the temp_converter() finction							       				                         */
/*****************************************************************************************************/
main() {
    temp_converter();
}
