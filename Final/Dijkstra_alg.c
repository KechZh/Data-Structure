#include<stdio.h>
#include<string.h>
int n;
int G[1000][1000];
int D[1000];
int par[1000];
int visit[1000];
void Dijkstra(int start){
    int que[1000];
    int front=0,rear=0;
    int i;
    memset(D,0x3f3f3f3f,sizeof(D));
    memset(visit,0,sizeof(visit));
    que[rear++]=start;
    D[start]=0;
    while(front!=rear){
        int now=que[front++];
        visit[now]=1;
        for(i=1;i<=n;i++)
            if(G[now][i]&&D[now]+G[now][i]<D[i]){
                D[i]=D[now]+G[now][i];
                par[i]=now;
                if(!visit[i])
                    que[rear++]=i;
            }
    }
}
void print_path(int start,int end){
    int now=end;
    int stack[1000];
    int top=0;
    int i;
    while(1){
        stack[top++]=now;
        if(now==start)
            break;
        now=par[now];
    }
    for(i=top-1;i>=0;i--){
        if(i>0)
            printf("%d ",stack[i]);
        else
            printf("%d\n",stack[i]);
    }
}
int main(){
    freopen("7input_3.txt","r",stdin);
    //freopen("7output.txt","w",stdout);
    int start,end;
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&G[i][j]);
    scanf("%d%d",&start,&end);
    Dijkstra(start);
    if(D[end]==0x3f3f3f3f)
        printf("-1\n");
    else
        print_path(start,end);
    return 0;
}
