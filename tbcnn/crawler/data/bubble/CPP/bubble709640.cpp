#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int n,a,k=0;
	cin >> n;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin >> v[i];
	for(int i=0;i<n;i++){
		for(int j=n-1;i<j;j--){
			if(v[j]<v[j-1]){
				a=v[j];
				v[j]=v[j-1];
				v[j-1]=a;
				k+=1;
			}
		}
	}
	cout << v[0];
	for(int i=1;i<n;i++) cout << " " << v[i];
	cout << endl << k << endl; 
	return 0;
}
