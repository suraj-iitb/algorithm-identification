/*
 * FileName:     depth_first_search_fix
 * CreatedDate:  2020-04-23 23:10:09 +0900
 * LastModified: 2020-04-24 00:14:45 +0900
 */

#include <stdio.h>
#include <string.h>

void dfs(int u,int *order,int *din,int *matrix,int *color,int n){
    color[u]=1;
    din[u]=*order;
    *order=*order+1;
    for(int v=0;v<n;v++){
        if(matrix[u*n+v]==1&&color[v]==0){
//            printf("%d->%d\n",u+1,v+1);
            din[v]=*order;
//            *order=*order+1;
            dfs(v,order,din,matrix,color,n);
            din[n+v]=*order;
            *order=*order+1;
        }
    }
}
int main(void){
    int n;
    scanf("%d",&n);
    int matrix[n*n];
    memset(matrix,0,sizeof(matrix));
    for(int i=0;i<n;i++){
        int u,k;
        scanf("%d",&u);
        scanf("%d",&k);
        for(int j=0;j<k;j++){
            int v;
            scanf("%d",&v);
            matrix[(u-1)*n+v-1]=1;
        }
    }
/*    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",matrix[i*n+j]);
        }
        printf("\n");
    }*/
    int color[n];
    for(int i=0;i<n;i++){
        color[i]=0;
    }
    int din[n*2],a=1;
    int *order=&a;
    for(int i=0;i<n;i++){
        if(color[i]==0){
//            printf("%d\n",i);
            dfs(i,order,din,matrix,color,n);
            din[n+i]=*order;
            *order+=1;
        }
    }
    for(int i=0;i<n;i++){
        printf("%d %d %d\n",i+1,din[i],din[n+i]);
    }
/*    for(int i=0;i<n;i++){
        printf("%d ",din[i]);
    }
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d ",din[n+i]);
    }*/
    return 0;
}

