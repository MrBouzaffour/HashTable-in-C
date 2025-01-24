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


typedef struct 
{
	int value;
}INT;
typedef struct 
{
	char *value;
}STR;
typedef union 
{
	INT integer;
	STR string;
}Container;

typedef struct 
{
	Container container;
	void (*hash) (Container *container, void value)
};


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
	/*
	 * Hash an int
	 */
	const double A = 0.6180339887; // fractional part of the golden ratio
	return (int)(size * (key * A - (int)(key * A)));
}


unsigned int hash_STRING(char *key, int size)
{
	/*
	 * Hash a string
	 */
	unsigned long hash = 0;
	while(*key)
	{
		hash = (hash + *key) % size;
		key ++;
	}
	return (unsigned int) hash;
}

HashTable *create (int size)
{
	/*
	* This function takes a size and returns a new empty hashtable
	*/
	HashTable *ptr = (HashTable*) malloc(size * sizeof(HashTable));

	assert(ptr != NULL);

	ptr->size = size;
	ptr->buckets = (Enteries*) calloc(size, sizeof(Enteries));	
	assert(ptr->buckets != NULL);
	return ptr;
}



void insert(HashTable *table, void *key, void *value, KeyType keyType)
{
	/*
	 * Insert a new value to the haveTable
	 */
	void *newkey = key;
	unsigned int index;
	if (keyType == INT) {
		index = hash_INT(*(int*)newkey, table->size);
		printf("Int inserted to index : %d\n",index);
	} else if (keyType == STR) {
		index = hash_STRING((char*)newkey, table->size);
		printf("Str inserted to index : %d\n",index);

	}else {
		fprintf(stderr, "Unknown key type.\n");
		return;
	}

	Enteries entry;
	entry.type = keyType;
	entry.key = key;
	entry.value = value;

	table->buckets[index] = entry;
}

void search(HashTable *table, void *key, KeyType keyType) {
	/*
	 * Search in the hashTable based on key and keytype
	 */   
	unsigned int index;

	if (keyType == INT) {
        	index = hash_INT(*(int*)key, table->size);
    	} else if (keyType == STR) {
        	index = hash_STRING((char*)key, table->size);
    	} else {
        	fprintf(stderr, "Unknown key type.\n");
        	return;
    	}

	if (table->buckets[index].key != NULL) {
		if (table->buckets[index].type == keyType) {
			if ((keyType == INT && *(int*)table->buckets[index].key == *(int*)key) ||
					(keyType == STR && strcmp((char*)table->buckets[index].key, (char*)key) == 0)) {
                		printf("Value found: %s\n", (char*)table->buckets[index].value);
                		return;
            		}
        	}
    	}

    	printf("Key not found.\n");
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
	/*
	 * Printing the hole hashTable
	 */
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


int main() {
	printf ("\nCreating hash Table in progress ... \n");
    	int size = 10;
	HashTable *hashtable = create(size);
	printf("HashTable created with size = %d\n\n",size);

    
	int intKey = 2;
	char *strKey = "hello";
	char *value = "world";


	printf("Testing Insertion : \n\n");
	insert(hashtable, strKey, value, STR);
	insert(hashtable, &intKey, value, INT);

	printf("\nTesting PtrintTable : \n\n");
	printTable(hashtable);


	printf("\nTesting Searching : \n\n");
	search(hashtable, &intKey, INT);  // Search with integer key
	search(hashtable, strKey, STR);   // Search with string key

	free_table(hashtable);

	printf("\nTesting FreeTable : \n\n");
	printTable(hashtable);


	printf("\nEnd of Testing.\n");
	return 0;
}
