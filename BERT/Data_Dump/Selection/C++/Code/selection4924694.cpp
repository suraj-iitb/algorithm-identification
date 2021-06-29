#include<bits/stdc++.h>
using namespace std;

int bubbleSort(int A[],int n,int ans){
	bool flag = true;
	while (flag){
		flag = false;
		for (int j=0;j<n-1;j++){
			if (A[j]>A[j+1]){
				int tmp = A[j];
				A[j] = A[j+1];
				A[j+1] = tmp;
				flag = true;
				ans+=1;
			}

		}
	}
	return ans;
}
int selectionSort(int A[],int n,int ans){
	for (int i=0;i<n;i++){
		int minj = i;
		for (int j=i;j<n;j++){
			if (A[j]<A[minj]) minj = j;
		}
		if (i!=minj){
			int tmp = A[i];
			A[i] = A[minj];
			A[minj] = tmp;
			ans+=1;
		}
		
	}
	return ans;
}
int main(){
	int n,ans=0;
	cin >> n;
	int A[n];
	for (int i=0;i<n;i++)cin>>A[i];

	//ans = bubbleSort(A,n,ans);
	ans = selectionSort(A,n,ans);
	for (int i=0;i<n-1;i++)cout<<A[i]<<" ";cout<<A[n-1]<<endl;
	cout << ans << endl;

}


