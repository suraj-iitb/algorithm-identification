#include <stdio.h>
#define max 100

int bubbleSort(int*,int);

int main(){
    int n,num[max],count;

    scanf("%d",&n);

    for(int i = 0;i<n;i++){
        scanf("%d",&num[i]);
    }

    count = bubbleSort(num,n);

    for(int i = 0;i < n;i++){
        printf("%d",num[i]);
        if(i < n-1)printf(" ");
    }

    printf("\n%d\n",count);

    return 0;
}

int bubbleSort(int *num,int n){
    int tmp;
    int count = 0;
    int flog = 1;
    int i = 0;

    while(flog){
        flog = 0;
        for(int j = n-1;j > i;j--){
            if(num[j] < num[j-1]){
                tmp = num[j];
                num[j] = num[j-1];
                num[j-1] = tmp;
                count++;
                flog = 1;
            }
        }
        i++;
    }

    return count;
}
