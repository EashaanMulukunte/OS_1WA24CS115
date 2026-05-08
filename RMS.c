#include <stdio.h>

struct Task {
    int id;
    int burst;
    int period;
    int remaining;
};

int main() {
    int n, totalTime;

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    struct Task t[n];
    int gantt[100];

    // Input
    for (int i = 0; i < n; i++) {
        printf("\nTask %d\n", i + 1);

        t[i].id = i + 1;

        printf("Burst Time: ");
        scanf("%d", &t[i].burst);

        printf("Period: ");
        scanf("%d", &t[i].period);

        t[i].remaining = 0;
    }

    printf("\nEnter total simulation time: ");
    scanf("%d", &totalTime);

    // Rate Monotonic Scheduling
    for (int time = 0; time < totalTime; time++) {

        // Release tasks at start of each period
        for (int i = 0; i < n; i++) {
            if (time % t[i].period == 0) {
                t[i].remaining = t[i].burst;
            }
        }

        int idx = -1;
        int minPeriod = 9999;

        // Select task with smallest period
        for (int i = 0; i < n; i++) {
            if (t[i].remaining > 0 &&
                t[i].period < minPeriod) {

                minPeriod = t[i].period;
                idx = i;
            }
        }

        // Execute selected task
        if (idx != -1) {
            gantt[time] = t[idx].id;
            t[idx].remaining--;
        } else {
            gantt[time] = 0; // Idle
        }
    }

    // Gantt Chart
    printf("\nGantt Chart:\n\n|");

    for (int i = 0; i < totalTime; i++) {
        if (gantt[i] == 0)
            printf(" Idle |");
        else
            printf(" T%d |", gantt[i]);
    }

    printf("\n0");

    for (int i = 1; i <= totalTime; i++) {
        printf("     %d", i);
    }

    printf("\n");

    return 0;
}
