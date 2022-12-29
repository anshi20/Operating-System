#include<bits/stdc++.h>
using namespace std;

typedef struct process{
    int maxneed[10];
    int allocated[10];
    int need[10];
}pro;

int safetyalgo(vector<pro> &processes ,vector<int>available , int n , int r ,vector<int>&safeseq){
 bool proceed=true;
 vector<bool>CheckCompleted(n,false);
 int complete=0;

 while(proceed){
 proceed=false;
 

 for (int i = 0; i < n; i++)
 {
    bool flag=true;
    if(!CheckCompleted[i]){

     for (int  j = 0; j < r; j++)
    {
        if(processes[i].need[j] <= available[j]){
         continue;
        }
        flag=false;
        break;
    }

    
    if(flag) {
         complete++;
         CheckCompleted[i]=true;
         safeseq.push_back(i);
         proceed=true;
        for (int j = 0; j < r; j++)
        {
            available[j]+=processes[i].allocated[j];
        }
        
    }
     }
    
 }
 }
 return n==complete;

}

int main(){
    int n;
    cin>>n;
    int r;
    cin>>r;

    vector<pro>processes(n);
    for(int i=0;i<n;i++){

    for(int j=0;j<r;j++)
     cin >> processes[i].maxneed[j];
    for(int j=0;j<r;j++)
     {
     cin >>processes[i].allocated[j];
     processes[i].need[j]=processes[i].maxneed[j] - processes[i].allocated[j];
     }

    } 

    vector<int>available(r);

    for(int i=0;i<r;i++)
    cin>>available[i];
    
    vector<int>safeSeq;
    
    cout<<"Process\t\t"<<"Max need\t\t"<<"Allocated\t\t"<<"Available\n";
    for(int i=0;i<n;i++){
    cout<<i<<"\t\t";
    for(int j=0;j<r;j++)
     cout<< " "<<processes[i].maxneed[j]<<" ";
     cout<<"\t\t";
     for(int j=0;j<r;j++)
     cout<<" "<<processes[i].allocated[j]<<" ";
     cout<<"\t\t";
     for(int j=0;j<r;j++)
     cout<<" "<<processes[i].need[j]<<" ";
     cout<<"\n";
    } 

    cout<<"\n\n";
    if(safetyalgo(processes,available,n,r,safeSeq)){
     cout<<"Safe Sequence : ";
     for (int i = 0; i < n; i++)
     {
        cout<<safeSeq[i]<<" ";
     }
     
    }
    else cout<<"Not a safe sequence";
    return 0;


}
// 4
// 3
// 3 3 3
// 1 2 2
// 4 4 4
// 1 1 1
// 2 2 2
// 1 1 1
// 4 4 4 
// 0 0 0
// 1 1 1
