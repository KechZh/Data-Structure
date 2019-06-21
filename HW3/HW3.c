#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
struct player{
    char name[100];
    struct player *next;
};
struct player *list,*first,*temp,*now;
char S[1000];
int len;
void reverse(){    //reverse the circle
    int i;
    temp=malloc(sizeof(struct player));
    now=malloc(sizeof(struct player));
    temp=first;now=first->next;
    for(i=0;i<len;i++){
        list=temp;
        temp=now;
        now=now->next;
        temp->next=list;
    }
    list=first;
}
void play(){    //start playing game
    int dir,ski;
    struct player *kill;
    int mod;
    int i;
    printf("Choose direction\n");
    printf("\t(1)right\n");
    printf("\t(2)left\n");
    scanf("%d",&dir);
    if(dir==2)
        reverse();
    printf("Input mode(1 is to random a skip number,2 is to input a skip number)\n");
    scanf("%d",&mod);
    if(mod==1){
        srand(time(NULL));
        ski=rand()%len;
        printf("The skip number is %d\n",ski);
    }
    if(mod==2){
        printf("Input skip number\n");
        scanf("%d",&ski);
        printf("The skip number is %d\n",ski);
    }
    while(len>1){
        kill=malloc(sizeof(struct player));
        temp=malloc(sizeof(struct player));
        printf("List length is : %d\n",len);
        kill=first;temp=first;
        for(i=0;i<ski;i++)
            first=first->next;
        for(i=0;i<=ski;i++)
            kill=kill->next;
        for(i=0;i<ski+2;i++)
            temp=temp->next;
        first->next=temp;
        printf("The data is poped : %s\n",kill->name);
        len--;
    }
    printf("The last data is : %s\n",first->name);
}
void read(){    //read data
    FILE *fp;
    int i;
    fp=fopen("data.csv","r");
    printf("Start read data from a file\n");
    first=NULL;list=NULL;len=0;
    first=malloc(sizeof(struct player));
    list=malloc(sizeof(struct player));
    while(fgets(S,1000,fp)!=NULL){
        S[strlen(S)-1]='\0';
        temp=malloc(sizeof(struct player));
        strcpy(temp->name,S);
        if(len==0){
            strcpy(first->name,temp->name);
            first->next=first;
            list=first;
        }
        else{
            list->next=temp;
            temp->next=first;
            list=temp;
        }
        len++;
        printf("%s is appended\n",list->name);
    }
    list=first;
    printf("The list data is : \n");
    for(i=0;i<len;i++){
        if(i==0)
            printf("[%s,",list->name);
        else if(i<len-1)
            printf("%s,",list->name);
        else
            printf("%s]\n",list->name);
        list=list->next;
    }
    play();
}
void append(){    //append new node
    int n;
    int i;
    printf("How many node do you want to append?\n");
    scanf("%d\n",&n);
    first=NULL;list=NULL;len=0;
    first=malloc(sizeof(struct player));
    list=malloc(sizeof(struct player));
    while(n--){
        fgets(S,1000,stdin);
        S[strlen(S)-1]='\0';
        temp=malloc(sizeof(struct player));
        strcpy(temp->name,S);
        if(len==0){
            strcpy(first->name,temp->name);
            first->next=first;
            list=first;
        }
        else{
            list->next=temp;
            temp->next=first;
            list=temp;
        }
        len++;
        printf("%s is appended\n",list->name);
    }
    list=first;
    printf("The list data is : \n");
    for(i=0;i<len;i++){
        if(i==0)
            printf("[%s,",list->name);
        else if(i<len-1)
            printf("%s,",list->name);
        else
            printf("%s]\n",list->name);
        list=list->next;
    }
    play();
}
int main(){
    int com=1;
    while(com!=0){
        printf("What do you want to do?\n\n");
        printf("\t(1)Read data from a file\n");
        printf("\t(2)Append new node\n");
        printf("\t(0)Exit\n");
        scanf("%d",&com);
        if(com==1)
            read();
        if(com==2)
            append();
    }
    return 0;
}
