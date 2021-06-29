#include<stdio.h>
void swap(int *a,int *b){
    int t=*a;
    *a = *b;
    *b = t;
    return;
}
int bubble(int n, int a[]){
    int i, j, flag, sw=0;
    flag=1;
    for(i=0;flag;i++){
        flag=0;
        for(j=n-1;j>=i+1;j--){
            if(a[j] < a[j-1]){
                swap(&a[j], &a[j-1]);
                flag=1;
                sw++;
            }
        }
    }
    return sw;
}
int main(void){
    int n, sw, i, a[100];
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    sw = bubble(n, a);
    for(i=0;i<n;i++) {
        if(i){
            printf(" ");
        }
        printf("%d",a[i]);
    }
    printf("\n%d\n",sw);
    return 0;
}
