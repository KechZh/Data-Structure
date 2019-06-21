#include<stdio.h>
#include<string.h>
FILE *fp;
char F[20];
int n;
int M[100][100];
int load_file(){
    printf("Input file : ");
    scanf("%s",F);
    if(fp=fopen(F,"r")){
        printf("Load success.\n\n");
        return 1;
    }
    else{
        printf("Load fail.Return.\n\n");
        return 0;
    }
}
int check(){
    int W[100]={0};
    int i;
    void find(int now){
        int i;
        W[now]=1;
        for(i=1;i<=n;i++)
            if(M[now][i]>0&&W[i]==0)
                find(i);
    }
    find(1);
    for(i=1;i<=n;i++)
        if(W[i]==0)
            return 0;
    return 1;
}
void Kruskal(){
    int line=1;
    int min,cost=0;
    int W[100]={0};
    int x,y,i,j;
    if(load_file()==0)
        return;
    fscanf(fp,"%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            fscanf(fp,"%d",&M[i][j]);
    if(check()==0){
        printf("No spanning tree.\n\n");
        return;
    }
    printf("Edges of min cost spanning tree are\n");
    while(1){
        x=0;y=0;min=0x7FFFFFFF;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
               if(M[i][j]>0&&M[i][j]<min){
                    min=M[i][j];
                    x=i;y=j;
               }
        if(x==0&&y==0)
            break;
        else if(W[x]==0||W[y]==0){
            printf("Edge %d : <%d,%d> cost : %d\n",line++,x,y,min);
            cost+=min;
        }
        W[x]=W[y]=1;
        M[x][y]=M[y][x]=0x7FFFFFFF;
    }
    printf("Min cost = %d\n\n",cost);
}
void Prim(){
    int que[100];
    int rear=0;
    int line=1;
    int min,cost=0;
    int W[100]={0};
    int x,y,i,j;
    if(load_file()==0)
        return;
    fscanf(fp,"%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            fscanf(fp,"%d",&M[i][j]);
    fscanf(fp,"%d",&que[rear++]);
    if(check()==0){
        printf("No spanning tree.\n\n");
        return;
    }
    printf("Edges of min cost spanning tree are\n");
    while(1){
        x=0;y=0;min=0x7FFFFFFF;
        for(i=0;i<rear;i++)
            for(j=1;j<=n;j++)
               if(M[que[i]][j]>0&&M[que[i]][j]<min){
                    min=M[que[i]][j];
                    x=que[i];y=j;
               }
        if(x==0&&y==0)
            break;
        else if(W[y]==0){
            printf("Edge %d : <%d,%d> cost : %d\n",line++,x,y,min);
            cost+=min;
            que[rear++]=y;
        }
        W[x]=W[y]=1;
        M[x][y]=M[y][x]=0x7FFFFFFF;
    }
    printf("Min cost = %d\n\n",cost);
}
void Dijkstra(){
    int a,b;
    int i,j;
    if(load_file()==0)
        return;
    fscanf(fp,"%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            fscanf(fp,"%d",&M[i][j]);
    while(1){
        printf("Enter start and end (Enter 0 and 0 to exit) : ");
        scanf("%d%d",&a,&b);
        if(a==0&&b==0){
            printf("\n");
            break;
        }
        int que[100];
        int fro=0,rear=0;
        int D[100];
        int W[100]={0};
        memset(D,-1,sizeof(D));
        que[rear++]=a;D[a]=0;
        while(fro!=rear){
            W[que[fro]]=1;
            for(i=1;i<=n;i++)
                if(M[que[fro]][i]>0){
                    if(D[que[fro]]+M[que[fro]][i]<D[i]||D[i]==-1)
                        D[i]=D[que[fro]]+M[que[fro]][i];
                    if(W[i]==0)
                        que[rear++]=i;
                }
            fro++;
        }
        printf("The cost from %d to %d : %d\n\n",a,b,D[b]);
    }
}
int main(){
    int mode=0;
    while(mode!=4){
        printf("Which algorithm do you wanna use?\n");
        printf("(1)Kruskal's algorithm.\n");
        printf("(2)Prim's algorithm.\n");
        printf("(3)Dijkstra's algorithm.\n");
        printf("(4)Exit.\n");
        scanf("%d",&mode);
        printf("\n");
        if(mode==1)
            Kruskal();
        else if(mode==2)
            Prim();
        else if(mode==3)
            Dijkstra();
    }
    return 0;
}
