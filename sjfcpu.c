#include <stdio.h>

int main() {
    int n, at[20], bt[20], ct[20], wt[20], tat[20], done[20]={0};
    int i, j, time=0, completed=0, min, idx;
    float awt=0, atat=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("AT BT: ");
        scanf("%d%d",&at[i],&bt[i]);
    }

    while(completed<n){
        min=9999; idx=-1;
        for(i=0;i<n;i++){
            if(at[i]<=time && !done[i] && bt[i]<min){
                min=bt[i];
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

    printf("\nP AT BT CT TAT WT\n");
    for(i=0;i<n;i++)
        printf("%d %d %d %d %d %d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);

    printf("Avg WT=%.2f\n",awt/n);
    printf("Avg TAT=%.2f\n",atat/n);

    return 0;
}
