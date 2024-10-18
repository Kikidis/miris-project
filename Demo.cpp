#include "Demo.h"





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



    Graph graph(1013);
    



//     char buffer[N];
// // apo edw arxizei h allhlepidrash me ton xrhsth
// // katharizw to buffer apo thn prohgoumenh xrhsh
// memset(buffer,0,N);
// printf("Dwse Entolh: ");
//     char ch = getchar();
//     while (ch != EOF) {
//         switch (ch) {
//                 case '\n':
//                 strncat(buffer, ((char*) &ch), 1);
//                 SendCommand(buffer);
//             }
//                     // katharizoume to buffer apo thn prohgoumenh xrhsh
//             memset(buffer,0,N);
//             printf("Dwse Entolh: ");
//                     break;
//                 default:
//                     strncat(buffer, ((char*) &ch), 1);
//                     break;
//         }
//         ch = getchar();
}

//na kanw to parssing sto cmd apo ton buffer