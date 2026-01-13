#include <stdio.h>

void dump(const char*);

/* Aliases to the same storage */
#define alias_init(var) \
static int local_alias  __attribute__((alias(#var))); \
extern int global_alias __attribute__((alias(#var))); \
extern int weak_alias   __attribute__((alias(#var), weak));

static int real = 5;

alias_init(real);	// alias must be created outside the main function

int weak_alias = 999;	// strong definition but override fails for same TU, alias binding takes precedence

int main()
{
    dump("before");
    global_alias = 42;     // modifies the SAME storage
    dump("after global");
	
    /* *
     * This does NOT override weak_alias
     * local static - completly independent storage
     * */

    static int weak_alias = 7;
    printf("block weak_alias = %d\n", weak_alias);

    dump("after block static");

    return 0;

}


void dump(const char *tag)
{
    printf("%s: real=%d local=%d global=%d weak=%d\n",
           tag, real, local_alias, global_alias, weak_alias);
}
