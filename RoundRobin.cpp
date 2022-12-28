#include<bits/stdc++.h>
using namespace std;

struct process
{
    
    int at,bt,st,ct,wt,rt,tat,pid;
    int bt_rem;
    
}p[10];
bool cmp(struct process a, struct process b)
{
    int x = a.at;
    int y = b.at;
    return x<y;
}
int main()
{
    int i,n;
    cout<<"Enter n : ";
    cin>>n;
    bool vis[n];
    int c = 0;
    int tq;
    int index;
    int sum_tat=0,sum_rt=0,sum_wt=0;
    cout<<"Enter details : \nAT BT\n";
    for(i=0;i<n;i++)
    {
        cin>>p[i].at>>p[i].bt;
        p[i].bt_rem = p[i].bt;
        p[i].pid = i+1;
        vis[i]=false;
    }
    cout<<endl;
    cout<<"enter tq : ";
    cin>>tq;
    //cout<<endl;
    queue<int> q;
    q.push(0);
    int current = 0,idle_time=0;
    bool i_f_p = true;
    sort(p,p+n,cmp);
    while(c!=n)
    {
        index=q.front();
        q.pop();
        if(p[index].bt_rem==p[index].bt)
        {
            p[index].st = max(p[index].at,current);
            idle_time += (i_f_p==true)?0:(p[index].st-current);
            current=p[index].st;
            i_f_p = false;
        }
        if(p[index].bt_rem-tq>0)
        {
            p[index].bt_rem-=tq;
            current+=tq;
        }
        else
        {
            current+=p[index].bt_rem;
            p[index].bt_rem=0;
            c++;
            p[index].ct = current;
            p[index].tat = p[index].ct - p[index].at;
            p[index].wt = p[index].tat - p[index].bt;
            p[index].rt = p[index].st - p[index].at;
            
            sum_wt += p[index].wt;
            sum_rt += p[index].rt;
            sum_tat +=p[index].tat;
        }
        for(i=1;i<n;i++)
        { if(p[i].bt_rem>0&&vis[i]==false&&p[i].at<=current)
                {
                    q.push(i);
                    vis[i]=true;
                    
                }
        }
        if(p[index].bt_rem>0)
        {
            q.push(index);
        }
        if(q.empty())
        {
            for(i=1;i<n;i++)
            {
                if(p[i].bt_rem>0)
                {
                    q.push(i);
                    vis[i]=true;
                    break;
                }
            }
        }
    }
    //cout<<endl;
    cout<<"pid\tat\tbt\tst\tct\ttat\twt\trt\n";
    for(i=0;i<n;i++)
    {
        cout<<p[i].pid<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].st<<"\t"<<p[i].ct<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<"\t"<<p[i].rt<<"\n";
    }
    int max_ct=INT_MIN;
    for(i=0;i<n;i++)
    {
        max_ct = max( p[i].ct,max_ct);
    }
    int length_cycle = max_ct-p[0].at;
    cout<<endl;
    cout<<"Avg TAT = "<<(float)sum_tat/n;
    cout<<endl;
    cout<<"Avg WT = "<<(float)sum_wt/n;
    cout<<endl;
    cout<<"Avg RT = "<<(float)sum_rt/n;
    cout<<endl;
    cout<<"Throughput = "<<n/(float)length_cycle;
    return 0;
}
