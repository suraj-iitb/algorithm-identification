#include  <stdio.h>

#define NUM 100

void insertionSort(int numbers[], int array_size);

void swap(int *p_from, int *p_to);

int numbers[NUM];


int main()
{
  int i, n, c;
  int numbers[NUM];

   
  scanf("%ld", &n);

   
  for(c = 0; c < n; c++)
    scanf("%ld", &numbers[c]);
  
  for (i = 0; i < n-1;i++) {
    printf("%d ", numbers[i]);
  }
  printf("%d\n",numbers[i]);

  insertionSort(numbers, n);

   

  return 0;
}

void insertionSort(int data[], int n)
{
  int i, j,tmp,k;

  for (i = 1; i < n; i++) {
    tmp = data[i];
    if (data[i - 1] > tmp) {
      j = i;
      do {
	data[j] = data[j - 1];
	j--;
      } while (j > 0 && data[j - 1] > tmp);
      data[j] = tmp;
    }

    for(k=0;k<n-1;k++){
      printf("%d ",data[k]);
    }
    printf("%d\n",data[k]);

  }



}
