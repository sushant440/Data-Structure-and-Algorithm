#include <stdio.h>

#define MAX 5

int data[MAX];       // array to store queue elements
int priority[MAX];   // array to store priorities
int size = -1;       // index of last element

// Function to insert element into Priority Queue
void enqueue(int value, int pr)
{
    if (size == MAX - 1)
    {
        printf("Queue Overflow!\n");
        return;
    }

    size++;
    data[size] = value;
    priority[size] = pr;

    printf("Enqueued: %d with priority %d\n", value, pr);
}

// Function to find index of highest priority element
int peek()
{
    int highest = -1;
    int index = -1;

    for (int i = 0; i <= size; i++)
    {
        if (priority[i] > highest)
        {
            highest = priority[i];
            index = i;
        }
    }
    return index;
}

// Function to remove highest priority element
void dequeue()
{
    if (size == -1)
    {
        printf("Queue Underflow!\n");
        return;
    }

    int index = peek();

    printf("Dequeued: %d (Priority: %d)\n", data[index], priority[index]);

    // Shift elements to left
    for (int i = index; i < size; i++)
    {
        data[i] = data[i + 1];
        priority[i] = priority[i + 1];
    }

    size--;
}

// Main function
int main()
{
    enqueue(10, 1);
    enqueue(30, 3);
    enqueue(20, 2);
    enqueue(40, 4);

    printf("\n--- Processing Queue ---\n");

    dequeue();   // removes 40
    dequeue();   // removes 30

    return 0;
}

/* 

     #include <stdio.h>

#define MAX 5   // Maximum size of the priority queue

// Array to store queue elements (data)
int data[MAX];

// Array to store priority of each element
int priority[MAX];

// Variable to keep track of the last index
// size = -1 indicates that the queue is empty
int size = -1;

/*
    Function: enqueue
    Purpose : Insert an element into the priority queue
    Logic   : Element is inserted at the end.
              Priority is handled during deletion.

void enqueue(int value, int pr)
{
    // Check for queue overflow
    if (size == MAX - 1)
    {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }

    // Increase size to point to next free position
    size++;

    // Store value and its priority
    data[size] = value;
    priority[size] = pr;

    printf("Enqueued: %d with priority %d\n", value, pr);
}

/*
    Function: peek
    Purpose : Find the index of the element
              having the highest priority
    Return  : Index of highest priority element

int peek()
{
    int highestPriority = -1;   // Stores highest priority found
    int index = -1;             // Stores index of highest priority element

    // Traverse through the queue
    for (int i = 0; i <= size; i++)
    {
        // If current element has higher priority
        if (priority[i] > highestPriority)
        {
            highestPriority = priority[i];
            index = i;
        }
    }

    return index;
}

/*
    Function: dequeue
    Purpose : Remove the element with highest priority

void dequeue()
{
    // Check for queue underflow
    if (size == -1)
    {
        printf("Queue Underflow! Queue is empty\n");
        return;
    }

    // Find index of highest priority element
    int index = peek();

    // Display deleted element
    printf("Dequeued: %d (Priority: %d)\n",
           data[index], priority[index]);

    /*
        Shift all elements after the deleted element
        one position to the left
    
    for (int i = index; i < size; i++)
    {
        data[i] = data[i + 1];
        priority[i] = priority[i + 1];
    }

    // Decrease size after deletion
    size--;
}

/*
    Main function to test the priority queue

int main()
{
    // Insert elements (value, priority)
    // Higher number means higher priority
    enqueue(10, 1);
    enqueue(30, 3);
    enqueue(20, 2);
    enqueue(40, 4);

    printf("\n--- Processing Queue ---\n");

    // Remove elements based on priority
    dequeue();   // Removes 40 (highest priority)
    dequeue();   // Removes 30 (next highest priority)

    return 0;
}



*/
