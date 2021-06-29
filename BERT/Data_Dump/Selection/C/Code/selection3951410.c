#include <stdio.h>
int selectionSort(int a[],int n){
    int ct=0,i,j,min_index,tmp;
    for(i = 0;i<n-1;i++){
        min_index = i;
        for(j =i;j<n;j++){
            if(a[min_index]>a[j]){
                min_index = j;
            }
        }
        if(i != min_index){
        tmp = a[i];
        a[i] = a[min_index];
        a[min_index]=tmp;
        ct++;
        }
    }
    return ct;
}
int main(){
    int a[100];
    int n,ct,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    ct = selectionSort(a,n);
    for(i =0;i<n-1;i++){
        printf("%d ",a[i]);
    }
    printf("%d\n%d\n",a[n-1],ct);
    return 0;
}
