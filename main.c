#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>


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
	Enteries *buckets;
}HashTable;


void resize()
{
	UNEMPLEMENTED;
}

unsigned int hash_INT (int key, int size)
{
	return key%size;
}

unsigned int hash_STRING(char *key, int size)
{
	unsigned long hash = 0;
	while(*key)
	{
		hash = (hash + *key) %size;
		key ++;
	}
	return (unsigned int) hash;
}

HashTable *create (int size)
{
	/*
	This function takes a size and returns an empty hashtable
	*/
	HashTable *ptr = (HashTable*) malloc(size * sizeof(HashTable));

	assert(ptr != NULL);


	ptr->size = size;
	ptr->buckets = (Enteries*) malloc(size * sizeof(Enteries));

	assert(ptr->buckets != NULL);
	printf("Hash Table created.\n");
	return ptr;
}



void insert(HashTable *table, void *key, void *value, KeyType keyType)
{
	unsigned int index;
	if (keyType == INT) {
		index = hash_INT(*(int*)key, table->size);
	} else if (keyType == STR) {
		index = hash_STRING((char*)key, table->size);
	}else {
		fprintf(stderr, "Unknown key type.\n");
		return;
	}
	Enteries entry;
	entry.type = keyType;
	entry.key = key;
	entry.value = value;

	table->buckets[index] = entry;
	printf("Inserted\n");
}

void search()
{
	UNEMPLEMENTED;
}

void delete ()
{	
	UNEMPLEMENTED;
}

void free_table (HashTable *table)
{
	free(table->buckets);
	free(table);
}

void printTable(HashTable *table)
{
	for (int i = 0; i < table->size; i++) {
		if (table->buckets[i].key != NULL) {
			printf("Entry %d: ", i);
			switch (table->buckets[i].type) {
				case INT:
					printf("Key (int) = %d, Value = %s\n", *(int*)table->buckets[i].key, (char*)table->buckets[i].value);
					break;
				case STR:
					printf("Key (str) = %s, Value = %s\n", (char*)table->buckets[i].key, (char*)table->buckets[i].value);
					break;
				default:
					printf("Unknown key type.\n");
			}
		}
	}
}


int main()
{
	int size = 10;
	HashTable *hashtable = create(size);
	
	int intKey = 2;
	char *strKey = "hello";
	char *value = "world";
	insert(hashtable, &intKey, value, INT);
	insert(hashtable, strKey, value, STR);
	
	//printTable(hashtable);
	//free_table(hashtable);
	

	printf("Program ended");
	return 0;
}
