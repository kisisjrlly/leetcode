#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<queue>
#include<iterator>

using namespace std;

const int maxn=100000+100;
char s[maxn];
bool failed;

class Node{
public:
    bool have_value;
    int v;
    Node *left,*right;
    Node():have_value(false),left(NULL),right(NULL){}

};

Node *root;
Node* newnode(){return new Node();}
void add_node(int v,char* s){
    int n =strlen(s);
    Node *u=root;
    for(int i=0;i<n;i++){
      if(s[i]=='L'){
        if(u->left==NULL) u->left=newnode();
        u=u->left;
      }
      else if(s[i]=='R'){
        if(u->right==NULL) u->right=newnode();
        u=u->right;
      }
    }
    if(u->have_value) failed=true;
    u->v=v;
    u->have_value=true;
}

bool bfs(vector<int>& ans){
    queue<Node*> q;
    ans.clear();
    q.push(root);
    while(!q.empty()){
      Node *u=q.front();q.pop();
      if(!u->have_value) return false;
      ans.push_back(u->v);
      if(u->left!=NULL) q.push(u->left);
      if(u->right!=NULL) q.push(u->right);
    }
    return true;
}

void remove_tree(Node *u){
  if(u==NULL) return;
  remove_tree(u->left);
  remove_tree(u->right);
  delete u;
}


bool read_input(){
  cout<<"dsdasd"<<endl;
  failed=false;
  root = newnode();
  
  while(1){
    if(scanf("%s",s)!=1) return false;
    //cout<<s<<endl;
    if(!strcmp(s,"()")) break;
    //cout<<"1dsdasd"<<endl;
    int v;
    sscanf(&s[1],"%d",&v);
    //cout<<"2dsdasd"<<endl;
    add_node(v,strchr(s,',')+1);
    //cout<<"3dsdasd"<<endl;
  }
  //cout<<"4dsdasd"<<endl;
  return true;
}

void preorder(Node *u){
  if (u==NULL) return;
  cout<<u->v<<endl;
  preorder(u->left);
  preorder(u->right);
}
int main(){
  
  if(!read_input()){
    cout<<"input error"<<endl;

  }
  
  if(failed==true){
    cout<<"error"<<endl;
  }
  vector<int> ans;
  if(!bfs(ans)){
    cout<<"bfs error"<<endl;
  }
  for(vector<int>::iterator it=ans.begin();it!=ans.end();it++){
    cout<<*it<<endl;
  }
  cout<<"-----------"<<endl;
  preorder(root);
  
  remove_tree(root);
}

//(11,LL) (7,LLL) (8,R) (5,) (4,L) (13,RL) (2,LLR) (1,RRR) (4,RR) ()
