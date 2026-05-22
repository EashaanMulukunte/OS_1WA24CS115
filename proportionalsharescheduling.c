#include <stdio.h>

int main() {
    int n;
    float totalTickets = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], tickets[n];
    float probability[n];

    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;

        printf("Enter tickets (weight) for Process %d: ", pid[i]);
        scanf("%d", &tickets[i]);

        totalTickets += tickets[i];
    }

    for (int i = 0; i < n; i++) {
        probability[i] = tickets[i] / totalTickets;
    }

    printf("\nProportional Scheduling Probabilities\n");
    printf("--------------------------------------\n");
    printf("PID\tTickets\tProbability\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%.3f\n",
               pid[i],
               tickets[i],
               probability[i]);
    }

    return 0;
}
