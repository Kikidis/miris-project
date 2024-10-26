#include "Demo.h"


bool isIllegalcmdargs(int argc, char* argv[]){
    int i, input = 0, output = 0;
    if (argc<5){
        return true;
    }
    for (i = 1; i < argc; i+=2){
        if(strcmp(argv[i],"-i") == 0){
            input ++;
        }
        else if(strcmp(argv[i], "-o") == 0){
            output ++;
        }
    }
    if(input != 1 || output != 1){
        return true;
    }
    else    
        return false;
}


void insertEdge(char* buffer, Graph &graph){
    char* tok;
    char fromNode[100], toNode[100];
    double sum;
    int day, month, year;

    //2 3 3900 2024-04-06

    tok = strtok(buffer, (char*) " ");  // tok δειχνει στον κομβο 2
    strcpy(fromNode,tok);
    graph.insertNode(fromNode);
    tok = strtok(NULL, (char*) " ");  // tok δειχνει στον κομβο 3
    strcpy(toNode,tok);
    graph.insertNode(toNode);
    tok = strtok(NULL, (char*) " ");  // tok δειχνει στο ποσο
    sum = atof(tok);
    tok = strtok(NULL, (char*)"-");    // tok δειχνει στο επομενο αλφαριθμητικο year
    year = atoi(tok);
    tok = strtok(NULL, (char*) "-");   // tok δειχνει στο month
    month = atoi(tok);
    tok = strtok(NULL,(char*) " \n");     // tok δειχνει στο day
    day= atoi(tok);

    graph.insertEdge(toNode, fromNode, sum, day, month, year);
}


// Συνάρτηση που αποστέλλει την εντολή προς εκτέλεση
void SendCommand(char *buffer, Graph &graph) {
    //printf("Executing command: %s\n", buffer);
    parseCommand(buffer, graph);
}

// Συνάρτηση που κάνει parsing 
void parseCommand(char *command, Graph &graph) {
    char cmd[10];
    char* tok;
    char fromNode[100], toNode[100];
    double sum;
    int day, month, year;
    
    // Παίρνουμε το πρώτο στοιχείο της εντολής (π.χ. i, n, d, l, κλπ)
    sscanf(command, "%s", cmd);

    // Εδώ θα κάνεις την επεξεργασία για την εντολή εισαγωγής κόμβου,1
    if (strcmp(cmd, "i") == 0) {
        tok = strtok(command, (char*) " ");         // tok δειχνει στο i
        tok = strtok(NULL, (char*) " ");            // tok δειχνει στο πρωτο ID
        while(tok != NULL){
            graph.insertNode(tok);          // εισαγει εναν νεο κομβο στον  γραφο
            tok = strtok(NULL, (char*)" ");        // παιρνω το επομενο αλφαριθμητικο αν υπαρχει
        }
        //graph.graphlist->printList();
    }
    else if (strcmp(cmd, "n") == 0) {   // Εδώ θα κάνεις την επεξεργασία για την εντολή εισαγωγής ακμής,2
        tok = strtok(command, (char*) " ");         // tok δειχνει στο n
        tok = strtok(NULL, (char*) " ");         // tok δειχνει στο πρωτο ID out
        strcpy(fromNode, tok);
        graph.insertNode(fromNode);                 // Αν δεν υπαρχει θα μπει, αλλιως τιποτα

        tok = strtok(NULL, (char*) " ");         // tok δειχνει στο δευτερο ID in
        strcpy(toNode, tok);
        graph.insertNode(toNode);

        tok = strtok(NULL, (char*) " ");     // tok δειχνει στο sum
        sum = atof(tok);

        tok = strtok(NULL, (char*)"-");        // παιρνω το επομενο αλφαριθμητικο year
        year = atoi(tok);

        tok = strtok(NULL, (char*) "-");   //παιρνω το month
        month = atoi(tok);

        tok = strtok(NULL,(char*) " \n");     //παιρνω το day
        day= atoi(tok);

        graph.insertEdge(toNode, fromNode, sum , day, month, year);

    } else if (strcmp(cmd, "d") == 0) {  // Εντολή διαγραφής κόμβου,3
        tok = strtok(command, (char*) " ");         // tok δειχνει στο d
        tok = strtok(NULL, (char*) " ");
        while(tok != NULL){
            graph.deleteGraphNode(tok);          // διαγραφει  κομβο στον  γραφο
            tok = strtok(NULL, (char*)" ");        // παιρνω το επομενο αλφαριθμητικο αν υπαρχει
        }
    } else if (strcmp(cmd, "l") == 0) {  // Εντολή διαγραφής ακμής,4
        // Διαγραφή ακμής
        tok = strtok(command, (char*) " ");         // tok δειχνει στο l
    } else if (strcmp(cmd, "m") == 0) {  // Εντολή τροποποίησης ακμής,5
        // Τροποποίηση ακμής
        tok = strtok(command, (char*) " ");         // tok δειχνει στο m
    } else if (strcmp(cmd, "f") == 0) {  // Εντολή εύρεσης εξερχόμενων συναλλαγών,6
        // Παρουσίαση εξερχόμενων δοσοληψιών
        tok = strtok(command, (char*) " ");         // tok δειχνει στο f
        tok = strtok(NULL, (char*) " ");         // tok δειχνει στο πρωτο ID out
        strcpy(fromNode, tok);
        graph.printAllOutEdges(fromNode);

    } else if (strcmp(cmd, "r") == 0) {  // Εντολή εύρεσης εισερχόμενων συναλλαγών,7
        // Παρουσίαση εισερχόμενων δοσοληψιών
        tok = strtok(command, (char*) " ");         // tok δειχνει στο r
        tok = strtok(NULL, (char*) " ");         // tok δειχνει στο πρωτο ID out
        strcpy(toNode, tok);
        graph.printAllInEdges(toNode);
    } else if (strcmp(cmd, "c") == 0) {  // Εντολή ανίχνευσης κύκλου,8
        // Εύρεση απλών κύκλων
        tok = strtok(command, (char*) " ");         // tok δειχνει στο c
    } else if (strcmp(cmd, "N") == 0) {  // Εντολή ανίχνευσης κύκλου,9
    // Εύρεση απλών κύκλων
    tok = strtok(command, (char*) " ");         // tok δειχνει στο N
    } else if (strcmp(cmd, "t") == 0) {  // Εντολή εντοπισμού ροών,10
        // Εντοπισμός ροών ποσών
        tok = strtok(command, (char*) " ");         // tok δειχνει στο t
    } else if (strcmp(cmd, "o") == 0) {  // Εντολή ανίχνευσης κύκλου,11
        // Εύρεση απλών κύκλων
        tok = strtok(command, (char*) " ");         // tok δειχνει στο o
    } else if (strcmp(cmd, "e") == 0) {  // Εντολή τερματισμού,12
        cout<<("Terminating program.\n");
        exit(0);
    }
}

int main(int argc, char* argv[]){

    int i;
    char inputFile[100], outputFile[100];
    char buffer[N];
    FILE* file;

    if(isIllegalcmdargs(argc, argv)){
        cout << "Arguments in cmd are wrong, try again.." << endl;
        return 1;    
    }

    for(i=1; i < argc; i+=2){
        if(strcmp(argv[i],"-i") == 0){
            strcpy(inputFile, argv[i+1]);
        }
        else if(strcmp(argv[i], "-o") == 0){
            strcpy(outputFile, argv[i+1]);
        }
    } 
    // Μεχρι εδω τα ορισματα ειναι σωστα και εχουμε τα ονοματα των αρχειων που μας δινει ο χρηστης
    // Δημιουργουμε τον γραφο και τον γεμιζουμε με τα στοιχεια του inputFile 
    Graph graph(1013);      // βαζω πρωτο αριθμο για καλυτερη διασπορα στο HashTable

    file = fopen(inputFile, "r"); // Ανοιγω το αρχειο για αναγνωση
    if(file != NULL){
        while(fgets(buffer, sizeof(buffer), file)){
            insertEdge(buffer, graph);
            memset(buffer,0,N); 
        }
        fclose(file);
    }
    else{
        cout << "Unable to open the file, exiting.. " << endl;
        return 1;
    }

    memset(buffer,0,N);
   
    // apo edw arxizei h allhlepidrash me ton xrhsth
    // katharizw to buffer apo thn prohgoumenh xrhsh
    printf("Give command: ");
    char ch = getchar();    // Διαβάζει τον πρώτο χαρακτήρα από την είσοδο

        while (ch != EOF) {
            switch (ch) {
                case '\n':                  // Αν το πλήκτρο Enter πατηθεί
                    SendCommand(buffer, graph);
                    memset(buffer,0,N);         // Καθαρισμός του buffer για την επόμενη εντολή
                    printf("Give command:");
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