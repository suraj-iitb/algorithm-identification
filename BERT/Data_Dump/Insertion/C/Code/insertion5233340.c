#include<stdio.h>

int main(void){
    int n;
    int a[101];
    int i, j, v;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    for(j=0;j<n;j++){
        if(j==n-1){
            printf("%d\n",a[j]);
        }else{
            printf("%d ",a[j]);
        }
    }
    for(i=1;i<n;i++){
        j = i - 1;
        while(j>=0&&a[j]>a[j+1]){
            v = a[j+1];
            a[j+1] = a[j];
            a[j] = v;
            j--;
        }
        for(j=0;j<n;j++){
            if(j==n-1){
                printf("%d\n",a[j]);
            }else{
                printf("%d ",a[j]);
            }
        }
    }
}
