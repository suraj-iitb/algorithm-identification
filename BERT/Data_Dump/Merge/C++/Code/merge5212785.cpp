#include "iostream"
#include "algorithm"
#include "vector"
#include "stack"
#include "queue"
#include "string"
#include "stdio.h"

using namespace std;

int num = 0;
int s[600000];

void merge(int *s,int left,int mid, int right)
{
	int n1,n2;

	n1 = mid - left;
	n2 = right - mid;

	int l[n1+1];
	int r[n2+1];

	for(int i=0;i<n1;i++){
		l[i] = s[i+left];
	}
	for(int i=0;i<n2;i++){
		r[i] = s[i+mid];
	}

	l[n1] = 1000000000;
	r[n2] = 1000000000;

	int k=0;
	int j=0;

	for(int i=left;i<right;i++){
		if(l[k] <= r[j]){
			s[i] = l[k];
			k += 1;
			num++;
		}
		else{
			s[i] = r[j];
			j += 1;
			num++;
		}
	}

}

void mergeSort(int *s,int left,int right)
{
	int mid;

	if(left+1 < right){
		mid = (left+right)/2;

		mergeSort(s,left,mid);
		mergeSort(s,mid,right);
		merge(s,left,mid,right);
	}
}

int main()
{
	int n;

	cin >> n;
	
	for(int i=0;i<n;i++){
		cin >> s[i];
	}

	mergeSort(s,0,n);

	for(int i=0;i<n;i++){
	    if(i+1==n){
	        printf("%d",s[i]);
	    }
	    else{
	        printf("%d ",s[i]);
	    }
	}
	cout << endl;

	cout << num << endl;

	return 0;
}


