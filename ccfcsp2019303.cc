#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>

using namespace std;

const int maxn=10000;

int n,s,l;//总此盘数，每个带上块数，好的磁盘数
int t;//查找块的次数
int b;//每次查找时的块号
int id;//磁盘编号
int idi[maxn];
char str[1005][maxn];//磁盘数组
char S[maxn];//每个磁盘上内容
int m[maxn];
int lenB;

string Xor(string str[]){
  string result;
  return "11111";
}

void Find(int b){
  int r=b/((n-1)*s);//行号，0,1,2,3...
  int i=(b-r*(n-1)*s)/s;//本行的第i块,0,1,2,3...
  int idn=(m[r%4]+1+i)%n;//位于第几个磁盘上,0,1,2,3...
  int block=(r*s+b%s);//所在磁盘的块号
  
  /*
  if idn in 好的磁盘中：
    直接读；
  else：
    result = Xor(string str[])
   */
  //如果不能恢复
  if(b>lenB||(idi[idn]==0&&n-l>1))
    puts("-");
  //如果在好的磁盘上
  else if(idi[idn]==1){
    //cout<<str[idn].substr(r*s*8,(r*s+(b%s))*8)<<endl;;
    for(int i=0;i<8;i++){
      putchar(str[idn][block*8+i]);
    }
    puts("");
  }
  //如果可以恢复
  else{
    int ans=0,k;
    char temp[9];
    for(int i=0;i<n;i++){
      if(idi[i]==1){
        for(int j=0;j<8;j++)
          temp[j]=str[i][block*8+j];
        temp[8]='\0';
        sscanf(temp,"%x",&k);
        ans^=k;
      }
    }
    printf("%08X\n",ans);
  }
  
}

int main(){
  
  scanf("%d%d%d",&n,&s,&l);
  memset(idi,0,sizeof(idi));
  memset(m,0,sizeof(m));
  for(int i=0;i<n;i++){
    m[i]=n-i-1;
  }
  for(int i=0;i<l;i++){
    scanf("%d%*c",&id);
    idi[id]=1;
    //scanf("%s",str[id]);
    fgets(str[id],maxn,stdin);
    lenB=strlen(str[id])/8;
  }
  scanf("%d",&t);
  for(int i=0;i<t;i++){
    scanf("%d",&b);
    Find(b);
  }
  
}

/*
3 2 2
0 000102030405060710111213141516172021222324252627
1 A0A1A2A3A4A5A6A7B0B1B2B3B4B5B6B7C0C1C2C3C4C5C6C7
2
2
5
 */
