
#ifndef _DATA_TYPES
#define _DATA_TYPES

int *string_GetSubStringIndices(char *string, char *substring);

/*check if string starts with check_string*/
int string_StartsWith_(char *string, char *check_pattern);

int string_EndsWith(char *string, char *check_pattern);

// reverse the characters of a strin such that it now begins from the end 
char *string_ReverseString(char *string);

char *string_ReplaceSubString(char *string, char *substring, char *repString);

// split a string into an array followin a certain provided delimeter
char *string_Split(char *string, char *delimeter);

/*check if check_string is in string 
check_string can also be a regular expression */
int in_String(char *string, char *check_string);

#endif