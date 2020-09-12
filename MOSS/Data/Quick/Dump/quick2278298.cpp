#include <iostream>
#include <algorithm>
using namespace std;

struct Card{
	int no;
	char name;
};

bool compare_as_ints(Card i,Card j)
{
	return (i.no<j.no);
}

int Partition(Card A[],int p,int r)
{
	Card x=A[r];
	int i=p-1;

	for(int j=p; j<=r-1; j++)
	{
		if(A[j].no<=x.no)
		{
			i++;
			swap(A[i],A[j]);
		}
	}
	swap(A[i+1],A[r]);
	return i+1;
}

void quickSort(Card A[], int p, int r)
{
	if(p<r){
		int q=Partition(A,p,r);
		quickSort(A,p,q-1);
		quickSort(A,q+1,r);
	}
}

int main()
{	
	int n;
	cin>>n;
	
	Card A[100000],B[100000];
	for(int i=0; i<n; i++){
		cin>>A[i].name>>A[i].no;
		B[i]=A[i];
	}

	quickSort(A,0,n-1);
	stable_sort(B,B+n,compare_as_ints);

	bool stable=true;
	for(int i=0; i<n; i++){
		if(A[i].no==B[i].no && A[i].name==B[i].name);
		else
			stable=false;
	}
	if(stable)
		cout<<"Stable"<<endl;
	else
		cout<<"Not stable"<<endl;

	for(int i=0; i<n; i++)
		cout<<A[i].name<<' '<<A[i].no<<endl;

	return 0;
}
