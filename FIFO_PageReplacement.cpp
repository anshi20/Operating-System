#include<bits/stdc++.h>
using namespace std;
bool check(int val,vector<int>&frame , int nf){
    for (int i = 0; i < nf; i++)
    {
        if(val==frame[i]) return true;
    }
    return false;
}
int findFault( vector<int>&pages , int pn, int nf, int &pm){
  int pf=0,r=0;
  vector<int>frame(nf);
  int index=0;
  for (int i = 0; i < pn; i++) {
    if(r<nf){
        if(!check(pages[i],frame,r)){
        pf++;
        frame[r++]=pages[i];
        }
        else
        {
           pm++; 
        }
    }
    else {
      if(!check(pages[i],frame,r)){
        pf++;
        frame[index++]=pages[i];
        index=index%nf;
        }
        else
        {
            pm++;
        }
    }
    for(int j=0;j<r;j++)
        printf("%d ",frame[j]);
    printf("\n");
  }
  return pf;
}
int main(){
    
    int pn,nf,pm=0;
    cout<<"enter no of pages : ";
    cin>>pn;
    cout<<"\nenter no of frames : ";
    cin>>nf;
    vector<int>pages(pn);
    for (int i = 0; i < pn; i++)
    {
        cin>>pages[i];
    }
    int pf=findFault(pages,pn,nf,pm);
    cout<<"\npage fault :"<<pf<<endl;
    cout<<"page hit : "<<pm<<endl;
    cout<<"hit rato : "<<(float)pm/(pm+pf)<<endl;
    cout<<"miss rato : "<<(float)pf/(pm+pf);
}
