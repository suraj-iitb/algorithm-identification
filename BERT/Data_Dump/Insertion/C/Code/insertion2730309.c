#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, size, str;
    int *num; // 割り振られた領域のアドレスを格納するためのint型のポインタnumを宣言
    
    scanf("%d", &size);
    num = (int *)malloc(size * sizeof(int));
    if(num == NULL)exit(0);
    for(i=0; i < size; i++){
        scanf("%d", &num[i]);
    }
    for(i=0; i < size; i++){
        for(j=0; j < size; j++){ // 配列の内容を表示
            printf("%d", num[j]);
            if(j < size-1)printf(" ");
        }
        printf("\n");
        if(num[i] > num[i+1]){
            str = num[i+1];
            num[i+1] = num[i];
            num[i] = str;
            for(j=i; j > 0; j--){
                if(num[j-1] > num[j]){
                    str = num[j-1];
                    num[j-1] = num[j];
                    num[j] = str;
                }
                else break;
            }
        }
    }
    free(num);
    return 0;
}

