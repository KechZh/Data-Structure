#include<stdio.h>
struct Ele{
    int x;
    int y;
    int d;
};
struct Rat{
    int x;
    int y;
};
FILE *fp;
int M[17][17];
int D[2][17][17]={0};
struct Ele stack[2][1000];
int top[2]={0};
struct Rat R[2],next;
void putstack(int n,int dir){ //put last step in stack
    if(top[n]==0){
        stack[n][top[n]].x=R[n].x;
        stack[n][top[n]].y=R[n].y;
        stack[n][top[n]].d=dir;
        top[n]++;
    }
    else{
        if(next.x!=stack[n][top[n]].x||next.y!=stack[n][top[n]].y){
            stack[n][top[n]].x=R[n].x;
            stack[n][top[n]].y=R[n].y;
            stack[n][top[n]].d=dir;
            top[n]++;
        }
        else{
            stack[n][top[n]].x=-1;
            stack[n][top[n]].y=-1;
            stack[n][top[n]].d=0;
            top[n]--;
        }
    }
}
void findway(int n){ //find the next step
    if(n==0){
        while(D[n][R[n].x][R[n].y]!=5){
            D[n][R[n].x][R[n].y]++;
            if(D[n][R[n].x][R[n].y]==1)
                if(M[R[n].x][R[n].y+1]==0){
                    next.x=R[n].x;next.y=R[n].y+1;break;
                }
            if(D[n][R[n].x][R[n].y]==2)
                if(M[R[n].x+1][R[n].y]==0){
                    next.x=R[n].x+1;next.y=R[n].y;break;
                }
            if(D[n][R[n].x][R[n].y]==3)
                if(M[R[n].x-1][R[n].y]==0){
                    next.x=R[n].x-1;next.y=R[n].y;break;
                }
            if(D[n][R[n].x][R[n].y]==4)
                if(M[R[n].x][R[n].y-1]==0){
                    next.x=R[n].x;next.y=R[n].y-1;break;
                }
        }
        if(D[n][R[n].x][R[n].y]!=5){
            putstack(n,D[n][R[n].x][R[n].y]);
            R[n].x=next.x;R[n].y=next.y;
            fprintf(fp,"RatA(%d,%d)\n",R[n].x-1,R[n].y-1);
        }
    }
    if(n==1){
        while(D[n][R[n].x][R[n].y]!=5){
            D[n][R[n].x][R[n].y]++;
            if(D[n][R[n].x][R[n].y]==1)
                if(M[R[n].x][R[n].y-1]==0){
                    next.x=R[n].x;next.y=R[n].y-1;break;
                }
            if(D[n][R[n].x][R[n].y]==2)
               if(M[R[n].x-1][R[n].y]==0){
                    next.x=R[n].x-1;next.y=R[n].y;break;
                }
            if(D[n][R[n].x][R[n].y]==3)
                if(M[R[n].x+1][R[n].y]==0){
                    next.x=R[n].x+1;next.y=R[n].y;break;
                }
            if(D[n][R[n].x][R[n].y]==4)
                if(M[R[n].x][R[n].y+1]==0){
                    next.x=R[n].x;next.y=R[n].y+1;break;
                }
        }
        if(D[n][R[n].x][R[n].y]!=5){
            putstack(n,D[n][R[n].x][R[n].y]);
            R[n].x=next.x;R[n].y=next.y;
            fprintf(fp,"RatB(%d,%d)\n",R[n].x-1,R[n].y-1);
        }
    }
}
int main(){
    char S[15];
    int i,j;
    fp=fopen("maze.txt","r");
    for(i=0;i<17;i++) //build the maze
        M[0][i]=M[i][0]=M[16][i]=M[i][16]=1;
    for(i=1;i<16;i++){
        fscanf(fp,"%s",S);
        for(j=1;j<16;j++)
            M[i][j]=S[j-1]-'0';
    }
    fp=fopen("result.txt","w");
    R[0].x=1;R[0].y=1;R[1].x=15;R[1].y=15;
    while((R[0].x!=15||R[0].y!=15)||(R[1].x!=1||R[1].y!=1)){
        if(R[0].x!=15||R[0].y!=15)
            findway(0);
        if(R[1].x!=1||R[1].y!=1)
            findway(1);
    }
    return 0;
}
