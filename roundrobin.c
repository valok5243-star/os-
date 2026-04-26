#include <stdio.h>

int main() {
    int n, bt[20], rem[20], wt[20], tat[20];
    int i, tq, time = 0, done;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter burst time: ");
        scanf("%d", &bt[i]);
        rem[i] = bt[i];
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    do {
        done = 1;
        for(i = 0; i < n; i++) {
            if(rem[i] > 0) {
                done = 0;
                if(rem[i] > tq) {
                    time += tq;
                    rem[i] -= tq;
                } else {
                    time += rem[i];
                    wt[i] = time - bt[i];
                    rem[i] = 0;
                }
            }
        }
    } while(!done);

    for(i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];

    printf("\nProcess\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);

    return 0;
}
