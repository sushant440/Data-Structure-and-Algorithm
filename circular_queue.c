#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Enqueue
void enqueue(int value) {
    if ((rear + 1) % MAX == front) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = value;
    printf("%d inserted into queue\n", value);
}

// Dequeue
void dequeue() {
    if (front == -1) {
        printf("Queue Underflow! Queue is empty\n");
        return;
    }

    printf("%d removed from queue\n", queue[front]);

    if (front == rear) {
        front = rear = -1;   // queue becomes empty
    } else {
        front = (front + 1) % MAX;
    }
}

// Display
void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(50);
    enqueue(69);
    display();

    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();

    display();

    enqueue(67);   // works correctly now
    display();

    return 0;
}