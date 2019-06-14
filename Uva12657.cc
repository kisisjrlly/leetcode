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

/*
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 100000 + 5;
int n, left[maxn], right[maxn];

inline void link(int L, int R) {
  right[L] = R; left[R] = L;
}

int main() {
  int m, kase = 0;
  while(scanf("%d%d", &n, &m) == 2) {
    for(int i = 1; i <= n; i++) {
      left[i] = i-1;
      right[i] = (i+1) % (n+1);
    }
    right[0] = 1; left[0] = n;
    int op, X, Y, inv = 0;

    while(m--) {
      scanf("%d", &op);
      if(op == 4) inv = !inv;
      else {
        scanf("%d%d", &X, &Y);
        if(op == 3 && right[Y] == X) swap(X, Y);
        if(op != 3 && inv) op = 3 - op;
        if(op == 1 && X == left[Y]) continue;
        if(op == 2 && X == right[Y]) continue;

        int LX = left[X], RX = right[X], LY = left[Y], RY = right[Y];
        if(op == 1) {
          link(LX, RX); link(LY, X); link(X, Y);
        }
        else if(op == 2) {
          link(LX, RX); link(Y, X); link(X, RY);
        }
        else if(op == 3) {
          if(right[X] == Y) { link(LX, Y); link(Y, X); link(X, RY); }
          else { link(LX, Y); link(Y, RX); link(LY, X); link(X, RY); }
        }
      }
    }

    int b = 0;
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
      b = right[b];
      if(i % 2 == 1) ans += b;
    }
    if(inv && n % 2 == 0) ans = (long long)n*(n+1)/2 - ans;
    printf("Case %d: %lld\n", ++kase, ans);
  }
  return 0;
}
*/
