#include<stdio.h>

int main(){
    int a[100], n, N, tmp, cnt=0, minj, i;

    scanf("%d", &N);
    n=N;
    for(int i=0;;i++){

        if(n==0){
            break;
        }else{
            scanf("%d",&a[i]);
            n=n-1;
        }
    }
    for(i=0;i<N;i++){
        minj = i;
        for(int j=i;j<N;j++){
            if(a[j]<a[minj]){
                minj = j;
            }
        }
        if(i!=minj){
            cnt ++;
        }
        tmp = a[i];
        a[i] = a[minj];
        a[minj] = tmp;


    }
    for(int i=0;i<N;i++){
        printf("%d",a[i]);
        if(i==N-1){
            printf("\n");
            break;
        }
        printf(" ");
    }
    printf("%d\n", cnt);

    return 0;

}
