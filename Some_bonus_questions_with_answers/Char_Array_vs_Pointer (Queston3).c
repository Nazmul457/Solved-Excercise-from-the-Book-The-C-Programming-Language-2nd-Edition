#include <stdio.h>
#include <string.h>
int main(){
    char a1[3][4]={"1X","2Y","3ZX"};
    char (*p1)[4];
  	char **pa1 = a1; 
//	char (*pa1)[4] = a1;
	int no_of_iteration = 1, j;

	for(p1=a1; p1<a1+3; p1++, pa1++){
	  printf("->Iteration %d: \n", no_of_iteration++);
	  printf("p1 points to address = %d\n",p1);
	  printf("Value at that address is (*p1) = %s\n",*p1);
	  for(j = 0; j<strlen(*p1); j++){
	  	printf("%c\n", *(*p1+j));
	  }
	}
	    
    printf("a1[3][4]=%d\n",a1[3][4]); 
    printf("a1[2][3]=%d\n",a1[2][3]); 
    printf("a1 size: %dBytes\n",sizeof(a1));

//  char *a2[3]={"1XYZ1XYU","2XYZ2X","3"};
  	char *a2[3]={"1XYZ123","2XYZ123","3XYZ123"}; 
    char **p2;
    printf("-->Printing each string of *a2[3] with their addresses:\n");
    for(p2=a2; p2<a2+3; p2++){ 
        printf("Address of %s is : %d\n", *p2, p2);
	}
	printf("address of a2: %d\n", a2);
    printf("a2 size: %dBytes\n",sizeof(a2)); 
    printf("a2[1] size: %dBytes\n",sizeof(a2[1])); 
    printf("a2 size: %dBytes\n",sizeof(*a2[1]));     
    return 0;
}
