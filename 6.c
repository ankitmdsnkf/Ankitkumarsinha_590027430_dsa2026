#include <stdio.h>
#include <stdlib.h>
struct employee {
    int id;
    char name[50];
    float salary;
};
int main() {
    int n, i, max = 0;
    printf("Enter number of employees: ");
    scanf("%d", &n);
    struct employee *e;
    e = (struct employee *)malloc(n * sizeof(struct employee));

    if(e == NULL) {
        printf("Memory allocation failed");
        return 1;
    }
    for(i = 0; i < n; i++) {
        printf("\nEnter details of employee %d\n", i + 1);
        printf("ID: ");
        scanf("%d", &e[i].id);
        printf("Name: ");
        scanf("%s", e[i].name);
        printf("Salary: ");
        scanf("%f", &e[i].salary);
    }
    for(i = 1; i < n; i++) {
        if(e[i].salary > e[max].salary) {
            max = i;
        }
    }
    printf("\nEmployee with highest salary:\n");
    printf("ID: %d\n", e[max].id);
    printf("Name: %s\n", e[max].name);
    printf("Salary: %.2f\n", e[max].salary);
    free(e); 
    return 0;
}
