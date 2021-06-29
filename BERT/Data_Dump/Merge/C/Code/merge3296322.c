#include <stdio.h>
#include <limits.h>
void mergeSort(int *, int, int );
void merge( int *, int, int, int );


int  cnt=0;
 int L[2500010],R[2500010];

int main(){
  int left=0,right=0,mid;
  int s[5000005];
  int n,i;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }

  mergeSort(s,0,n);
  
  for(i=0;i<n;i++){
    printf("%d",s[i]);
    if(i!=n-1)printf(" ");
  }
  printf("\n%d\n",cnt);

    

  return 0;
}

void mergeSort( int *s, int left, int right){
  int mid;
  if (left+1 < right){
    mid =(left+right)/2;
    mergeSort(s,left,mid);
    mergeSort(s,mid,right);
    merge(s, left, mid, right);
  }
}

void merge(int *s,int left, int mid, int right){
  int n1,n2;
  // int L[2500000],R[250000];
  int i=0,j=0,k;
    
  n1 = mid - left;
  n2 = right - mid;

  for(i=0;i<n1;i++){
    L[i] = s[left+i];
  }
  for(i=0;i<n2;i++){
    R[i] = s[mid+i];
  }
    L[n1]=INT_MAX;
    R[n2]=INT_MAX;  

    i=0;
    j=0;
    
    for(k= left; k<right;k++){
      cnt++;
      if(L[i]<=R[j]){
	s[k]=L[i];
	i++;
      }
      else{
	s[k]=R[j];
	j++;
      }  
    }
  
}

