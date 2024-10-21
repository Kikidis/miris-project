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
    if(hashtable->getGraphNode(id) == NULL){
        GraphNodeListNode* gnln = graphlist->insertNode(id);          // εισαγει εναν νεο κομβο στον  γραφο
        hashtable->insertNodeaddr(id, gnln);
    }
    else
        cout << "ID already existed "<< id << endl;
}