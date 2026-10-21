#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

void display(Node *head){

    if(head->next == NULL){
        printf("Empty Linked List\n");
    }
    else{

        Node *temp = head->next;
        while(temp != NULL){

            printf("%p\t",temp);
            printf("%d\t",temp->data);
            printf("%p\n",temp->next);

            temp = temp->next;
        }
    }
}

int lengthLL(Node *head){

    int len = 0;
    if(head->next == NULL){
        printf("Empty Linked List\n");
    }
    else{
        Node *temp = head->next;
        while(temp != NULL){
            len++;
            temp = temp->next;
        }
    }
    return len;
}

void addAtBeginning(Node *head, int data){

    Node *newnode = malloc(sizeof(Node));
    newnode->data = data;

    if(head->next == NULL){
        newnode->next = NULL;
        head->next = newnode;
    }
    else{
        newnode->next = head->next;
        head->next = newnode;
    }
}

void addAtEnd(Node *head, int data){

    Node *newnode = malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;

    if(head->next == NULL){
        head->next = newnode;
    }
    else{
        Node *temp = head->next;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void addAtPos(Node *head, int data, int pos){

    int len = lengthLL(head);
    if(pos < 1 || pos > len + 1){
        printf("Invalid position\n");
    }
    else{
        Node *temp = head;
        for(int i = 1; i < pos; i++){
            temp = temp->next;
        }
        Node *newnode = malloc(sizeof(Node));
        newnode->data = data;
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void addByData(Node *head, int data){
    
    Node *newnode = malloc(sizeof(Node));
    newnode->data = data;

    if(head->next == NULL){
        newnode->next = NULL;
        head->next = newnode;
    }
    else{
        Node *temp = head;
        while(temp->next != NULL && temp->next->data != data){
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void addInOrder(Node *head, int element){
    Node *newnode = malloc(sizeof(Node));
    newnode->data = element;
    
    Node *temp = head;
    while(temp->next != NULL && temp->next->data < element){
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void deleteFromBeginning(Node *head)
{
    if(head->next == NULL)
        printf("Linked List is empty\n");
    else
    {
        Node *temp = head->next;
        head->next = head->next->next;
        free(temp);
    }
}

void deleteFromEnd(Node *head)
{
    if(head->next == NULL)
        printf("Linked List is empty\n");
    else
    {
        Node *prev = head;
        Node *temp = head->next;
        while(temp->next != NULL){
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
    }
}

void deleteAtPos(Node *head, int pos){
    int len = lengthLL(head);
    if(pos < 1 || pos > len){
        printf("Invalid position\n");
    }
    else{
        Node *prev = head;
        Node *temp = head->next;
        for(int i = 1; i < pos; i++){
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        free(temp);
    }
}

void deleteByData(Node *head, int data){
    if(head->next == NULL){
        printf("Linked List is empty\n");
    }
    else{
        Node *prev = head;
        Node *temp = head->next;
        while(temp != NULL && temp->data != data){
            prev = temp;
            temp = temp->next;
        }
        if(temp == NULL){
            printf("Data not found\n");
        }
        else{
            prev->next = temp->next;
            temp->next = NULL;
            free(temp);
        }
    }
}

void reverse(Node *head){

    if(head->next == NULL){
        printf("Empty Linked List\n");
    }
    else{
        Node *lastrev = NULL;
        Node *present = head->next;
        Node *infuture;

        while(present != NULL){
            infuture = present->next;
            present->next = lastrev;
            lastrev = present;
            present = infuture;
        }
        head->next = lastrev;

    }
    
}

void sortbydata(Node *head){

    Node *curr1, *curr2;
    if(head->next == NULL){
        printf("Empty Linked List\n");
    }
    else{
        curr1 = head->next;
        while(curr1 != NULL){
            curr2 = curr1->next;
            while(curr2 != NULL){
                if(curr1->data > curr2->data){
                    int temp = curr1->data;
                    curr1->data = curr2->data;
                    curr2->data = temp;
                }
                curr2 = curr2->next;
            }
            curr1 = curr1->next;
        }
    }
}

void sortbynode(Node *head){

    Node *prev, *curr1, *curr2;
    int len = lengthLL(head);

    if(head->next == NULL){
        printf("Empty Linked List\n");
    }
    else{
        int p = 0;
        while(p < len - 1){
            prev = head;
            curr1 = head->next;
            while(curr1->next != NULL){
                curr2 = curr1->next;
                if(curr1->data > curr2->data){
                    curr1->next = curr2->next;
                    curr2->next = curr1;
                    prev->next = curr2;
                    prev = curr2;
                }
                else{
                    prev = curr1;
                    curr1 = curr1->next;
                }
            }
            p++;
        }
    }
}

int main(){

    Node *head = malloc(sizeof(Node));
    head->next = NULL;
    
    int choice, data, pos;
    do{
        printf("\n");
        printf("Enter 1 for display linked list\nEnter 2 for length of linked list\nEnter 3 for add at beginning\nEnter 4 for add at end\nEnter 5 for add at position\nEnter 6 for add by data\nEnter 7 for add in order\nEnter 8 to delete from beginning\nEnter 9 to delete from end\nEnter 10 to delete at position\nEnter 11 to delete by data\nEnter 12 to reverse linked list\nEnter 13 to sort by data\nEnter 14 to sort by node\nEnter 0 to exit : ");
        scanf("%d", &choice);
        printf("\n");
        switch(choice){
            case 1:
                display(head);
                break;
            case 2:
                printf("Length of linked list : %d\n", lengthLL(head));
                break;
            case 3:
                printf("Enter data to add at beginning : ");
                scanf("%d", &data);
                addAtBeginning(head, data);
                break;
            case 4:
                printf("Enter data to add at end : ");
                scanf("%d", &data);
                addAtEnd(head, data);
                break;
            case 5 :
                printf("Enter data and position : ");
                scanf("%d %d", &data, &pos);
                addAtPos(head, data, pos);
                break;
            case 6:
                printf("Enter data to add by value : ");
                scanf("%d", &data);
                addByData(head, data);
                break;
            case 7:
                printf("Enter data to add in order : ");
                scanf("%d", &data);
                addInOrder(head, data);
                break;
            case 8:
                deleteFromBeginning(head);
                break;
            case 9:
                deleteFromEnd(head);
                break;
            case 10:
                printf("Enter position to delete : ");
                scanf("%d", &pos);
                deleteAtPos(head, pos);
                break;
            case 11:
                printf("Enter data to delete : ");
                scanf("%d", &data);
                deleteByData(head, data);
                break;
            case 12:
                reverse(head);
                display(head);
                break;
            case 13:
                sortbydata(head);
                display(head);
                break;
            case 14:
                sortbynode(head);
                display(head);
                break;
            case 0:
                printf("Exit\n");
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 0);
    return 0;
}