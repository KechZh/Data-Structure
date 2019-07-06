#include<stdio.h>
void play(int n,char a,char b,char c){
    if(n==1)
        printf("Move sheet from %c to %c\n",a,c);
    else{
        play(n-1,a,c,b);
        play(1,a,b,c);
        play(n-1,b,a,c);
    }
}
int main(){
    int n;
    freopen("17input.txt","r",stdin);
    //freopen("17output.txt","w",stdout);
    scanf("%d",&n);
    printf("%d\n",(1<<n)-1);
    play(n,'A','B','C');
    return 0;
}
