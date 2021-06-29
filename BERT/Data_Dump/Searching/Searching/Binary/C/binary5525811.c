#include <stdio.h>
#include <stdlib.h>

int search(int arr[], int key, int n){
    int left=0;
    int right=n;
    while(left<right){
        int mid=(left+right)/2;
        if(arr[mid]==key){
            return 1;
        } else if(key<arr[mid]){
            right = mid;
        } else {
            left = mid+1;
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
    int temp;
    int count=0;
    for(int j=0; j<b; j++){
        scanf("%d",&temp);
        count += search(arr1,temp,a);

    };

    printf("%d\n",count);

    return 0;
}

