#include<stdio.h>

int kazu=0;

int merge(int A[],int left,int mid,int right){
  int n1=mid-left;
  int n2=right-mid;
  int i,j,k;
  int Le[250001];
  int Ri[250001];

  for(i=0;i<=n1-1;i++) Le[i]=A[left+i];
  for(i=0;i<=n2-1;i++) Ri[i]=A[mid+i];
  Le[n1]=1000000001;
  Ri[n2]=1000000001;
  i=0;
  j=0;

  for(k=left;k<=right-1;k++){
    kazu++;
    if(Le[i]<=Ri[j]){
      A[k]=Le[i];
      i++;
    }
    else {
      A[k]=Ri[j];
      j++;
    }
  }
}


int mergeSort(int A[], int left, int right)
{
	int mid;
	if(left+1<right)
	{
		mid=(left+right)/2;
		mergeSort(A,left,mid);
		mergeSort(A,mid,right);
		merge(A,left,mid,right);
	}
}


int main(void)
{
	int i,n;
	int S[500000];
	
	scanf("%d",&n);
	for(i=0;i<=n-1;i++) scanf("%d",&S[i]);
	
	mergeSort(S,0,n);
	for(i=0;i<=n-1;i++)
	{
		if(i) printf(" ");
		printf("%d",S[i]);
	}
	
	printf("\n%d\n",kazu);
	return 0;
}

