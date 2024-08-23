#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define CHECK_TYPE(var) _Generic((var), \
    int: INT, \
    char*: STR, \
    default: -1)

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
}Enteries;

typedef struct
{
	int size;
	Enteries buckets;
}HashTable;


void hash()
{
	UNEMPLEMENTED;
}
void resize()
{
	UNEMPLEMENTED;
}
HashTable *create (int size)
{
	HashTable *ptr = (HashTable*) malloc(size * sizeof(HashTable));
	assert(ptr != NULL);



	return ptr;
}
void insert()
{
	
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
	int size = 10;
	HashTable *hashtable = create(size);
}
