#include <iostream>
using namespace std;
const int MAX = 1000000+5;
int n,a[MAX],cnt = 0;
void Swap(int x,int y){
	int t = a[x];
	a[x] = a[y];
	a[y] = t;
}
void BubbleSort(){
	for(int i = 0;i < n;i++)
		for(int j = n-1;j >= i+1;j--){
			if(a[j] < a[j-1]){
				Swap(j,j-1);
				cnt++;
			}
		}
}
void Print(){
	for(int i = 0;i < n-1;i++)
		cout << a[i] << " ";
	cout << a[n-1] << endl;
	cout << cnt << endl;
}
int main(int argc, char const *argv[])
{
	cin >> n;
	for(int i = 0;i < n;i++)
		cin >> a[i];
	BubbleSort();
	Print();
	return 0;
}
