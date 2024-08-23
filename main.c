#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define UNEMPLEMENTED \
	do {	\
		fprintf(stderr,"%s:%d: TODO: %s is not implemented yet.\n",\
				__FILE__,__LINE__,__func__);\
		abort();\
	}while(0)


typedef enum
{
	INT,
	STR
} KeyType;

typedef struct
{
	KeyType type;
	void *key;
	void *value;
}HachEntry;

typedef struct
{
	int size;

}


HashTable hash()
 /*
 * Compute an index in the hash table array from a given key
 * 	@params : 
 * 	@returns :  
 */
{
	UNEMPLEMENTED;
}
void resize()
{
	UNEMPLEMENTED;
}
void create ()
{
	UNEMPLEMENTED;
}
void insert()
{
	UNEMPLEMENTED;
}

void search()
{
	UNEMPLEMENTED;
}

void delete ()
{	
	UNEMPLEMENTED;
}

void free_table ()
{
	UNEMPLEMENTED;
}



int main()
{
	printf("hello");
}
