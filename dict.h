#ifndef _DICT
#define _DICT

typedef struct{
    char *key;
    char *value;
}key_value_pair;

typedef struct{
    int num_of_pairs; 
    int key_sizes; // total size(bytes) of all the keys
    int value_sizes; // total size(bytes) of all the values
    char **keys;
    char **values;
    key_value_pair **pairs;// point to pointers of pairs
} dict;

dict *dict_CreateDict(); // returns a dict 
void Initialize_dict(dict *dict);
void dict_AddNewPair(dict *dict,char *key,char *value);
void dict_PrintDict(dict *dict);
void dict_Clear(dict *dict);
char **dict_GetKeys(dict *Dict);
char **dict_GetValues(dict *Dict);

#endif