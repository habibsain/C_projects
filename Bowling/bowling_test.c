#include<stdio.h>
#include "../include/mem.h"


int main(){

    typedef struct Node{
        int data;
        struct Node* next;
    } Node;

    Node* node1;
    node1  = (Node*)NEW(sizeof(Node));


    node1 ->data = 0;
    node1 ->next = NULL;

    //Link another node to it
    Node* node2;

    //Allocate memory
    node2 = (Node*)NEW(sizeof(Node));
   
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