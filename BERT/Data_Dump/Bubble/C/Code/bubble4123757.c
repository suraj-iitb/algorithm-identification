//2020 1.22 バブルソート

#include <stdio.h>
#define N 100 

int main()
{
    int i;
    int a,cnt1=0,cnt2=0;
    int array[N];

    scanf("%d",&a);

    for(i=0;i<a;i++)
    {
        scanf("%d",&array[i]);
    }
    
    if(a>1)
    {
    while(1)
    {
        i = a;
      while(1)
        {
         if(array[i-2] > array[i-1])
            {
                int temp = array[i-2];
                array[i-2] = array[i-1];
                array[i-1] = temp;
                cnt1++;
            }
            i = i-1;
            if(i == 1) break;
        }
        cnt2++;
        if(cnt2 > a) break;
    }
    }
    
    for(i=0;i<a;i++)
    {
        printf("%d",array[i]);
        if(i != a-1)
        {
        printf(" ");
        }
    }
    printf("\n");
    printf("%d\n",cnt1);
    return 0;
}
