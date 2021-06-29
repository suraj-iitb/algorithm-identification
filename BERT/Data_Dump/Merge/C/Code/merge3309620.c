#include <stdlib.h>
#include <stdio.h>




void mergeSort(int numbers[], int temp[], int array_size);
void m_sort(int numbers[], int temp[], int left, int right);
void merge(int numbers[], int temp[], int left, int mid, int right);

int numbers[500000];
int temp[500000];
int cnt=0;

int main()
{
	int i;
	int n;
	scanf("%d",&n);
	
	for (i = 0; i < n; i++)
	scanf("%d",&numbers[i]);

	
	mergeSort(numbers, temp, n);

	for (i = 0; i < n; i++){
	if(i){
	printf(" ");
	}
	printf("%d", numbers[i]);
	}
	printf("\n%d\n", cnt);
	
	return 0;
}


void mergeSort(int numbers[], int temp[], int array_size)
{
  m_sort(numbers, temp, 0, array_size - 1);
}



void m_sort(int numbers[], int temp[], int left, int right)
{
  int mid;

  if (right > left)
  {
    mid = (right + left) / 2;
    m_sort(numbers, temp, left, mid);
    m_sort(numbers, temp, mid+1, right);

    merge(numbers, temp, left, mid+1, right);
  }
}


void merge(int numbers[], int temp[], int left, int mid, int right)
{
  int i, end_left, num_elements, tmp_pos;

  end_left = mid - 1;
  tmp_pos = left;
  num_elements = right - left + 1;

  while ((left <= end_left) && (mid <= right))
  {
    if (numbers[left] <= numbers[mid])
    {
      temp[tmp_pos] = numbers[left];
      tmp_pos = tmp_pos + 1;
      left = left +1;
    	cnt++;
    }
    else
    {
      temp[tmp_pos] = numbers[mid];
      tmp_pos = tmp_pos + 1;
      mid = mid + 1;
    	cnt++;
    }
  }

  while (left <= end_left)
  {
    temp[tmp_pos] = numbers[left];
    left = left + 1;
    tmp_pos = tmp_pos + 1;
  	cnt++;
  }
  while (mid <= right)
  {
    temp[tmp_pos] = numbers[mid];
    mid = mid + 1;
    tmp_pos = tmp_pos + 1;
  	cnt++;
  }

  for (i=0; i <= num_elements; i++)
  {
    numbers[right] = temp[right];
    right = right - 1;
  }
}
