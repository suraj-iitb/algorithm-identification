#include <stdio.h>
#include <stdlib.h>


int main()
{   int count=0;
    int n;
    scanf("%d",&n);
    int Arr[n];


    void merge(int arr[],int left, int mid, int right){
        int len = right-left+1;
        int temp[len];
        int i=left;
        int j=mid+1;
        for(int k=0; k<len; k++, count++){
            if(i>mid){
                temp[k]=arr[j];
                j++;
            } else if (j>right) {
                temp[k]=arr[i];
                i++;
            } else {
                if(arr[i]>arr[j]){
                    temp[k]=arr[j];
                    j++;
                } else {
                    temp[k]=arr[i];
                    i++;
                };
            };
        };
        for(int i =0;i<len; i++){
            arr[left+i]=temp[i];
        };
    };

    void mergesort(int arr[], int left, int right)
{
    if (left < right) {
        int mid = (left+right) / 2;
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);
        merge(arr,left,mid,right);
    };
}

    for(int i=0; i<n; i++){
        scanf("%d",&Arr[i]);
    };
    mergesort(Arr,0,n-1);

    for(int i=0; i<n; i++){
        if(i==n-1){
            printf("%d\n",Arr[i]);
            break;
        }
        printf("%d ",Arr[i]);
    };
    printf("%d\n",count);


    return 0;
}

