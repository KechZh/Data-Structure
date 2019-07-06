#include<stdio.h>
#include<string.h>
typedef struct edge{
    int v,w;
    int val;
}edge;
int main(){
    freopen("5input_3.txt","r",stdin);
    //freopen("5output.txt","w",stdout);
    int n;
    int i,j;
    scanf("%d",&n);
    int G[n+1][n+1],W[n+1];
    edge E[n+1];
    int ne=1;
    memset(W,0,sizeof(W));
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&G[i][j]);
    while(ne<n){
        int v=0,w=0;
        int min=0x7FFFFFFF;
        for(i=1;i<=n;i++)
            for(j=i;j<=n;j++)
                if(G[i][j]>0&&G[i][j]<min&&W[i]+W[j]<2){
                    min=G[i][j];
                    v=i;w=j;
                }
        if(v==0&&w==0)
            break;
        E[ne].v=v;E[ne].w=w;
        E[ne].val=min;
        ne++;
        W[v]=W[w]=1;
        G[v][w]=G[w][v]=0;
    }
    if(ne==n)
        for(i=1;i<ne;i++)
            printf("%d %d %d\n",E[i].v,E[i].w,E[i].val);
    else
        printf("No spanning tree.\n");
    return 0;
}
