#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"dict.h"

#define INITIAL_DICT_SIZE 8

void Initialize_dict(dict *Dict){
    Dict->num_of_pairs =0;
    Dict->key_sizes =0;
    Dict->value_sizes = 0;
    key_value_pair **pairs = (key_value_pair **)malloc(sizeof(double));
    Dict->keys = (char **)malloc(sizeof(double));
    Dict->values = (char **)malloc(sizeof(double));
    // Dict->pair_array_size = sizeof(key_value_pair);
    Dict->pairs = pairs;
}

/*Create a new dict`ionary object
Remember to call dict_Clear() function to free call the memory to avoid memory leaks*/
dict *dict_CreateDict(){
    dict *Dict  = (dict *)malloc(sizeof(dict));
    Initialize_dict(Dict);
    return Dict; // the Dict returned has in it the num_of_pairs set to 0 and the pairs set to the address of pairs
};

void dict_AddNewPair(dict *Dict,char *key,char *value){// Add a new key:value pair to the dict
    int key_len = strlen(key);
    int value_len = strlen(value);
    Dict->num_of_pairs += 1;
    Dict->key_sizes += key_len;
    Dict->value_sizes += value_len;
    int n_size = key_len+value_len; //size that can be covered by the key and value
    // new_size = current_pair_array_size + n_size(size of key and value) + 2(null characters)
    Dict->pairs = (key_value_pair **)realloc(Dict->pairs,sizeof(double)*Dict->num_of_pairs);
    key_value_pair *pair;
    pair = malloc(sizeof(n_size + 2));
    pair->key = key;
    pair->value = value;
    Dict->pairs[Dict->num_of_pairs-1] = pair;
}

// read all the elements in the dict_array and print them out to the screen
void dict_PrintDict(dict *Dict){
    printf("%s","{");
    for (size_t i = 0; i < Dict->num_of_pairs; i++)
    {
        char *key = Dict->pairs[i]->key;
        char *value = Dict->pairs[i]->value;
        if (i==Dict->num_of_pairs-1)
        {
            printf("%s:%s", key, value);
        }else{printf("%s:%s,", key, value);}
    } 
    printf("%s\n","}");  
}

// returns an array of the dictionary keys
char **dict_GetKeys(dict *Dict){
    for (size_t i = 0; i < Dict->num_of_pairs; i++)
    {
        char *key = Dict->pairs[i]->key;
        Dict->keys[i]  = key;
    }
    return Dict->keys;
}

// returns an array of the dictionary values
char **dict_GetValues(dict *Dict){
    for (size_t i = 0; i < Dict->num_of_pairs; i++)
    {
        char *key = Dict->pairs[i]->value;
        Dict->values[i]  = key;
    }
    return Dict->values;
}

void dict_Clear(dict *dict){

    for (size_t i = 0; i < dict->num_of_pairs; i++)
    {
        free((void *)dict->pairs[i]);
    }
    free((void *)dict->keys);
    free((void *)dict->values);
    free((void *)dict->pairs);
    free((void *)dict);
}
