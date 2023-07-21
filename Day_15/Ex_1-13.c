#include <stdio.h>
#define MAXSIZE  1000

int freq_of_individual_wordsize[MAXSIZE+1];
int max_window_height = 0;

/*******************************************************************************************/
/* FUNCTION NAME : draw_histogram												  	 	                             */
/*																						                                             */																							     
/* INPUTS 	   :  no arguements														 	                               */
/*        																				                                         */
/* RETURN 	   : nothing																                                   */
/*            																			                                       */
/* NOTES 	   : draw the histogram	against individual words having same sizes frequencies   */
/*******************************************************************************************/
void draw_histogram(){
    int histogram_bar_height, i, j;
    for(histogram_bar_height = max_window_height; histogram_bar_height > 0; histogram_bar_height--){
        printf("%3d|", histogram_bar_height);
        for(j = 0; j < MAXSIZE; j++){
            if(freq_of_individual_wordsize[j] == 0) continue;
            if(freq_of_individual_wordsize[j] < histogram_bar_height) {
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
        else if(freq_of_individual_wordsize[i]) {
            printf("---");
        }
    }
    printf("\n");

    for(i = 0; i <= MAXSIZE; i++) {
        if(i == 0){
            printf("    ");
        }
        else if(freq_of_individual_wordsize[i]) {
            printf("%3d", i);
        }
    }
    printf("\n");
}

/*****************************************************************************************/
/* FUNCTION NAME : process_input												   	     */
/*																				   	     */																							     
/* INPUTS 	   :  no arguements													   	     */
/*        																		         */
/* RETURN 	   : nothing														         */
/*            																	         */
/* NOTES 	   : process the input string by updating frequencies the words according to */
/*				 their sizes in freq_of_individual_wordsize[] array. 					 */
/*****************************************************************************************/
void process_input() {
    int each_string_length = 0;
    char ch;
    while((ch = getchar()) != EOF) {
        if(ch == ' ' || ch == '\t' || ch == '\n') {
            if(each_string_length) {
                freq_of_individual_wordsize[each_string_length]++;
                if(freq_of_individual_wordsize[each_string_length] > max_window_height) {
                    max_window_height =  freq_of_individual_wordsize[each_string_length];
                }
            }
            each_string_length = 0;
        }
        else {
            each_string_length++;
        }
    }
}

int main() {
    process_input();
    draw_histogram();

    return 0;
}


