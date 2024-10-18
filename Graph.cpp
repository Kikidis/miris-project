#include "Graph.h"



Graph::Graph(int size){
    this->graphlist = new GraphNodeList();
    this->hashtable = new HashTable(size);
}

Graph::~Graph(){
    delete graphlist;
    delete hashtable;
}

void Graph::insertNode(char* id){
    GraphNodeListNode* gnln = graphlist->insertNode(id);
}