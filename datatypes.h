
#ifndef _DATA_TYPES
#define _DATA_TYPES

/*check if string starts with check_string*/
int string_StartsWith_(char *string, char *check_pattern);

/*check if check_string is in string 
check_string can also be a regular expression */
int in_String(char *string, char *check_string);

#endif