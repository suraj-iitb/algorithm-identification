#include <stdio.h>
#include <stdlib.h>

int linsearch(int arr[], int key, int len){
    for(int i=0; i<len; i++){
        if(arr[i]==key){
            return 1;
        };
    };
    return 0;
}


int main()
{
    int a,b;
    scanf("%d",&a);
    int arr1[a];
    for(int i=0; i<a; i++){
        scanf("%d",&arr1[i]);
    };

    scanf("%d",&b);
    int arr2[b];
    for(int i=0; i<b; i++){
        scanf("%d",&arr2[i]);
    };


    int count=0;
    for(int j=0; j<b; j++){
        count += linsearch(arr1,arr2[j],a);
    };

    printf("%d\n",count);
    return 0;
}

