#include<stdio.h>

int linearSearch(int S[], int n, int key){
    int i=0;

    S[n] = key;

    while(S[i] != key){
        i++;

        if(i==n){
            return 0;
        }
    }

    return 1;
}

int main(){
    int S[500000], key, i, n, q;
    int sum = 0;

    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &S[i]);
    }

    scanf("%d", &q);
    for(i=0; i<q; i++){
        scanf("%d", &key);
        if(linearSearch(S,n,key) == 1)
            sum++;
    }

    printf("%d\n", sum);
    return 0;
}
