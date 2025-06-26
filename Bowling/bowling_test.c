#include<stdio.h>
#include<stdlib.h>
#include "../include/mem.h"


int main(){

    typedef
    struct{
        int data;
        struct Node* next;
    } Node;

   Node* node;
   node = (Node*)NEW(sizeof(Node));


   node ->data = 0;
   node ->next = NULL;


   printf("The data in the node is:%d\n", node->data);

    return 0;
}