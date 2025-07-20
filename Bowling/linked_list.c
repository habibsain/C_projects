#include <stdio.h>
#include "mem.h"


int main(){
    //typedef struct node Node;

    struct Node{
        int data;
        struct Node* next;
    }*node1, *node2;

    //Node* node1;
    node1  = (struct Node*)NEW(sizeof(struct Node));


    node1 ->data = 0;
    node1 ->next = NULL;

    //Link another node to it
    //Node* node2;

    //Allocate memory
    node2 = (struct Node*)NEW(sizeof(struct Node));
   
    //Assign new data
    node1 ->next = node2;
    node2 ->data = 1;
    node2 ->next = NULL;


    printf("The data in the node1 is:%d\n", node1->data);
    printf("The data in the node2 is:%d\n", node1->next->data);

    FREE(node1);
    FREE(node2);

    return 0;
}