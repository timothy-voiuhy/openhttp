#include<sys/socket.h>

#include "dict.h"
#include "response.h"

#ifndef _HTTP
#define _HTTP

#define SCHEME_HTTP "http"
#define SCHEME_HTTPS "https"

#define NETLOC_PATTERN "\\/\\/.*\\/"
#define HTTPS_REGEX "https\\:\\/\\/.*\\/.*"
#define HTTP_REGEX "http\\:\\/\\/.*\\/.*"

#define h_ACCEPT "Accept"
#define h_ACCEPT_CHARSET "Accept-Charset"
#define h_ACCEPT_ENCODING "Accept-Encoding"
#define h_ACCEPT_LANGUAGE "Accept-Language"
#define h_AUTHORIZATION  "Authorization"
#define h_CACHE_CONTROL  "Cache-Control"
#define h_CONNECTION "Connection"
#define h_CONTENT_ENCODING  "Content-Encoding"
#define h_CONTENT_LENGTH "Content-Length"
#define h_CONTENT_RANGE "Content-Range"
#define h_CONTENT_TYPE "Content-Type"
#define h_COOKIE  "Cookie"
#define h_EXPIRES "Expires"
#define h_HOST "Host"
#define h_IF_MODIFIED_SINCE "If-Modified-Since"
#define h_IF_NONE_MATCH "If-None-Match"
#define h_LAST_MODIFIED "Last-Modified"
#define h_LOCATION "Location"
#define h_PRAGMA "Pragma"
#define h_PROXY_AUTHORIZATION "Proxy-Authorization"
#define h_PROXY_CONNECTION "Proxy-Connection"
#define h_RANGE "Range"
#define h_REFERER "Referer"
#define h_REFRESH  "Refresh"  //Reference: http://stackoverflow.com/a/283794
#define h_SERVER  "Server"
#define h_SET_COOKIE  "Set-Cookie"
#define h_TRANSFER_ENCODING "Transfer-Encoding"
#define h_URI "URI"
#define h_USER_AGENT "User-Agent"
#define h_VIA  "Via"
#define h_X_POWERED_BY "X-Powered-By"
#define h_X_DATA_ORIGIN "X-Data-Origin"

typedef struct{
    char *header_key;
    char *header_value;
}http_header;

typedef struct{
    dict *http_headers;
    char **keys;
    char **values;}http_headers;

typedef struct{
    char *scheme;
    in_addr_t netloc;
    char *path;
    dict *url_paramaters;
}URL;

// decompiles the url provided by the user to the url structure
URL DecompileUrl(char *url);

int  IsValidUrl(char *url);

/*example of the header data*/
char *http_packet = "GET /index.html HTTT 1.1\r\nHOST:www.example.com\r\nset-cookie:sfksfk\r\n\r\ndata";

char *http_MakeHttpPacket(URL url, char *method);

char *http_GetDefaultHeaders(URL url);

// get method
// get http version
// get the host 
// other headers 
// concatenate all this in a single string 
// send the data

Response HttpGet();

Response HttpPost();

//check if the url has scheme HTTPS
int MatchHttps(char *url);

char *MatchReturnNetloc(char *url);

Response http_ProcessResponse(char *response);

#endif