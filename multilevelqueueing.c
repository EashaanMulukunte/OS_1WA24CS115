#include <stdio.h>

int main() {
    int i, ns, nu;

    printf("Enter number of system processes: ");
    scanf("%d", &ns);

    int sys[ns];
    printf("Enter burst times:\n");
    for (i = 0; i < ns; i++)
        scanf("%d", &sys[i]);

    printf("Enter number of user processes: ");
    scanf("%d", &nu);

    int user[nu];
    printf("Enter burst times:\n");
    for (i = 0; i < nu; i++)
        scanf("%d", &user[i]);

    int time = 0;
    float total_wt = 0, total_tat = 0;

    printf("\nProcess\tBT\tWT\tTAT\n");

    for (i = 0; i < ns; i++) {
        int wt = time;
        int tat = wt + sys[i];
        printf("S%d\t%d\t%d\t%d\n", i + 1, sys[i], wt, tat);

        total_wt += wt;
        total_tat += tat;

        time += sys[i];
    }

    for (i = 0; i < nu; i++) {
        int wt = time;
        int tat = wt + user[i];
        printf("U%d\t%d\t%d\t%d\n", i + 1, user[i], wt, tat);

        total_wt += wt;
        total_tat += tat;

        time += user[i];
    }

    int total_processes = ns + nu;

    printf("\nAverage Waiting Time = %.2f\n", total_wt / total_processes);
    printf("Average Turnaround Time = %.2f\n", total_tat / total_processes);

    printf("\nGantt Chart:\n|");

    for (i = 0; i < ns; i++)
        printf(" S%d |", i + 1);

    for (i = 0; i < nu; i++)
        printf(" U%d |", i + 1);

    printf("\n0");
    time = 0;

    for (i = 0; i < ns; i++) {
        time += sys[i];
        printf("   %d", time);
    }

    for (i = 0; i < nu; i++) {
        time += user[i];
        printf("   %d", time);
    }

    printf("\n");

    return 0;
}
