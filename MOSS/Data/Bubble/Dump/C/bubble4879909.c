#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(void){
    int i,j,k, N,count=0;
    scanf("%d", &N);
    int bubble[N];
    for(i=0; i<N; i++){
        scanf("%d", &bubble[i]);
    }
    for(i=0; i<N; i++){
        for(j=0; j<N-1; j++){
            if(bubble[j]>bubble[j+1]){
                k = bubble[j];
                bubble[j] = bubble[j+1];
                bubble[j+1] = k;
                count++;
            }
        }
    }
    for(i=0; i<N; i++){
        if(i)printf(" ");
        printf("%d", bubble[i]);
    }
    printf("\n");
    printf("%d\n", count);
    return 0;
}
