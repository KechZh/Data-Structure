#include<stdio.h>
#include<string.h>
struct Data{
    char name[100];
    int index;
};
struct Data list[100];
char M[1000];
int lps[100];
void makemain(int n){
    int tot=0;
    char temp[1000];
    int i,j;
    strcpy(M,list[0].name);tot=list[0].index;
    for(i=1;i<n;i++){
        strcpy(temp,M+tot);
        for(j=strlen(M);j>=tot;j--)
            M[j]='\0';
        strcat(M,list[i].name);
        strcat(M,temp);
        tot+=list[i].index;
        printf("Main string : %s\n",M);
    }
}
void failure(char S[]){
    int F[100];
    int i,j;
    F[0]=-1;
    for(j=1;j<strlen(S);j++){
        i=F[j-1];
        while(S[j]!=S[i+1]&&i>=0)
            i=F[i];
        if(S[j]==S[i+1])
            F[j]=i+1;
        else
            F[j]=-1;
    }
    for(j=0;j<strlen(S);j++)
        lps[j]=F[j]+1;
}
void read(){
    FILE *fp;
    char S[1000];
    char *tok;
    int tot=0;
    int i;
    fp=fopen("data.csv","r");
    printf("====================\n");
    for(i=0;fgets(S,1000,fp)!=NULL;i++){
        tok=strtok(S,",");
        strcpy(list[i].name,tok);
        tok=strtok(NULL,"\n");
        list[i].index=atoi(tok);
        printf("===The name : %s\n",list[i].name);
        printf("===The index : %d\n",list[i].index);
    }
    printf("====================\n");
    makemain(i);
}
void write(){
    char S[10];
    int i,j;
    for(i=0;1;i++){
        printf("===input name (input stop to stop)\n->");
        scanf("%s",list[i].name);
        if(strcmp(list[i].name,"-")==0)
            break;
        printf("===input index\n->");
        scanf("%d",&list[i].index);
    }
    j=i;
    printf("====================\n");
    for(i=0;i<j;i++){
        printf("===The name : %s\n",list[i].name);
        printf("===The index : %d\n",list[i].index);
    }
    printf("====================\n");
    makemain(i);
}
void pop(){
    char P[100];
    int i,j;
    printf("input pop name\n");
    scanf("%s",P);
    printf("input pop name is : %s\n",P);
    failure(P);
    printf("lps = {");
    for(i=0;i<strlen(P)-1;i++)
        printf("%d,",lps[i]);
    printf("%d}\n",lps[i]);
    i=j=0;
    while(i<strlen(M)&&j<strlen(P)){
        if(M[i]==P[j]){
            i++;j++;
        }
        else if(j==0)
            i++;
        else
            j=lps[j-1];
    }
    if(j==strlen(P)){
        for(j=i-strlen(P);j<strlen(M)-strlen(P);j++)
            M[j]=M[j+strlen(P)];
        for(;j<strlen(M);j++)
            M[j]='\0';
        printf("The output is :%s\n",M);
    }
    else
        printf("No pop name in main string.\n");
}
int main(){
    printf("What do you want to do?\n\n");
    printf("\t(1)Read data from a file\n");
    printf("\t(2)Write new data\n");
    printf("\t(3)Pop data\n");
    printf("\t(0)Exit\n");
    int com=1;
    while(com!=0){
        scanf("%d",&com);
        if(com==1)
            read();
        if(com==2)
            write();
        if(com==3)
            pop();
    }
    return 0;
}
