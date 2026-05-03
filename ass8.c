/*
====================================================================
DATA STRUCTURES LAB ASSIGNMENT
====================================================================

1. Write a C program to implement the Bubble Sort algorithm.
   (i) Input: An array of n integers.
   (ii) Output: Sorted array in ascending order.
   (iii) Requirements:
        • Display the array after each pass.
        • Count and display the total number of comparisons and swaps.

2. Write a C program to implement the Selection Sort algorithm.
   (i) Input: An array of n integers.
   (ii) Output: Sorted array in ascending order.
   (iii) Requirements:
        • Display the array after each pass.
        • Count and display the total number of comparisons and swaps.

3. Write a C program to implement the Insertion Sort algorithm.
   (i) Input: An array of n integers.
   (ii) Output: Sorted array in ascending order.
   (iii) Requirements:
        • Display the array after inserting each element.

4. Write a C program to implement the Merge Sort using recursion.
   (i) Input: An array of n integers.
   (ii) Output: Sorted array in ascending order.
   (iii) Requirements:
        • Clearly implement the divide and merge steps.

5. Write a C program to implement the Quick Sort using recursion.
   (i) Input: An array of n integers.
   (ii) Output: Sorted array in ascending order.
   (iii) Requirements:
        • Use any partitioning scheme.

6. Write a C program to perform Linear Search that finds all occurrences
   of a given element in an array.
   (i) Input: Array of size n and a key element.
   (ii) Output: All positions where the element occurs.
   (iii) If the element does not exist, display an appropriate message.

7. Write a C program to implement Binary Search using recursion.
   (i) Input a sorted array and a key value.
   (ii) Use a recursive function to perform the search.
   (iii) Return and display the index of the element if found.

====================================================================
COMBINED C PROGRAM FOR ALL QUESTIONS
====================================================================
*/

#include <stdio.h>

// -------------------- Utility Function --------------------
void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// ==================== Q1. Bubble Sort ====================
void bubbleSort(int arr[], int n) {
    int comparisons = 0, swaps = 0;

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            comparisons++;

            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
            }
        }

        printf("After Pass %d: ", i + 1);
        printArray(arr, n);
    }

    printf("Sorted Array: ");
    printArray(arr, n);

    printf("Total Comparisons = %d\n", comparisons);
    printf("Total Swaps = %d\n", swaps);
}

// ==================== Q2. Selection Sort ====================
void selectionSort(int arr[], int n) {
    int comparisons = 0, swaps = 0;

    for(int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for(int j = i + 1; j < n; j++) {
            comparisons++;

            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if(minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            swaps++;
        }

        printf("After Pass %d: ", i + 1);
        printArray(arr, n);
    }

    printf("Sorted Array: ");
    printArray(arr, n);

    printf("Total Comparisons = %d\n", comparisons);
    printf("Total Swaps = %d\n", swaps);
}

// ==================== Q3. Insertion Sort ====================
void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;

        printf("After inserting element %d: ", i + 1);
        printArray(arr, n);
    }

    printf("Sorted Array: ");
    printArray(arr, n);
}

// ==================== Q4. Merge Sort ====================
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for(int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;

        // Divide
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge
        merge(arr, left, mid, right);
    }
}

// ==================== Q5. Quick Sort ====================
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// ==================== Q6. Linear Search ====================
void linearSearch(int arr[], int n, int key) {
    int found = 0;

    printf("Element found at positions: ");

    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            printf("%d ", i);
            found = 1;
        }
    }

    if(!found) {
        printf("Element not found.");
    }

    printf("\n");
}

// ==================== Q7. Recursive Binary Search ====================
int binarySearch(int arr[], int low, int high, int key) {
    if(low > high)
        return -1;

    int mid = (low + high) / 2;

    if(arr[mid] == key)
        return mid;
    else if(arr[mid] > key)
        return binarySearch(arr, low, mid - 1, key);
    else
        return binarySearch(arr, mid + 1, high, key);
}

// ==================== Main Function ====================
int main() {
    int n, choice, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n], tempArr[n];

    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\n=========== MENU ===========\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("5. Quick Sort\n");
    printf("6. Linear Search\n");
    printf("7. Recursive Binary Search\n");
    printf("============================\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Copy original array
    for(int i = 0; i < n; i++) {
        tempArr[i] = arr[i];
    }

    switch(choice) {
        case 1:
            bubbleSort(tempArr, n);
            break;

        case 2:
            selectionSort(tempArr, n);
            break;

        case 3:
            insertionSort(tempArr, n);
            break;

        case 4:
            mergeSort(tempArr, 0, n - 1);
            printf("Sorted Array: ");
            printArray(tempArr, n);
            break;

        case 5:
            quickSort(tempArr, 0, n - 1);
            printf("Sorted Array: ");
            printArray(tempArr, n);
            break;

        case 6:
            printf("Enter element to search: ");
            scanf("%d", &key);
            linearSearch(arr, n, key);
            break;

        case 7:
            printf("Enter element to search: ");
            scanf("%d", &key);

            // Sort before Binary Search
            mergeSort(tempArr, 0, n - 1);

            printf("Sorted Array for Binary Search: ");
            printArray(tempArr, n);

            int result = binarySearch(tempArr, 0, n - 1, key);

            if(result != -1)
                printf("Element found at index %d\n", result);
            else
                printf("Element not found.\n");

            break;

        default:
            printf("Invalid Choice!\n");
    }

    return 0;
}
