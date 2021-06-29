#include <stdio.h>
int main(void){
    int n, s;
    scanf("%d", &n);
    int ns[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &ns[i]);
    }
    
    scanf("%d", &s);
    int ss[s];
    for (int i=0; i<s; i++) {
        scanf("%d", &ss[i]);
    }
    
    int c = 0;
    int left, mid, right;
    
    for (int i=0; i<s; i++) {
        left = 0;
        right = n-1;
        while (left <= right) {
            mid = (left+right)/2;
            if (ss[i] == ns[mid]) {
                c++;
                break;
            } else if (ss[i] < ns[mid]) {
                right = mid-1;
            } else if (ss[i] > ns[mid]) {
                left = mid+1;
            }
        }
    }
    
    printf("%d\n", c);
}

