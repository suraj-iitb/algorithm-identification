#include <stdio.h>

void insertionSort(int *,int);
void print(int *,int);

int main()
{
  int N,i;
  
  scanf("%d",&N);

  int number[N];
  
  for(i=0;i<N;i++){
    scanf("%d",&number[i]);
  }
  
  insertionSort(number,N);

  return 0;
}

void insertionSort(int *number,int n)
{
  int i,j,v;

  print(number,n);

  
  for(i=1;i<n;i++){
    v = number[i];
    j = i-1;
    while(j>=0 && number[j]>v){
      number[j+1] = number[j];
      j--;
    }
    number[j+1] = v;
    print(number,n);
  }
}

void print(int *number,int n)
{
  int i;
  for(i=0;i<n;i++){
    printf("%d",number[i]);
    if(i < n-1) printf(" ");
    else printf("\n");
  }
}


    
  
  

