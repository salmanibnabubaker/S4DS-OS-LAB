#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
void displaydetails(int n,int p[n],int allo[n]){
    printf("pro\tsize\tbno\n");
    for(int i=0;i<n;i++){
        printf("P-%d\t%d\t\t%d\n",i,p[i],allo[i]);
    }
}
void first_fit(int n,int m,int p[n],int b[m]){
    int allo[n];
    
    for(int i=0;i<n;i++){
        allo[i]=-1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(p[i]<=b[j]){
                b[j]-=p[i];
                allo[i]=j;
                break;
            }
        }
    }
    displaydetails(n,p,allo);
}
void best_fit(int n,int m,int p[n],int b[m]){
    int allo[n];
    
    for(int i=0;i<n;i++){
        allo[i]=-1;
    }
    int diff,index;
    for(int i=0;i<n;i++){
        diff=INT_MAX;
        index=-1;
        for(int j=0;j<m;j++){
            if((b[j]>p[i])&&(b[j]-p[i])<diff){
                diff=b[j]-p[i];
                index=j;
            }
        }
        if(index!=-1){
            allo[i]=index;
            b[index]-=p[i];
        }
    }
    displaydetails(n,p,allo);
}
void worst_fit(int n,int m,int p[n],int b[m]){
    int allo[n];
    
    for(int i=0;i<n;i++){
        allo[i]=-1;
    }
    int diff,index;
    for(int i=0;i<n;i++){
        diff=INT_MIN;
        index=-1;
        for(int j=0;j<m;j++){
            if((b[j]>p[i])&&(b[j]-p[i])>diff){
                diff=b[j]-p[i];
                index=j;
            }
        }
        if(index!=-1){
            allo[i]=index;
            b[index]-=p[i];
        }
    }
    displaydetails(n,p,allo);
}
void main(){
    int n,m,sel=1;
    while(sel!=4){
            printf("enter\n1.first fit\n2.best fit\n3.first fit\n4.exit\n");
            scanf("%d",&sel);
            if(sel!=4){
                printf("enter no of processes:");
                scanf("%d",&n);
                printf("enter no of blocks:");
                scanf("%d",&m);
                int p[n],b[m];
                for(int i=0;i<n;i++){
                    printf("enter size of P-%d:",i);
                    scanf("%d",&p[i]);
                }
                for(int i=0;i<m;i++){
                    printf("enter size of block-%d:",i);
                    scanf("%d",&b[i]);
                }
                switch(sel){
                    case 1:first_fit(n,m,p,b);break;
                    case 2:best_fit(n,m,p,b);break;
                    case 3:worst_fit(n,m,p,b);break;
                    default:printf("invalid choice\n");break;
                }
            }
    }
    
}
