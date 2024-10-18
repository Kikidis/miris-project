#include "GraphComponents.h"

Edge::~Edge(){
    delete date;
}

EdgeListNode::~EdgeListNode(){
    delete edge;
}

EdgeList::~EdgeList(){
    EdgeListNode* current = head;
    while (current != NULL) {
        EdgeListNode* temp = current;
        current = current->next;
        delete temp;
    }

}

bool EdgeList::isEmpty(){
    return count == 0;
    //ελέγχω αν η λίστα είναι άδεια
}


void EdgeList::insertNode(Edge &edge) {
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
void EdgeList::printList(){
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


// Εισαγωγή εισερχόμενης ακμής στον κόμβο
void GraphNode::insertInEdge(Edge &edge){
    in.insertNode(edge);
}


// Εισαγωγή εξερχόμενης ακμής στον κόμβο
void GraphNode::insertOutEdge(Edge &edge){
    out.insertNode(edge);
}

// Ένας κόμβος της λίστας GraphNodeList
GraphNodeListNode::GraphNodeListNode(char* id){
    graphnode = new GraphNode(id);
    next = NULL;
    prev = NULL;
}

GraphNodeListNode::~GraphNodeListNode(){
    delete graphnode;
}

GraphNodeList::~GraphNodeList(){
    GraphNodeListNode* current = head;
    while (current != NULL) {
        GraphNodeListNode* temp = current;
        current = current->next;
        delete temp;
    }
}
    

// Έλεγχος αν η λίστα είναι άδεια
bool GraphNodeList::isEmpty(){
    return count == 0;
    //ελέγχω αν η λίστα είναι άδεια
}

// Εισαγωγή νέου κόμβου (id) στη λίστα
GraphNodeListNode* GraphNodeList::insertNode(char* id){
    GraphNodeListNode* newNode = new GraphNodeListNode(id);

    if (isEmpty()) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    count++;
    return newNode;         // Επιστρέφει την διεύθυνση του νέου κόμβου
}


// Εκτύπωση της λίστας των κόμβων του γράφου
void GraphNodeList::printList(){
    GraphNodeListNode* current = head;
    while (current != NULL) {
        // id: "id"

        cout << "ID : " << current->graphnode->id << endl;
        current = current->next;
    }
}    


HashList::~HashList(){
    HashListNode* current = head;
    while (current != NULL) {
        HashListNode* temp = current;
        current = current->next;
        delete temp;
    }
}

bool HashList::isEmpty(){
    return count == 0;
}

void HashList::insertNode(GraphNodeListNode* gnlnode){
    HashListNode* newNode = new HashListNode(gnlnode);

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


HashTable::HashTable(int size){
    this->size = size;                          // Ορίζω το μέγεθος του πίνακα
    this->hashtable = new HashList[size];       // Δημιουργούμε τον πίνακα με τις λίστες
}

HashTable::~HashTable(){
    delete [] hashtable;
}

void HashTable::insertNodeaddr(char* id, GraphNodeListNode* gnln){
    int position  = universalHashingString(id);
    hashtable[position].insertNode(gnln);
}

int HashTable::universalHashingString(char *str)
{
	int h =0;
	// parameter a
	int a =6;
	// 1000th prime number
	int p = 7919;
	// universal hashing for strings
	int i =0;
	while ( str[i] != '\0')
	{
		h = (h*a + str[i]) % p;
		i++;
	}
	return (h % size)+1;        // Επιστρεύει την θέση που θα τοποθετιθεί το GraphNodeListNode
}
