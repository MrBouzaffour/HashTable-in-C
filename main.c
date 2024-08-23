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
void create (int size)
{
	// allocate memory of an empty array of a size 'siz'
	void *ptr = (HashTable*) malloc(size * sizeof(HashTable));
	if (ptr == NULL)
	{
		printf("Memory is not allocated");
		exit(0);
	}
	else
	{
		printf("The creating of the hashtable is completed");
	}
	
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
	int size = 10;
	create(size);
	printf("hello");
}
