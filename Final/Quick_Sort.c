#include<stdio.h>
void print_array(int N[],int n){
    int i;
    for(i=0;i<n;i++){
        if(i<n-1)
            printf("%d ",N[i]);
        else
            printf("%d\n",N[i]);
    }
}
void quick_sort(int N[],int n,int l,int r){
    if(l>=r)
        return;
    int piv=N[l];
    int i=l,j=r+1;
    do{
        do
            i++;
        while(N[i]<piv);
        do
            j--;
        while(N[j]>piv);
        if(i<j){
            int temp=N[i];
            N[i]=N[j];
            N[j]=temp;
            print_array(N,n);
        }
    }while(i<j);
    if(j!=l){
        int temp=N[l];
        N[l]=N[j];
        N[j]=temp;
        print_array(N,n);
    }
    quick_sort(N,n,l,j-1);
    quick_sort(N,n,j+1,r);
}
int main(){
    freopen("4input_3.txt","r",stdin);
    //freopen("4output.txt","w",stdout);
    int N[1000];
    int n=0;
    while(scanf("%d",&N[n])!=EOF)
        n++;
    quick_sort(N,n,0,n-1);
    return 0;
}
