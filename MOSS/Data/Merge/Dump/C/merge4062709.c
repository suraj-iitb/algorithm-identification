#include<stdio.h>
#define N 500000
int tem[N];
int c=0;
void MG(int x[ ], int left, int right)
{
  int mid, i, j, k;
        
  if (left >= right)             
    return;                                                      
  mid = (left + right) / 2;      
  MG(x, left, mid);       
  MG(x, mid + 1, right);
  for (i = left; i <= mid; i++)
    tem[i] = x[i];     
  for (i = mid + 1, j = right; i <= right; i++, j--)
    tem[i] = x[j];
  i = left;        
  j = right;       
  for (k = left;k<= right; k++)   
    if (tem[i]<= tem[j]){        
      x[k]=tem[i++];c++;
    }
    else{
      x[k]=tem[j--];c++;
    }
}

int main(){
  int o1;
   int i,j;
   int A1[N];
 scanf("%d",&o1);
  for(i=0;i<o1;i++){
    scanf("%d",&A1[i]);
  }

  MG(A1,0,o1-1);
for (i = 0; i < o1; i++)
  {
    printf("%d",A1[i]);
 
 if(i!=o1 - 1)printf(" ");
  }
 printf("\n");
 printf("%d\n",c);
  return 0;
}


