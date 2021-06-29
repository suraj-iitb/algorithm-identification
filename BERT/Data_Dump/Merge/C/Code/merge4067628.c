#include<stdio.h>

void mergeSort (int array[], int left, int right);
int n,count;

int main (void){
  int array[500000];
  int i;

    scanf("%d",&n);
    for (i = 0; i < n; i++)
    scanf("%d",&array[i]); 

  mergeSort(array, 0, n-1);

  for (i = 0; i < n; i++){
       printf("%d", array[i]);
       if(i < n-1)
       printf(" "); 
       }
  printf("\n");
  printf("%d\n",count);
  return 0;
}
void mergeSort (int array[], int left, int right){
  int i, j, k, mid;
  int work[n];  
  if(left < right){
    mid = (left + right)/2; 
    mergeSort(array, left, mid);  
    mergeSort(array, mid+1, right);  
    for(i = mid; i >= left; i--)
        work[i] = array[i];
    for(j = mid+1; j <= right; j++)
      work[right-(j-(mid+1))] = array[j]; 
    i = left;
    j = right;
    for(k = left; k <= right; k++){
        count++;
      if(work[i] < work[j]){ 
        array[k] = work[i++]; 
        }else{
          array[k] = work[j--];
            }
    }
  }
}
