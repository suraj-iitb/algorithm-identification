#include<stdio.h>

int binary_search(int *a, int n, int key)
{
    int left = 0, right = n, mid;
    while(left < right){
        mid = (left + right) / 2;
        if(a[mid] == key) return 1;
        else if(key < a[mid]) right = mid;
        else left = mid + 1;
    }
    return 0;
}

int main()
{
    int i, n, q, key, a[100000], cnt;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    scanf("%d", &q);
    for(i = 0; i < q; i++){
        scanf("%d", &key);
        if(binary_search(a, n, key)) cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
