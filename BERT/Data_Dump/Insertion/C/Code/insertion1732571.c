#include<stdio.h>

void output(int*,int);
void insertionSort(int*,int);

int main()
{
  int n,i;
  int a[100];

  scanf("%d",&n);
  for(i=0; i<n; i++) scanf("%d",&a[i]);
  
  output(a,n);
  insertionSort(a,n);

  return 0;
}

void output(int *a,int n) /* print */
{
  int i;
  for(i=0; i<n; i++){ 
    printf("%d",a[i]);
    if(i<n-1) printf(" ");
  }
  printf("\n");
}
    
void insertionSort(int *a,int n) /* sort */
{
  int i,j,v;

  for (i=1; i<n; i++){
    v = a[i];
    /* insert a[j] into the sorted sequence a[1,...,j-1] */
    j = i-1;
    while(j >= 0 && a[j] > v) {
      a[j+1] = a[j];
      j--;
    }

    a[j+1] = v;
    output(a,n);
  }
}
    
