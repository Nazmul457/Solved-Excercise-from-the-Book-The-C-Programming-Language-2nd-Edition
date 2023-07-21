#include <stdio.h>
#define MAXSIZE 256

int freq_of_individual_character[MAXSIZE+1];
int max_window_height = 0;

/************************************************************************************/
/* FUNCTION NAME : draw_histogram												  	                        */
/*																					                                        */																							     
/* INPUTS 	     : no arguements						  						                          */
/*        																		                                    	*/
/* RETURN 	     : nothing															                            */
/*            																		                                  */
/* NOTES 	   		 : draw the histogram	for individual character frequencies		      */
/************************************************************************************/
void draw_histogram(){
    int histogram_bar_height, i, j;
    for(histogram_bar_height = max_window_height; histogram_bar_height > 0; histogram_bar_height--){
        printf("%3d|", histogram_bar_height);
        for(j = 0; j < MAXSIZE; j++){
            if(freq_of_individual_character[j] == 0) continue;
            if(freq_of_individual_character[j] < histogram_bar_height) {
                printf("   ");
            }
            else {
                printf("  *");
            }
        }
        printf("\n");
    }
    for(i = 0; i <= MAXSIZE; i++) {
        if(i == 0){
            printf("    ");
        }
        else if(freq_of_individual_character[i]) {
            printf("---");
        }
    }
    printf("\n");
	
	printf("    ");
    for(i = 0; i < MAXSIZE; i++) {
        if(freq_of_individual_character[i]){
	        if(i == ' '){
	        	printf("\' \'");
			}
			else if(i == '\n') {
				printf(" \\n");
			}
			else if(i == '\t'){
				printf(" \\t");
			}
			else if(freq_of_individual_character[i]) {
	            printf("%3c", i);
	        }
		}	
    }
    printf("\n");
return;
}

/***********************************************************************************/
/* FUNCTION NAME : process_input												                           */
/*																				                                         */																							     
/* INPUTS 	   :  no arguements													                           */
/*        																		                                     */
/* RETURN 	   : nothing														                               */
/*            																	                                   */
/* NOTES 	   : process the input string by updating the individual character       */ 
/*				     frequencies	in freq_of_individual_character[] array.			         */
/***********************************************************************************/
void process_input() {
    
    char ch;
    while((ch = getchar()) != EOF) {
        freq_of_individual_character[ch]++;
        if(freq_of_individual_character[ch] > max_window_height) {
            max_window_height =  freq_of_individual_character[ch];
        }          
    }
return;
}

int main() {
    process_input();
    draw_histogram();
    return 0;
}


