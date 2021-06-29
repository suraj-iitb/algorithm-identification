#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,temp,swap=0;
    scanf("%d",&n);
    int arr[n];
    for(int k=0;k<n;k++){
        scanf("%d",&arr[k]);
    };

    for(int i=0; i<n;i++){
        for(int j=n-1; j>i; j--){
            if(arr[j]<arr[j-1]){
                temp=arr[j-1];
                arr[j-1]=arr[j];
                arr[j]=temp;
                swap++;
            };
        };
    };
    for(int l=0; l<n; l++){
        if(l==n-1){
            printf("%d\n",arr[l]);
        }
        else{
            printf("%d ",arr[l]);
        };
    };
    printf("%d\n",swap);
}

