#include <stdio.h>

int n;
int S[100000];

int binary_search(int key){
    int left = 0;
    int right = n;

    while(left < right){
        int middle = (left + right) / 2;
        if(S[middle] == key){
            return 1;
        }else if(S[middle] < key){
            left = middle + 1;
        }else{
            right = middle;
        }
    }

    return 0;
}

int main(void){
    int q;
    int T[50000];
    int res = 0;

    scanf("%d\n", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &S[i]);
    }

    scanf("%d\n", &q);
    for(int i=0; i<q; i++){
        scanf("%d", &T[i]);
        res += binary_search(T[i]);
    }

    printf("%d\n", res);

    return 0;
}
