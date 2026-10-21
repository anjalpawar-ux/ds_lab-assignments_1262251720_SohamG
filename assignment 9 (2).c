#include <stdio.h>
#define MAX 20

struct JobSeq{
    int jobID;
    char JobTitle[20];
};

int front = -1, rear = -1;
struct JobSeq arr[MAX];

int isEmpty(struct JobSeq q){
    return (front == -1);
}

int isFull(struct JobSeq q){
    return ((rear + 1) % MAX == front);
}

void Add(struct JobSeq q, struct JobSeq value){
    if(isFull(q)){
        printf("Queue is full\n");
        return;
    }
    if(front == -1){
        front = 0;
    }
    rear = (rear + 1) % MAX;
    arr[rear] = value;
}

int Delete(struct JobSeq q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return -1;
    }

    printf("Deleted: JobID %d, Title %s\n", arr[front].jobID, arr[front].JobTitle);
    int deletedID = arr[front].jobID;

    if(front == rear){
        front = -1;
        rear = -1;
    }
    else{
        front = (front + 1) % MAX;
    }
    return deletedID;
}

void printQueue(struct JobSeq q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return;
    }
    printf("Queue contents:\n");
    int i = front;
    while(1){
        printf("JobID: %d, Title: %s\n", arr[i].jobID, arr[i].JobTitle);
        if(i == rear) break;
        i = (i + 1) % MAX;
    }
}

int main(){
    int choice;
    struct JobSeq dummy;

    do{
        printf("\n=== Circular Job Queue Menu ===\n");
        printf("1. Add Job\n");
        printf("2. Delete Job\n");
        printf("3. Display Queue\n");
        printf("4. End\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: {
                struct JobSeq newJob;
                printf("Enter Job ID: ");
                scanf("%d", &newJob.jobID);
                printf("Enter Job Title: ");
                scanf("%s", newJob.JobTitle);
                Add(dummy, newJob);
                printQueue(dummy);
                break;
            }
            case 2:
                Delete(dummy);
                printQueue(dummy);
                break;
            case 3:
                printQueue(dummy);
                break;
            case 4:
                printQueue(dummy);
                break;
            default:
                printf("Invalid choice\n");
        }
    }while (choice != 4);

    return 0;
}