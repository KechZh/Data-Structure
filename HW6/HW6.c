#include<stdio.h>
FILE *fp;
int load_file(){
    char F[20];
    printf("Input file : ");
    scanf("%s",F);
    if(fp=fopen(F,"r")){
        printf("Load success.\n\n");
        return 1;
    }
    else{
        printf("Load fail.\n\n");
        return 0;
    }
}
void print_array(int N[],int n,int m){
    int i;
    for(i=0;i<n;i++)
        printf("%3d ",N[i]);
    for(i=0;i<m;i++)
        printf("\n");
}
void copy(int A[],int B[],int n){
    int i;
    for(i=0;i<n;i++)
        A[i]=B[i];
}
void selection_sort(int N[],int n){
    int step=0;
    int min,temp;
    int i,j,k;
    printf("Selection Sort : \n");
    for(i=0;i<n;i++){
        min=0x7FFFFFFF;
        for(j=i+1;j<n;j++)
            if(N[j]<min){
                min=N[j];
                k=j;
            }
        if(min<N[i]){
            temp=N[i];
            N[i]=N[k];
            N[k]=temp;
        }
        print_array(N,n,1);
        step++;
    }
    printf("Total step : %d\n\n",step);
}
void bubble_sort(int N[],int n){
    int step=0;
    int temp;
    int i,j;
    printf("Bubble Sort : \n");
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++)
            if(N[j]>N[j+1]){
                temp=N[j];
                N[j]=N[j+1];
                N[j+1]=temp;
            }
        print_array(N,n,1);
        step++;
    }
    printf("Total step : %d\n\n",step);
}
void insertion_sort(int N[],int n){
    int step=0;
    int temp;
    int i,j,k;
    printf("Insertion Sort : \n");
    for(i=0;i<n;i++){
        temp=N[i];
        for(j=0;j<i;j++){
            if(j==0&&temp<N[j])
                break;
            else if(j==i-1&&temp>=N[j]){
                j++;
                break;
            }
            else if(temp>=N[j-1]&&temp<N[j])
                break;
        }
        for(k=i;k>j;k--)
            N[k]=N[k-1];
        N[j]=temp;
        print_array(N,n,1);
        step++;
    }
    printf("Total step : %d\n\n",step);
}
void quick_sort(int N[],int n,int l,int r){
    if(l>=r)
        return;
    int piv=N[l];
    int i=l,j=r+1;
    if(l==0&&r==n-1)
        printf("Quick Sort : \n");
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
        }
    }while(i<j);
    if(j!=l){
        int temp=N[l];
        N[l]=N[j];
        N[j]=temp;
    }
    print_array(N,n,1);
    quick_sort(N,n,l,j-1);
    quick_sort(N,n,j+1,r);
}
int main(){
    int com=0;
    int in;
    while(1){
        printf("Start to load file?\n");
        printf("(1)Yes.\n");
        printf("(2)No.\n");
        scanf("%d",&com);
        if(com==2)
            break;
        if(load_file()==0)
            continue;
        int N[1000],T[1000];
        int n=0;
        while(fscanf(fp,"%d",&in)!=EOF)
            N[n++]=in;
        printf("Input array : \n");
        print_array(N,n,2);
        copy(T,N,n);
        selection_sort(T,n);
        copy(T,N,n);
        bubble_sort(T,n);
        copy(T,N,n);
        insertion_sort(T,n);
        copy(T,N,n);
        quick_sort(T,n,0,n-1);
    }
    return 0;
}
