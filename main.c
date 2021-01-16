#include <stdio.h>
#include "Node.h"
#include  <stdlib.h>
#include <stdbool.h>


Node* insertHead2(Node**head ,int key);

Node* RemoveHead2(Node*head);


void PrintList2(Node**head);


void InsertAtend2(Node**head, int key);


bool SearchKey(Node* Head, int key);

int main() {

    Node* head = NULL;

    InsertAtend2(&head,1);
    InsertAtend2(&head,2);
    InsertAtend2(&head,3);
    InsertAtend2(&head, 4);
    InsertAtend2(&head, 5);
    PrintList2(&head);
    printf("head is %d\n" , head->key);
    printf("We are removing the head \n");
    head =RemoveHead2(head);
    printf("head is now %d\n" , head->key);
    printf("\n");
    PrintList2(&head);
    printf("We are inserting a new head \n");
   head= insertHead2(&head,7);
    PrintList2(&head);
    int value = 9;
    bool a = SearchKey(head,value);

    if(a == 1)
        printf("The value %d is present in the list.", value);
    else
        printf("The value %d is not present in the list.", value);

    return 0;
}



/*
sscanf using the %n format specifier
        it lets you move forward = to the number of chars you read

*/

Node* RemoveHead2(Node* head){

    if(head == NULL) {
        printf("The list is empty there is nothing to remove");
        return NULL;
    }

else
    {
        Node *temp = head;
        head = head->next;
        free(temp);

        return head;
    }
}


void InsertAtend2(Node**head, int key) {

    Node* node = (Node*)malloc (sizeof(Node));
    node->key = key;
    node ->next = NULL;
    if(*head == NULL) {

        *head = node ;
    }

    else {

        Node * current = *head;

        while(current->next !=NULL){
            current = current ->next;
        }

        current ->next = node;
        node->next=NULL;


    }


}

Node* insertHead2(Node**head ,int key){


    Node* node = (Node*)malloc (sizeof(Node));
    node->key = key;
    node ->next = NULL;
    if(*head == NULL) {

        *head = node ;
    }

    else {
        node ->next = *head;
        return node;

    }


}


void PrintList2(Node**head){

    if(*head == NULL) {
        printf("The list is empty,there is nothing to print");
    }
    else {

        Node * current = *head;
        while(current !=NULL){

            printf("{%d}-->",current ->key );
            current = current ->next;
            }
        }

    printf("\n");
    }

bool SearchKey(Node* Head,int key){
    if(Head == NULL)
        return false;

    if(Head->key == key)
        return true;

     else
       return SearchKey(Head->next,key);

}