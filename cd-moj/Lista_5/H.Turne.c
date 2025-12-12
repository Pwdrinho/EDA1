#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char cidade[30];
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;

void initQueue(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

int isEmpty(Queue *q) {
    return q->front == NULL;
}

void enqueue(Queue *q, char *nome) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        exit(1);
    }
    strcpy(newNode->cidade, nome);
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue *q, char *dest) {
    if (isEmpty(q)) return 0;

    Node *temp = q->front;
    strcpy(dest, temp->cidade);

    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return 1;
}

void peek(Queue *q, char *dest) {
    if (!isEmpty(q)) {
        strcpy(dest, q->front->cidade);
    }
}

int main() {
    Queue q;
    initQueue(&q);
    char buffer[50]; 

    while (scanf("%s", buffer) != EOF) {
        enqueue(&q, buffer);
    }

    if (isEmpty(&q)) return 0;

    char cidadeAtual[30];
    dequeue(&q, cidadeAtual);
    printf("%s\n", cidadeAtual);

    char ultimaLetra = cidadeAtual[strlen(cidadeAtual) - 1];

    while (!isEmpty(&q)) {
        char proximaCidade[30];
        peek(&q, proximaCidade);

        if (tolower(proximaCidade[0]) == tolower(ultimaLetra)) {
            dequeue(&q, proximaCidade);
            enqueue(&q, proximaCidade);
            
            if (dequeue(&q, cidadeAtual)) {
                 printf("%s\n", cidadeAtual);
                 ultimaLetra = cidadeAtual[strlen(cidadeAtual) - 1];
            }
        } 
        else {
            
            dequeue(&q, cidadeAtual);
            printf("%s\n", cidadeAtual);
            ultimaLetra = cidadeAtual[strlen(cidadeAtual) - 1];
        }
    }
    return 0;
}