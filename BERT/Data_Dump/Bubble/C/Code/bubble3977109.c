#include <stdio.h>
int array[100];
int main()
{
    int n,tmp;
    int i,j,k=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
        {
           scanf("%d",&array[i]);
        }

    for (i = 0; i < n - 1; i++){
    for (j = n - 1; j >= i ; j--){   
      if (array[j] < array[j-1]) { 
      		tmp=array[j-1];
            array[j-1]=array[j];
            array[j]=tmp;
              k++;
      }
    }
  }
        printf("%d",array[0]);
        for(i=1;i<n;i++){
            printf(" %d",array[i]);
        }
        printf("\n%d\n",k);
    
    return 0;
}

