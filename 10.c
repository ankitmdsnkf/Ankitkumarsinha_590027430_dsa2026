#include <stdio.h>
#include <stdlib.h>

struct Student {
    int id;
    char name[50];
    float marks;
};
int main() {
    int n,i,j;
    struct Student *s,temp;
    printf("Enter number of students: ");
    scanf("%d",&n);
    s = (struct Student*)malloc(n*sizeof(struct Student));
    for(i=0;i<n;i++){
        printf("\nEnter ID Name Marks: ");
        scanf("%d %s %f",&s[i].id,s[i].name,&s[i].marks);
    }
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(s[i].marks > s[j].marks){
                temp=s[i];
                s[i]=s[j];
                s[j]=temp;
            }
        }
    }
    printf("\nSorted Students:\n");
    for(i=0;i<n;i++)
        printf("%d %s %.2f\n",s[i].id,s[i].name,s[i].marks);
    free(s);
    return 0;
}
