#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Record {
    int id;
    char name[50];
};
int main() {
    struct Record *rec = NULL;
    int n = 0, choice, i, del, found;
    while(1) {
        printf("\n1.Add  2.Display  3.Delete  4.Exit\n");
        scanf("%d",&choice);
        switch(choice) {
        case 1:
            rec = realloc(rec, (n+1)*sizeof(struct Record));
            printf("Enter ID and Name: ");
            scanf("%d %s",&rec[n].id,rec[n].name);
            n++;
            break;
        case 2:
            for(i=0;i<n;i++)
                printf("%d %s\n",rec[i].id,rec[i].name);
            break;
        case 3:
            printf("Enter ID to delete: ");
            scanf("%d",&del);
            found=0;
            for(i=0;i<n;i++){
                if(rec[i].id==del){
                    rec[i]=rec[n-1];
                    n--;
                    rec=realloc(rec,n*sizeof(struct Record));
                    found=1;
                    break;
                }
            }
            if(!found) printf("Record not found\n");
            break;
        case 4:
            free(rec);
            printf("Memory freed. Exit.\n");
            return 0;
        }
    }
}
