#include<stdio.h>


struct Node {
    int value;
    struct Node * next;
};

struct Node* head = NULL;

int main(){
    head = malloc(sizeof(struct Node));
//    int v = head->value;
//    int address = head->next;
    head->value = 10;
    head->next=NULL;

    int v = head->value;
    int address = head->next;

    printf("value = %d\n",v);
    printf("address = %d\n",address);

    printf("head->value = %d\n",head->value);
    printf("head->next = %d\n",head->next);

    return 0;
}

