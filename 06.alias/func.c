#include <stdio.h>

#define alias_init(addFunc) \
static int add(int a,int b) __attribute__((alias(#addFunc))) 
	
static int myFunc(int a, int b)
{
	printf("%s : %d + %d =\t %d\n",__func__, a,b,a+b );
	return 0;
}

alias_init(myFunc);	// alias must be created outside the main function

int main()
{
	myFunc(3,6);
	add(3,5);
	return 0;
}
