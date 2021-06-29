#include "stdio.h"
#include "iostream"

using namespace std;

int select_sort(int *arr,int n)
{
	int i,j,num=0;
	int mini;

	for(i=0;i<n;i++){
		mini = i;
		for(j=i;j<n;j++){
			if(arr[mini] > arr[j]){
				mini = j;
			}
		}
		if(mini != i){
			swap(arr[mini],arr[i]);
			num++;
		}
	}

	return num;
}

int main()
{
	int n,num;
	
	cin >> n;

	int arr[n];

	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	
	num = select_sort(arr,n);

	for(int i=0;i<n;i++){
		if(i != n-1){
			printf("%d ",arr[i]);
		}
		else{
			printf("%d\n",arr[i]);
		}
	}
	
	cout << num << endl;

	return 0;
}	

