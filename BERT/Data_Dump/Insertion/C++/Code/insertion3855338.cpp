
#include<iostream>
using namespace std;
void insertionSort(int arr[],int n);
int main() {
    int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;++i){
        cin>>a[i];
	}
    for(int i=0;i<n-1;i++){
        cout<<a[i]<<" ";
    }
    cout<<a[n-1]<<endl;
  insertionSort(a,n);

  return 0;
}
void insertionSort(int arr[],int n)
{
	int i,j,key;
	for (i=1;i<=n-1;i++)
	{
		key=arr[i];
		j=i-1;
 		while (j>=0&&arr[j]>key)
 		{
 			arr[j+1]=arr[j];
 			j--;
 		}
 		arr[j+1]=key;

 		for(int k=0;k<n-1;k++){
            cout<<arr[k]<<" ";
 		}
 		cout<<arr[n-1]<<endl;
	}
}

