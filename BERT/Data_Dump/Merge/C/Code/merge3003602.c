#include <stdio.h>

int temp[10000000];
void merge(int *,int,int);
int count=0;

int main(){
  
  int i,a,n,m,cont1=0,cont2=0;
  int x[500000],y[50000];
  
  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%d",&x[i]);
  }     

  
  merge(x, 0, a - 1);
  
  for (i = 0; i < a; i++){
    if(i!=a-1){ 
      printf("%d ", x[i]);
    }
    else printf("%d",x[i]);
  }
  printf("\n%d\n",count);
  
}


void merge(int x[ ], int left, int right)
{
  int mid, i, j, k;
  
  if (left >= right){
    return;
  }
  
  
  mid = (left + right) / 2;       
  merge(x, left, mid);
  merge(x, mid + 1, right);   
  
  
  for (i = left; i <= mid; i++)
    temp[i] = x[i];
  
  
  
  for (i = mid + 1, j = right; i <= right; i++, j--){
    
    temp[i] = x[j];
    
  }  
  i = left;        
  j = right;       
  
  for (k = left; k <= right; k++)   
    if (temp[i] <= temp[j]){
      count++;
      x[k] = temp[i++];
      
    }
    else{
      count++;
      x[k] = temp[j--];      
    }
}

