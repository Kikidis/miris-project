#include "GraphComponents.h"

Edge::~Edge(){
    delete date;
}

EdgeListNode::~EdgeListNode(){
    delete edge;
}

EdgeList::~EdgeList(){

}

bool EdgeList::isEmpty(){
    return count == 0;
}

void EdgeList::insertNode(Edge &edge){
   // φτιάχνω κόμβο/ελέγχω αν είναι άδεια/ βρίσκω head tail/ ελέγχω αν δουλεύει
    
}

// Εκτύπωση της λίστας με printList
void EdgeList::printList(){

}
//TETARTH 11.30-1.30