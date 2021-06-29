# include <stdio.h>
int N = 10000;
void CountingSort(int *, int *, int);

int main(){
    int num[2000003];
    int check[2000003];
    int n, i;

    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &num[i]);
    }
    CountingSort(num, check, i);
    for(i = 1; i < n; i++){
        printf("%d ", check[i]);
    }
    printf("%d\n", check[i]);
    return 0;

}

void CountingSort(int *num, int *check, int i){
    int j, k;
    int C[2000003];
    for (k = 0; k <= N; k++){
         C[k] = 0;
    }
        
     /* C[i] に i の出現数を記録する */
     for (j = 0; j < i; j++){
         C[num[j]]++;
     }

     /* C[i] に i 以下の数の出現数を記録する*/
    for (k = 1; k <= N; k++){
        C[k] = C[k] + C[k-1];
    }

    for (j = i-1; j >= 0; j--){
         check[C[num[j]]] = num[j];
        C[num[j]]--;
    }
}
