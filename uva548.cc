#include<iostream>
#include<string>
#include<cstdlib>
#include<sstream>
#include<vector>
using namespace std;

const int maxn=10000+100;
//int in_order[maxn],pre_order[maxn];
vector<int> in_order,pre_order;
class Node{
public:
    int v;
    //bool have_value;
    Node *left,*right;
    Node(int x):v(x),left(NULL),right(NULL){}
};

bool read_list(vector<int> &a){
  string line;
  int n=0;
  int x=0;
  if(!getline(cin,line))  return false;
  stringstream ss(line);
  while(ss>>x) {a.push_back(x);}
  return true;
}

//Node *root=new Node();

Node* func(vector<int> &a,vector<int> &b,int in_start, int in_end, int post_start, int post_end){
  if(post_end==post_start) return new Node(b[post_end]);
  if(post_start>post_end) return NULL;
  int root_value=b[post_end];
  Node *root =new Node(root_value);
  int i=0;
  for(;i<in_end;i++){
      if(a[i]==root_value)
        break;
  }
  root->left=func(a,b,in_start,i-1,post_start,post_start+i-1-in_start);
  root->right = func(a,b,i+1,in_end,post_start+i-in_start,post_end-1);
  return root;
}

Node* build_tree(vector<int> &a,vector<int> &b){
  //cout<<sizeof(a)<<"fsdfs"<<endl;
    return func(a,b,0,a.size(),0,b.size()-1);
}

int best_sum=10000000;
int best;
void dfs(Node *r,int sum){
  //int u=r->v;
  sum+=r->v;
  if(!r->left&&!r->right){
    if(sum<best_sum||(sum==best_sum&&r->v<best)){best=r->v,best_sum=sum;}
  }
  if(r->left) dfs(r->left,sum);
  if(r->right) dfs(r->right,sum);
}

void scan(Node *u){
  if(u==NULL) return;
  scan(u->left);
  cout<<u->v;
  scan(u->right);

}

int main(){
    while(read_list(in_order)){
      best_sum=10000000;
      read_list(pre_order);
      Node *r=build_tree(in_order,pre_order);
      dfs(r,0);
      cout<<best<<endl;
      //scan(r);
    }
}

//3 2 1 4 5 7 6
//3 1 2 5 6 7 4
