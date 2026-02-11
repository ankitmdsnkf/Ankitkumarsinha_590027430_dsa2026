#include<stdio.h>
#include<stdlib.h>

int main(){
    int *arr;
    int n,r;

    printf("Enter number of elements: ");
    scanf("%d",&n);

   
    arr = (int *)malloc(n * sizeof(int));

    if(arr == NULL){
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter elements:\n");
    for(r = 0; r < n; r++){
        scanf("%d",&arr[r]);
    }

    printf("Array elements are:\n");
    for(r = 0; r < n; r++){
        printf("%d ",arr[r]);
    }

    free(arr);
    printf("\nMemory freed successfully.\n");

    return 0;
}
