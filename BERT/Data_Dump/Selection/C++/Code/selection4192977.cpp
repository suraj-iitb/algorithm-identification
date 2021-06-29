#include<stdio.h>

int selectionSort(int a[],int n){
    int sw=0,i,j,temp,minj;
    for( i=0;i<n-1;i++){
        minj=i;
        for( j=i;j<n;j++){
            if(a[minj]>a[j])minj=j;
        }
            temp=a[i];
            a[i]=a[minj];
            a[minj]=temp;
            if(minj!=i)sw++;
     }
     return sw;
}   


int main(){
    int sw=0,n,a[100];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sw=selectionSort(a,n);
    for(int i=0;i<n;i++){
        if(i)printf(" ");
        printf("%d",a[i]);
    }
    printf("\n%d\n",sw);
    return 0;
}
