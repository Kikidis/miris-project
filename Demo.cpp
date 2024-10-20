#include "Demo.h"
#define N 1000  // μέγεθος του buffer

// Πρωτότυπο της συνάρτησης για το parsing
void parseCommand(char *command);


// Συνάρτηση που αποστέλλει την εντολή προς εκτέλεση
void SendCommand(char *buffer) {
    printf("Executing command: %s\n", buffer);
    parseCommand(buffer);
}


// Συνάρτηση που κάνει parsing 
void parseCommand(char *command) {
    char cmd[10];
    // Παίρνουμε το πρώτο στοιχείο της εντολής (π.χ. i, n, d, l, κλπ)
    sscanf(command, "%s", cmd);

    if (strcmp(cmd, "i") == 0) {
        cout<<("Insert command detected.\n");
        // Εδώ θα κάνεις την επεξεργασία για την εντολή εισαγωγής κόμβου,1
    }
    else if (strcmp(cmd, "n") == 0) {
        cout<<("Insert edge command detected.\n");
        // Εδώ θα κάνεις την επεξεργασία για την εντολή εισαγωγής ακμής,2
    } else if (strcmp(cmd, "d") == 0) {  // Εντολή διαγραφής κόμβου,3
        // Διαγραφή κόμβων
    } else if (strcmp(cmd, "l") == 0) {  // Εντολή διαγραφής ακμής,4
        // Διαγραφή ακμής
    } else if (strcmp(cmd, "m") == 0) {  // Εντολή τροποποίησης ακμής,5
        // Τροποποίηση ακμής
    } else if (strcmp(cmd, "f") == 0) {  // Εντολή εύρεσης εξερχόμενων συναλλαγών,6
        // Παρουσίαση εξερχόμενων δοσοληψιών
    } else if (strcmp(cmd, "r") == 0) {  // Εντολή εύρεσης εισερχόμενων συναλλαγών,7
        // Παρουσίαση εισερχόμενων δοσοληψιών
    } else if (strcmp(cmd, "c") == 0) {  // Εντολή ανίχνευσης κύκλου,8
        // Εύρεση απλών κύκλων
    } else if (strcmp(cmd, "N") == 0) {  // Εντολή ανίχνευσης κύκλου,9
    // Εύρεση απλών κύκλων
    } else if (strcmp(cmd, "t") == 0) {  // Εντολή εντοπισμού ροών,10
        // Εντοπισμός ροών ποσών
    } else if (strcmp(cmd, "O") == 0) {  // Εντολή ανίχνευσης κύκλου,11
        // Εύρεση απλών κύκλων
    } else if (strcmp(cmd, "e") == 0) {  // Εντολή τερματισμού,12
        cout<<("Terminating program.\n");
        exit(0);
    }
}

int main(){
    EdgeList edgelist;
    Date d(30,9,2001);
    Edge edge(400,d,NULL);
    edgelist.insertNode(edge);
    edgelist.insertNode(edge);
    edgelist.insertNode(edge);
    edgelist.insertNode(edge);
    edgelist.printList();


    GraphNodeList gr;
    gr.insertNode((char*) "A180");
    gr.insertNode((char*) "A200");
    gr.insertNode((char*) "A220");
    gr.printList();


    //Graph graph(1013);

    char buffer[N];
    memset(buffer,0,N);

    // apo edw arxizei h allhlepidrash me ton xrhsth
    // katharizw to buffer apo thn prohgoumenh xrhsh
    printf("Dwse Entolh: ");
    char ch = getchar();    // Διαβάζει τον πρώτο χαρακτήρα από την είσοδο

        while (ch != EOF) {
            switch (ch) {
                case '\n':                  // Αν το πλήκτρο Enter πατηθεί
                    SendCommand(buffer);
                    memset(buffer,0,N);         // Καθαρισμός του buffer για την επόμενη εντολή
                    printf("Dwse Entolh: ");
                    strncat(buffer, ((char*) &ch), 1);
                    break;
                default:
                    strncat(buffer, ((char*) &ch), 1);   // Προσθέτουμε τον χαρακτήρα στον buffer
                    break;
            }
            ch = getchar();
        }
    return 0;
}