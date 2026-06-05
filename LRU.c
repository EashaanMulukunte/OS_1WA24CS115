#include <stdio.h>

int main()
{
    int pages[50], frames[10], recent[10];
    int n, f, i, j;
    int faults = 0, found, pos, min;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
    {
        frames[i] = -1;
        recent[i] = -1;
    }

    for(i = 0; i < n; i++)
    {
        found = 0;

        for(j = 0; j < f; j++)
        {
            if(frames[j] == pages[i])
            {
                found = 1;
                recent[j] = i;
                break;
            }
        }

        if(!found)
        {
            min = recent[0];
            pos = 0;

            for(j = 1; j < f; j++)
            {
                if(recent[j] < min)
                {
                    min = recent[j];
                    pos = j;
                }
            }

            frames[pos] = pages[i];
            recent[pos] = i;
            faults++;
        }
    }

    printf("Page Faults = %d\n", faults);

    return 0;
}