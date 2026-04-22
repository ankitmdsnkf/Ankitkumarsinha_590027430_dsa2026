#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insertBST(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insertBST(root->left, value);
    else if (value > root->data)
        root->right = insertBST(root->right, value);
    else
        printf("Duplicate not allowed\n");

    return root;
}

struct Node* findMin(struct Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct Node* deleteBST(struct Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteBST(root->left, key);
    else if (key > root->data)
        root->right = deleteBST(root->right, key);
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        else if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right, temp->data);
    }
    return root;
}

void searchBST(struct Node* root, int key) {
    if (root == NULL) {
        printf("Element not found\n");
        return;
    }
    if (root->data == key) {
        printf("Element found\n");
        return;
    }
    if (key < root->data)
        searchBST(root->left, key);
    else
        searchBST(root->right, key);
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int index) {
    while (index > 0 && heap[(index - 1)/2] > heap[index]) {
        swap(&heap[(index - 1)/2], &heap[index]);
        index = (index - 1)/2;
    }
}

void insertHeap(int value) {
    heap[size] = value;
    heapifyUp(size);
    size++;
}

void heapifyDown(int index) {
    int smallest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(smallest);
    }
}

void deleteHeap() {
    if (size == 0) {
        printf("Heap empty\n");
        return;
    }
    printf("Deleted: %d\n", heap[0]);
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
}

void displayHeap() {
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

struct PQNode {
    int value;
    int priority;
};

struct PQNode pq[MAX];
int pqSize = 0;

void swapPQ(struct PQNode *a, struct PQNode *b) {
    struct PQNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUpPQ(int index) {
    while (index > 0 && pq[(index-1)/2].priority > pq[index].priority) {
        swapPQ(&pq[(index-1)/2], &pq[index]);
        index = (index-1)/2;
    }
}

void insertPQ(int value, int priority) {
    pq[pqSize].value = value;
    pq[pqSize].priority = priority;
    heapifyUpPQ(pqSize);
    pqSize++;
}

void heapifyDownPQ(int index) {
    int smallest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;

    if (left < pqSize && pq[left].priority < pq[smallest].priority)
        smallest = left;

    if (right < pqSize && pq[right].priority < pq[smallest].priority)
        smallest = right;

    if (smallest != index) {
        swapPQ(&pq[index], &pq[smallest]);
        heapifyDownPQ(smallest);
    }
}

void deletePQ() {
    if (pqSize == 0) {
        printf("Queue empty\n");
        return;
    }
    printf("Removed: %d\n", pq[0].value);
    pq[0] = pq[pqSize - 1];
    pqSize--;
    heapifyDownPQ(0);
}

void peekPQ() {
    if (pqSize == 0)
        printf("Queue empty\n");
    else
        printf("Top: %d\n", pq[0].value);
}

void displayPQ() {
    for (int i = 0; i < pqSize; i++)
        printf("(Val:%d, Pri:%d) ", pq[i].value, pq[i].priority);
    printf("\n");
}

int main() {
    int choice, sub, val, key, pri;
    struct Node* root = NULL;

    while (1) {
        printf("\n1.BST  2.Heap  3.Priority Queue  4.Exit\n");
        scanf("%d", &choice);

        switch(choice) {
        case 1:
            printf("\n1.Insert 2.Delete 3.Search 4.Traversal\n");
            scanf("%d", &sub);
            if (sub == 1) {
                printf("Enter value: ");
                scanf("%d", &val);
                root = insertBST(root, val);
            }
            else if (sub == 2) {
                printf("Enter key: ");
                scanf("%d", &key);
                root = deleteBST(root, key);
            }
            else if (sub == 3) {
                printf("Enter key: ");
                scanf("%d", &key);
                searchBST(root, key);
            }
            else if (sub == 4) {
                inorder(root);
                printf("\n");
            }
            break;

        case 2:
            printf("\n1.Insert 2.Delete Root 3.Display\n");
            scanf("%d", &sub);
            if (sub == 1) {
                printf("Enter value: ");
                scanf("%d", &val);
                insertHeap(val);
            }
            else if (sub == 2) {
                deleteHeap();
            }
            else if (sub == 3) {
                displayHeap();
            }
            break;

        case 3:
            printf("\n1.Insert 2.Delete 3.Peek 4.Display\n");
            scanf("%d", &sub);
            if (sub == 1) {
                printf("Enter value & priority: ");
                scanf("%d %d", &val, &pri);
                insertPQ(val, pri);
            }
            else if (sub == 2) {
                deletePQ();
            }
            else if (sub == 3) {
                peekPQ();
            }
            else if (sub == 4) {
                displayPQ();
            }
            break;

        case 4:
            exit(0);
        }
    }
}
