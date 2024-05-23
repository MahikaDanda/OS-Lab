#include<stdio.h>

void findCompletionTime(int processes[], int n, int bt[], int at[], int wt[], int tat[], int rt[], int ct[])
{
    int completion[n];
    int remaining[n];

    for (int i = 0; i < n; i++)
        remaining[i] = bt[i];

    int currentTime = 0;

    for (int i = 0; i < n; i++)
    {
        int shortest = -1;
        for (int j = 0; j < n; j++)
        {
            if (at[j] <= currentTime && remaining[j] > 0)
            {
                if (shortest == -1 || remaining[j] < remaining[shortest])
                    shortest = j;
            }
        }

        if (shortest == -1)
        {
            currentTime++;
            continue;
        }

        completion[shortest] = currentTime + remaining[shortest];
        currentTime = completion[shortest];
        wt[shortest] = currentTime - bt[shortest] - at[shortest];
        tat[shortest] = currentTime - at[shortest];
        rt[shortest] = wt[shortest];
        remaining[shortest] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        ct[i] = completion[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], at[i], bt[i], ct[i], wt[i], tat[i], rt[i]);
    }
    float avg_tat = 0, avg_wt = 0;
    for (int i = 0; i < n; i++)
    {
        avg_tat += tat[i];
        avg_wt += wt[i];
    }
    avg_tat /= n;
    avg_wt /= n;
    printf("The average Turnaround time is %f\n", avg_tat);
    printf("The average Waiting time is %f\n", avg_wt);
}

void main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n];
    int burst_time[n];
    int arrival_time[n];

    printf("Enter Process Number:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &processes[i]);
    }
    printf("Enter Arrival Time:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arrival_time[i]);
    }
    printf("Enter Burst Time:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &burst_time[i]);
    }

    int wt[n], tat[n], rt[n], ct[n];

    for (int i = 0; i < n; i++)
        rt[i] = -1;

    printf("\nSJF (Non-preemptive) Scheduling:\n");
    findCompletionTime(processes, n, burst_time, arrival_time, wt, tat, rt, ct);
}
