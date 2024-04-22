#include<stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void sort_arr(int n,int p[n],int arr_t[n],int burst_t[n]){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr_t[j]>arr_t[j+1]){
                swap(&arr_t[j],&arr_t[j+1]);
                swap(&p[j],&p[j+1]);
                swap(&burst_t[j],&burst_t[j+1]);
            }
        }
    }
}
void fcfs(int n,int p[n],int arr_t[n],int burst_t[n]){
    int 
}
void main(){
    int n;
    printf("enter no of processes:");
    scanf("%d",&n);
    
    int p[n],arr_t[n],burst_t[n];
    printf("enter details for each processes\n");
    for(int i=0;i<n;i++){
        p[i]=i;
        printf("enter arrival time of P-%d:",i);
        scanf("%d",&arr_t[i]);
        printf("enter burst time of P-%d:",i);
        scanf("%d",&burst_t[i]);
    }
    sort_arr(n,p,arr_t,burst_t);
}
