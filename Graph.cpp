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
    // else
    //     cout << "ID already existed "<< id << endl;
}


void Graph::insertEdge(char* to, char* from, double sum, int year, int month, int day){
    GraphNodeListNode* toNode = hashtable->getGraphNode(to);        // ο κομβος της λιστας του γραφου που περιεχει εναν κομβο του γραφου στον οποιο ερχεται η ακμη
    GraphNodeListNode* fromNode = hashtable->getGraphNode(from);    // ο κομβος της λιστας του γραφου που περιεχει εναν κομβο του γραφου στον οποιο φευγει η ακμη
    Date date(day, month, year);
    Edge inEdge(sum, date, fromNode->graphnode);
    Edge outEdge(sum, date, toNode->graphnode);
    toNode->graphnode->in.insertNode(inEdge);                        // Στον graphnode που καταληγει η αμκη την εισαγω στην λιστα ακμην in
    fromNode->graphnode->out.insertNode(outEdge);                   // Στον graphnode που καταληγει η αμκη την εισαγω στην λιστα ακμην out

}

void Graph::printAllOutEdges(char* id){
    GraphNodeListNode* node = hashtable->getGraphNode(id);
    if(node == NULL){
        return;
    }
    GraphNode* gn = node->graphnode;                    //ανακτω τον graphnode Που μεσα του εχει τα oyt edges
    gn->out.printListOut(id);
}

void Graph::printAllInEdges(char* id){
    GraphNodeListNode* node = hashtable->getGraphNode(id);          //βρισκω τον κομβω
    if(node == NULL){                                       //ελεγχος που δεν εχω καμια συναλαγη
        return;
    }
    GraphNode* gn = node ->graphnode;               //ανακτω τον graphnode Που μεσα του εχει τα in edges
    gn->in.printListIn(id);                             // τα εκτυπωνω
}

// Διαγραφει απο ολους τους κομβους του γραφου τις ακμες που ερχονται απο τον κομβο προς διαγραφη
// και τις ακμες που στελνουμε στον κομβο προς διαγραφη
// και στο τελος τον κομβο
void Graph::deleteGraphNode(char* id){
    GraphNodeListNode* deletednode = hashtable->getGraphNode(id);   // ανακτουμε τον κομβο προς διαγραφη 
    GraphNode* deletedgn = deletednode->graphnode;                  // ο κομβος του γραφου του οποιου η παρουσια στις ακμες των αλλων κομβων θελουμε να διαγραψουμε
    EdgeList &in = deletedgn->in;                                   // ειναι οι εισερχομενες ακμες του συγκεκριμενου κομβου

    EdgeListNode* current = in.head;                            
    while(current){
        current->edge->node->out.removeNodes(deletedgn);    // Διαγραφω απο τις out λιστες ακμων των αλλων κομβων την παρουσια του deletedgn
        current = current->next;
    }

    EdgeList &out = deletedgn->out;                             // ειναι οι εξερχομενες ακμες του συγκεκριμενου κομβου
    current = out.head;
    while(current){
        current->edge->node->in.removeNodes(deletedgn);      // Διαγραφω απο τις in λιστες ακμων των αλλων κομβων την παρουσια του deletedgn
        current = current->next;
    }

    graphlist->deleteNode(deletednode);                     //διαγραφω εν τελη και τον ιδιο τον κομβο 
    
}