#pragma once

#include <iostream>
#include <string.h>
#include <string>
#include <cstring>
#include "GraphComponents.h"


using namespace std;

struct Graph{
    GraphNodeList* graphlist;
    HashTable* hashtable;

    Graph(int size);

    void insertNode(char* id);

    ~Graph();
};


