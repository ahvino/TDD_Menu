#include <list>
#include <iostream>
#include "HashTable.h"
#include <stdlib.h>
#include <cstdlib>

HashTable::HashTable(int numbernumKeys)
{
    numKeys = numbernumKeys;
    hasht = new std::list<std::string>[numKeys];
}

void HashTable::Insert(std::string data)
{
    int dataKey = HashKey(data);
    hasht[dataKey].push_back(data);
}

unsigned long HashTable::HashFunction(std::string data)
{
    //large 4 digit prime number
    int hash = 9643;
    int c;

    for (char _char : data)
    {
        c = static_cast<int>(_char);
        hash = ((hash << 3) + hash) + c;
    }
    return abs(hash);

}

int HashTable::HashKey(std::string data)
{
    int hashedKey = HashFunction(data);

    return hashedKey % numKeys;
}

void HashTable::Display()
{
    for (int i = 0; i < numKeys; i++)
    {
        printf("Hash Tables at index '%i'\n", i);
        for (auto cStr : hasht[i])
        {
            printf("        <-- '%s' --> ", cStr.c_str());

        }
        printf("\n");
    }
}

void HashTable::Delete(std::string data)
{
    bool valueFound = false;

    int dataKey = HashKey(data);
    std::list<std::string> ::iterator i;
    i = hasht[dataKey].begin();
    while (!valueFound && i != hasht[dataKey].end())
    {
        if (*i == data)
        {
            valueFound = true;
        }
        else
        {
            i++;
        }
    }
    if (i != hasht[dataKey].end())
    {
        hasht[dataKey].erase(i);
    }
}


bool HashTable::FindValue(std::string data)
{
    bool valueFound = false;

    int dataKey = HashKey(data);
    std::list<std::string> ::iterator i;
    i = hasht[dataKey].begin();
    while (!valueFound && i != hasht[dataKey].end())
    {
        if (*i == data)
        {
            valueFound = true;
        }
        else
        {
            i++;
        }
    }
    if (i != hasht[dataKey].end())
    {
        return true;
    }
    else
    {
        return false;
    }
}
