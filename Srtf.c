#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct proces
{
    int pid;
    int at;
    int st;
    int bt;
    int ct;
    int tat;
    int wt;
    int rt;
}process;

int minimum(int x, int y)
{
    return x<y?x:y;
}
int maximum(int x, int y)
{
    return x>y?x:y;
}

int main()
{
   
    int i;
    int n;
    int bt_remaining[n];
    int completed = 0;
    int current_time = 0;
    int min_bt_index = 0;
    printf("Name : Anshika Maheshwari               Sec : A             Std. ID : 20012553\n\n");
    printf("\nEnter number of processes : ");
    scanf("%d",&n);
    process p[n];
    int prev=0;
    int idle_time=0;
    int sum_tat=0,sum_wt=0,sum_rt=0;
    float avg_wt,avg_rt,avg_tat,cpu_util;
    bool first_process = true;
    bool is_completed[n];
    for(i=0;i<n;i++)
    { 
       printf("\nEnter Arrival time and burst time for P%d : ",i+1);
       scanf("%d  %d",&p[i].at,&p[i].bt);
       p[i].pid = i+1 ;
       bt_remaining[i] = p[i].bt;
       is_completed[i] = false;
    }
    while(completed!=n)
    {
        
        int min_bt_index = -1;
        int m = INT_MAX;
        for(int i = 0;i<n;i++)
        {
        if((p[i].at<=current_time) && (is_completed[i] == false))
          {
            if(bt_remaining[i]<m)
            {
              m = bt_remaining[i];
              min_bt_index = i;
            }
            if(bt_remaining[i]==m)
            {
                if(p[i].at < p[min_bt_index].at)
                {
                    m=bt_remaining[i];
                    min_bt_index = i;
                }
            }
          }
        
        }
        if(min_bt_index == -1)
        {
            current_time++;
            
        }
        else
        {
            if(bt_remaining[min_bt_index]==p[min_bt_index].bt)
            {
                p[min_bt_index].st = current_time;
                idle_time = idle_time + (first_process==true?0:(p[min_bt_index].st - prev));
                first_process = false;
            }
            bt_remaining[min_bt_index] --;
            current_time++;
            prev=current_time;
            if(bt_remaining[min_bt_index] == 0)
            {
                p[min_bt_index].ct = current_time;
                p[min_bt_index].tat = p[min_bt_index].ct - p[min_bt_index].at;
                p[min_bt_index].wt = p[min_bt_index].tat - p[min_bt_index].bt;
                p[min_bt_index].rt = p[min_bt_index].st - p[min_bt_index].at;
                completed++;
                
                sum_tat +=p[min_bt_index].tat;
                sum_wt += p[min_bt_index].wt;
                sum_rt += p[min_bt_index].rt;
                is_completed[min_bt_index]=true;
            }
        }
    }
    printf("\nProcess ID.\tAT\tCPU Burst Time\tST\tCT\tTAT\tWT\tRT\n");
    for(int i=0;i<n;i++){
    p[i].rt = p[i].st - p[i].at; 
    printf("%d\t\t%d\t%d\t\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].st,p[i].ct,p[i].tat,p[i].wt,p[i].rt);
    }
     
    int max_completion_time = INT_MIN;
    int min_arrival_time = INT_MAX;
    
    
    
    for(int i=0;i<n;i++)
    {
        max_completion_time = maximum(max_completion_time,p[i].ct);
        min_arrival_time = minimum(min_arrival_time,p[i].at);
    }
    int length_cycle = (max_completion_time)-(min_arrival_time);
    printf("\n");  
    printf("Length cycle = %d",length_cycle);
    printf("\n");
    printf("Throughput = %f",n/(float)length_cycle);
    printf("\n");
    printf("Avg Waiting Time = %f",(float)sum_wt/n);
    printf("\n");
    printf("Avg Turn-around Time = %f",(float)sum_tat/n);
    printf("\n");
    printf("Avg Response Time = %f",(float)sum_rt/n);
    printf("\n");
    cpu_util = ((float)(length_cycle-idle_time)/length_cycle)*100;
    printf("CPU Utilisation = %f",cpu_util);
    return 0;
}
