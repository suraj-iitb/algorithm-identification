#include<stdio.h>

#define N 100

void SelectionSort(int[],int);
/*スワップ数*/
int count=0;
int main(){
  int i,n;
  int A[N];
  scanf("%d",&n);
  /*配列格納*/
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  /*SelectionSort*/
  SelectionSort(A,n);
  /*スワップ後の数&とスワップ数表示*/
  for(i=0;i<n-1;i++)
    
  printf("%d ",A[i]);
  
  printf("%d\n",A[n-1]);
 
  printf("%d\n",count);
  return 0;}
/*SelectionSort*/
void SelectionSort(int A[],int n)
{
  int i,j,mini,temp,hit=0;
 
  
  for(i=0;i<n;i++){
    mini=i;
    hit=0;
    for(j=i+1;j<n;j++){
      if(A[j]<A[mini]){
	mini=j;
	hit=1;
      }
      
    }
    temp=A[i];
    A[i]=A[mini];
    A[mini]=temp;
    if(hit==1)
    count++;
  }
  

}

