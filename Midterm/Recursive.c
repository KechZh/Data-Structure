#include<stdio.h>
#include<string.h>
int compress(int in){
    int out=0;
    while(in!=0){
        out+=in%10;
        in/=10;
    }
    return out;
}
int main(){
    char S[100];
    int ans=0;
    int i;
    freopen("15input-1.txt","r",stdin);
    //freopen("15output.txt","w",stdout);
    scanf("%s",S);
    for(i=strlen(S)-1;i>=0;i--)
        ans+=S[i]-'0';
    while(ans>=10)
        ans=compress(ans);
    printf("%d\n",ans);
    return 0;
}
