#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    unsigned long long int max;
    int i,j,k;
    int tmp;
    int n;
    int m;
    int cnt = 0;
    unsigned long long int a[20000];
    scanf("%d",&n);
    for (i = 0; i < n; i++) {
        scanf("%lld",&a[i]);
    }
    for (i = 0; i < n-1; i++) {
        for (j = n-1; j > i; j--) {
            if(a[j-1] > a[j]) {
                tmp = a[j-1] ; a[j-1] = a[j]; a[j] = tmp;
                cnt++;
            }
        }
    }
    for(i = 0; i < n-1; i++) 
        printf("%d ",a[i]);
    printf("%d\n",a[n-1]);
    printf("%d\n",cnt);
    return 0;
}
