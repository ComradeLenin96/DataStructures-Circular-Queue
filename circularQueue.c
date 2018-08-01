#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}Node;

typedef struct queue {
    Node* front;
    Node* tail;
}CirqularQueue;

Node* createNode(int);
CirqularQueue* emptyQueue();
void enQueue(CirqularQueue*, int);
void deQueue(CirqularQueue*);
void display(CirqularQueue*);
int countElem(CirqularQueue*);

int main() {
    CirqularQueue* q = emptyQueue();
    int count = 0;
    printf("COUNT:%d\n", count);
    enQueue(q, 5);
    enQueue(q, 6);
    enQueue(q, 7);
    enQueue(q, 8);
    enQueue(q, 9);
    count = countElem(q);
    printf("COUNT:%d\n", count);
    display(q);
    deQueue(q);
    display(q);
    deQueue(q);
    deQueue(q);
    display(q);
    deQueue(q);
    deQueue(q);
    count = countElem(q);
    printf("COUNT:%d\n", count);
    return 0;
}

Node* createNode(int data) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

CirqularQueue* emptyQueue() {
    CirqularQueue* q = malloc(sizeof(CirqularQueue));
    if (q == NULL) {
        printf("Allocation failed\n");
        return NULL;
    }
    q->front = q->tail = NULL;
    return q;
}

//add elements at the end
void enQueue(CirqularQueue* q, int data) {
    Node* newNode = createNode(data);
    //if queue if empty
    if (q->front == NULL) {
        q->front = q->tail = newNode;
        newNode->next = q->front;
    }else{
        q->tail->next = newNode;
        newNode->next = q->front;
        q->tail = newNode;
    }
    printf("enQueue\n");
}

void deQueue(CirqularQueue* q) {
    Node* temp = q->front;
    //if we have one element in the queue
    if (q->front == q->tail) {
        q->front = q->tail = NULL;
        temp->next = NULL;
        free(temp);
    }else {
        q->front = temp->next;
        temp->next = NULL;
        q->tail->next = q->front;
        free(temp);
    }
    printf("deQueue\n");
}

void display(CirqularQueue* q) {
    if (q->front == NULL) printf("Empty\n");
    Node* curr = q->front;
    while (curr->next != q->front) {
        printf("q->data:%d\t", curr->data);
        curr = curr->next;
    }
    printf("q->data:%d\t", curr->data);
    printf("\n");
}

int countElem(CirqularQueue* q) {
    int count = 0;
    if (q->front == NULL) return 0;
    Node* curr = q->front;
    while (curr->next != q->front) {
        ++count;
        curr = curr->next;
    }
    ++count;
    return count;
} 




