#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int  n,a;
	cin >> n;
	vector<int> num(n);
	for(int i=0;i<n;i++) cin >> num[i];
	for(int i=0;i<n;i++){
		for(int j=i;0<j;j--){
			if(num[j]<num[j-1]){
				a=num[j-1];
				num[j-1]=num[j];
				num[j]=a;
			}
		}
		cout << num[0];
		for(int j=1;j<n;j++){
			cout << " " << num[j];
		}
		cout << endl;
	} 
	return 0;
}
