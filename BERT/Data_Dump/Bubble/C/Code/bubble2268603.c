#include<stdio.h>

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int bubblesort(int n,int *r){
    int flag = 1;
    int i;
    int cnt=0;
    while(flag){
        flag = 0;
        for(i=n-1;i>0;i--){
            if(r[i]<r[i-1]){
                swap(&r[i], &r[i-1]);
                cnt++;
                flag = 1;
            }
        }
    }
    return cnt;
}

int main(){
    int n,i;
    int r[100];
    int res;
    
    scanf("%d", &n);
    for(i=0;i<n;i++) scanf("%d", &r[i]);

    res = bubblesort(n, r);
    for(i=0;i<n;i++) {
        printf("%d", r[i]);
        if(i+1<n) printf(" ");
    }
    printf("\n");
    printf("%d\n", res);
    return 0;
}
