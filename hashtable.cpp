#include <iostream>
#include <cstdlib>

using namespace std;
const int SIZE = 128;

class HashElement
{
    public:
        int key;
        int value;
        HashElement(int key, int value)
        {
            this->key = key;
            this->value = value;
        }
};

class HashTable
{
    HashElement **table;
    public:
        HashTable();
        ~HashTable();
        int hash(int key);
        void insert(int key, int value);
        int search(int key);
        void remove(int key);
};

HashTable :: HashTable()
{
    this->table = new HashElement* [SIZE];
    for(int i=0; i<SIZE; i++) table[i] = NULL;
}

HashTable :: ~HashTable()
{
    for(int i=0; i<SIZE; ++i)
    {
        if(table[i] != NULL) delete table[i];
        //delete[] table;
    }
}

int HashTable :: hash(int key){ return key%SIZE; }

void HashTable::insert(int key, int value)
{
    int hashedkey = hash(key);
    while(table[hashedkey]!=NULL && table[hashedkey]->key != key)
    {
        /*checking if the table has any HashElement at hashedkey index
         and if the key value of that value matches*/
        hashedkey = hash(hashedkey + 1); 
        //if it has the element, but key value doesn't match
    }
    if(table[hashedkey]!=NULL) //if hash table is full
        delete table[hashedkey];
    table[hashedkey] = new HashElement(key, value);
}

void HashTable::remove(int key)
{
    int hashedkey = hash(key);
    while(table[hashedkey]!=NULL)
    {
        if(table[hashedkey]->key==key) break;
        hashedkey = hash(hashedkey+1);
    }

    if(table[hashedkey]==NULL)
    {
        cout << "No element at the key" << endl;
        return;
    }
    else table[hashedkey]=NULL;
}

int HashTable::search(int key)
{
    int hashedkey = hash(key);
    while(table[hashedkey]!=NULL && table[hashedkey]->key!=key)
    {
        hashedkey = hash(hashedkey+1);
    }

    if(table[hashedkey]==NULL)
    {
        cout << "Nothing found for key "<< key << endl;
        return -1; //Not found
    }
    return table[hashedkey]->value;
}

int main()
{
    HashTable h;
    h.insert(3,6);
    cout << h.search(3) << endl;
    h.remove(3);
    cout << h.search(3) << endl;
    h.insert(2048,10);
    cout << h.search(2048) << endl;
    
}