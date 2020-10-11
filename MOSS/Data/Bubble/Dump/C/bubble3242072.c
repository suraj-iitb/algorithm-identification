#include <stdio.h>
int bubblesort(int A[],int N) {
    int temp = 0;
    int x = 0;
    int flag = 1;
    while(flag == 1){
    flag = 0;    
        for (int j = N - 1; j >= 1; j--) {
            if (A[j] < A[j - 1]) {
                temp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = temp;
                flag = 1;
                x++;
             }
        }
    }
    return x;
}
int main() {
    int n,c,i;
    int a[100];
    c = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    c = bubblesort(a, n);
    for(i=0; i<n-1; i++)
        printf("%d ",a[i]);
    printf("%d\n",a[n-1]);
    printf("%d\n",c);
    
    return 0;
}
