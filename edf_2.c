#include <stdio.h>

struct Task {
    int at, bt, dl, rt;
};

int main() {
    int n, time = 0, done = 0, g[100];

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    struct Task t[n];

    // Input
    for (int i = 0; i < n; i++) {
        printf("\nTask %d\n", i + 1);

        printf("Arrival Time: ");
        scanf("%d", &t[i].at);

        printf("Burst Time: ");
        scanf("%d", &t[i].bt);

        printf("Deadline: ");
        scanf("%d", &t[i].dl);

        t[i].rt = t[i].bt;
    }

    // EDF Scheduling
    while (done < n) {
        int idx = -1, min = 9999;

        for (int i = 0; i < n; i++) {
            if (t[i].at <= time && t[i].rt > 0 && t[i].dl < min) {
                min = t[i].dl;
                idx = i;
            }
        }

        if (idx != -1) {
            g[time] = idx + 1;
            t[idx].rt--;

            if (t[idx].rt == 0)
                done++;
        } else {
            g[time] = 0;
        }

        time++;
    }

    // Gantt Chart
    printf("\nGantt Chart:\n\n|");

    for (int i = 0; i < time; i++) {
        if (g[i] == 0)
            printf(" Idle |");
        else
            printf(" T%d |", g[i]);
    }

    printf("\n0");

    for (int i = 1; i <= time; i++)
        printf("     %d", i);

    printf("\n");

    return 0;
}
