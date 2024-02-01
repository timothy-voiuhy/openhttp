#include <string.h>
#include<strings.h>
#include<regex.h>
#include<stdio.h>
#include<stdlib.h>

#include "core.h"
#include "http.h"
#include "dns_resolve.h"
#include "datatypes.h"

#ifndef __HTTP
#define __HTTP

int  IsValidUrl(char *url){// test whether the url is valid or not 
    if(in_String(url, HTTP_REGEX) != 0){
        if(in_String(url,HTTPS_REGEX) != 0){
            return EXIT_FAILURE;
        }
    };
    return EXIT_SUCCESS;
}

int url_StartsWithHttp(char *url){
    return string_StartsWith_(url, "http");
}

int url_StartsWithHttps(char *url){
    return string_StartsWith_(url, "https");
}

int MatchHttps(char *url){
    return in_String(url,HTTPS_REGEX);
}

char *MatchReturnNetloc(char *url){
    if(IsValidUrl(url) != 0){
        perror("provided URL is invalid");
    }else{
        regex_t compiled_expression;
        regmatch_t match[1];
        char *pattern  = NETLOC_PATTERN;
        if(regcomp(&compiled_expression, pattern , 0)!=0){
            fprintf(stderr, "compilation failed");
        }else{
            if(regexec(&compiled_expression, url,1, match, 0)==0){
                // extract netloc
                char matched_netloc[100];
                snprintf(matched_netloc, sizeof(matched_netloc),"%.*s",match[0].rm_eo-match[0].rm_so,url+match[0].rm_eo);
                return &matched_netloc;
                }else{
                    return (char *)EXIT_FAILURE;
            }
        }
    }    
}

URL DecompileUrl(char *url){
    URL decompiled_url;
    if (IsValidUrl(url) != EXIT_SUCCESS){
        fprintf(stderr, "Cannot decompile url. Provided string Is not valid url");
    }
    if (MatchHttps(url) != EXIT_SUCCESS){
        decompiled_url.scheme = SCHEME_HTTPS;
    }else{
        decompiled_url.scheme = SCHEME_HTTP;
        }
    char *netloc = MatchReturnNetloc(url);
    if(netloc != (char *)1){
        decompiled_url.netloc = netloc;
    }    
} 


/*get the default http headers 
don't forget to free the headers pointer*/
char *http_GetDefaultHeaders(URL url){
    dict *http_headers = dict_CreateDict();
    dict_AddNewPair(http_headers,h_HOST,url.netloc);
    dict_AddNewPair(http_headers,"Accept-Encoding","gzip, deflate");
    dict_AddNewPair(http_headers,"Accept-Language","en-US,en;q=0.9");
    dict_AddNewPair(http_headers,"Referrer-Policy","origin-when-cross-origin");
    dict_GetKeys(http_headers);
    dict_GetValues(http_headers);
    char *headers;
    for (size_t i = 0; i < http_headers->num_of_pairs; i++)
    {
        char *key = http_headers->keys[i];
        char *value = http_headers->values[i];
        char *header = (char *)malloc(strlen(key)+strlen(value)+4);
        char *http_newline_chr = "\r\n";
        snprintf(header,strlen(key)+strlen(value),"%s:%s",key,value);
        //concatenate the header with the  \r\n string
        if(i=0){
            headers = malloc(strlen(header)+1);
            strncpy(headers,header,strlen(header));
        }else{
            strncat(headers, header,strlen(header));
        }
        return headers;
        free((void *)header);
    }
    dict_Clear(http_headers);
}

char *http_MakeHttpPacket(URL url, char *method){
    char *packet;
    char *headers = http_GetDefaultHeaders(url);
    packet = malloc(strlen(method)+1);
    strncat(packet,method, strlen(method));
    strncat(packet,"\r",1);
    strncat(packet,(char *)url.netloc,strlen((char *)url.netloc));
    strncat(packet,url.scheme,strlen(url.scheme));
    strncat(packet,"\r\n",2);
    strncat(packet,headers,strlne(headers));
    return packet;
}

Response http_MakeRequest(char *url,char *method){
    URL url_struct = DecompileUrl(url);
    char *data  = http_MakeHttpPacket(url_struct,"GET");
    char *ip_addr  = dns_ResolveUrl(url);
    char *response = http_CreateConnectionSend(ip_addr,data);
    return http_ProcessResponse(response);
}

Response HttpGet(char *url){
    return http_MakeRequest(url,"GET");
}
 
Response http_ProcessResponse(char *response){
    Response res;
    res.resp_len = strlen(response);
    res.content = response;
    if(response != NULL){
        res.respc = 200;
    }
    res.content_type = "html";
    // the response must be proecessed by reading the headers and readiing the actuall http response code and the actual content not including the http headers and analysing each of the headers forexample cookies
}

Response HttpPost(){
}

#endif