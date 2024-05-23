#include <stdio.h>
#include <stdbool.h>

void findCompletionTime(int processes[], int n, int bt[], int at[], int wt[], int tat[], int ct[], int rt[], int priority[], bool isLowerPriorityHigher)
{
    int remaining[n];
    int currentTime = 0;
    int completed = 0;
    bool isFinished[n];

    for (int i = 0; i < n; i++) {
        remaining[i] = bt[i];
        isFinished[i] = false;
        rt[i] = -1;
    }
    while (completed < n) {
        int highestPriorityIndex = -1;
        int highestPriority = isLowerPriorityHigher ? 1000000 : -1;


        for (int i = 0; i < n; i++) {
            if (at[i] <= currentTime && !isFinished[i] &&
                ((isLowerPriorityHigher && priority[i] < highestPriority) ||
                 (!isLowerPriorityHigher && priority[i] > highestPriority))) {
                highestPriority = priority[i];
                highestPriorityIndex = i;
            }        }

        if (highestPriorityIndex == -1) {
            currentTime++;
            continue;
        }
        int currentProcess = highestPriorityIndex;

        if (rt[currentProcess] == -1) {
            rt[currentProcess] = currentTime - at[currentProcess];
        }

        remaining[currentProcess]--;
        currentTime++;

        if (remaining[currentProcess] == 0) {
            isFinished[currentProcess] = true;
            completed++;
            ct[currentProcess] = currentTime;
            tat[currentProcess] = ct[currentProcess] - at[currentProcess];
            wt[currentProcess] = tat[currentProcess] - bt[currentProcess];
        }    }

    printf("Process\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\tResponse Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i], at[i], bt[i], priority[i], ct[i], tat[i], wt[i], rt[i]);
    }}
void main()
{

    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n];
    int burst_time[n];
    int arrival_time[n];
    int priority[n];
    int priorityType;
    bool isLowerPriorityHigher;

    printf("Enter 1 if lower number indicates higher priority, 0 if higher number indicates higher priority: ");
    scanf("%d", &priorityType);
    isLowerPriorityHigher = (priorityType == 1);

    printf("Enter Process Number:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &processes[i]);
    }
    printf("Enter Priority:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &priority[i]);
    }
    printf("Enter Arrival Time:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arrival_time[i]);
    }
    printf("Enter Burst Time:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &burst_time[i]);
    }

    int wt[n], tat[n], ct[n], rt[n];
    printf("\nPriority Scheduling (Preemptive):\n");
    findCompletionTime(processes, n, burst_time, arrival_time, wt, tat, ct, rt, priority, isLowerPriorityHigher);
}

