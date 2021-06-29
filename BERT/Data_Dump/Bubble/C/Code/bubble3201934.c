#include <stdio.h>

int main() {
    int i,j;
    int N = 0;
    int count=0;
    int temp;
    int data[110];

    scanf("%d",&N);
    for (i = 0; i < N; ++i){
        scanf("%d",&data[i]);
    }

    for(i = 0; i < N ; i++){
        for(j = N - 1; j > i ; --j) {
            if (data[j] < data[j - 1]) {
                temp = data[j];
                data[j] = data[j - 1];
                data[j - 1] = temp;
                ++count;
            }
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
