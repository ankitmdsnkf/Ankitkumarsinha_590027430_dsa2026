#include<stdio.h>
#include<stdlib.h>

int main(){
    int *arr;
    int n,i;
    int sum = 0;
    float avg;

    printf("Enter number of elements: ");
    scanf("%d",&n);
    arr = (int*) malloc(n * sizeof(int));

    if(arr == NULL) {
        printf("Memory allocation failed!");
        return 1;
    }
    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Array elements are:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        sum += arr[i];
    }
    avg = (float)sum / n;

    printf("\nSum = %d", sum);
    printf("\nAverage = %.2f", avg);

    free(arr);

    return 0;
}


  