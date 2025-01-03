#include<stdio.h>
struct Node {
    int value;
    struct Node * next;
};
struct Node* head = NULL;


void insertHead(int v){
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->value = v;
    newNode->next=NULL;

    if(head==NULL){
        head = newNode;
    }else{
        newNode->next=head;
        head =  newNode;
    }
}

void insertTail(int v){
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->value = v;
    newNode->next=NULL;

    struct Node * traveller;
    traveller = head;

    if(head==NULL){
        head=newNode;
    }else{
        while(traveller->next!=NULL){
            traveller=traveller->next;
        }
        traveller->next=newNode;
    }

}

void deleteTail(){
    if(head==NULL){
        printf("There is nothing to delete\n");
        return;
    }

    struct Node * traveller;
    struct Node * follower;

    traveller=head;
    follower=NULL;

    while(traveller->next!=NULL){
        follower=traveller;
        traveller=traveller->next;
    }

    if(follower==NULL){// there was only one element in the list
        free(traveller);
        head=NULL;
    }else{
        free(traveller);
        follower->next=NULL;
    }

}

void printList(){
    struct Node * traveller;
    traveller = head;

    printf("\n********Linked List Condition********\n");
    while(traveller!=NULL){
        printf("%d ",traveller->value);
        traveller =  traveller->next;
    }
    printf("\n**************************************\n");
}

void deleteByValue(int dvalue){
    if(head==NULL){
        printf("The linked list is empty\n");
        return;
    }

    if(head->value==dvalue){
        struct Node * deletePointer;
        deletePointer = head;

        head = head->next;
        free(deletePointer);
        return;
    }

    struct Node* traveller;
    traveller = head;

    while(traveller->next!=NULL){
        if(traveller->next->value==dvalue){
            struct Node * deletePointer;
            deletePointer = traveller->next;

            traveller->next= traveller->next->next;
            free(deletePointer);
            return;
        }else{
            traveller=traveller->next;
        }

    }

    printf("Value not found!\n");

}

int main(){
    printList();
    insertTail(30);
    printList();
    insertTail(20);
    printList();
    insertTail(10);
    printList();
    insertTail(0);

    printList();

    insertHead(100);
    insertHead(200);
    insertHead(300);
    insertTail(-300);
    insertTail(-200);
    insertTail(-100);
    printList();

    deleteTail();
    deleteTail();
    deleteTail();

    printList();
    insertTail(1000);
    insertTail(2000);
    deleteTail();
    printList();
    deleteByValue(30);
    printList();
    deleteByValue(300);
    printList();
    deleteByValue(1000);
    printList();
    deleteByValue(0);
    printList();
    deleteByValue(256);
    printList();

    return 0;
}


