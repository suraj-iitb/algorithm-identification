#include<stdio.h>

int main()
{
  int n,i,j,irekae;
  int cnt=0;

    scanf("%d",&n);

    int A[n];

    for(i = 0;i < n; i++)scanf("%d",&A[i]);

    for(i = 0;i < n; i++)
    {
        for(j = n-1; j > i; j--)
        {
            if(A[j] < A[j-1])
            {
                irekae = A[j-1];
                A[j-1] = A[j];
                A[j] = irekae;
                cnt++;
            }
        }
    }
    for(i = 0;i < n-1; i++)printf("%d ",A[i]);
    printf("%d\n%d\n",A[n-1],cnt);

    return 0;
}
