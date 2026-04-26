#include <stdio.h>

int main() {
    int n, at[20], bt[20], pr[20], ct[20], wt[20], tat[20], done[20]={0};
    int i, time=0, completed=0, idx, best;
    float awt=0, atat=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("AT BT PR: ");
        scanf("%d%d%d",&at[i],&bt[i],&pr[i]);
    }

    while(completed<n){
        best=9999; idx=-1;
        for(i=0;i<n;i++){
            if(at[i]<=time && !done[i] && pr[i]<best){
                best=pr[i];
                idx=i;
            }
        }

        if(idx==-1){
            time++;
        } else {
            time+=bt[idx];
            ct[idx]=time;
            done[idx]=1;
            completed++;
        }
    }

    for(i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        awt+=wt[i];
        atat+=tat[i];
    }

    printf("\nP AT BT PR CT TAT WT\n");
    for(i=0;i<n;i++)
        printf("%d %d %d %d %d %d %d\n",i+1,at[i],bt[i],pr[i],ct[i],tat[i],wt[i]);

    printf("Avg WT=%.2f\n",awt/n);
    printf("Avg TAT=%.2f\n",atat/n);

    return 0;
}
