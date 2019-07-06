#include<stdio.h>
#include<string.h>
int main(){
    freopen("2input_1.txt","r",stdin);
    //freopen("2output.txt","w",stdout);
    int n,g;
    int i,j;
    scanf("%d",&n);
    int in[n],out[n];
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    for(i=0;i<n;i++)
        for(j=0;j<n;j++){
            scanf("%d",&g);
            if(g==1){
                in[j]++;
                out[i]++;
            }
        }
    for(i=0;i<n;i++)
        printf("%d %d %d\n",i+1,in[i],out[i]);
    return 0;
}
