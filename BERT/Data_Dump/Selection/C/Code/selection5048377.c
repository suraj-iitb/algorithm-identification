#include<stdio.h>

int main()
{
  int n,i,j;
  int minj,irekae;
  int cnt=0;

    scanf("%d",&n);

    int A[n];

    for(i = 0;i < n; i++)scanf("%d",&A[i]);

    for(i = 0;i < n; i++)
    {
        minj = i;

        for(j = i+1;j < n; j++)
        {
            if(A[j] < A[minj])
            {
                minj = j;
            }
        }
        if(minj != i)
        {
            irekae = A[minj];
            A[minj] = A[i];
            A[i] = irekae;
            cnt++;
        }
    }
    for(i = 0;i < n-1; i++)printf("%d ",A[i]);
    printf("%d\n%d\n",A[n-1],cnt);

    return 0;
}
