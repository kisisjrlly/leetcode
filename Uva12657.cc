#include<iostream>
#include<algorithm>
#include<cstdio>
#include<list>
using namespace std;



int main(){
  int numOfbox;
  int numOfop;
  int op,box1,box2;
  int n=0;
  while(scanf("%d",&numOfbox)!=EOF){
    n++;
    int j=1;
    long long sum=0;
    list<int> l;
    cin>>numOfop;
    while(numOfop--){
      
      for(int i=0;i<numOfbox;i++)
      l.push_back(i+1);
      cin>>op;
      if(op==1){
        cin>>box1>>box2;
        list<int>::iterator p1,p2;
        p1=find(l.begin(),l.end(),box1);
        p2=find(l.begin(),l.end(),box2);
        l.insert(p2,*p1);
        l.erase(p1);
      }
      else if(op==2){
        cin>>box1>>box2;
        list<int>::iterator p1,p2;
        p1=find(l.begin(),l.end(),box1);
        p2=find(l.begin(),l.end(),box2);
        l.insert(p1,*p2);
        l.erase(p2);
      }
      else if(op==3){
        cin>>box1>>box2;
        list<int>::iterator p1,p2;
        p1=find(l.begin(),l.end(),box1);
        p2=find(l.begin(),l.end(),box2);
        l.insert(p1,*p2);
        l.insert(p2,*p1);
        l.erase(p1);
        l.erase(p2);
      }
      else{
        l.reverse();
      }
    }
    
    for(list<int>::iterator it=l.begin();it!=l.end();it++){
      if(j%2==1)
        sum+=(*it);
      //cout<<*it<<" ";
      j++;
      //cout<<j;
    }
    cout<<"Case "<<n<<": "<<sum<<endl;
  }
}
