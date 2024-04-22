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
            else if(arr_t[j]==arr_t[j+1]){
                if(burst_t[j]>burst_t[j+1]){
                    swap(&arr_t[j],&arr_t[j+1]);
                    swap(&p[j],&p[j+1]);
                    swap(&burst_t[j],&burst_t[j+1]);
                }
            }
        }
    }
}
void displaydetails(int n,int p[n],int arr_t[n],int burst_t[n],int comp_t[n],int turn_t[n],int wait_t[n]){

    printf("pro\tat\tbt\tct\ttt\twt\n");
    for(int i=0;i<n;i++){
        printf("P-%d\t%d\t%d\t%d\t%d\t%d\n",p[i],arr_t[i],burst_t[i],comp_t[i],turn_t[i],wait_t[i]);
    }
}
void sort_proc(int n,int p[n],int arr_t[n],int burst_t[n],int comp_t[n],int turn_t[n],int wait_t[n]){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j]>p[j+1]){
                swap(&p[j],&p[j+1]);
                swap(&arr_t[j],&arr_t[j+1]);
                swap(&burst_t[j],&burst_t[j+1]);
                swap(&comp_t[j],&comp_t[j+1]);
                swap(&turn_t[j],&turn_t[j+1]);
                swap(&wait_t[j],&wait_t[j+1]);
            }
        }
    }
    
}
void averages(int n,int turn_t[n],int wait_t[n]){
    float a=0,b=0;
    for(int i=0;i<n;i++){
        a+=turn_t[i];
        b+=wait_t[i];
    }
    printf("average turn arounfd time is:%f\naverage waiting time is:%f",a/n,b/n);
}
void fcfs(int n,int p[n],int arr_t[n],int burst_t[n]){
    
    int comp_t[n],turn_t[n],wait_t[n],t=0;
    
    for(int i=0;i<n;i++){
        if(i==0){
            t+=arr_t[i];
        }
        t+=burst_t[i];
        comp_t[i]=t;
        turn_t[i]=comp_t[i]-arr_t[i];
        wait_t[i]=comp_t[i]-burst_t[i];
        
    }
    sort_proc(n,p,arr_t,burst_t,comp_t,turn_t,wait_t);
    displaydetails(n,p,arr_t,burst_t,comp_t,turn_t,wait_t);
    averages(n,turn_t,wait_t);
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
    fcfs(n,p,arr_t,burst_t);
}
