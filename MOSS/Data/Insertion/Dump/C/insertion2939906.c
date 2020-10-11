#include <stdio.h>
void ppp(int arr[], int size){
    int i, j, counter;
    int key = 0;
    for(i=1; i<size+1; i++){
        for(counter=0; counter<size; counter++){
            if(counter>0) printf(" ");
            printf("%d",arr[counter]);
        }
        printf("\n");
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}
int main()
{
    int N;
    scanf("%d", &N);
    if(N<1 || N>100){
        return 0;
    }
    else{
        int arr[N];
        int k = 0;
        for(k=0; k<N; k++){
            scanf("%d",&arr[k]);
        }
        ppp(arr, N);
        //printf("\n");
    }
    return 0;
}

