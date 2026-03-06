#include <stdio.h>

struct pr
{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};
int main()
{
    struct pr p[100],temp;
    int n,time = 0;
    printf("Enter no. of processes: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("\nEnter PID of process %d: ",i+1);
        scanf("%d", &p[i].pid);
        printf("Enter Arrival Time: ");
        scanf("%d", &p[i].at);
        printf("Enter Burst Time: ");
        scanf("%d", &p[i].bt);
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(p[i].at > p[j].at)
            {
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(time < p[i].at)
            time = p[i].at;

        p[i].ct = time + p[i].bt;
        time = p[i].ct;

        p[i].tat = p[i].ct-p[i].at;
        p[i].wt = p[i].tat-p[i].bt;
    }
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for(int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
        p[i].pid, p[i].at, p[i].bt,
        p[i].ct, p[i].tat, p[i].wt);
    }
    return 0;
}
