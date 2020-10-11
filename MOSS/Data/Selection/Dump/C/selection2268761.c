#include<stdio.h>

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int selectionsort(int n, int* r){
    int i,j,minj;
    int cnt=0;
    for(i=0;i<n;i++){
        minj = i;
        for(j=i;j<n;j++){
            if(r[j]<r[minj]) minj = j;
        }
        swap(&r[i], &r[minj]);
        if(i!=minj) cnt++;
    }
    return cnt;
}

int main(){
    int n, r[100];
    int i, res;

    scanf("%d", &n);
    for(i=0;i<n;i++) scanf("%d", &r[i]);

    res = selectionsort(n, r);
    for(i=0;i<n;i++){
        printf("%d", r[i]);
        if(i+1<n) printf(" ");
    }
    printf("\n%d\n", res);
    return 0;
}
