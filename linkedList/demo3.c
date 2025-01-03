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

int sumOfNodes(){
    struct Node * traveller;
    traveller = head;

    int sum = 0;
    while(traveller!=NULL){
        sum+=traveller->value;
        traveller=traveller->next;
    }
    return sum;
}

void insertAtPosition(int position, int value){
    if(head==NULL){
        if(position==1){
            // this is possible
            struct Node * newNode = malloc(sizeof(struct Node));
            newNode->value = value;
            newNode->next=NULL;
            head=newNode;
            return;
        }else{
            // this is not possible
            printf("NOT POSSIBLE");
            return;
        }
    }

    // if there is only one element and position 1
    if((head!=NULL && head->next==NULL) && position==1){
        struct Node * newNode;
        newNode = malloc(sizeof(struct Node));
        newNode->value=value;
        newNode->next=NULL;

        newNode->next=head;
        head=newNode;
        return;
    }

    struct Node * countingPtr;
    countingPtr = head;

    int counter = 0;
    while(countingPtr!=NULL){
        // count
        counter++;
        if(counter==position-1){
            break;
        }
        // proceed forward
        countingPtr = countingPtr->next;
    }
    if(countingPtr==NULL){
        printf("NOT POSSIBLE!\n");
        return;
    }
    struct Node * newNode;
    newNode = malloc(sizeof(struct Node));

    newNode->value=value;
    newNode->next=NULL;

    newNode->next=countingPtr->next;
    countingPtr->next=newNode;
}

int main(){
    insertAtPosition(1,100);
    insertAtPosition(1,200);
    insertAtPosition(3,400);
    insertAtPosition(10,400); // won't work

    printList();
    insertAtPosition(2,5000);
    printList();

//    int result =sumOfNodes();
//    printf("Result = %d\n",result);

    return 0;
}
