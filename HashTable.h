#pragma once
#include <string>
#include <iostream>
#include <list>
#include <string>

class HashTable
{
    private:
        int numKeys;
        std::list<std::string>* hasht;

    public:
        HashTable(int numbernumKeys);
        void Insert(std::string data);
        int HashKey(std::string data);
        bool FindValue(std::string data);
        void Display();
        void Delete(std::string data);
        unsigned long HashFunction(std::string data);
};