#include <stdio.h>
void trace(int [], int);
void insertionSort(int [], int);
int main()
{
  int i,j,n;
  int data[100];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&data[i]);
  }
  trace(data, n);
  insertionSort(data,n);
  return 0;
}

void trace(int data[], int n){
  int i;
  for(i=0; i<n; i++){
    if(i>0) printf(" ");
    printf("%d",data[i]);
  }
  printf("\n");
}
 
void insertionSort(int data[], int n){ /* data[] = A, n = N */
  int i,j,v;
  for(i = 1 ; i < n ; i++){
    v = data[i];
    j = i-1;
    while((j >= 0) && (data[j] > v)){
      data[j+1] = data[j];
      j--;
    }
    data[j+1] = v;
    trace(data, n);
  }
}
