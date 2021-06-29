#include<stdio.h>
#include<stdlib.h>

#define NMAX 2000001
#define AMAX 10000

void print_array(int *, int);

int main()
{
    int i, j, max = 0;
    int c[AMAX + 1];

    for(i = 0 ; i <= AMAX ; i++) {
        c[i] = 0;
    }

    int n;
    scanf("%d", &n);
    if(n < 0 || n >= NMAX) {
        exit(1);
    }
    int a[n + 1], b[n + 1];
    for(i = 1 ; i <= n ; i++) {
        scanf("%d", &a[i]);
        c[a[i]]++;
        if(a[i] < 0 || a[i] > AMAX) {
            exit(2);
        }
        if(max < a[i]) {
            max = a[i];
        }
    }

   /* for(i = 1 ; i <= n ; i++) {
        for(j = 0 ; j <= max ; j++) {
            if(a[i] == j) {
                c[j] += 1;
                break;
            }
        }
    }
*/
    /*for(i = 0 ; i <= max ; i++) {
        printf("%d ",c[i]);
    }
    printf("\n");

*/
    for(i = 0 ; i < max ; i++) {
        c[i + 1] += c[i];
    }


/*    printf("\n");
    for(i = 0 ; i <= max ; i++) {
        printf("%d ",c[i]);
    }
    printf("\n\n");
*/

    for(i = n ; i > 0 ; i--) {
        b[c[a[i]]] = a[i];
        c[a[i]]--;
    }

    print_array(b, n); 

    return 0;
}

void print_array(int *a, int n)
{
    int i;
    for(i = 1 ; i <= n ; i++) {  
        printf("%d",a[i]);
            if(i < n) {
            printf(" ");
        }
    }
    printf("\n");
}
