#include <stdio.h>
#include <math.h>


int binary(int A[], int size, int x)
{
    int low = 0;
    int high = size;
    while (low < high)
    {
        int mid = (low +  high)/2;
        if (A[mid] == x)
        {
            return 1;
        }
        else if (A[mid]>x)
        {
            high = mid;
        }
        else
            low = mid + 1;
    }
    return  0;
}


int main() {

    int n;
    scanf("%d", &n);
    int S[100005];
    int i;
    for (i=0; i<n; i++){
        scanf("%d", &S[i]);
    }

    int  q;
    scanf("%d", &q);
    int T[100005];
    int j;
    for (j=0; j<q; j++){
        scanf("%d", &T[j]);
    }

    int ctr=0;
    for (i=0; i<q; i++)
    {
        if (binary(S, n, T[i]) >0)
            ctr ++;
    }
    printf("%d", ctr);
    printf("\n");
    return 0;
}

