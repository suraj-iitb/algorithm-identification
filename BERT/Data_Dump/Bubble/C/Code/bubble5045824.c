#include <stdio.h>

#define N_LIMIT 100 // integer N limit

int bubblesort(int *,int);

int main(){
    int a[N_LIMIT],i,n,cnt;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    cnt = bubblesort(a,n);

    for(i=0;i<n;i++){
        if (i!=n-1)printf("%d ",a[i]); 
        else printf("%d\n",a[i]);
    }

    printf("%d\n",cnt);

    return 0;
}

int bubblesort(int *a,int n){
    int i,j,cnt=0,rep;//replace elements of A[] to swap

    for(i=0;i<n;i++){
        for(j=n-1;j>=i+1;j--){
            if(a[j] < a[j-1]){
                cnt++;
                rep = a[j];
                a[j] = a[j-1];
                a[j-1] = rep;
            }
        }
    }

    return cnt;
}
