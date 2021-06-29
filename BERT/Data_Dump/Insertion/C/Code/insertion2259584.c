#include <stdio.h>
int trace(int a[], int N){
    int i;
    for (i = 0; i < N; i++) {
        if (i>0)
            printf(" ");
        printf("%d", a[i]);

    }
    printf("\n");
}
int main(){
    int a,b,c,d;
    int i;
    scanf("%d", &a);
    int array[a];
    for(i=0;i<a;i++){
        scanf("%d", &array[i]);
    }
    trace(array,a);
    for(b=1; b<a; b++) {
        c = array[b];
        d = b - 1;
        while (d >= 0 && array[d] > c) {
            array[d + 1] = array[d];
            d--;
        }//
        array[d + 1] = c;
        trace(array, a);
    }
    return 0;
}
