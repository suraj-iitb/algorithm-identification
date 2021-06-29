#include <iostream>
using namespace std;
int main(){
	int n,a[100],i,j,minj,cnt=0;
	cin >> n;
	for(i=0;i<n;i++)
		cin >> a[i];
	for(i=0;i<n;i++){
		minj=i;
		for(j=i;j<n;j++){
			if(a[j]<a[minj]){
				minj = j;				
			}
		}
		if(i!=minj) cnt++;
		swap(a[i],a[minj]);
	}
	for(i=0;i<n;i++){
		cout << a[i];
		if(i!=n-1) cout << " ";
	}
	cout << endl << cnt << endl;
	return 0;
}
