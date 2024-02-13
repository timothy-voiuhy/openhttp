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

int *string_GetSubStringIndices(char *string, char *substring){
    if(in_String(string, substring) != 0){
        perror("substring does not exist in string");
    }else{
        int *indices = (int *)malloc(sizeof(int)*2);
        int *last_idx=(int *)malloc(sizeof(int));
        int *first_idx = (int *)malloc(sizeof(int));
        int i = 0;
        while (i<strlen(string)-1)   
        {
            if (string[i] == substring[0]){
                *first_idx = i;
                int n = i+1;
                for (int m=1; m<strlen(substring);m++){
                    if(string[n] == substring[m]){
                        if (m == strlen(substring)-1){
                            *last_idx = n;
                            break;
                        }
                    }
                    n++;
                }
            }
            i++;
        }
        indices[0] = *first_idx;
        indices[1] = *last_idx;
        free((void *)first_idx);
        free((void *)last_idx);
        return indices;
    }    
}

// the returned string should be freed 
char *string_ReplaceSubString(char *string, char *substring, char *repString){
    if(in_String(string , substring) == 0){
        int *indices = malloc(sizeof(int)*2);
        // get first and last indices of the substring in the string
        indices = string_GetSubStringIndices(string ,substring);
        int first_idx = indices[0];
        int last_idx = indices[1];
        int len_lastportion = strlen(string) - (first_idx+1);
        // allocate memory for first and last portions
        char *sFirstPortion = malloc(first_idx+2);
        char *sLastPortion = malloc(strlen(string) - len_lastportion +1);
        // copy the firt portion of the string to sFirstPortion
        strncpy(sFirstPortion, string, first_idx);
        // copy the second portion of the string to the sLastPortion
        strncpy(sLastPortion, string+last_idx+1, len_lastportion);
        // concatenate the repString then sLastPortion to the sFirstPortion
        strcat(sFirstPortion, repString);
        strcat(sFirstPortion, sLastPortion);
        free((void *)indices);
        free((void *)sLastPortion);
        return sFirstPortion;
    }
    return NULL;
}
