#include<stdio.h>
#include<stdbool.h>

void bankersalgorithm(int n,int m,int allocated[n][m],int need[n][m],int available[m]){
    int safesequence[n],index=0;
    bool done[n];
    for(int i=0;i<n;i++){
        safesequence[i]=-1;
        done[i]=false;
    }
    bool notstopped=true;
    while(notstopped){
        notstopped=false;
        for(int i=0;i<n;i++){
            if(done[i]==false){
                bool nowavailable=true;
                for(int j=0;j<m;j++){
                    if(need[i][j]>available[j]){
                        nowavailable=false;
                        break;
                    }
                }
                if(nowavailable){
                    printf("P-%d executes and leaves,releases resources held by it\nnew available resource instances:\n",i);
                    for(int j=0;j<m;j++){
                        available[j]+=allocated[i][j];
                        printf("%c:%d\n",(char)(j+65),available[j]);
                    }
                    safesequence[index]=i;
                    index++;
                    done[i]=true;
                    notstopped=true;
                    
                }
            }
        }
    }
    bool completed=true;
    for(int i=0;i<n;i++){
        if(done[i]==false){
            completed=false;
        }
    }
    if(completed){
        printf("State-S\nsafe sequence is:\n");
        for(int i=0;i<n;i++){
            printf("p-%d\t",safesequence[i]);
        }
    }
    else{
        printf("deadlock condition arised\n");
    }

}
void main(){
    int n,m;
    printf("enter no of resource types:");
    scanf("%d",&m);
    printf("enter no of processes:");
    scanf("%d",&n);
    
    int allocated[n][m],max[n][m],need[n][m],available[m];
    
    for(int i=0;i<n;i++){
        printf("enter allocated resource instances for P-%d\n",i);
        for(int j=0;j<m;j++){
            printf("%c:",(char)(j+65));
            scanf("%d",&allocated[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        printf("enter requested resource instances for P-%d\n",i);
        for(int j=0;j<m;j++){
            printf("%c:",(char)(j+65));
            scanf("%d",&need[i][j]);
        }
    }
    printf("enter available resource instances:\n");
    for(int j=0;j<m;j++){
        printf("%c:",(char)(j+65));
        scanf("%d",&available[j]);
    }
    bankersalgorithm(n,m,allocated,need,available);
}
