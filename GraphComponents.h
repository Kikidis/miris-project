#pragma once

#include <iostream>
#include <string.h>
#include <string>
#include <cstring>


using namespace std;

struct GraphNode; // Forward declaration 

struct Date{
    int day;
    int month;
    int year;
    
    Date(int day, int month, int year){
        this->day = day;
        this->month = month;
        this->year = year;
    }
};


struct Edge{
    double amount;
    Date* date;
    GraphNode* node;
    
    Edge(double amount, Date &date, GraphNode* node){
        this->amount = amount;
        this->date = new Date(date.day, date.month, date.year);
        this->node = node;
    }
    ~Edge();

};

struct EdgeListNode{
    Edge* edge;
    EdgeListNode* next;
    EdgeListNode* prev;

    EdgeListNode(Edge &edge){
        this->edge = new Edge(edge.amount, *(edge.date), edge.node);
        this->next = NULL;
        this->prev = NULL;
    }

    ~EdgeListNode();

};

struct EdgeList{
    int count;
    EdgeListNode* head;
    EdgeListNode* tail;

    EdgeList(){             // default constructor
        this->count = 0;
        this->head = NULL;
        this->tail = NULL;
    }

    ~EdgeList();
    

    // Έλεγχος αν η λίστα είναι άδεια
    bool isEmpty();


    // Εισαγωγή νέου κόμβου (Edge) στη λίστα
    void insertNode(Edge &edge);

    EdgeListNode* removeNode(EdgeListNode*);

    void removeNodes(GraphNode*);       // διαγραφει τους κομβους που περιεχουν ακμες με συγκεκριμενο GraphNode*

    // Εκτύπωση της λίστας ακμών
    void printList();       // Δήλωση της printList 
};


struct GraphNode{
    char id[100];
    EdgeList in;
    EdgeList out;

    GraphNode(char* id){
        strcpy(this->id, id);  // copying argument id to class member id
    }

    void insertInEdge(Edge &edge);
    void insertOutEdge(Edge &edge);
};


struct GraphNodeListNode{
    GraphNode* graphnode;
    GraphNodeListNode* next;
    GraphNodeListNode* prev;

    GraphNodeListNode(char* id);

    ~GraphNodeListNode();
};


struct GraphNodeList{
    int count;
    GraphNodeListNode* head;
    GraphNodeListNode* tail;

    GraphNodeList(){             // default constructor
        this->count = 0;
        this->head = NULL;
        this->tail = NULL;
    }

    ~GraphNodeList();
    

    // Έλεγχος αν η λίστα είναι άδεια
    bool isEmpty();

    // Εισαγωγή νέου κόμβου (Edge) στη λίστα
    GraphNodeListNode* insertNode(char* id);

    // διαγραφει τον κομβο που του δινουμε σαν ορισμα
    void deleteNode(GraphNodeListNode* node);

    // Εκτύπωση της λίστας ακμών
    void printList();       // Δήλωση της printList 
};


struct HashListNode{                // Ο κόμβος λίστας στον πίνακα κατακερματισμού
    GraphNodeListNode* gnlnode;
    HashListNode* prev;
    HashListNode* next;

    HashListNode(GraphNodeListNode* gnlnode){
        this->gnlnode = gnlnode;
        this->next = NULL;
        this->prev = NULL;
    }
};

struct HashList{                // Οι λίστες που υπάρχουν σε κάθε θέση του πίνακα κατακερματισμού
    int count;
    HashListNode* head;
    HashListNode* tail;

    HashList(){
        this->count = 0;
        this->head = NULL;
        this->tail = NULL; 
    }

    bool isEmpty();

    void insertNode(GraphNodeListNode* gnlnode);
    
    GraphNodeListNode* getGraphNode(char* id);

    ~HashList();

};

struct  HashTable{
    int size;
    HashList* hashtable;

    HashTable(int size);

    void insertNodeaddr(char* id, GraphNodeListNode* gnln);

    int universalHashingString(char *str);

    GraphNodeListNode* getGraphNode(char* id);

    ~HashTable();
};
