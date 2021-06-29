#include <stdio.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void pri(int n, int *a){
    int i;
    for(i = 0;i < n; i++) {
        if(i)printf(" ");
        printf("%d",a[i]);
    }
    printf("\n");
}

void bubbleSort(int n, int *a){
    int flg = 1;
    int cou = 0;
    int i;
    while (flg) {
        flg = 0;
        for(i = n-1; i > 0; i--) {
            if(a[i] < a[i-1]){
                swap(&a[i], &a[i-1]);
                cou++;
                flg = 1;
            }
        }
    }

    pri(n,a);
    printf("%d\n",cou);
}

int main() {
    int n;
    scanf("%d",&n);

    int a[100]={};
    int i;
    for(i = 0;i < n; i++){
        scanf("%d",&a[i]);
    }

    bubbleSort(n,a);
    return 0;
}


