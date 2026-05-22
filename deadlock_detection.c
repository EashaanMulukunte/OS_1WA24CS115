#include <stdio.h>

int main() {
    int p, r, i, j, k;

    printf("Enter number of processes and resources: ");
    scanf("%d %d", &p, &r);

    int alloc[p][r], req[p][r], avail[r];
    int finish[p];

    printf("Enter Allocation Matrix:\n");
    for(i = 0; i < p; i++)
        for(j = 0; j < r; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Request Matrix:\n");
    for(i = 0; i < p; i++)
        for(j = 0; j < r; j++)
            scanf("%d", &req[i][j]);

    printf("Enter Available Resources:\n");
    for(i = 0; i < r; i++)
        scanf("%d", &avail[i]);

    for(i = 0; i < p; i++)
        finish[i] = 0;

    int done;

    do {
        done = 0;

        for(i = 0; i < p; i++) {

            if(finish[i] == 0) {

                for(j = 0; j < r; j++) {
                    if(req[i][j] > avail[j])
                        break;
                }

                if(j == r) {

                    for(k = 0; k < r; k++)
                        avail[k] += alloc[i][k];

                    finish[i] = 1;
                    done = 1;
                }
            }
        }

    } while(done);

    int deadlock = 0;

    for(i = 0; i < p; i++) {
        if(finish[i] == 0) {
            printf("Process P%d is in Deadlock\n", i);
            deadlock = 1;
        }
    }

    if(deadlock == 0)
        printf("No Deadlock Detected\n");

    return 0;
}
