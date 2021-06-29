#include <stdio.h>

#define N_LIMIT 100 // integer N limit

void insertionSort(int *,int);
int main(){
    int a[N_LIMIT],n,i,j;

    scanf("%d",&n);
    for(i=0;i<n;i++){
    scanf("%d",&a[i]);
    }

    for(i=0;i<n;i++){
            if(i!=n-1)printf("%d ",a[i]);
            else printf("%d",a[i]);
        }
    printf("\n");
    

    insertionSort(a,n);

    return 0;
}

void insertionSort(int *a,int n){
    int i,j,k,key;

    for(i=1;i<n;i++){
        key = a[i];
        //insert a[i] into the sorted sequence a[0,...,i-1]
        j = i-1;
        while (j >= 0 && a[j] > key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
        for(k=0;k<n;k++){
            if(k!=n-1)printf("%d ",a[k]);
            else printf("%d",a[k]);
        }
        printf("\n");
    }
}
