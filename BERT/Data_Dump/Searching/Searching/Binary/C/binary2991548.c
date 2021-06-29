#include <stdio.h>
#include <stdlib.h>

int N[100000];

int search(const void* a, const void* b)
{ 
    return *(int*)a - *(int*)b;
}

int main(void)
{
  int n,n2;
  int i, j;
  int count;

    scanf("%d",&n);
    for (i=0;i<n;++i){
        scanf("%d",N+i);
    }

    scanf("%d", &n2);
    count = 0;
    for (i=0;i<n2;++i){
        int t;

        scanf("%d", &t);
        if (bsearch(&t,N,n,sizeof(int),search) != NULL){
            count=count+1;
        }
    }

    printf("%d\n",count);

    return (0);
}

