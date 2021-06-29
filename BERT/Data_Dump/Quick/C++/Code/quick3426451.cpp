#include<bits/stdc++.h>
using namespace std;
#define Max 100005
#define stable 2000000000
int n;
struct node{
	char huase;
	int num;
};
node L[Max/2+2],R[Max/2+2],B[Max],C[Max];

void merge(node A[],int left,int mid,int right)
{
	int n1,n2;
	n1 = mid - left;
	n2 = right- mid;
	for(int i = 0;i<n1;i++) L[i] = A[left+i];
	for(int i=0;i<n2;i++) R[i] = A[mid+i];
	L[n1].num = stable;
	R[n2].num = stable;
	int i=0,j=0;
	for(int k=left;k<right;k++)
	{
		if(L[i].num<=R[j].num)
			A[k] = L[i++];
		else 
			A[k] = R[j++];
	}
 } 
 
void mergeSort(node A[],int left,int right)
{
	if(left+1<right)
	{
		int mid = (left+right)/2;
		mergeSort(A,left,mid);
		mergeSort(A,mid,right);
		merge(A,left,mid,right);
	}
	
}

int partition(node A[],int p,int r)
{
	int X = A[r].num;
	int i = p-1;
	for(int j=p;j<r;j++)
	{
		if(A[j].num<=X)
		{
			swap(A[++i],A[j]);
		}
	}
	swap(A[++i],A[r]);
	return i;	
}

void quickSort(node A[],int p,int r)
{
	if(p<r)
	{
		int q =partition(A,p,r);
		quickSort(A,p,q-1);
		quickSort(A,q+1,r);
	}
}

int main()
{
	cin>>n;
	int nm;
	char c;
	int flag = 1;
	for(int i=0;i<n;i++)
	{
		cin>>c>>nm;
		B[i].num = nm;
		B[i].huase = c;
		C[i].num = nm;
		C[i].huase = c;
	}
	mergeSort(B,0,n);  //right不包括 
	quickSort(C,0,n-1);  //right包括 
	for(int i=0;i<n;i++)
	{
		if(B[i].huase!=C[i].huase)
		{
			flag =0;
			break;
		}
	}
	if(flag)
		cout<<"Stable"<<endl;
	else 
		cout<<"Not stable"<<endl;
	for(int i =0;i<n;i++)
		cout<<C[i].huase<<' '<<C[i].num<<endl;
	return 0;
	 
	
	
}








 
 
 
