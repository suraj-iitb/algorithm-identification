#include <stdio.h>

int main() {
    int i,j;
    int minj;
    int N;
    int count=0;
    int temp;
    int data[110];
    int flag = 0;

    scanf("%d",&N);

    for(i = 0; i < N; ++i){
        scanf("%d", &data[i]);
    }

    for(i = 0; i < N ; ++i){
        minj = i;
        flag = 0;
        for(j = i ; j < N ; ++j) {
            if (data[minj] > data[j]) {
                minj = j;
                flag = 1;
            }
        }
        if(flag == 1) {
            temp = data[i];
            data[i] = data[minj];
            data[minj] = temp;
            count++;
        }
    }
    for(i = 0; i < N-1; ++i){
        printf("%d ",data[i]);
    }
    printf("%d",data[N-1]);
    putchar('\n');
    printf("%d\n",count);
    return 0;
}
