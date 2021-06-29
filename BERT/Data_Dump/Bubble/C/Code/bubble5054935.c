#include<stdio.h>

int main(){
    int a[100], n, N, flag, tmp, cnt=0;

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
    flag = 1;
    while(flag==1){
        flag = 0;
        for(int j=N-1;j>=1;j--){
            if(a[j]<a[j-1]){
                tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
                flag = 1;
                cnt ++;

            }
        }
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
