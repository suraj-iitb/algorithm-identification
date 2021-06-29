#include<stdio.h>

int selectionSort(int [], int);
void swap(int *, int *);

int main()
{
  int i,n,data[100],cnt;
  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&data[i]);
  }
  cnt = selectionSort(data, n);
  for(i=0; i<n; i++){
    if(i>0) printf(" ");
    printf("%d",data[i]);
  }
  printf("\n");
  printf("%d\n",cnt);
  return 0;
}

void swap(int *a, int *b){
  int temp;
  temp=*a;
  *a=*b;
  *b=temp;
}

int selectionSort(int a[], int n){
  int i,j,minj,cnt=0;
  for(i=0; i<n-1; i++){
    minj = i;
    for(j=i+1; j<n; j++){
      if(a[j] < a[minj]){
	minj = j;
      }
    }
    swap(&a[i], &a[minj]);
    if(i != minj) cnt++;
  }
  return cnt;
}
