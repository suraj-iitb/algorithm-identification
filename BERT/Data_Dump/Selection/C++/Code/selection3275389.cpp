#include<stdio.h>

int SelectionSort(int [],int n);
int min(int, int);

int main()
{
  int n;
  int i;
  int A[110];
  int cnt=0;
  
  scanf("%d",&n);
  for(i=0;i < n;i++){
    scanf("%d",&A[i]);
  }

  cnt = SelectionSort(A,n);
  printf("%d\n",cnt);
  return 0;
}

int SelectionSort(int A[],int n)
{
  int i,j;
  int cnt = 0;
  
  int mini;
  int temp;
  
  for(i=0;i < n;i++){
    mini = i;
    
    for(j = i+1;j < n;j++){
      if(A[j] < A[mini]) mini = j;
    }
    
    temp = A[mini];
    A[mini] = A[i];
    A[i] = temp;
    if(mini != i) cnt++;
  }
  
  for(i=0;i < n;i++){
    if(i) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  
  return cnt; 
}

int min(int a, int b)
{
  if(a < b) return a;
  else return b;
}

