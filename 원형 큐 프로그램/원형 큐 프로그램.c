#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 100

typedef int element;

typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void initQueue(QueueType* q) {
    q->front = q->rear = 0;
}

bool isEmpty(QueueType* q) {
    return q->front == q->rear;
}

bool isFull(QueueType* q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

void enqueue(QueueType* q, element item) {
    if (isFull(q)) {
        printf("큐가 꽉 찼습니다.\n");
        return;
    }

    q->data[q->rear] = item;
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
}

element dequeue(QueueType* q) {
    if (isEmpty(q)) {
        printf("큐가 비어 있습니다.\n");
        return -1;
    }

    element item = q->data[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return item;
}

void printQueue(QueueType* q) {
    if (isEmpty(q)) {
        printf("큐가 비어 있습니다.\n");
        return;
    }

    int i = q->front;

    while (i != q->rear) {
        printf("%d ", q->data[i]);
        i = (i + 1) % MAX_QUEUE_SIZE;
    }

    printf("%d\n", q->data[i]);
}

int main() {
    QueueType q;
    initQueue(&q);

    int choice;

    while (1) {
        printf("메뉴:\n");
        printf("1. 큐에 원소를 삽입\n");
        printf("2. 큐에서 원소를 삭제하고 출력\n");
        printf("3. 큐의 원소를 출력\n");
        printf("4. 종료\n");
        printf("옵션을 선택하세요: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            element item;
            printf("삽입할 원소를 입력하세요: ");
            scanf("%d", &item);
            enqueue(&q, item);
            break;
        case 2:
            element item2 = dequeue(&q);
            if (item2 != -1) {
                printf("삭제된 원소: %d\n", item2);
            }
            break;
        case 3:
            printf("큐의 원소: ");
            printQueue(&q);
            break;
        case 4:
            exit(0);
        default:
            printf("잘못된 선택입니다.\n");
        }
    }

    return 0;
}
