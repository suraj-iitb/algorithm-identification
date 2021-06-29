#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trace(int A[], int n){
  int i;
  for ( i = 0; i < n; i++ ){
    if ( i > 0 ) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

int count = 0;

void doMS(int A[], int head, int len)
{
    if (len < 2)
        return;
    int toplen = len / 2;
    int botlen = len - toplen;
    int tophead = head;
    int bothead = tophead + toplen;
    doMS(A, tophead, toplen);
    doMS(A, bothead, botlen);
    // merge top and bottom
    int res[len];
    int i = tophead;
    int j = bothead;
    int res_i = 0;
    while (i < tophead + toplen || j < bothead + botlen)
    {
        if (i >= tophead + toplen)
        {
            memcpy(res + res_i, A + j, sizeof(int) * (bothead + botlen - j));
            count += bothead + botlen - j;
            break;
        }
        if (j >= bothead + botlen)
        {
            memcpy(res + res_i, A + i, sizeof(int) * (tophead + toplen - i));
            count += tophead + toplen - i;
            break;
        }
        res[res_i++] = A[i] > A[j] ? A[j++] : A[i++];
        count++;
    }
    memcpy(A + head, res, sizeof(int) * len);
}

int main(){
    int n, i, j, key, temp;
    int *A;
    //extern count;
    scanf("%d", &n);
    A = malloc(sizeof(int) * n);

    for ( i = 0; i < n; i++ ) scanf("%d", &A[i]);
    
    doMS(A, 0, n);
    trace(A, n);
    printf("%d\n", count);

    return 0;
}

/* 
8 5 9 2 6 3 7 1 10 4
*/
