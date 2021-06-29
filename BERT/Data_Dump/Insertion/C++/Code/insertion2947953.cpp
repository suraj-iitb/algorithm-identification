#include <cstdio>
#include <algorithm>
int A[100],v,j;

int main(){
    int N;
    scanf("%d",&N);
    for(int i = 0;i < N;i++)
        scanf("%d",&A[i]);
    for(int k = 0;k < N;k++){
        if(k)
            printf(" ");
        printf("%d",A[k]);
    }
    printf("\n");
    for(int i = 1;i < N;i++){
        v = A[i];
        j = i - 1;
        while(j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        for(int k = 0;k < N;k++){
            if(k)
                printf(" ");
            printf("%d",A[k]);
        }
        printf("\n");
    }

    return 0;
}
