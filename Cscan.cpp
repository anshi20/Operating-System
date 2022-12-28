#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter size of hard disk : ";
    int i,n;
    cin>>n;
    int size;
    cout<<"\nEnter size of request queue : ";
    cin>>size;
    int a[size];
    cout<<"\nEnter elements in ready queue : \n";
    for(i=0;i<size;i++)   cin>>a[i];
    int l_count=0;
    int head;
    cout<<"\nEnter initial position of read write head : ";
    cin>>head;
    for(i=0;i<size;i++)
    {
        if(a[i]>head){
           l_count=i;
           break;
            
        }
    }
    sort(a,a+size);
    int direction;
    cout<<"\nEnter direction : (1 -> Right     0 -> Left     : )";
    cin>>direction;
    int ans[size+2];
    int j=0;
    int seekdistance=0;
    if(direction==1)
    {
        for(i=l_count;i<size;i++)
        {
            seekdistance += abs(a[i]-head);
            head=a[i];
            ans[j++]=a[i];
        }
        
        seekdistance+=abs(head-(n-1));
        ans[j++]=n-1;
        head=n-1;
        seekdistance+=abs(head-(0));
        head=0;
        ans[j++]=0;
        for(i=0;i<l_count;i++)
        {
            seekdistance += abs(a[i]-head);
            head=a[i];
            ans[j++]=a[i];
        }
    }
    else if(direction==0)
    {
        for(i=l_count-1;i>=l_count;i--)
        {
            seekdistance+=abs(head-a[i]);
            head=a[i];
            ans[j++]=a[i];
        }
        seekdistance+=abs(head-0);
        head=0;
        ans[j++]=0;
        seekdistance+=abs(0-(n-1));
        ans[j++]=n-1;
        head=n-1;
        for(i=size-1;i>=l_count;i--)
        {
            seekdistance+=abs(head-a[i]);
            head=a[i];
            ans[j++]=a[i];
        }
    }
    
    cout<<endl;
    cout<<"Seek sequence : ";
    for(int i = 0 ; i < j ; i++)
        cout<<ans[i]<<" ";
    cout<<"Seek distance = "<<seekdistance;

    return 0;
    
    
}
