#include<stdio.h>
void DFS();
void search(int);
int n,data[100][100],flag[100],k,x[100],y[100];
int main(){
    int k,v,i,j,u;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            data[i][j]=0;
        }
    }
    for(i=0;i<n;i++){
        scanf("%d %d",&u,&k);
        u=u-1;
        for(j=0;j<k;j++){
            scanf("%d",&v);
            v=v-1;
            data[u][v]=1;
        }
    }
    DFS();
}
void DFS(){
    int i;
    k=0;
    for(i=0;i<n;i++){
        flag[i]=0;
    }
    for(i=0;i<n;i++){
        if(flag[i]==0)search(i);
    }
    for(i=0;i<n;i++){
        printf("%d %d %d\n",i+1,x[i],y[i]);
    }
}
void search(int i){
    int j;
    flag[i]=1;
    x[i]=++k;
    for(j=0;j<n;j++){
        if(data[i][j]==0)continue;
        if(flag[j]==0)search(j);
    }
    flag[i]=2;
    y[i]=++k;
}
