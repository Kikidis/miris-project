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

// Διαγραφει απο την λιστα τον κομβο που παιρνει ως ορισμα και επιστρεφει τον επομενο του
EdgeListNode* EdgeList::removeNode(EdgeListNode* node){
    if(isEmpty()){
        return NULL;
    }
    if (count == 1){            // Ο Node ειναι head και tail
        head = tail = NULL;
        count = 0;
        delete node;
        return NULL;
    }
    else if(node == head){        // ο Node ειναι ο πρωτος κομβος
        head = head->next;
        count--;
        node->next->prev = NULL;    // Το prev του επομενου κομβου του node να ειναι NULL αφου θα ειναι ο πρωτος κομβος
        delete node;
        return head;
    }
    else if(node == tail){
        node->prev->next = NULL;    // Το next του προηγουμενου κομβου θα ειναι NULL αφου θα ειναι ο τελευταιος κομβος
        tail = tail->prev;
        count--;
        delete node;
        return tail;
    }
    else{   // γενικη περιπρωση το node βρισκεται καπου μεσα στην λιστα
        node->prev->next = node->next; // Το next του προηγουμενου του Node Να δειχνει στον επομενο του Node
        node->next->prev = node->prev;
        count--;
        EdgeListNode* next = node->next;
        delete node;
        return next;
    }

}


void EdgeList::removeNodes(GraphNode* gn){
    EdgeListNode* current = head;
    while (current != NULL){
        if(current->edge->node == gn){
            current = removeNode(current);
        }
        else
            current = current->next; 
    }
}

// Εκτύπωση της λίστας ακμών
void EdgeList::printListOut(char* idfromnode){
        EdgeListNode* current = head;
        while (current != NULL) {
            // Amount: "amoount"
            // Date: "day/month/year"
            cout << idfromnode << " "<< current->edge->node->id<< " " 
            << current->edge->amount<< " "
            << current->edge->date->day << "-"
            << current->edge->date->month << "-"
            << current->edge->date->year << endl;
            current = current->next;
        }
}

void EdgeList::printListIn(char* idtonode){
        EdgeListNode* current = head;
        while (current != NULL) {
            // Amount: "amoount"
            // Date: "day/month/year"
            cout << current->edge->node->id<< " " << idtonode << " "
            << current->edge->amount<< " "
            << current->edge->date->day << "-"
            << current->edge->date->month << "-"
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


void GraphNodeList::deleteNode(GraphNodeListNode* node){
    if(isEmpty()){
        return;
    }
    if (count == 1){            // Ο Node ειναι head και tail
        head = tail = NULL;
        count = 0;
        delete node; 
    }
    else if(node == head){        // ο Node ειναι ο πρωτος κομβος
        head = head->next;
        count--;
        node->next->prev = NULL;    // Το prev του επομενου κομβου του node να ειναι NULL αφου θα ειναι ο πρωτος κομβος
        delete node;
    }
    else if(node == tail){
        node->prev->next = NULL;    // Το next του προηγουμενου κομβου θα ειναι NULL αφου θα ειναι ο τελευταιος κομβος
        tail = tail->prev;
        count--;
        delete node;
    }
    else{   // γενικη περιπρωση το node βρισκεται καπου μεσα στην λιστα
        node->prev->next = node->next; // Το next του προηγουμενου του Node Να δειχνει στον επομενο του Node
        node->next->prev = node->prev;
        count--;
        delete node;

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


// Ψαχνει να βρει μεσα στο ΗashList αν υπαρχει κομβος με το συγκεκριμενο id
GraphNodeListNode* HashList::getGraphNode(char* id){
    HashListNode* current = head;
    while(current){
        if (!strcmp(current->gnlnode->graphnode->id, id)){
            return current->gnlnode;
        }
        current = current->next;
    }
    return NULL;
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

int HashTable::universalHashingString(char *str)            // Universal Hasing String
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

GraphNodeListNode* HashTable::getGraphNode(char* id){
    int position  = universalHashingString(id);
    return hashtable[position].getGraphNode(id);
}