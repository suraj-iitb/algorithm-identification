#include <stdio.h>

int selectsort(int n,int *a){
    int flag = 0;
    int count = 0;
    int i,j,tmp,minj;
    for(i = 0; i < n; i++){
        minj = i;
        for(j = i; j < n; j++){
            if(a[j] < a[minj]){
                minj = j;
                flag = 1;
                //count++;
            }

        }
        tmp = a[i];
        a[i] = a[minj];
        a[minj] = tmp;
        if(flag){
            count++;
            flag = 0;
        }
    }
    return count;
}

int main() {

    int n,i,j,x;
    int a[101] = {};

    scanf("%d",&n);

    for(i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    x = selectsort(n,a);

    for(j = 0; j < n; j++ ){
        if(j == 0){
            printf("%d",a[j]);
        }else{
            printf(" %d", a[j]);
        }
    }
    putchar('\n');
    printf("%d\n",x);
    return 0;
}

