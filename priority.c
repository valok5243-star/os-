#include <stdio.h>

int main() {
    int n, bt[20], pr[20], wt[20], tat[20];
    int i, j, temp;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter burst time: ");
        scanf("%d", &bt[i]);
        printf("Enter priority: ");
        scanf("%d", &pr[i]);
    }

    for(i = 0; i < n; i++) {
        for(j = i+1; j < n; j++) {
            if(pr[i] > pr[j]) {
                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }

    wt[0] = 0;

    for(i = 1; i < n; i++)
        wt[i] = wt[i-1] + bt[i-1];

    for(i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];

    printf("\nProcess\tBT\tPR\tWT\tTAT\n");
    for(i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\n", i+1, bt[i], pr[i], wt[i], tat[i]);

    return 0;
}
