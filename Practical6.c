#include <stdio.h>
#include<conio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
int data;
struct Node* next;

};

// Helper function to dynamically allocate a new node
struct Node* createNode(int value) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
if (newNode == NULL) {
printf("Memory allocation failed!\n");
exit(1); // Exit if heap memory is full
}
newNode->data = value;
newNode->next = NULL;
return newNode;
}

// Insertion at the beginning (Head)
void insertAtBeginning(struct Node** headRef, int value) {
struct Node* newNode = createNode(value);

// Point the new node to the current head, then update head
newNode->next = *headRef;
*headRef = newNode;
printf("Inserted %d at the beginning.\n", value);
}

// Insertion at the end (Tail)
void insertAtEnd(struct Node** headRef, int value) {
struct Node* newNode = createNode(value);

// If the list is empty, the new node becomes the head
if (*headRef == NULL) {
*headRef = newNode;

printf("Inserted %d at the end (list was empty).\n", value);
return;
}

// Traverse to find the last node
struct Node* temp = *headRef;
while (temp->next != NULL) {
temp = temp->next;
}

// Link the last node to the new node
temp->next = newNode;
printf("Inserted %d at the end.\n", value);
}

// Insertion at a specified position (1-indexed)
void insertAtPosition(struct Node** headRef, int value, int position) {
// If position is 1, it's equivalent to inserting at the beginning
if (position == 1) {
insertAtBeginning(headRef, value);
return;
}

struct Node* temp = *headRef;

// Traverse to the node right before the target position (position - 1)
for (int i = 1; i < position - 1; i++) {
if (temp == NULL) {
printf("Invalid position! The list is shorter than expected.\n");
return;
}

temp = temp->next;
}

// Check if the previous node exists
if (temp == NULL) {
printf("Invalid position! Position is out of bounds.\n");
return;
}

// Create node and link it into the list
struct Node* newNode = createNode(value);
newNode->next = temp->next;
temp->next = newNode;
printf("Inserted %d at position %d.\n", value, position);
}

// Function to print the entire linked list
void displayList(struct Node* head) {
if (head == NULL) {
printf("The list is currently empty.\n");
return;
}

struct Node* temp = head;
printf("Linked List: ");
while (temp != NULL) {
printf("%d -> ", temp->data);
temp = temp->next;
}
printf("NULL\n");
}

// Memory cleanup routine to avoid memory leaks
void freeList(struct Node* head) {
struct Node* temp;
while (head != NULL) {
temp = head;
head = head->next;
free(temp);
}
}

// Main execution frame demonstrating functionality
void main() {
// Initialize an empty list
struct Node* head = NULL;

// Demonstrate Insert at Beginning
insertAtBeginning(&head, 10);
insertAtBeginning(&head, 20);
displayList(head); // Output: 20 -> 10 -> NULL

// Demonstrate Insert at End
insertAtEnd(&head, 30);
insertAtEnd(&head, 40);
displayList(head); // Output: 20 -> 10 -> 30 -> 40 -> NULL

// Demonstrate Insert at Specified Position
insertAtPosition(&head, 15, 2); // Insert 15 at position 2
displayList(head); // Output: 20 -> 15 -> 10 -> 30 -> 40 -> NULL

insertAtPosition(&head, 5, 1); // Insert 5 at position 1 (Head edge case)

displayList(head); // Output: 5 -> 20 -> 15 -> 10 -> 30 -> 40 -> NULL

insertAtPosition(&head, 100, 10); // Attempt an out-of-bounds position

// Free heap allocations before exiting
freeList(head);
getch();
}
