#include <stdio.h>

#define MAX_DATA 500000

int temp[MAX_DATA];   
int count=0;

void MergeSort(int x[ ], int left, int right);
 
void MergeSort(int x[ ], int left, int right)
{
    int mid, i, j, k;
	
    if (left >= right)              
        return;                     

                                   
    mid = (left + right) / 2;      
    MergeSort(x, left, mid);        
    MergeSort(x, mid + 1, right);   

      
    for (i = left; i <= mid; i++)
        temp[i] = x[i];

      
    for (i = mid + 1, j = right; i <= right; i++, j--)
        temp[i] = x[j];

    i = left;         
    j = right;        
    
    for (k = left; k <= right; k++)    
      if (temp[i] <= temp[j]){      
	x[k] = temp[i++];
	count++;}
      else{
	x[k] = temp[j--];
	count++;}
    
}

int main()
{
  int i,n,x[MAX_DATA];

  scanf("%d",&n);
  for(i=0; i<n; i++)
    scanf("%d",&x[i]);

    MergeSort(x, 0, n - 1);
    
    for (i = 0; i < n-1; i++)
        printf("%d ", x[i]);
    printf("%d\n",x[i]);
    printf("%d\n",count);

    return 0;
}
