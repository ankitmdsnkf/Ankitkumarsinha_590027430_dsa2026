#include<stdio.h>
#include<stdlib.h>

int main(){
    int *arr,n,i;
    int largest,smallest;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    arr = (int *)malloc(n * sizeof(int));

    if(arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter elements:\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    largest = smallest = arr[0];

    for(i=1;i<n;i++){
        if(arr[i] > largest)
            largest = arr[i];
        if(arr[i] < smallest)
            smallest = arr[i];
    }

    printf("Largest element = %d\n", largest);
    printf("Smallest element = %d\n", smallest);

    free(arr);

    return 0;
}
