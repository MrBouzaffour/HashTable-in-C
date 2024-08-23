#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

<<<<<<< HEAD
=======
#define CHECK_TYPE(var) _Generic((var), \
    int: INT, \
    char*: STR, \
    default: -1)
>>>>>>> dev

#define UNEMPLEMENTED \
	do {	\
		fprintf(stderr,"%s:%d: TODO: %s is not implemented yet.\n",\
				__FILE__,__LINE__,__func__);\
		abort();\
	}while(0)
<<<<<<< HEAD
=======


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
	Enteries *buckets;
}HashTable;


>>>>>>> dev
void hash()
{
	UNEMPLEMENTED;
}
void resize()
{
	UNEMPLEMENTED;
}
<<<<<<< HEAD
void create ()
{
	UNEMPLEMENTED;
}
void insert()
{
	UNEMPLEMENTED;
=======
HashTable *create (int size)
{
	HashTable *ptr = (HashTable*) malloc(size * sizeof(HashTable));
	assert(ptr != NULL);


	ptr->size = size;
	ptr->buckets = (Enteries*) malloc(size * sizeof(Enteries));
	assert(ptr->buckets != NULL);

	return ptr;
}
void insert()
{
	
>>>>>>> dev
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
<<<<<<< HEAD
	printf("hello");
=======
	int size = 10;
	HashTable *hashtable = create(size);
>>>>>>> dev
}
