#include <iostream>
using namespace std;

#define SIZE 5  // Defining the size of the queue
int queueArray[SIZE];  // Array to store queue elements
int frontIndex = -1;  // Index of the front element in the queue
int rearIndex = -1;  // Index of the rear element in the queue

// Function to check whether the queue is empty
bool isQueueEmpty() {
    return (frontIndex == -1 && rearIndex == -1);
}

// Function to insert an element into the queue
void enqueue(int value) {
    if (rearIndex == SIZE - 1) {  // Check if the queue is full
        cout << "Queue is full\n";
    } else {
        if (frontIndex == -1) {  // If the queue is empty, set the front index to 0
            frontIndex = 0;
        }
        rearIndex++;  // Move rear index forward
        queueArray[rearIndex] = value;  // Insert the element at the rear index
    }
}

// Function to remove an element from the queue
void dequeue() {
    if (isQueueEmpty()) {  // Check if the queue is empty
        cout << "Queue is empty\n";
    } else {
        if (frontIndex == rearIndex) {  // If there's only one element, reset the queue
            frontIndex = rearIndex = -1;
        } else {
            frontIndex++;  // Move front index forward
        }
    }
}

// Function to display the element at the front of the queue
void showFront() {
    if (isQueueEmpty()) {  // Check if the queue is empty
        cout << "Queue is empty\n";
    } else {
        cout << "Element at the front is: " << queueArray[frontIndex] << "\n";
    }
}

// Function to display all elements in the queue
void displayQueue() {
    if (isQueueEmpty()) {  // Check if the queue is empty
        cout << "Queue is empty\n";
    } else {
        cout << "Queue elements: ";
        for (int i = frontIndex; i <= rearIndex; i++) {  // Loop through the queue
            cout << queueArray[i] << " ";
        }
        cout << "\n";
    }
}

int main() {
    cout << "Inserting elements in queue: \n";
    enqueue(2);
    displayQueue();
    enqueue(3);
    displayQueue();
    enqueue(5);
    displayQueue();
    enqueue(7);
    displayQueue();
    enqueue(8);
    displayQueue();

    // Here the queue is full
    enqueue(9);  // This will print "Queue is full"

    // Showing the element at the front of the queue
    showFront();

    cout << "Removing elements from queue\n";
    dequeue();
    displayQueue();
    dequeue();
    displayQueue();
    dequeue();
    displayQueue();
    dequeue();
    displayQueue();
    dequeue();
    displayQueue();  // After this, the queue will be empty
}

