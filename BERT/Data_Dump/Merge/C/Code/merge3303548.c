#include<stdio.h>
#include<stdlib.h>

void merge(int *,int ,int ,int);
void mergeSort(int *,int, int);

int count = 0;

int main(){
  int n,s[500000],i,left,right;

  scanf("%d",&n);
  if(500000 < n)exit(0);
  
  left = 0;
  right = n;
   
  //  s = (int *)malloc(n*sizeof(int));
  for(i = 0; i < n; i++){
    scanf(" %d",&s[i]);
    if(s[i] < 0 || 1000000000 < s[i])exit(0);
  }
  
  mergeSort(&s[0],left,right);
  
  printf("%d",s[0]);
  for(i = 1; i < n; i++){
    printf(" %d",s[i]);
  }
  printf("\n");
  printf("%d\n",count);
  
  return 0;
}

void mergeSort(int *s,int left,int right){
  int mid;

  if(left + 1 < right){
    mid = (left + right)/2;
    mergeSort(&s[0],left,mid);
    mergeSort(&s[0],mid,right);
    merge(&s[0],left,mid,right);
  }
  
}

void merge(int *s,int left,int mid ,int right){
  int n1,n2,l1[mid - left],l2[right - mid],i,j,k,inf = 9999999999;
  
  n1 = mid - left;
  n2 = right - mid;

  //  l1 = (int *)malloc(n1*sizeof(int));
  //l2 = (int *)malloc(n2*sizeof(int));
  
  for(i = 0; i < n1; i++)l1[i] = s[left + i];
  for(i = 0; i < n2; i++)l2[i] = s[mid + i];
  
  l1[n1] = inf;
  l2[n2] = inf;

  i = 0;
  j = 0;

  for(k = left; k < right; k++){
    if(l1[i] <= l2[j]){
      
      s[k] = l1[i];
      i = i + 1;
      count++;
    }
    else {
      
      s[k] = l2[j];
      j = j + 1;
      count++;
    }
    
  }
}

