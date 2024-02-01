#include"dict.h"
#ifndef RESPONSE
#define RESPONSE

// http response codes
#define respc_CONTINUE 100
#define respc_SWITCHING_PROTOCOLS 101
#define respc_PROCESSING 102
#define respc_EARLY_HINTS 103
#define respc_OK 200
#define respc_CREATED 201
#define respc_ACCEPTED 202
#define respc_NO_CONTENT 204
#define respc_RESET_CONTENT 205
#define respc_PARTIAL_CONTENT 206
#define respc_MULTIPLE_CHOICES 300
#define respc_MOVED_PERMANENTLY 301;
#define respc_FOUND_MOVED_TEMPORARILY 302;
#define respc_SEE_OTHER 303;
#define respc_NOT_MODIFIED 304;
#define respc_REDIRECT 307;
#define respc_PERMANENT_REDIRECT 308;
#define respc_BAD_REQUEST 400;
#define respc_UNAUTHORIZED 401;
#define respc_FORBIDDEN 403;
#define respc_NOT_FOUND 404;
#define respc_NOT_ALLOWED 405;
#define respc_NOT_ACCEPTABLE 406;
#define respc_PROXY_AUTHENTICATION_REQUIRED 407;
#define respc_REQUEST TIMEOUT 408;
#define respc_CONFLICT 409;
#define respc_GONE 410;
#define respc_LENGTH_REQUIRED 411;
#define respc_PRECONDITION_FAILED 412;
#define respc_PAYLOAD_TOO_LARGE 413;
#define respc_URI_TOO_LONG 414;
#define respc_MEDIA TYPE 415;
#define respc_RANGE_NOT_SATISFIABLE 416;
#define respc_EXPECTATION_FAILED 417;
#define respc_IM_A_TEAPOT 418;
#define resp_MISDIRECTED_REQUEST 421;
#define respc_UNPROCESSABLE_ENTITY 422;
#define respc_LOCKED 423;
#define respc_FAILED_DEPENDENCY 424;
#define respc_UPGRADE_REQUIRED 426;
#define respc_PRECONDITION_REQUIRED 428;
#define respc_TOO_MANY_REQUESTS 429;
#define respc_REQUEST_HEADER_FIELDS_TOO_LARGE 431;
#define respc_UNAVAILABLE_FOR_LEGAL_REASONS 451;
#define respc_INTERNAL_SERVER_ERROR 500;
#define respc_NOT_IMPLEMENTED 501;
#define respc_BAD_GATEWAY 502;
#define respc_SERVICE_UNAVAILABLE 503;
#define respc_GATEWAY_TIMEOUT 504;
#define respc_HTTP_VERSION_NOT_SUPPORTED 505;
#define respc_VARIANT_ALSO_NEGOTIATES 506;
#define respc_INSUFFICIENT_STORAGE 507;
#define respc_LOOP_DETECTED 508;
#define respc_NOT_EXTENDED 510;
#define respc_NETWORK_AUTHENTICATION_REQUIRED 511;

int resp_ContentLen(char *content);

char *resp_BytesToString(long *bytes_buffer);

typedef struct{
    int respc; // response code
    char *content;
    int resp_len;
    char *content_type;
}Response;

#endif
