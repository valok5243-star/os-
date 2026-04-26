#include <stdio.h>

int main() {
    int n, at[20], bt[20], ct[20], wt[20], tat[20];
    int i;
    float awt=0, atat=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("AT BT: ");
        scanf("%d%d",&at[i],&bt[i]);
    }

    ct[0]=at[0]+bt[0];

    for(i=1;i<n;i++){
        if(ct[i-1]<at[i])
            ct[i]=at[i]+bt[i];
        else
            ct[i]=ct[i-1]+bt[i];
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
