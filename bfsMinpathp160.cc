// it is a toy code

#include<cstdio>
#include<cstdlib>
#include<string>
#include<queue>
#include<map>
const int maxn=100;

int v[maxn][maxn];

int d[maxn][maxn];

int idx[maxn];

int m,n;

using namespace std;


void bfs(int a,int b){
    queue<int> temp;
    temp.push(a);
    while(!temp.empty()){
        int e=temp.front();
        temp.pop();
        for(int i=0;i<m;i++){
            if(v[e][i]!=0&&idx[i]==0){
                //d[a][i]=d[a][i]+v[e-1][i];
                
                printf("%d\n",v[e][i]);
                temp.push(i);
            }
        }
        idx[e]=1;
        //printf("----------------\n");
    }

    
    
}
map<pair<int,int>,pair<int,int> > path;
int dis[maxn][maxn];
int dfs(int sx,int sy,int dx,int dy){
    queue<pair<int,int> > Q;
    Q.push(pair<int,int>(sx,sy));
    for(int i=0;i<maxn;i++)
    for(int j=0;j<maxn;j++){
        dis[i][j]=100000;
    }
    //memset(dis,1000,sizeof(dis));
    dis[sx][sy]=0;
    while(!Q.empty()){
        printf("-----------------\n");
        pair<int,int> q=Q.front();
        Q.pop();
        int nx=q.first;
        int ny=q.second;
        if(nx==dx&&ny==dy){
            break;
        }
        printf("%d,%d\n",nx,ny);
        int inx[]={-1,1,0,0};
        int iny[]={0,0,-1,1};
        for(int t=0;t<=3;t++){
            int i=inx[t];
            int j=iny[t];
                if(i!=0||j!=0){

                    printf(" dis[%d][%d]=%d\n", nx+i,ny+j,dis[nx+i][ny+j]);
                    
                    if( (nx+i)>=0 && nx+i<m && ny+j>=0 && ny+j<n && v[nx+i][ny+j]==1 && dis[nx+i][ny+j]==100000){
                        printf("%d,%d\n",nx+i,ny+j);
                        dis[nx+i][ny+j]=dis[nx][ny]+1;
                        Q.push(pair<int,int>(nx+i,ny+j));
                        //path.insert(pair<pair<int,int>,pair<int,int> >(pair<int,int>(nx+i,ny+j),pair<int,int>(nx,ny)));
                        path.insert(make_pair(pair<int,int>(nx+i,ny+j),pair<int,int>(nx,ny)));
                    }
                }
            }
        
    }
    printf("%d,%d\n",dx,dy);
    int x=path[pair<int,int>(dx,dy)].first;
    int y=path[pair<int,int>(dx,dy)].second;
    while(1){
        printf("-------8888----\n");
        if(x==sx&&y==sy)
            break;
        printf("%d,%d\n",x,y);
        int temp=x;
        x=path[pair<int,int>(x,y)].first;
        y=path[pair<int,int>(temp,y)].second;
    }
    return dis[dx][dy];
}



int main(){
    
    while(scanf("%d%d",&m,&n)==2&&m&&n){
        memset(idx,0,sizeof(idx));
        memset(d,0,sizeof(d));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&v[i][j]);
            }
        }
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        //bfs(a,b);
        printf("%d\n",dfs(a,b,c,d));
    }
    



}

/*
6 6
0 1 2 3 4 5
1 0 0 0 0 0
2 0 0 0 0 0
3 0 0 0 0 0
4 0 0 0 0 0
5 0 0 0 0 0
1 1

5 5
0 2 3 0 0
2 0 0 4 0
3 0 0 0 5
0 4 0 0 6
0 0 5 6 0
1 1

6 5
1 1 0 1 1
1 0 1 1 1
1 0 1 0 0
1 0 1 1 1
1 1 1 0 1
1 1 1 1 1
0 0 0 4

 */
