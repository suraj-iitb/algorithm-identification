#include<stdio.h>
int main(){
    int N,i,j,time,n;
    int num[100];
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&num[i]);
    }
    for(i=0,n=N;i<N;i++,n--){
        for(j=1;j<n;j++){
            if(num[j-1] > num[j]){
                int temp=num[j];
                num[j] = num[j-1];
                num[j-1] = temp;
                time++;
            }
        }
    }
    for(i=0;i<N;i++){
        printf("%d",num[i]);
        if(i<N-1){
            printf(" ");
        }
    }
    printf("\n%d\n",time);
}
