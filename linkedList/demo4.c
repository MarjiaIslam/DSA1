#include<stdio.h>

struct Node{
    int value;
    struct Node * prev;
    struct Node * next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

void insertHead(int value){
    struct Node * newNode = malloc(sizeof(struct Node));
    newNode-> value = value;
    newNode -> next = NULL;
    newNode -> prev = NULL;

    if(head==NULL){ // the linked list is empty
        head=newNode;
        tail=newNode;
    }else{
        newNode->next=head;
        head->prev=newNode;
        head = newNode;
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

struct Node * search(int value){
    struct Node *traveller;
    traveller = head;

    while(traveller!=NULL){
        // check
        if(traveller->value==value){
            return traveller;
        }
        // proceed forward
        traveller=traveller->next;
    }

    return NULL;
}

void deleteNode(int value){
    struct Node * ptr = search(value);

    if(ptr==NULL){
        printf("Value not found!\n");
        return;
    }

    // the searched node is the only node in the list
    if(head==tail){
        free(head);
        head=NULL;
        tail=NULL;
        return;
    }

    // the searched node is the first node
    if(head==ptr){
        ptr->next->prev=NULL;
        //ptr->next->prev=ptr->prev;
        head = head->next;
        free(ptr);
        return;
    }

    if(tail==ptr){
        ptr->prev->next=NULL;
        tail = tail->prev;
        free(ptr);
        return;
    }

    ptr->prev->next=ptr->next;
    ptr->next->prev=ptr->prev;
    free(ptr);
};

int main(){
    //printList();
    insertHead(300);
    insertHead(200);
    insertHead(100);
    insertHead(1000);
    insertHead(2000);
    insertHead(4000);

    printList();

    struct Node * ptr1 =search(1000);
    printf("ptr1 = %d\n",ptr1);
    printf("ptr1->value = %d\n",ptr1->value);
    printf("ptr1->next = %d\n",ptr1->next);


    struct Node * ptr2 =search(1500);
    printf("ptr2 = %d\n",ptr2);
//    printf("ptr2->value = %d\n",ptr2->value);
//    printf("ptr2->next = %d\n",ptr2->next);

    deleteNode(1000);
    printList();
    deleteNode(300);
    printList();
    deleteNode(200);
    printList();
    deleteNode(4000);
    printList();
    deleteNode(2000);
    printList();

    return 0;
}
