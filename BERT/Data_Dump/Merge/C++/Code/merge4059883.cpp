#include <stdio.h>



int count=0;
int temp[500000];    

void MergeSort(int *,int,int);


int main(void)
{
  int i,n;
 
  int A[1000000];
 
  scanf("%d",&n);
  for (i = 0; i < n; i++)
    scanf("%d",&A[i]);

  MergeSort(A,0,n-1);

  /*出力*/
  
  for (i=0;i<n-1;i++)
    printf("%d ",A[i]);
  printf("%d\n",A[n-1]);
  printf("%d\n",count);
  return 0;
}

/* left から right マージソート */
void MergeSort(int *A, int left, int right)
{
  int mid,i,j,k;
   /* 配列の要素が一つの場合 */
  if (left>=right)             
    return;                     

  
  mid=(left+right)/2;      
  MergeSort(A,left,mid);       
  MergeSort(A,mid+1,right);  

  /* left から mid*/
  for(i=left;i<=mid;i++)
    temp[i]=A[i];

  /* mid + 1からright */
  for(i=mid+1,j=right;i<=right;i++,j--)
    temp[i]=A[j];

  i=left;         
  j=right;       

  for(k=left;k<=right;k++){    
    if(temp[i]<=temp[j])      
      A[k]=temp[i++];
    
    else
      A[k]=temp[j--];

    count++;
  }
}

