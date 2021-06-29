#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <stack>
#include <queue>
#include <list>
#include <stdio.h>
#include <algorithm>
#define MAX 100000
using namespace std;
typedef long long ll;
struct card
{
	char suit;
	int num;
};
struct card L[50002],R[50002];
void Merge(struct card a[],int left,int mid,int right)
{
	int len,len1,len2,i,j;
	len1=mid-left;
	len2=right-mid;
	len=len1+len2;
	for( i=0;i<len1;i++) L[i]=a[left+i];
	for( i=0;i<len2;i++) R[i]=a[mid+i];
	L[len1].num=R[len2].num=2000000001;
	i=j=0;
	for(int k=0;k<len;k++)
	{
		if(L[i].num<=R[j].num){
			a[left+k]=L[i++];
		}else{
			a[left+k]=R[j++];
		}
	}
}
void mergeSort(struct card a[],int left,int right)
{
	int mid=(left+right)/2;
	if(left+1<right){
		mergeSort(a,left,mid);
		mergeSort(a,mid,right);
		Merge(a,left,mid,right);
	}
}
int partition(struct card a[],int left,int right)
{
	struct card stan=a[right],t;
	int j=left-1;
	for(int i=left;i<right;i++)
	{
		if(a[i].num<=stan.num){
			++j;
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}
	t=a[j+1];
	a[j+1]=a[right];
	a[right]=t;
	return j+1;
}
void quickSort(struct card a[],int left,int right)
{
	int q;
	if(left<right)
	{
		q=partition(a,left,right);
		quickSort(a,left,q-1);
		quickSort(a,q+1,right);
	}
}
int main()
{	
	int n,tmp;
	char S[5];
	bool judge=true;
	struct card a[100001],b[100001];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%s %d",S,&tmp);
		a[i].suit=b[i].suit=S[0];
		a[i].num=b[i].num=tmp;
	}
	mergeSort(a,0,n);
	quickSort(b,0,n-1);
	for(int i=0;i<n;i++)
	{
		if(a[i].suit!=b[i].suit) {
			judge=false;
			break;
		}
	}
	if(judge){
		cout<<"Stable"<<endl;
	}else{
		cout<<"Not stable"<<endl;
	}
	
	for(int i=0;i<n;i++){
		printf("%c %d\n",b[i].suit,b[i].num);
	}
	return 0;
}
