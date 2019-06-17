#include<iostream>
#include<queue>
#include<stack>
using namespace std;

const int maxn=100000+100;
int sum[maxn];

class Node{
public:
  int v;
  Node *right,*left;
  Node(int x):v(x),right(NULL),left(NULL){}
};

stack<Node*> freenodes;

void Alloc(){
  for(int i=0;i<100000;i++)
    freenodes.push(new Node(0));
}

Node* build(int p){
  int x;
  cin>>x;
  if(x==-1) return NULL;
  sum[p]+=x;
  //Node *r=new Node(x);
  Node *r=freenodes.top();
  r->v=x;
  freenodes.pop();
  r->left=build(p-1);
  r->right=build(p+1);
  return r;
}

bool init(){
  Alloc();
  int x;
  cin>>x;
  //cout<<x<<"xxxxxxx"<<endl;
  if(x==-1) return false;
  memset(sum,0,sizeof(sum));
  int pos=maxn/2;
  sum[pos]=x;
  build(pos-1);build(pos+1);
  while(!freenodes.empty())
    freenodes.pop();
  //cout<<"yyyyyyy"<<endl;
  return true;
}

void scan(Node *u){
  if(u==NULL) return;
  cout<<u->v<<endl;
  scan(u->left);
  scan(u->right);
}

int main(){
  //Node *r=build();
  //scan(r);
  int kcase=0;
  while(init()){
    //cout<<"--------"<<endl;
    int p=0;
    while(sum[p]==0) p++;
    cout<<"Case "<<++kcase<<":\n"<<sum[p++];
    while(sum[p]!=0) cout<<" "<<sum[p++];
    cout<<"\n\n";
  }
}

/*
5 7 -1 6 -1 -1 3 -1 -1
8 2 9 -1 -1 6 5 -1 -1 12 -1 -1 3 7 -1 -1 -1
  5
7   3
  6

    8
  2   3
    7
9   6
  5   12
  
 */
