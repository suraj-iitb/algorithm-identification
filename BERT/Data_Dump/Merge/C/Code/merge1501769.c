#include<stdio.h>
int c=0;
long A[500001];
void merge(long A[],int left,int mid,int right)
{
	int i,j,k;
	long INFTY = 2147483647;
	int n1 = mid - left;
	int n2 = right - mid;
	long L[250001],R[250001];
	for (i = 0; i < n1; i++){
		L[i] = A[left + i];}
	for (i = 0; i < n2; i++){
		R[i] = A[mid + i];}
	L[n1] = INFTY;
	R[n2] = INFTY;
	i = j = 0;
	for (k = left; k < right; k++){
		if (L[i] <= R[j]){
			A[k] = L[i++];
			c++;}
		else {
			A[k] = R[j++];
			c++;}}
}
void mergeSort(long A[],int left,int right)
{
	int mid;
	if (left + 1 < right){
		mid = (left + right)/2;
		mergeSort(A, left, mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);}
}
int main(void)
{
	int i,n;
	scanf("%d",&n);
	for(i=0; i<n; i++){
		scanf("%ld",&A[i]);}
	mergeSort(A,0,n);
	for(i=0; i<n; i++){
		printf("%ld",A[i]);
		printf(!(i-n+1)?"\n":" ");}
		printf("%d\n",c);
	return 0;
}
