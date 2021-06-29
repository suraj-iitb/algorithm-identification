#include <stdio.h>
#include <stdlib.h>

int SelectionSort(int,int *);

int main(){
    int n,i;
    int *buffer;
    int cnt;

    scanf("%d",&n);

    buffer =(int *)malloc(sizeof(int)*n);

    for(i=0;i<n;i++){
        scanf("%d",&buffer[i]);
    }

    cnt = SelectionSort(n,buffer);

    for ( i = 0; i < n; i++){
        if(i==n-1)printf("%d\n",buffer[i]);
        else printf("%d ",buffer[i]);
    }

    printf("%d\n",cnt);
    
    return 0;
}

int SelectionSort(int n,int *A){
    int i,j,cnt=0,k;
    int mini,tmp;

    for(i=0;i<n;i++){
        mini=i;
        for ( j = i; j < n; j++){
            if(A[j]<A[mini]){
                mini = j;
            }
        }
        if(i!=mini)cnt++;
        tmp=A[mini];
        A[mini]=A[i];
        A[i]=tmp;
    }
        
    return cnt;
}
