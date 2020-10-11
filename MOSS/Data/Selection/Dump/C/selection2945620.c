#include <stdio.h>
#define max 100

int selectionSort(int*,int);


int main(){
    int n,num[max];
    int count;

    scanf("%d",&n);

    for(int i = 0;i < n;i++)scanf("%d",&num[i]);

    count = selectionSort(num,n);

    for(int i = 0;i < n;i++){
        printf("%d",num[i]);
        if(i < n-1)printf(" ");
    }

    printf("\n%d\n",count);

    return 0;
}

int selectionSort(int *num,int n){
    int minj,tmp;
    int count = 0;
    int flag;

    for(int i = 0;i < n;i++){
        minj = i;
        flag = 0;
        for(int j = i;j < n;j++){
            if(num[j] < num[minj]){
                minj = j;
                flag = 1;
            }
        }
        if(flag == 1){
            tmp = num[minj];
            num[minj] = num[i];
            num[i] = tmp;
            count++;
        }
    }

    return count;
}
