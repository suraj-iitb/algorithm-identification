#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,temp,mini,swap=0;
    scanf("%d",&n);
    int arr[n];
    for(int k=0;k<n;k++){
        scanf("%d",&arr[k]);
    };

    for(int i=0; i<n;i++){
        mini=i;
        for(int j=i; j<n; j++){
            if(arr[j]<arr[mini]){
                mini=j;
            };
        };
        if(mini!=i){
            temp = arr[i];
            arr[i]=arr[mini];
            arr[mini]=temp;
            swap++;
        }
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

