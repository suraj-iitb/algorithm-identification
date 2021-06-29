#include <stdio.h>
#include <stdlib.h>

int main() {
    int N =0;
    int i,j;
    int sorted=0;
    int data[110];
    int temp;

    scanf("%d",&N);

    for(i = 0; i < N; i++){
        scanf("%d",&data[i]);
    }
    while(sorted < N-1) {

        for(i = 0;i < N-1; ++i){
            printf("%d ",data[i]);
        }
        printf("%d",data[N-1]);

        for (i = 0; i < sorted+1; ++i) {
            if (data[sorted + 1] < data[i]) {
                temp = data[sorted + 1];
                for (j = sorted; j >= i ; --j) {
                    data[j + 1] = data[j];
                }
                data[i] = temp;
                break;
            }
        }


        putchar('\n');
        sorted++;
    }

    for(i = 0;i < N-1; ++i){
        printf("%d ",data[i]);
    }
    printf("%d\n",data[N-1]);


    return 0;
}
