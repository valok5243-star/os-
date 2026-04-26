#include <stdio.h>

int main() {
    int n, bt[20], wt[20], tat[20];
    int i;
    float awt = 0, atat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i+1);
        scanf("%d", &bt[i]);
    }

    wt[0] = 0;

    for(i = 1; i < n; i++)
        wt[i] = wt[i-1] + bt[i-1];

    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        awt += wt[i];
        atat += tat[i];
    }

    printf("\nProcess\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);

    printf("\nAvg WT = %.2f", awt/n);
    printf("\nAvg TAT = %.2f\n", atat/n);

    return 0;
}
