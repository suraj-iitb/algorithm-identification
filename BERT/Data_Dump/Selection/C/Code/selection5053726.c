#include <stdio.h>

#define N_LIMIT 100

int selectionsort(int *,int);

int main (){
    int a[N_LIMIT],i,n,cnt;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    cnt = selectionsort(a,n);
    
    for(i=0;i<n;i++){
        if(i==n-1) printf("%d\n",a[i]);
        else printf("%d ",a[i]);
    }

    printf("%d\n",cnt);

    return 0;
}

int selectionsort(int *a,int n){
    int i,j,cnt=0,mini,rep;

    for(i=0;i<n;i++){
        mini = i;
        for(j=i;j<n;j++){
            if(a[j] < a[mini])mini = j;
        }
        
        if(mini != i){
            rep = a[i];
            a[i] = a[mini];
            a[mini] = rep;
            cnt++;
        }
    }

    return cnt;
}

