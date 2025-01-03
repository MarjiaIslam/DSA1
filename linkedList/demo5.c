#include<stdio.h>
struct Node{
    int data;
    struct Node * prev;
    struct Node * next;

};

struct Node * head = NULL;
struct Node * tail = NULL;

void insertHead(int value){


    if(head==NULL){
        struct Node * newNode = malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next=NULL;
        newNode->prev=NULL;
        head=newNode;
        tail=newNode;
    }else{
        struct Node *newNode = malloc(sizeof(struct Node));
        newNode->data=value;
        newNode->next=NULL;
        newNode->prev=NULL;

        newNode->next=head;
        head->prev = newNode;
        //head=newNode;
        head=head->prev;
    }
}


void printList(){
    printf("\n********************\n");
    struct Node * traveller;
    traveller=head;

    while(traveller!=NULL){
        printf("%d ",traveller->data);
        traveller=traveller->next;
    }

    printf("\n********************\n");
}


struct Node * findMiddleElement(){
    int counter = 0;
    struct Node * countingPointer;
    countingPointer = head;

    while(countingPointer!=NULL){
        counter++;
        countingPointer = countingPointer->next;
    }
    printf("Total number of nodes %d\n",counter);

    int midNodePosition;
    if(counter%2==0){ // there are even number of nodes
        midNodePosition = counter/2;
    }else{
        midNodePosition = counter/2+1;
    }


    printf("mid node position %d\n",midNodePosition);

    struct Node * traveller;
    traveller = head;

    for(int i=1;i<=midNodePosition-1;i++){
        traveller = traveller ->next;
    }

    printf("Traveller ->data = %d\n",traveller->data);

    return traveller;
}


void reverseLinkedList(){
    struct Node *ptr;
    ptr=findMiddleElement();

    struct Node *t1;
    struct Node *t2;

    t1 = head;
    t2 = tail;

    while(1){
        // swapping the values of the two pointers
        int temp;
        temp = t1->data;
        t1->data =  t2->data;
        t2->data = temp;

        if(t1==ptr){
            break;
        }else{
            t1=t1->next;
            t2=t2->prev;
        }
    }


}



int main(){
    insertHead(50);
    insertHead(10);
    insertHead(5);
    insertHead(2);
    insertHead(50);
    insertHead(10);
    insertHead(5);
    insertHead(2);
    insertHead(1);

    printList();

    struct Node * ptr = findMiddleElement();
    ptr->data = -50;
    printList();

    ptr->next->data = ptr->next->data * -10;
    ptr->next->next->data = ptr->next->next->data * -10;

    printList();
    printf("Reversing the linked list\n");

    reverseLinkedList();
    printList();


    return 0;
}
