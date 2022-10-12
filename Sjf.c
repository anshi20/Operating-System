#include<stdio.h>
#include<stdlib.h>
typedef struct pro
{
    int pid, at;
    int bt;
    int st;
    int ct;
    int tat;
    int wt, rt;
}process;
int cmpfunc(const void *p1, const void *p2)
{
   int a = ((process *)p1)->bt;
   int b = ((process *)p2)->bt;
   int x = ((process *)p1)->pid;
   int y = ((process *)p2)->pid;
   if (a <= b && x < y){
      return -1;
   }
   else{
      return 1;
   }
}

int main()
{
    int i,n;
    printf("\nAnshika Maheshwari      Sec : A    Std ID : 20012553\n\n");
    printf("Enter no. of processes : ");
    scanf("%d",&n);
    process p[n];
    for(i=0;i<n;i++){
    printf("\nEnter arrival time of process %d : ",i+1);
    scanf("%d",&p[i].at);
    printf("Enter burst time of process %d : ",i+1);
    scanf("%d",&p[i].bt);
    p[i].pid=i+1;
    }
    qsort((void *)p, n, sizeof(process), cmpfunc);
    float avg_tat=0.0;
    float avg_wt=0.0;
    float avg_rt=0.0;
    int length_cycle;
    int idle_time=0;
    float throughput;
    float cpu_utilisation;
    int sum_tat=0;
    int sum_wt=0;
    int sum_rt=0;
    p[0].st=p[0].at;
    p[0].ct=p[0].st+p[0].bt;
    p[0].tat=p[0].ct-p[0].at;
    p[0].wt=p[0].tat-p[0].bt;
    p[0].rt=p[0].st-p[0].at;
    for(i=1;i<n;i++)
    {
        if(p[i].at<=p[i-1].ct)
        {
            p[i].st=p[i-1].ct;
        }
        else
        {
            if(p[i].at>p[i-1].ct)
                  idle_time+=(p[i].at-p[i-1].ct);
            p[i].st=p[i].at;
        }
        p[i].ct=p[i].st+p[i].bt;
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
        p[i].rt=p[i].st-p[i].at;
        //sum_tat+=p[i].tat;
        //sum_wt+=p[i].wt;
        //sum_rt+=p[i].rt;
        
    }
    printf("\n\n");
    printf("  PID |  AT  |   BT     |   ST     |  CT   |   TAT |    WT  |   RT  \n");
    for(i=0;i<n;i++)
    {
        printf("  %d   |  %d   |   %d      |    %d     |   %d   |   %d   |   %d   |   %d  \n",p[i].pid,p[i].at,p[i].bt,p[i].st,p[i].ct,p[i].tat,p[i].wt,p[i].rt);
    
        sum_tat+=p[i].tat;
        sum_wt+=p[i].wt;
        sum_rt+=p[i].rt;
    }
    length_cycle=p[n-1].ct-p[0].st;
    throughput=n/(float)length_cycle;
    cpu_utilisation=(length_cycle-idle_time)/(float)length_cycle;
    avg_rt=(float)sum_rt/n;
    avg_wt=(float)sum_wt/n;
    avg_tat=(float)sum_tat/n;
    printf("\n");
    printf("Average Turn-around time : %f",avg_tat);
    printf("\nAverage Waiting time : %f",avg_wt);
    printf("\nAverage Response time : %f",avg_rt);
    printf("\nThroughput : %f",throughput);
    printf("\nCPU utilisation : %f%c",cpu_utilisation*100,37);
    return 0;
}

