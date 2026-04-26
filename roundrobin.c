#include <stdio.h>

int main() {
    int n, at[20], bt[20], rem[20], ct[20], wt[20], tat[20];
    int i, tq, time=0, done;
    float awt=0, atat=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("AT BT: ");
        scanf("%d%d",&at[i],&bt[i]);
        rem[i]=bt[i];
    }

    printf("Enter time quantum: ");
    scanf("%d",&tq);

    do{
        done=1;
        for(i=0;i<n;i++){
            if(rem[i]>0 && at[i]<=time){
                done=0;
                if(rem[i]>tq){
                    time+=tq;
                    rem[i]-=tq;
                } else {
                    time+=rem[i];
                    ct[i]=time;
                    rem[i]=0;
                }
            }
        }
        for(i=0;i<n;i++){
            if(rem[i]>0 && at[i]>time)
                time=at[i];
        }
    }while(!done);

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
