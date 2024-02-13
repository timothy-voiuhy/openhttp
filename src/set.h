#ifndef __SET
#define __SET

typedef struct {

int n_;
char **setcomponents;

}set;

set CreateSet();

void set_AddValue(set *s_);

void set_RemoveValue(set *s_);

void set_Delete(set *s_);

void set_Clear(set *s_);

#endif