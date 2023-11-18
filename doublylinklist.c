#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void insertAtFront(struct Node** head, int data) {
    // Create a new struct node and allocate memory.
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    // Initialize data in the newly created node.
    newNode->data = data;
    // Make the next pointer of the new node point to the head.
    // In this way, this new node is added at front of the linked list.
    newNode->next = (*head);
    newNode->prev = NULL;
    // If the head is not NULL, then we update the prev pointer in the current head.
    // The prev pointer of the current head will point to the new node.
    if((*head) != NULL) {
        (*head)->prev = newNode;
    }
    // Update the head pointer to point to the new node.
    (*head) = newNode;
}

void insertAtEnd(struct Node** head, int data) {
    // Create a new struct node and allocate memory.
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    // Initialize data in the newly created node.
    newNode->data = data;
    newNode->next = NULL;
    if((*head) == NULL) {
        // If the head is NULL, then the new node is the new head.
        newNode->prev = NULL;
        // Assign head as the new node.
        (*head) = newNode;
        return ;
    }
    // If the list is not empty then traverse to the end of the list.
    struct Node* ptr = (*head);
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }
    // From the last node, add a link to the new node.
    ptr->next = newNode;
    // Update the prev pointer in the new node to point to the previous last node.
    newNode->prev = ptr;
}

void insertAfterNode(struct Node* node, int data) {
    if(node == NULL) {
        // If the node is NULL, then we cannot insert.
        printf("The given node cannot be NULL.");
        return ;
    }
    // Create a new struct node and allocate memory.
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    // Initialize data in the newly created node.
    newNode->data = data;
    // Add a link from new node to next_node.
    newNode->next = node->next;
    // Add a link from the given node to the new node.
    node->next = newNode;
    // Update the prev pointer of the new node to the given node.
    newNode->prev = node;
    // If the next_node is not NULL, then update the prev of the next_node.
    if(newNode->next != NULL) {
        newNode->next->prev = newNode;
    }
}

void insertBeforeNode(struct Node** head, struct Node* node, int data) {
    if(node == NULL) {
        // If the given node is NULL, then we cannot insert a node before a NULL node.
        printf("The given node cannot be NULL.");
        return ;
    }
    // Create a new struct node and allocate memory.
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    // Initialize data in the newly created node.
    newNode->data = data;
    // Add a link from the new node to the given node.
    newNode->next = node;
    if(node->prev != NULL) {
        // If the given node is not the head node, then we update the next pointer of previous node
        node->prev->next = newNode;
        // Update the prev pointer of the new node to point to the previous node.
        newNode->prev = node->prev;
    }
    else {
        // If the previous value is NULL, then this means the given node is head.
        // So we are inserting it at the front of head.
        // Hence, we update the value of the head pointer to the new node.
        *head = newNode;
    }
    // Update the previous pointer of the given node.
    node->prev = newNode;
}

void deleteAtFront(struct Node** head) {
    // If the head pointer is NULL, then we cannot delete it.
    if((*head) == NULL) return ;
    struct Node* curr = *head;
    // Update the head pointer to the next node.
    *head = (*head)->next;
    // Make the previous head pointer NULL and free the memory.
    curr->next = NULL;
    free(curr);
}

void deleteAtLast(struct Node** head) {
    // If the head pointer is NULL, then we cannot delete it.
    if((*head) == NULL) return ;
    // Traverse to the last node.
    struct Node* curr = *head;
    while(curr->next != NULL) {
        curr = curr->next;
    }
    // Second last node will point to NULL.
    struct Node* prev = curr->prev;
    prev->next = NULL;
    // Make the last node NULL and free the memory.
    curr->prev = NULL;
    free(curr);
}

void deleteAtPosition(struct Node** head, int position) {
    struct Node* curr = *head;
    if(position == 1) {
        // If the position is 1, then delete the head and return.
        deleteAtFront(head);
        return ;
    }
    // Go the node to be deleted.
    while(position > 1 && curr) {
        // While the position is greater than 1 and the current node is not NULL,
        // we iterate forward and decrease position by 1.
        curr = curr->next;
        position --;
    }
    // If the current node is NULL, then we cannot delete it.
    // The node at the specified position does not exist.
    if(curr == NULL) {
        printf("Node at position is not present.\n");
        return ;
    }
    // Create pointers to the previous node and the next node of the current node.
    struct Node* prevNode = curr->prev;
    struct Node* nextNode = curr->next;
    // Update the next pointer of the previous node and the previous pointer of the next node.
    // In this way, the middle node is removed from the list.
    curr->prev->next = nextNode;
    if(nextNode != NULL) {
        nextNode->prev = prevNode;
    }
    // Remove the link to the list and free the memory.
    curr->next = curr->prev = NULL;
    free(curr);
}

void traverse(struct Node* head) {
    for(struct Node* i = head; i != NULL; i = i->next) {
        printf("%d", i->data);
        if(i->next) printf(" <--> ");
    }
    printf(" -> NULL \n");
}


int main() {
    struct Node* head = NULL;
    printf("Insert 1 at the front\n");
    insertAtFront(&head, 1);
    traverse(head);
    printf("Insert 2 at the front\n");
    insertAtFront(&head, 2);
    traverse(head);
    printf("Insert 4 at the end\n");
    insertAtEnd(&head, 4);
    traverse(head);
    printf("Insert 5 at the front\n");
    insertAtEnd(&head, 5);
    traverse(head);
    printf("Insert 3 after head->next\n");
    insertAfterNode(head->next, 3);
    traverse(head);
    printf("Insert -1 before the head\n");
    insertBeforeNode(&head, head, -1);
    traverse(head);
    printf("Insert 100 before head->next->next\n");
    insertBeforeNode(&head, head->next->next, 100);
    traverse(head);
    printf("Delete the front node.\n");
    deleteAtFront(&head);
    traverse(head);
    printf("Delete the last node\n");
    deleteAtLast(&head);
    traverse(head);
    printf("Delete the second node from the front.\n");
    deleteAtPosition(&head, 2);
    traverse(head);
    return 0;
}
