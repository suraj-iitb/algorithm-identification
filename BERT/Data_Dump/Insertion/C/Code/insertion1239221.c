#include <stdio.h>
int main()
{
    int N, a[101]={0}, i, j, k, key;
    scanf("%d", &N);
    for(i=0; i<N; i++){
        scanf("%d", &a[i]);
    }
    for(i=1; i<N+1; i++){
        for(k=0; k<N; k++){
            printf("%d", a[k]);
            if(k!=N-1) printf(" ");
        }
        printf("\n");
        key=a[i];
        for(j=i-1; j>=0; j--){
            if(a[j]>key){
                a[j+1]=a[j];
            } else {
                a[j+1]=key;
                break;
            }
            if(j==0){
                a[0]=key;
            }
        }
    }
    return 0;
}
