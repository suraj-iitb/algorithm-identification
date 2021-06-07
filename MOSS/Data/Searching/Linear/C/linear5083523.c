#include <stdio.h>

int search(int *arr, int n, int key){
    int i = 0;
    arr[n] = key;
    for(; arr[i] != key; i++);
    return i != n;
}

int main(){
    int i, n, arr[10001], q, key, sum = 0;

    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    scanf("%d", &q);
    for(i = 0; i < q; i++){
        scanf("%d", &key);
        if(search(arr, n, key)){
            sum++;
        }
    }
    printf("%d\n", sum);

    return 0;
}
