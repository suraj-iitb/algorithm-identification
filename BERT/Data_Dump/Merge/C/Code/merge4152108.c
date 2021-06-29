#include<stdio.h>
#define INFTY 1000000001
int t=0;
void merge(int s[],int left,int mid,int right){
	int n1=mid-left;
	int n2=right-mid;
	int l[n1+1],r[n2+1];
	int i,j,k;
	for(i=0;i<n1;i++)
	l[i]=s[left+i];
	for(i=0;i<n2;i++)
	r[i]=s[mid+i];
	l[n1]=INFTY;
	r[n2]=INFTY;
	i=0;
	j=0;
	for(k=left;k<right;k++){
		if(l[i]<=r[j]){
			s[k]=l[i];
			i++;
		}
		else{
			s[k]=r[j];
			j++;
		}
		t++;
	}
}
void mergeSort(int s[],int left,int right){
	if(left+1<right){
		int mid=(left+right)/2;
		mergeSort(s,left,mid);
		mergeSort(s,mid,right);
		merge(s,left,mid,right);
	}
}
int main(){
	int n,i;
	scanf("%d",&n);
	int s[n];
	for(i=0;i<n;i++)
	scanf("%d",&s[i]);
	int left=0;
	int right=n;
	mergeSort(s,left,right);
	for(i=0;i<n;i++){
		if(i>0)
		printf(" ");
		printf("%d",s[i]);
	}	 
	printf("\n");
	printf("%d\n",t);
	return 0;
} 
