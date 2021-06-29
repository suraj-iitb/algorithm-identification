#include<stdio.h>

void swap(int *, int *);
int bubbleSort(int [], int);

int main()
{
  int i,n,data[100],cnt;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&data[i]);
  }
  cnt = bubbleSort(data, n);
  for(i=0;i<n;i++){
    if(i>0) printf(" ");
    printf("%d",data[i]);
  }
  printf("\n");
  printf("%d\n",cnt);
  return 0;
}

void swap(int *a, int *b){
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int bubbleSort(int data[], int n){
  int i,j,cnt=0;
    for(i = 0 ; i<n-1 ; i++){
    for(j = n-1 ; j > i ; j--){
      if(data[j] < data[j-1]){
	swap(&data[j], &data[j-1]);
        cnt++;
      }
    }
  }
    return cnt;
}
