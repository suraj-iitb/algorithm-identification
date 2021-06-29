#include <iostream>
#include <iomanip>
#include <algorithm>
  
using namespace std;
  
int main(void)
{
	int N;
	cin >> N;
  
	int Arr[102] = {0};
	for (int i = 0; i < N; i++){
		cin >> Arr[i];
	}
  
	for (int i = 0; i < N; i++){
		cout << Arr[i];
		if(i!=N-1) cout<<" ";
	}
	cout << endl;
  
	int Tmp = 0, j = 0;
	for (int i = 1; i < N; i++){
		Tmp = Arr[i];
		j = i-1;
		while (j >= 0 && Arr[j] > Tmp){
			Arr[j+1] = Arr[j];
			j--;
		}
		Arr[j+1] = Tmp;
		for (int i = 0; i < N; i++){
			cout << Arr[i];
			if(i!=N-1) cout<<" ";
		}
		cout<<endl;
	}
  
	return 0;
}
