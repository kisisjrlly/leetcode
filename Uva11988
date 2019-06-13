#include<cstring>
#include<cstdio>
const int maxn=100000+5;
int last,cur,next[maxn];

char s[maxn];

typedef struct chr{
  char c;
  chr *next;  
};

int main(){
  while(scanf("%s",s+1)==1){
    int n=strlen(s+1);
    last=cur=0;
    next[0]=0;
    chr *str,*first,*end,*endd;
    str->c=' ';
    str->next=NULL;
    endd=end=first=str;
    first->next=str;
    
    for(int i=1;i<=n;i++){
      if(s[i]=='['){end=first->next;}
      else if(s[i]==']'){end=NULL;}
      else{
        chr *temp = new chr;
        temp->c=s[i];
        temp->next=end;
        if(end==NULL){
          endd=temp;
        }
        if(end==first->next){
          first->next=temp;
        }
        str->next=temp;
        str=temp;
      }
    }
    chr *p=first;
    while(p){
      printf("%c ",p->c);
      p++;
    }
    printf("\n");
  }
  return 0;
}
