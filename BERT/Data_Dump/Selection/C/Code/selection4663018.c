#include<stdio.h>
int selectionSort(int a[], int n){
    int i, j, p, minj;
    int count=0;
    for(i=0;i<n;i++){
        minj=i;
        for(j=i;j<n;j++){
            if(a[j]<a[minj]){
                minj=j;
            }
        }
        if(minj != i){
            p=a[i];
            a[i]=a[minj];
            a[minj]=p;
            count++;
        }
    }
    return count;
}

int main(){
    int n,i,date[1000];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&date[i]);
    }
    int count=selectionSort(date,n);
    
    for(i=0;i<n-1;i++){
        printf("%d ",date[i]);
    }
    printf("%d\n%d\n",date[n-1],count);
    return 0;
}
