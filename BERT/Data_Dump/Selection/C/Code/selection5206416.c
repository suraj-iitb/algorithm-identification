#include<stdio.h>


int main()
{
    int N;
    scanf("%d", &N);
    int A[N];
    int s;
    for (s=0; s<N; s++){
        scanf("%d", &A[s]);
    }
    int c =0;
    int i, j, m;
  for(i=0; i<N; i++) {
    m=i;
    for(j=i+1; j<N; j++) {
      if(A[j]<A[m]) m=j;
    }
    if(A[i]>A[m]) {
      int tmp=A[i];
      A[i]=A[m];
      A[m]=tmp;
      c++;
    }
  }
    for(i = 0; i < N; i++)
    {
        if(i > 0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n%d\n", c);
	return 0;
}


