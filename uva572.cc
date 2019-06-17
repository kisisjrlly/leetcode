#include<cstdio>
#include<string>
#include<cstdlib>
using namespace std;
const int maxn=100+5;

char pic[maxn][maxn];
int idx[maxn][maxn];
int m,n;
char temp;

void dfs(int r,int c,int id){
    if(r<0||r>=m||c>=n||c<0) return;
    //printf("------------------1\n");
    if(idx[r][c]>0||pic[r][c]!='@') return;
    //printf("------------------2\n");
    idx[r][c]=id;
   // printf("------------------\n");
    for(int rd=-1;rd<=1;rd++)
        for(int cd=-1;cd<=1;cd++){
            //printf("------------------\n");
           // printf("rd:%d\n",rd);
           // printf("cd:%d\n",cd);
            if(rd!=0||cd!=0) dfs(r+rd,c+cd,id);
        }
}

int main(){
	while(scanf("%d %d",&m,&n)==2&&m&&n){
        for(int i=0;i<m;i++)    scanf("%s",pic[i]);
        memset(idx,0,sizeof(idx));
        int cnt=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(idx[i][j]==0&&pic[i][j]=='@') {
                    //printf("i:%d\n",i);
                    //printf("j:%d\n",j);
                    
                    dfs(i,j,++cnt);
                    //printf("cnt:%d\n",cnt);
                }

            }
        printf("%d\n",cnt);
    }
}
/*
5 5
****@
*@@*@
*@**@
@@@*@
@@**@

 */
