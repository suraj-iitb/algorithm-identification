
#include<stdio.h>

void mergeSort(int S[], int temp[], int array_size);
void m_sort(int S[], int temp[], int left, int right);
void merge(int S[], int temp[], int left, int mid, int right);

int n,count=0;
int numbers[500001];
int temp[500001];


int main()
{
  int i;
  scanf("%d",&n);
  
  for (i = 0; i < n; i++){
   scanf("%d",&numbers[i]);
  }
  mergeSort(numbers, temp, n);


  for (i = 0; i < n-1; i++){
    printf("%d ", numbers[i]);
}
  printf("%d",numbers[n-1]);
  printf("\n");

  printf("%d\n",count);
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
  int i, left_end, num_elements, tmp_pos;

  left_end = mid - 1;
  tmp_pos = left;
  num_elements = right - left + 1;

  while ((left <= left_end) && (mid <= right))
  {
    if (numbers[left] <= numbers[mid])
    {
      temp[tmp_pos] = numbers[left];
      tmp_pos = tmp_pos + 1;
      left = left +1;
      count++;
    }
    else
    {
      temp[tmp_pos] = numbers[mid];
      tmp_pos = tmp_pos + 1;
      mid = mid + 1;
      count++;
    }
  }

  while (left <= left_end)
  {
    temp[tmp_pos] = numbers[left];
    left = left + 1;
    tmp_pos = tmp_pos + 1;
    count++;
  }
  while (mid <= right)
  {
    temp[tmp_pos] = numbers[mid];
    mid = mid + 1;
    tmp_pos = tmp_pos + 1;
    count++; 
 }

  for (i=0; i <= num_elements; i++)
  {
    numbers[right] = temp[right];
    right = right - 1;
  }
}
