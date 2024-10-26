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

    void insertEdge(char* to, char* from, double sum, int year, int month, int day);

    void deleteGraphNode(char* id);

    void printAllOutEdges(char* id);
    void printAllInEdges(char* id);

    ~Graph();
};


