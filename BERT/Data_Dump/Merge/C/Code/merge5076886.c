#include <stdio.h>

int sum = 0;
void MergeSort(int *,int,int);

int main(){
  int n,i;
  scanf("%d",&n);
  int S[n];

  for (i=0;i<n;i++)
    scanf("%d",&S[i]);
  MergeSort(S,0,n-1);

  for (i=0;i<n;i++){
    printf("%d",S[i]);
    if(i!=n-1) printf(" ");
  }
  printf("\n");
  printf("%d\n",sum);

  return 0;
}

void MergeSort(int *S,int left, int right){
  int mid,i,j,k,temp[right+1];
  if (left>=right)
    return;

  mid = (left + right)/2;
  MergeSort(S,left,mid);
  MergeSort(S,mid+1,right);

  for(i=left;i<=mid;i++)
    temp[i] = S[i];

  j=right;
  for(i=mid+1;i<=right;i++){
    temp[i] = S[j];
    j--;
  }

  i = left;
  j = right;
  for (k=left;k<=right;k++){
    if (temp[i]<=temp[j])
      S[k] = temp[i++];
    else S[k] = temp[j--];
    sum++;
  }
}
