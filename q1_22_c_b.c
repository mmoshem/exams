#include <stdio.h>
#include <stdlib.h>









// Structure for a node
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
}Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = ( Node*)malloc(sizeof( Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    
    }
    else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
   
}

// Function to display the doubly linked list
void display(Node* head) {
    Node* temp = head;
    printf("Doubly linked list: ");
    while (temp != NULL) {
        printf("[%d]-> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}






int isPoliOrAllmostPoli(Node* head, Node* tail) {
    int flag = 1;
    while (head != tail) {
        if (abs(head->data - tail->data) == 0) {
            head = head->next;
            tail = tail->prev;
            continue;
        }
        else if (abs(head->data - tail->data) == 1) {
            head = head->next;
            tail = tail->prev;
            flag = 2;
            continue;
        }
        else{
            return 0;
        }


    }
    return flag;
}




int main() {
    Node* head = NULL; // Initialize an empty list
    
    insertAtBeginning(&head, 3);
    Node* tail = head;
    insertAtBeginning(&head, 6);
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 0);

    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 7);

    insertAtBeginning(&head, 3);

    display(head);
    printf("\n%d ", isPoliOrAllmostPoli(head, tail));
    return 0;
}