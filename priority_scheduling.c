#include <stdio.h>

struct Process {
    int pid;
    int bt;
    int priority;
    int wt;
    int tat;
};

void sortProcesses(struct Process p[], int n) {
    struct Process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            if (p[j].priority > p[j+1].priority) {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

int main() {
    int n;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Burst Time and Priority for Process %d: ", i + 1);
        scanf("%d %d", &p[i].bt, &p[i].priority);
    }

    sortProcesses(p, n);

    p[0].wt = 0;
    for (int i = 1; i < n; i++) {
        p[i].wt = p[i-1].wt + p[i-1].bt;
        avg_wt += p[i].wt;
    }

    for (int i = 0; i < n; i++) {
        p[i].tat = p[i].bt + p[i].wt;
        avg_tat += p[i].tat;
    }

    printf("\nProcess\tBT\tPriority\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t\t%d\t%d\n", p[i].pid, p[i].bt, p[i].priority, p[i].wt, p[i].tat);
    }

    printf("\nAverage Waiting Time: %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat / n);

    return 0;
}
