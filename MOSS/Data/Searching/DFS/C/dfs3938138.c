#include <stdio.h>

int search(int a[100][100],int stamp[100][2],int n,int num,int ntime){
    int i;
    stamp[num][0] = ntime;
    for(i=0;i<n;i++){
        if(a[num][i]==1&&stamp[i][0]==0){
            ntime = search(a,stamp,n,i,ntime+1);
        }
    }
    stamp[num][1] = ntime+1;
    return ntime+1;
}

int main(void){
    int n,i,j,u,k,l,time=0;
    int a[100][100];
    int stamp[100][2];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        stamp[i][0]=0;
        stamp[i][1]=0;
        for(j=0;j<n;j++){
            a[i][j] = 0;
        }
    }
    for(i=0;i<n;i++){
        scanf("%d",&u);
        scanf("%d",&k);
        for(j=0;j<k;j++){
            scanf("%d",&l);
            a[u-1][l-1] = 1;
        }
    }
    for(i=0;i<n;i++){
        if(stamp[i][0]==0){
            time = search(a,stamp,n,i,time+1);
        }
    }
    for(i=0;i<n;i++){
        printf("%d %d %d\n",i+1,stamp[i][0],stamp[i][1]);
    }
}
