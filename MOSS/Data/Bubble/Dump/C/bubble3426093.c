#include <stdio.h>

void bubblesort(int n,int *a){
    int flag = 1;
    int i,j,tmp,count;
    count = 0;
    i = 0;
    while(flag){
        flag = 0;
        for(j = n-1; j > i;j--){
            if(a[j] < a[j-1]){
                tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
                flag = 1;
                count++;
            }
        }
        i++;
    }

    for(j = 0; j < n; j++ ){
        if(j == 0){
            printf("%d",a[j]);
        }else{
            printf(" %d", a[j]);
        }
    }
    putchar('\n');
    printf("%d\n",count);
}

int main() {

    int n,i,count;
    count = 0;
    int a[101] = {};

    scanf("%d",&n);

    for(i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    bubblesort(n,a);

    return 0;
}

