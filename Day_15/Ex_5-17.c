#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>

#define MAX_NUMBER_OF_LINES 5000

#define MAX_LINE_LENGTH 1000
#define ALLOC_MEM_SIZE 10000

#define MAXIMUM_NUMBER_OF_FIELDS 100
#define MAXIMUM_NUMBER_OF_FIELD_OPTIONS 4

#define INT_MAXIMUM_NUMBER_OF_DIGITS (int)(floor(log10(labs(INT_MAX))) + 1)

static char alloc_buf[ALLOC_MEM_SIZE];
static char *alloc_p = alloc_buf;

char *alloc(int size);
void afree(char *ptr);

int get_line(char line[], int max_line_len);

int arguments_list_parsing(int argc, char *argv[]);

int nth_blank_pos_in_string(const char *s, int n);
char *sub_string(const char *s, int start, int end);
int read_lines(char *line_ptr[], const int max_nr_of_lines);
void write_lines(char *line_ptr[], const int nr_of_lines);

int numcmp(const char *s1, const char *s2);
int my_strcasecmp(const char *s1, const char *s2);
int fields_compare(const char *s1, const char *s2);
void swap(void *v[], int i, int j);
void my_quick_sort(void *v[], int start, int end, int (*comp)(void *, void *));

int sorting_order = 1;     /*1 ascendent, -1 descendent*/
int fold = 0;      /*0 case sensitive, 1 case insensitive*/
int directory = 0; /*0 normal, 1 directory*/
int (*comp)(const char *, const char *) = my_strcasecmp;

enum field_option
{
  INDEX_OF_FIELD_COMP,
  ORDER,
  FOLD,
  DIRECTORY
};

int nr_of_fields_to_compare = 0;
int (*fields_indexes_to_comp[MAXIMUM_NUMBER_OF_FIELDS])(const char *, const char *);
int fields_options[MAXIMUM_NUMBER_OF_FIELDS][MAXIMUM_NUMBER_OF_FIELD_OPTIONS];

/*****************************************************************************************************/
/* FUNCTION NAME : main																			                                         */
/*																								                                                   */																							     
/* INPUTS 	   :  1. argc -- the number of parameters provided to the main function				           */
/*       		      2. argv -- the pointer to the input string array of parameters          			     */
/*        																						                                               */
/* RETURN 	   : = 0	-- Success																                                     */
/*		  	     : < 0	-- Failed		                                  														     */
/*            																					                                             */
/* NOTES 	   : invoking all other functions with necessary parameters and inputs				  	         */
/*****************************************************************************************************/
int main(int argc, char *argv[])
{
  
  if (!arguments_list_parsing(argc, argv))
  {
    puts("Error: invalid arguments.");
    return EXIT_FAILURE;
  }

  int nr_of_lines;
  char *line_ptr[MAX_NUMBER_OF_LINES];

  if ((nr_of_lines = read_lines(line_ptr, MAX_NUMBER_OF_LINES)) != -1)
  {
    my_quick_sort((void **)line_ptr, 0, nr_of_lines - 1, (int (*)(void *, void *))comp);
    if(EXIT_SUCCESS) printf("The result after applying q-sort: \n");
    write_lines(line_ptr, nr_of_lines);
  }
  else
  {
    puts("Error: input too large.");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

/*****************************************************************************************************/
/* FUNCTION NAME : arguments_list_parsing													     	                             */
/*																								                                                   */																							     
/* INPUTS 	   : 1. argc -- the number of parameters provided to the main function			       	     */
/*       		     2. argv -- the pointer to the input string array of parameters 					           */
/*        																						                                               */
/* RETURN 	   :  integer																		                                         */
/* NOTES 	   :  Parses the command-line arguments and sets the sorting options				 	             */
/*****************************************************************************************************/
int arguments_list_parsing(int argc, char *argv[]) {
	int i;
	for (i = 1; i < argc; ++i) {
	int arguments_length = strlen(argv[i]);
	if (arguments_length > 1 && argv[i][0] == '-')
	{
	  int j;
	  for (j = 1; j < arguments_length; ++j)
	  {
	    if (isdigit(argv[i][j]) && !fields_options[i - 1][INDEX_OF_FIELD_COMP])
	    {
	      char field_index_str[INT_MAXIMUM_NUMBER_OF_DIGITS];
	
	      int k = 0;
	      while (isdigit(argv[i][j]) && j < arguments_length && k < INT_MAXIMUM_NUMBER_OF_DIGITS)
	      {
	        field_index_str[k++] = argv[i][j++];
	      }
	      field_index_str[k] = '\0';
	
	      fields_options[i - 1][INDEX_OF_FIELD_COMP] = atoi(field_index_str);
	
	      --j;
	      ++nr_of_fields_to_compare;
	    }
	    else
	    {
	      switch (argv[i][j])
	      {
	      case 'n':
	        comp = numcmp;
	        break;
	    	
	      case 'f':
	        fold = 1;
	        break;
	
	      case 'd':
	        directory = 1;
	        break;
	
	      case 'r':
	        sorting_order = -1;
	        break;
	
	      default:
	        return 0;
	        break;
	      }
	    }
	  }
	
	  if (nr_of_fields_to_compare || argc > 2)
	  {
	    if (!fields_options[i - 1][INDEX_OF_FIELD_COMP])
	    {
	      return 0;
	    }
	
	    fields_indexes_to_comp[i - 1] = comp;
	    fields_options[i - 1][ORDER] = sorting_order;
	    fields_options[i - 1][FOLD] = fold;
	    fields_options[i - 1][DIRECTORY] = directory;
	
	    comp = my_strcasecmp;
	    sorting_order = 1;
	    fold = 0;
	    directory = 0;
	  }
	}
	else
	{
	  return 0;
	}
	}
	
	if (nr_of_fields_to_compare && nr_of_fields_to_compare == argc - 1)
	{
	comp = fields_compare;
	}
	else if (argc > 2)
	{
	return 0;
	}
	
	return 1;
}

/*****************************************************************************************************/
/* FUNCTION NAME : nth_blank_pos_in_string													     	                           */
/*																								                                                   */																							     
/* INPUTS 	     :  1. *s -- pointer to the character string										                     */
/*				        2. n  -- blank position number in string											                     */
/*        																						                                               */
/* RETURN 	     :  integer																	                                    	   */
/* NOTES 	       :  Returns the position of the nth blank character in a string 		             		 */
/*****************************************************************************************************/
int nth_blank_pos_in_string(const char *s, int n)
{
  int pos = 0;
  while (n && *s != '\0')
  {
    if (*s == ' ' || *s == '\t')
    {
      do
      {
        ++pos;
        ++s;
      } while (*s == ' ' || *s == '\t');

      --n;
    }
    else
    {
      ++pos;
      ++s;
    }
  }

  return pos;
}

/*****************************************************************************************************/
/* FUNCTION NAME : *sub_string																     	                                 */
/*																								                                                   */																							     
/* INPUTS 	   :  1. *s -- pointer to the character string										                       */
/*       				  2. start  -- start position in string												                       */
/*			      	  3. end -- end position of string										 			                         */
/*        																						                                               */
/* RETURN 	   :  pointer to a character														                                 */
/* NOTES 	     :  Extracts a substring from a given string 					 	 					                     */
/*****************************************************************************************************/
char *sub_string(const char *s, int start, int end)
{
  if (start > end)
  {
    return NULL;
  }

  const int len = end - start;
  char *dest = alloc(len + 1);
  int i;
  for (i = start; i < end && s[i] != '\0'; ++i)
  {
    *dest = s[i];
    ++dest;
  }
  *dest = '\0';

  return dest - len;
}

/*****************************************************************************************************/
/* FUNCTION NAME : get_line																     	 	                                   */
/*																								                                                   */																							     
/* INPUTS 	   :  1. line[] 	     -- store single line from input		              						     */
/*				        2. max_line_len  -- maximum length of line										                     */
/*        																						                                               */
/* RETURN 	   :  integer																		                                         */
/* NOTES 	   	 :  Reads a line from standard input and returns its length	 	 					               */
/*****************************************************************************************************/
int get_line(char line[], int max_line_len)
{
  int c;
  int i;

  for (i = 0; i < max_line_len - 1 && (c = getc(stdin)) != EOF && c != '\n'; ++i)
  {
    line[i] = c;
  }

  if (c == '\n')
  {
    line[i] = c;
    ++i;
  }

  line[i] = '\0';

  return i;
}

/*****************************************************************************************************/
/* FUNCTION NAME : read_lines															     	 	                                   */
/*																								                                                   */																							     
/* INPUTS 	   :  1. *line_ptr[]   	  -- store the lines from input								                   */
/*				        2. max_nr_of_lines  -- maximum number of lines to take input						           */
/*        																						                                               */
/* RETURN 	   :  integer																		                                         */
/* NOTES 	     :  Reads a line from standard input and returns its length	 	 					               */
/*****************************************************************************************************/
int read_lines(char *line_ptr[], const int max_nr_of_lines)
{
  int line_length;
  int nr_of_lines = 0;

  char *current_line = alloc(MAX_LINE_LENGTH);
  char *current_line_copy = NULL;

  while ((line_length = get_line(current_line, MAX_LINE_LENGTH)))
  {
    if (nr_of_lines >= max_nr_of_lines || (current_line_copy = alloc(line_length)) == NULL)
    {
      return -1;
    }
    else
    {
      current_line[line_length - 1] = '\0';
      strcpy(current_line_copy, current_line);
      line_ptr[nr_of_lines++] = current_line_copy;
    }
  }

  afree(current_line);

  return nr_of_lines;
}

void write_lines(char *line_ptr[], const int nr_of_lines)
{
  
  int i;
  for (i = 0; i < nr_of_lines; ++i)
  {
    puts(line_ptr[i]);
    afree(line_ptr[i]);
  }
}

/*****************************************************************************************************/
/* FUNCTION NAME : numcmp																     	 	                                     */
/*																								                                                   */																							     
/* INPUTS 	   :  1. *s1   	  -- pointer to 1st character										                         */
/*				        2. *s1   	  -- pointer to 2nd character											                       */
/*        																						                                               */
/* RETURN 	   :  integer																		                                         */
/* NOTES 	     :  Compares two strings numerically.							 	 					                         */
/*****************************************************************************************************/
int numcmp(const char *s1, const char *s2)
{
  double nr1 = atof(s1);
  double nr2 = atof(s2);

  if (nr1 < nr2)
  {
    return sorting_order * -1;
  }
  else if (nr1 > nr2)
  {
    return sorting_order * 1;
  }

  return 0;
}

/*****************************************************************************************************/
/* FUNCTION NAME : my_strcasecmp														     	 	                                 */
/*																								                                                   */																							     
/* INPUTS 	   :  1. *s1   	  -- pointer to 1st character of String 1							                   */
/*				        2. *s1   	  -- pointer to 2nd character of String 2					                			 */
/*        																						                                               */
/* RETURN 	   :  integer																		                                         */
/* NOTES 	   :  Compares two strings case-insensitively.							 	 			                       */
/*****************************************************************************************************/
int my_strcasecmp(const char *s1, const char *s2)
{
  while (*s1 != '\0' && *s2 != '\0')
  {
    if (directory)
    {
      while (*s1 != '\0' && !isalnum(*s1) && !isspace(*s1))
      {
        ++s1;
      }
      while (*s2 != '\0' && !isalnum(*s2) && !isspace(*s2))
      {
        ++s2;
      }
    }

    int result = fold ? tolower(*s1) - tolower(*s2) : *s1 - *s2;
    if (result == 0)
    {
      ++s1;
      ++s2;
    }
    else
    {
      return sorting_order * result;
    }
  }

  return 0;
}

/*****************************************************************************************************/
/* FUNCTION NAME : fields_compare														     	 	                                 */
/*																								                                                   */																							     
/* INPUTS 	   :  1. *s1   	  -- pointer to 1st character of string 1							                   */
/*				        2. *s2   	  -- pointer to 2nd character of string 2								                 */
/*        																						                                               */
/* RETURN 	   :  integer																		                                         */
/* NOTES 	     :  Compares two strings based on specified fields and options.		 	 	                 */
/*****************************************************************************************************/
int fields_compare(const char *s1, const char *s2)
{
  int i = 0;
  while (i < nr_of_fields_to_compare)
  {
    int start_s1 = nth_blank_pos_in_string(s1, fields_options[i][INDEX_OF_FIELD_COMP] - 1);
    int end_s1 = nth_blank_pos_in_string(s1, fields_options[i][INDEX_OF_FIELD_COMP]);
    char *field_s1 = sub_string(s1, start_s1, end_s1);

    int start_s2 = nth_blank_pos_in_string(s2, fields_options[i][INDEX_OF_FIELD_COMP] - 1);
    int end_s2 = nth_blank_pos_in_string(s2, fields_options[i][INDEX_OF_FIELD_COMP]);
    char *field_s2 = sub_string(s2, start_s2, end_s2);

    comp = fields_indexes_to_comp[i];
    sorting_order = fields_options[i][ORDER];
    fold = fields_options[i][FOLD];
    directory = fields_options[i][DIRECTORY];

    int comp_result = comp(field_s1, field_s2);

    afree(field_s1);
    afree(field_s2);

    if (comp_result == 0)
    {
      ++i;
    }
    else
    {
      return comp_result;
    }
  }

  return 0;
}

/*****************************************************************************************************/
/* FUNCTION NAME : swap																	     	 	                                     */
/*																								                                                   */																							     
/* INPUTS 	     :  1. *v[]  	-- pointer to the array to swap in					  	                       */
/*				          2. i   	  -- index of 1st element												                         */
/*				          3. j		  -- index of 2nd element												                         */
/*        																						                                               */
/* RETURN 	    :  integer																	                                         */
/* NOTES 	      :  Compares two strings based on specified fields and options.		 	 			           */
/*****************************************************************************************************/
void swap(void *v[], int i, int j)
{
  void *temp;
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

/*****************************************************************************************************/
/* FUNCTION NAME : swap																	     	 	                                     */
/*																								                                                   */																							     
/* INPUTS 	   :  1. *v[]  	 -- pointer to the array to swap in			                                 */
/*				  			2. start   -- index of 1st element							                                   */
/*				  			3. end		 -- index of last element						                                     */
/*				  			4. int (*comp)(void *, void *)	--  function pointer to the comparison function    */
/*														that is used for sorting 					                                     */
/*        																						     																					 */
/* RETURN 	   :  integer																		                                         */
/* NOTES 	     :  Compares two strings based on specified fields and options.		 			               */
/*****************************************************************************************************/
void my_quick_sort(void *v[], int start, int end, int (*comp)(void *, void *))
{
  if ((long)start >= (long)end)
  {
    return;
  }

  swap(v, start, (start + end) / 2);

  int last = start;
  int i;
  for (i = start + 1; i <= end; ++i)
  {
    if ((*comp)(v[i], v[start]) < 0)
    {
      swap(v, ++last, i);
    }
  }

  swap(v, start, last);
  my_quick_sort(v, start, last - 1, comp);
  my_quick_sort(v, last + 1, end, comp);
}

char *alloc(int size)
{
  if (alloc_buf + ALLOC_MEM_SIZE - alloc_p >= size)
  {
    alloc_p += size;
    return alloc_p - size;
  }

  return NULL;
}

void afree(char *ptr)
{
  if (ptr >= alloc_buf && ptr < alloc_buf + ALLOC_MEM_SIZE)
  {
    alloc_p = ptr;
  }
}
