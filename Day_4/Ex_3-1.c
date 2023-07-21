#include <stdio.h>
#include <time.h>
/*****************************************************************************************************/
/* FUNCTION NAME : binsearch_basic																     */
/*																								     */																							     
/* INPUTS 	   :  1. x   -- the value to search													     */
/*       		  2. v[] -- the array in which the binary search occurs								 */
/*				  3. n   -- the size of the array													 */
/*        																						     */
/* RETURN 	   : = 0	-- Success																     */
/*		  	   : < 0	-- Failed																     */
/*            																					     */
/* NOTES 	   :  find x in v[0] <= v[1] <= ... <= v[n-1] basic binary search					 	 */
/*****************************************************************************************************/
int binsearch_basic(int x, int v[], int n) {
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low+high)/2;
		if (x < v[mid])
			high = mid + 1;
		else if (x > v[mid])
			low = mid + 1;
		else /* found match */
			return mid;
	}	
return -1; /* no match */
}

/********************************************************************************************************/
/* FUNCTION NAME : binsearch_modified																    */
/*																								     	*/																							     
/* INPUTS 	   :  1. x   -- the value to search													     	*/
/*       		  2. v[] -- the array in which the binary search occurs									*/
/*				  3. n   -- the size of the array													 	*/
/*        																						     	*/
/* RETURN 	   : = 0	-- Success																     	*/
/*		  	   : < 0	-- Failed																     	*/
/*            																					      	*/
/* NOTES 	   :  find x in v[0] <= v[1] <= ... <= v[n-1] binary search modifying an if-else statement 	*/
/********************************************************************************************************/
int binsearch_modified(int x, int v[], int n) {
	int low, mid, high;
	low = 0;
	high = n - 1;
	while (low <= high) {
    	mid = (low + high) / 2;
	    if (x < v[mid])
      		high = mid - 1;
    	else
      		low = mid + 1;
    	}
  	if (x == v[low - 1]) 
    	return low - 1;
  return -1;
}

/********************************************************************************************************/
/* FUNCTION NAME : main 																			    */
/*																								     	*/																							     
/* INPUTS 	    : no input parameters														   			*/
/*        																						     	*/
/* RETURN 	   : = 0	-- Success																     	*/
/*		  	   : < 0	-- Failed																     	*/
/*            																					      	*/
/* NOTES 	   : calling all other functions and observe the run-time of previous two functions		  	*/
/********************************************************************************************************/
int main() {
	int key, size, i, j;
	clock_t start, end;
	double cpu_time_used_basic = 0, cpu_time_used_modified = 0;
	
	printf("Please enter the size of the array: ");
	scanf("%d", &size);
	int arr[size];
	printf("Input the array elements:\n");
	for(i=1; i<=size; i++) {
		scanf("%d", &arr[i]);
	}
	printf("Input the value to find from the array: ");
	scanf("%d", &key);	
	for(i=0; i<1000000; i++){
		start = clock(); // Start the timer
		binsearch_basic(key, arr, size); // Calling the function
		end = clock(); // Stop the timer
		cpu_time_used_basic += ((double) (end-start))/CLOCKS_PER_SEC;
		
		start = clock(); // Start the timer
		binsearch_modified(key, arr, size); // Calling the function
		end = clock(); // Stop the timer
		cpu_time_used_modified += ((double) (end-start))/CLOCKS_PER_SEC;
		
	}
	
	printf("Execution time for Basic Binary Search function is: %.2lf\n", cpu_time_used_basic);
	printf("Execution time for Modified Binary Search function is: %.2lf\n", cpu_time_used_modified);
	
return 0;
}
