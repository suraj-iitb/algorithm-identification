#include<stdio.h>

int sw=0,n,a[100];

void bubbleSort(){
    for(int i=0;i<n;i++){
        for(int j=n-1;j>i;j--){
            if(a[j]<a[j-1]){
                int temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
                sw++;
            }
        }
    }
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    bubbleSort();
    for(int i=0;i<n;i++){
        if(i)printf(" ");
        printf("%d",a[i]);
    }
    printf("\n%d\n",sw);
    return 0;
}
