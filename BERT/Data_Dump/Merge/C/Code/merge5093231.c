#include<stdio.h>
#define M 500000

int count=0;

void merge_sort(int *,int,int);

int main () {
  int array[M];
  int n,i;

  scanf("%d",&n);
  i = 0;
  for(i = 0;i < n;i++) {
   scanf("%d",&array[i]);
  }
  merge_sort(array, 0, n-1);

  for (i = 0; i < n-1; i++) { 
      printf("%d ", array[i]);
       }
  printf("%d\n",array[i]);
  printf("%d\n",count);

  return 0;
}

void merge_sort (int array[], int left, int right) {
  int i, j, k, mid;
  int temp[M];

  if(left >=right) return ;
    mid = (left + right)/2; 
    merge_sort(array, left, mid);
    merge_sort(array, mid+1, right);
     for (i = left; i <= mid; i++){
        temp[i] = array[i];
  }
      
    for (i = mid + 1, j = right; i <= right; i++, j--){
        temp[i] = array[j];
    }

    i = left;         
    j = right;       

    for (k = left; k <= right; k++){    
        if (temp[i] <= temp[j]){       
            array[k] = temp[i++];
        }
        else{
            array[k] = temp[j--];
        }
          count++;
    }
  }
