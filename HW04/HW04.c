#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    int n;
    struct node *lc;
    struct node *rc;
}node;
node *root,*now,*pre,*temp,*temp2;
char T[10];
void insert(int in){
    temp=malloc(sizeof(node));
    temp->n=in;
    temp->lc=NULL;
    temp->rc=NULL;
    if(root==NULL)
        root=temp;
    else{
        now=root;
        while(1){
            if(temp->n<now->n){
                if(now->lc==NULL){
                    now->lc=temp;
                    break;
                }
                else
                    now=now->lc;
            }
            else{
                if(now->rc==NULL){
                    now->rc=temp;
                    break;
                }
                else
                    now=now->rc;
            }
        }
    }
}
void delete(int in){
    int dir;
    now=root;
    pre=NULL;
    while(1){
        if(in<now->n){
            pre=now;
            now=now->lc;
            dir=0;
        }
        else if(in>now->n){
            pre=now;
            now=now->rc;
            dir=1;
        }
        else
            break;
    }
    if(now->lc==NULL&&now->rc==NULL){
        if(pre==NULL)
            root=NULL;
        else if(dir==0)
            pre->lc=NULL;
        else
            pre->rc=NULL;
    }
    else if(now->rc==NULL){
        temp=now->lc;
        now->n=temp->n;
        now->lc=temp->lc;
        now->rc=temp->rc;
    }
    else if(now->lc==NULL){
        temp=now->rc;
        now->n=temp->n;
        now->lc=temp->lc;
        now->rc=temp->rc;
    }
    else{
        temp=now->rc;
        pre=NULL;
        while(temp->lc!=NULL){
            pre=temp;
            temp=temp->lc;
        }
        now->n=temp->n;
        if(temp->rc==NULL&&pre!=NULL){
            pre->lc=NULL;
        }
        else if(temp->rc!=NULL){
            temp2=temp->rc;
            temp->n=temp2->n;
            temp->lc=temp2->lc;
            temp->rc=temp2->rc;
        }
    }
}
int search(int in){
    now=root;
    while(1){
        if(in<now->n){
            if(now->lc!=NULL)
                now=now->lc;
            else
                return 0;
        }
        else if(in>now->n){
            if(now->rc!=NULL)
                now=now->rc;
            else
                return 0;
        }
        else
            return 1;
    }
}
void inorder(node *pr){
    if(pr==NULL)
        return;
    inorder(pr->lc);
    printf("%d ",pr->n);
    inorder(pr->rc);
}
void lvorder(){
    node *queue[1000];
    int front=0,rear=0;
    queue[rear++]=root;
    while(front!=rear){
        if(queue[front]->lc)
            queue[rear++]=queue[front]->lc;
        if(queue[front]->rc)
            queue[rear++]=queue[front]->rc;
        printf("%d ",queue[front++]->n);
    }
}
void BST(){
    char com='\0';
    int k;
    int found;
    root=NULL;
    while(com!='R'&&com!='r'){
        printf("(I)Insert a number\n");
        printf("(D)Delete a number\n");
        printf("(S)Search a number\n");
        printf("(P)Print Infix & Level order\n");
        printf("(R)Return\n");
        scanf("%c",&com);
        if(com=='I'||com=='i'){
            printf("Enter a number : ");
            scanf("%d",&k);
            if(root==NULL)
                found=0;
            else
                found=search(k);
            if(!found){
                insert(k);
                printf("Number %d is inserted.\n",k);
            }
            else
                printf("Error.Number %d is exists.\n",k);
        }
        else if(com=='D'||com=='d'){
            printf("Enter a number to delete : ");
            scanf("%d",&k);
            if(root==NULL)
                found=0;
            else
                found=search(k);
            if(found){
                delete(k);
                printf("Number %d is deleted.\n",k);
            }
            else
                printf("Number not found.\n");
        }
        else if(com=='S'||com=='s'){
            printf("Enter the element to search : ");
            scanf("%d",&k);
            if(root==NULL)
                found=0;
            else
                found=search(k);
            if(found)
                printf("Bingo!Number is found.\n");
            else
                printf("Sorry.Number not found.\n");
        }
        else if(com=='P'||com=='p'){
            printf("The tree in infix order : ");
            inorder(root);
            printf("\n");
            printf("The tree in level order : ");
            lvorder();
            printf("\n");
        }
        gets(T);
    }
}
void travel(int key,int tre){
    int RK[1000],RT[1000],R[2000];
    int i=0,j=0,k=0;
    memset(RK,-1,sizeof(RK));
    memset(RT,-1,sizeof(RT));
    now=root;
    while(1){
        RK[i++]=now->n;
        if(key<now->n)
            now=now->lc;
        else if(key>now->n)
            now=now->rc;
        else
            break;
    }
    now=root;
    while(1){
        RT[j++]=now->n;
        if(tre<now->n)
            now=now->lc;
        else if(tre>now->n)
            now=now->rc;
        else
            break;
    }
    while(k<i-1){
        R[k]=RK[k];
        k++;
    }
    i--;
    while(RK[i]!=RT[i])
        R[k++]=RK[i--];
    while(i<j)
        R[k++]=RT[i++];
    for(i=0;i<k;i++){
        if(i<k-1)
            printf("%d->",R[i]);
        else
            printf("%d\n\n",R[i]);
    }
}
void TH(){
    FILE *fp;
    char F[1000];
    int k,key,tre,bom,t;
    int K[1000];
    int f1,f2;
    int i=0,j;
    root=NULL;
    printf("Please input the map file : ");
    scanf("%s",F);
    if(fp=fopen(F,"r"))
        printf("Load file success.\n\n");
    else{
        printf("Not such file.Return.\n\n");
        return;
    }
    while(fscanf(fp,"%d",&k)!=EOF){
        insert(k);
        K[i++]=k;
    }
    fclose(fp);
    printf("Please input the key location : ");
    scanf("%d",&key);
    printf("Please input the treasure location : ");
    scanf("%d",&tre);
    printf("Please input the bomb number (0~9) : ");
    scanf("%d",&bom);
    for(j=0;j<i;j++){
        k=K[j];
        for(t=k;t>0;t/=10)
            if(t%10==bom){
                delete(k);
                printf("Number %d is deleted.\n",k);
                break;
            }
    }
    printf("\n");
    f1=search(key);
    f2=search(tre);
    if(f1&&f2){
        printf("Adventurer successfully found the treasure.\n");
        printf("Shortest path to find the treasure:\n");
        travel(key,tre);
    }
    else
        printf("Adventurer fail to find the treasure.\n\n");
}
int main(){
    int game=0;
    while(game!=3){
        printf("(1)Binary Search Tree\n");
        printf("(2)Treasure Hunter\n");
        printf("(3)Exit\n");
        scanf("%d",&game);
        gets(T);
        if(game==1)
            BST();
        else if(game==2)
            TH();
    }
    return 0;
}
