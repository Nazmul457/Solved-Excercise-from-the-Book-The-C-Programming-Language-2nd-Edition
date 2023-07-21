#include <stdio.h>
#define LIMIT 50
int main(){
	int i, c;
	char s[LIMIT];
	
	printf("Enter the string: ");
	for(i = 0; ; ++i){
		if(i> (LIMIT-1))
			break;
		c = getchar();
		
		if(c == '\n')
		 	break;
		 
		else if(c==EOF)
			break;
		else
			s[i] = c;
	}
	
	s[i] = '\0';
	printf("String is: %s\n", s);
	return 0;
	
}
