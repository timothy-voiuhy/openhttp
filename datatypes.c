#include<stdlib.h>
#include<strings.h>
#include<regex.h>
#include<string.h>
#include<stdio.h>

#include "datatypes.h"

int string_StartsWith_(char *string, char *check_string){
    if(strncasecmp(check_string, string, strlen(check_string))==0){
        return EXIT_SUCCESS;
    }else{
        return EXIT_FAILURE;
    }
}

int in_String(char *string, char *check_pattern){
    char *pattern = check_pattern;
    regex_t compiled_xp;
    regmatch_t matched_xp[1];
    if(regcomp(&compiled_xp,pattern,0)!=0){
        printf("pattern compilation failed");
        return EXIT_FAILURE;
    }else{
        if(regexec(&compiled_xp, string,1,matched_xp,0)!=0){
            return EXIT_FAILURE;
        }else{
            return EXIT_SUCCESS;
        }
    }
    regfree(&compiled_xp);
}   

