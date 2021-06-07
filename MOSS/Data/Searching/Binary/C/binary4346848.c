#include <stdio.h>

int binary(int *A, int n, int key){
    int begin = 0, end = n, mid;

    while(begin < end){
        mid = (begin + end) / 2;
        if (A[mid] == key){
            return 1;
        }else if (A[mid] > key){
            end = mid;
        }else{
            begin = mid + 1;
        }
    }

    return 0;
}


int main(void){
    int n, S[100000], q, key, sum = 0;

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &S[i]);
    }

    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        scanf("%d", &key);
        if(binary(S, n, key)){
            sum++;
        }
    }

    printf("%d\n", sum);
    return 0;
}

/*5
1 2 3 4 5
3      
3 4 1*/
