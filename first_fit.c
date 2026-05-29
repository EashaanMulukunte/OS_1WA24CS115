#include <stdio.h>

int main()
{
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};

    int blocks = 5, processes = 4;
    int allocation[4];
    int i, j;

    for(i = 0; i < processes; i++)
        allocation[i] = -1;

    for(i = 0; i < processes; i++)
    {
        for(j = 0; j < blocks; j++)
        {
            if(blockSize[j] >= processSize[i])
            {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    printf("FIRST FIT MEMORY ALLOCATION\n");
    printf("Process\tSize\tBlock\n");

    for(i = 0; i < processes; i++)
    {
        printf("P%d\t%d\t", i + 1, processSize[i]);

        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
