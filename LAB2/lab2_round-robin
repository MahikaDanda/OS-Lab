#include <stdio.h>

int main() {
    int n;
    int time, gantt[100];
    char pid[10];
    int readyqueue[100];
    int at[10], bt[10], bt1[10];
    int ct[10], tat[10], wt[10];
    float avgTurnaroundTime = 0, avgWaitingTime = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("\nEnter the process IDs: ");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &pid[i]);
    }

    printf("Enter the arrival times: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }

    printf("Enter the burst times: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        bt1[i] = bt[i];
    }

    printf("Enter the time quantum: ");
    scanf("%d", &time);

    // Initialize completion times to 0
    for (int i = 0; i < n; i++) {
        ct[i] = 0;
    }

    int least = 0;
    for (int i = 1; i < n; i++) {
        if (at[i] < at[least])
            least = i;
    }

    int f = 0, r = 0, i = 0, curr_time = 0;
    readyqueue[r++] = least;

    while (f < r) {
        int a = readyqueue[f];
        if (bt[a] > time) {
            gantt[i++] = pid[a]; // Store process ID in Gantt chart
            curr_time += time;
            bt[a] -= time;
        } else if (bt[a] > 0) {
            gantt[i++] = pid[a]; // Store process ID in Gantt chart
            curr_time += bt[a];
            ct[a] = curr_time;
            bt[a] = 0;
        }

        for (int k = 0; k < n; k++) {
            if (bt[k] > 0 && at[k] <= curr_time && k != a) {
                int alreadyInQueue = 0;
                for (int j = f; j < r; j++) {
                    if (readyqueue[j] == k) {
                        alreadyInQueue = 1;
                        break;
                    }
                }
                if (!alreadyInQueue) {
                    readyqueue[r++] = k;
                }
            }
        }

        if (bt[a] > 0) {
            readyqueue[r++] = a;
        }

        f++;

        if (i >= 100) // Prevent buffer overflow
            break;
    }

    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt1[i];
        avgTurnaroundTime += tat[i];
        avgWaitingTime += wt[i];
    }

    avgTurnaroundTime /= n;
    avgWaitingTime /= n;

    printf("\nProcess\t Arrival Time\t Burst Time\t Completion Time\t Turnaround Time\t Waiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%c\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n", pid[i], at[i], bt1[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time: %.2f", avgTurnaroundTime);
    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime);

    printf("\nGantt Chart: ");
    for (int j = 0; j < i; j++) {
        printf("%c ", gantt[j]);
    }
    printf("\n");

    return 0;
}
