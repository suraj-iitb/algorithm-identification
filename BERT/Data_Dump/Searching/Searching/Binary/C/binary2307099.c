#include<stdio.h>
#define N 100000
#define Q 50000

int Search();

int S[N];
int n, key;

int main(){
    int T[Q];
    int q, i;
    int count = 0;

    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &S[i]);
    }

    scanf("%d", &q);
    for(i = 0; i < q; i++){
        scanf("%d", &T[i]);
    }

    for(i = 0; i < q; i++){
        key = T[i];
        if(Search() == 1) count++;
    }

    printf("%d\n",count);

    return 0;
}

int Search(){
    int mid;
    int left = 0;
    int right = n;

    while(left < right){
        mid = (left + right) / 2;

        if(key == S[mid]) return 1;
        else if(key > S[mid]){
            left = mid + 1;
        }
        else right = mid;
    }

    return 0;
}
