#include <stdio.h>
#include <stdlib.h>

/* ================= Q1 =================
Write a C program to create a binary tree using an array.
Operations:
- Insert elements
- Display elements
- Display parent, left child, right child
*/

int tree[100];
int n = 0;

void insertArray(int value) {
    tree[n++] = value;
}

void displayArray() {
    for(int i = 0; i < n; i++) {
        printf("%d ", tree[i]);
    }
    printf("\n");
}

void relations(int index) {
    if(index >= n) {
        printf("Invalid node\n");
        return;
    }

    printf("Node: %d\n", tree[index]);

    if(index == 0)
        printf("No Parent\n");
    else
        printf("Parent: %d\n", tree[(index - 1)/2]);

    if(2*index + 1 < n)
        printf("Left Child: %d\n", tree[2*index + 1]);
    else
        printf("No Left Child\n");

    if(2*index + 2 < n)
        printf("Right Child: %d\n", tree[2*index + 2]);
    else
        printf("No Right Child\n");
}

/* ================= Q2 =================
Write a C program to create a binary tree using linked list.
Functions:
- Count total nodes
- Count leaf nodes
- Find height
*/

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* create(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int countNodes(struct Node* root) {
    if(root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countLeaf(struct Node* root) {
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    return countLeaf(root->left) + countLeaf(root->right);
}

int height(struct Node* root) {
    if(root == NULL) return 0;
    int l = height(root->left);
    int r = height(root->right);
    return (l > r ? l : r) + 1;
}

/* ================= Q3 =================
Recursive Traversals:
- Inorder
- Preorder
- Postorder
*/

void inorderRec(struct Node* root) {
    if(root == NULL) return;
    inorderRec(root->left);
    printf("%d ", root->data);
    inorderRec(root->right);
}

void preorderRec(struct Node* root) {
    if(root == NULL) return;
    printf("%d ", root->data);
    preorderRec(root->left);
    preorderRec(root->right);
}

void postorderRec(struct Node* root) {
    if(root == NULL) return;
    postorderRec(root->left);
    postorderRec(root->right);
    printf("%d ", root->data);
}

/* ================= Q4 =================
Level Order Traversal using Queue
*/

struct Node* queue[100];
int front = 0, rear = 0;

void enqueue(struct Node* n) {
    queue[rear++] = n;
}

struct Node* dequeue() {
    return queue[front++];
}

void levelOrder(struct Node* root) {
    front = rear = 0;
    enqueue(root);

    while(front < rear) {
        struct Node* temp = dequeue();
        printf("%d ", temp->data);

        if(temp->left) enqueue(temp->left);
        if(temp->right) enqueue(temp->right);
    }
}

/* ================= Q5 =================
Non-Recursive Traversals using Stack:
- Inorder
- Preorder
*/

struct Node* stack[100];
int top = -1;

void push(struct Node* n) {
    stack[++top] = n;
}

struct Node* pop() {
    return stack[top--];
}

void inorderNonRec(struct Node* root) {
    struct Node* curr = root;
    top = -1;

    while(curr != NULL || top != -1) {
        while(curr != NULL) {
            push(curr);
            curr = curr->left;
        }
        curr = pop();
        printf("%d ", curr->data);
        curr = curr->right;
    }
}

void preorderNonRec(struct Node* root) {
    top = -1;
    push(root);

    while(top != -1) {
        struct Node* curr = pop();
        printf("%d ", curr->data);

        if(curr->right) push(curr->right);
        if(curr->left) push(curr->left);
    }
}

/* ================= MAIN FUNCTION ================= */

int main() {

    printf("---- Q1: Array Tree ----\n");
    insertArray(10);
    insertArray(20);
    insertArray(30);
    insertArray(40);
    insertArray(50);
    displayArray();
    relations(1);

    printf("\n---- Q2: Linked List Tree ----\n");
    struct Node* root = create(10);
    root->left = create(20);
    root->right = create(30);
    root->left->left = create(40);
    root->left->right = create(50);

    printf("Total Nodes: %d\n", countNodes(root));
    printf("Leaf Nodes: %d\n", countLeaf(root));
    printf("Height: %d\n", height(root));

    printf("\n---- Q3: Recursive Traversals ----\n");
    printf("Inorder: ");
    inorderRec(root);
    printf("\nPreorder: ");
    preorderRec(root);
    printf("\nPostorder: ");
    postorderRec(root);

    printf("\n\n---- Q4: Level Order ----\n");
    levelOrder(root);

    printf("\n\n---- Q5: Non-Recursive ----\n");
    printf("Inorder: ");
    inorderNonRec(root);
    printf("\nPreorder: ");
    preorderNonRec(root);

    return 0;
}
