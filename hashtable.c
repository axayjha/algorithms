/*Hash table with string as key and int as value*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 128

struct hashElement
{   
    char *key;
    int  value;
};

struct hashTable
{
    struct hashElement **table;
};

typedef struct hashElement HashElement;
typedef struct hashTable HashTable;

int hash(char *);
HashTable *newHashTable();
HashElement *newHashElement(char *key, int value);
void insert(HashTable *table, char *key, int value);
void delete(HashTable *table, char *key);
int search(HashTable *table, char *key);

int main()
{
    
    HashTable *h = newHashTable();
    insert(h, "3", 6);
    printf("%d\n", search(h, "3"));
    delete(h, "3");
    printf("%d\n", search(h, "3"));
    insert(h, "2048", 10);
    printf("%d\n", search(h, "2048"));


}

int hash(char *str)
{
    int sum=0; 
    for(int i=0, n=strlen(str); i<n; i++)
    {
        sum += (int)str[i];
    }
    return sum%SIZE;
}

HashTable *newHashTable()
{
    HashTable *t = (HashTable *)malloc(sizeof(HashTable));
    //t->table = HashElement **
    t->table = (HashElement **)malloc(SIZE*sizeof(HashElement *));
    for(int i=0; i<SIZE; i++) t->table[i]=NULL;
    return t;
}

HashElement *newHashElement(char *key, int value)
{
    HashElement *newEntry = (HashElement *)malloc(sizeof(HashElement));
    newEntry->key= (char *)malloc(20*sizeof(char));
    strcpy(newEntry->key, key);
    newEntry->value = value;
    return newEntry;
}

void insert(HashTable *t, char *key, int value)
{
    int hashedkey = hash(key);
    while(t->table[hashedkey]!=NULL && (strcmp(t->table[hashedkey]->key, key) != 0))
    {
        hashedkey = (hashedkey+1)%SIZE;
    }
    
    t->table[hashedkey] = (HashElement *)malloc(sizeof(HashElement));
    t->table[hashedkey] = newHashElement(key, value);
}   


void delete(HashTable *t, char *key)
{
    int hashedkey = hash(key);
    while(t->table[hashedkey]!=NULL)
    {
        if(strcmp(t->table[hashedkey]->key, key) == 0) break;
        hashedkey = (hashedkey+1)%SIZE;
    }
    if(t->table[hashedkey]==NULL)
    {
        printf("Nothing found for key %s\n", key);
        return;
    }
    else t->table[hashedkey]=NULL;
}  

int search(HashTable *t, char *key)
{
    int hashedkey = hash(key);
    while(t->table[hashedkey]!=NULL && (strcmp(t->table[hashedkey]->key, key) != 0))
    {
        hashedkey = (hashedkey+1)%SIZE;
    }

    if(t->table[hashedkey]==NULL)
    {
        printf("Nothing found for key %s\n", key);
        return -1;
    }
    
    return t->table[hashedkey]->value;
}