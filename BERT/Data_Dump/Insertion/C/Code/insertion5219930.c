#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    int key , j, loop;
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    };


    for(int i=0;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && key<arr[j]){
          arr[j+1] = arr[j];
          j--;
         };
        arr[j+1]=key;
        for(loop=0; loop<n;loop++){
            if(n-1==loop){
                printf("%d\n",arr[loop]);
            }
            else{
                printf("%d ",arr[loop]);
            };
        };
    };

    return 0;
}

