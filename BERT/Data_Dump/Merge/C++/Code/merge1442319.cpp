#include<stdio.h>
int n,S[500000],count=0,i,a[500000];
int MergeSort(int S[],int left,int right);
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&S[i]);
	MergeSort(S,0,n-1);
	for(i=0;i<n;i++){
		printf("%d",S[i]);
		if(i<n-1)
		printf(" ");
	}
	printf("\n%d\n",count);
	return 0;
}
int MergeSort(int S[],int left,int right)
{
	int mannaka,j,k;
	if(left>=right)
		return S[n];
	mannaka=(left+right)/2;
    MergeSort(S,left,mannaka);        
    MergeSort(S,mannaka+1,right);   
    for(i=left;i<=mannaka;i++)
        a[i]=S[i];
    for(i=mannaka+1,j=right;i<=right;i++,j--)
        a[i]=S[j];
	i=left;
    j=right; 
    for(k=left;k<=right;k++){
		count++;
        if (a[i]<=a[j])      
            S[k]=a[i++];
        else
            S[k]=a[j--];
	}
}
