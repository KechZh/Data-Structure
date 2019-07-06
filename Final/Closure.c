#include<stdio.h>
#include<string.h>
int n;
int G[1000][1000];
int W[1000];
void dfs(int sta,int now){
    int i;
    for(i=0;i<n;i++)
        if(G[now][i]==1&&W[i]==0){
            G[sta][i]=1;
            W[i]=1;
            dfs(sta,i);
        }
}
int main(){
    freopen("3input_1.txt","r",stdin);
    //freopen("3output.txt","w",stdout);
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&G[i][j]);
    for(i=0;i<n;i++){
        memset(W,0,sizeof(W));
        dfs(i,i);
    }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++){
            if(j<n-1)
                printf("%d ",G[i][j]);
            else
                printf("%d\n",G[i][j]);
        }
    return 0;
}
