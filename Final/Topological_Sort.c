#include<stdio.h>
int n;
int G[1000][1000];
int vis[1000]={0};
int ord[1000],bot;
void dfs(int now){
    int i;
    if(vis[now])
        return;
    vis[now]=1;
    for(i=1;i<=n;i++)
        if(G[now][i]){
            dfs(i);
        }
    ord[bot--]=now;
}
int main(){
    freopen("1input_3.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&G[i][j]);
    bot=n-1;
    for(i=n;i>=1;i--)
        dfs(i);
    for(i=0;i<n;i++){
        if(i<n-1)
            printf("%d ",ord[i]);
        else
            printf("%d\n",ord[i]);
    }
    return 0;
}
