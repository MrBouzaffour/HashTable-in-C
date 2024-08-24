#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

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
	Enteries *buckets;
}HashTable;

unsigned int hash_INT(int key, int size)
{
	UNEMPLEMENTED;
}
unsigned int hashString(char *key, int size)
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


	ptr->size = size;
	ptr->buckets = (Enteries*) malloc(size * sizeof(Enteries));
	assert(ptr->buckets != NULL);

	return ptr;
}
void insert(HashTable *table, void *key, void *value)
{
	KeyType keyType = CHECK_TYPE(*(int*)key);
	int index;
	
	if (keyType == INT) {
		index = *(int *)key;
	} 
	
	else if (keyType == STR) {
		index = strlen((char*)key);
	}
	Enteries entry;
	entry.type = keyType;
	entry.key = key;
	entry.value = value;

	table->buckets[index] = entry;
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
	
	insert(hashtable, &intKey, value);
	insert(hashtable, strKey, value);
	
	printTable(hashtable);
	free_table(hashtable);
	
	return 0;
}
