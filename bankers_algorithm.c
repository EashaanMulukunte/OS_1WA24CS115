#include <stdio.h>

int main() {
    int p, r, i, j, k;

    printf("Enter processes and resources: ");
    scanf("%d %d", &p, &r);

    int alloc[p][r], max[p][r], need[p][r], avail[r];
    int finish[p], safe[p];

    printf("Enter Allocation Matrix:\n");
    for(i=0;i<p;i++)
        for(j=0;j<r;j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Max Matrix:\n");
    for(i=0;i<p;i++)
        for(j=0;j<r;j++)
            scanf("%d", &max[i][j]);

    printf("Enter Available Resources:\n");
    for(i=0;i<r;i++)
        scanf("%d", &avail[i]);

    // Calculate Need matrix
    for(i=0;i<p;i++)
        for(j=0;j<r;j++)
            need[i][j] = max[i][j] - alloc[i][j];

    for(i=0;i<p;i++)
        finish[i] = 0;

    int count = 0;

    while(count < p) {
        int found = 0;

        for(i=0;i<p;i++) {
            if(finish[i] == 0) {

                for(j=0;j<r;j++)
                    if(need[i][j] > avail[j])
                        break;

                if(j == r) {
                    for(k=0;k<r;k++)
                        avail[k] += alloc[i][k];

                    safe[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0) {
            printf("System is NOT in safe state\n");
            return 0;
        }
    }

    printf("Safe Sequence: ");
    for(i=0;i<p;i++)
        printf("P%d ", safe[i]);

    return 0;
}
