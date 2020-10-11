#include <stdio.h>

int count[10001], array[2000000], out[2000000];
void Counting_Sort(int in[], int out[], int len, int max){
    int i, j;
    for (i = 0;i < len;i++) count[in[i]]++;
    count[0]--;
    for (i = 1;i <= max;i++) count[i] += count[i - 1];
    for (i = len - 1;i >= 0; i--) {
        out[count[in[i]]] = in[i];
        count[in[i]]--;
    }
    return;
}

int main(){
    int n, i;
    scanf("%d", &n);
    for (i = 0;i < n;i++)  scanf("%d", array + i);
    Counting_Sort(array, out, n, 10000);
    
    for (i = 0;i < n - 1;i++) printf("%d ", out[i]);
    printf("%d\n", out[i]);
    
    return 0;
}
