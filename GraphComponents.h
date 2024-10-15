#pragma once

#include <iostream>


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

Date::~Date() {
    // No dynamic memory to delete
}

struct Edge{
    double amount;
    Date* date;
    GraphNode* node;
    
    Edge(double amount, Date &date, GraphNode* node){
        this->amount = amount;
        this->date = new Date(date.day, date.month, date.year);
        this->node = node;
    }
    ~Edge(){
        delete date;
    }

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

    ~EdgeListNode(){
        delete edge;
    }

};

struct EdgeList{
    int count;
    EdgeListNode* head;
    EdgeListNode* tail;

    EdgeList(){
        this->count = 0;
        this->head = NULL;
        this->tail = NULL;
    }

    ~EdgeList(){
    EdgeListNode* current = head;
        while (current != NULL) {
            EdgeListNode* temp = current;
            current = current->next;
            delete temp;
        }
    }

    // Έλεγχος αν η λίστα είναι άδεια
    bool isEmpty();


    // Εισαγωγή νέου κόμβου (Edge) στη λίστα
    void insertNode(Edge &edge) {
        EdgeListNode* newNode = new EdgeListNode(edge);

        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        count++;
    }

    // Εκτύπωση της λίστας ακμών
    void printList(){
            EdgeListNode* current = head;
            while (current != NULL) {
                // Amount: "amoount"
                // Date: "day/month/year"
                cout << "Amount: " << current->edge->amount
                    << " Date: " << current->edge->date->day << "/"
                    << current->edge->date->month << "/"
                    << current->edge->date->year << endl;
                current = current->next;
            }
    }
};