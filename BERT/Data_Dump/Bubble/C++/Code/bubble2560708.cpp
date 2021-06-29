#include <iostream>
#include <vector>
using namespace std;
//---------------------------------------
int BubbleSort(vector<int>& a);
void Show(const vector<int> a, const int bs_count);
//---------------------------------------

int main(void)
{
	int n;
	vector<int> a;
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		a.push_back(num);
	}
	
	int bs_count = BubbleSort(a); //????????????(??????????????????)
	Show(a, bs_count);
	
	return 0;
}

//------------------------------------------
int BubbleSort(vector<int>& a){
	
	int bs_count = 0;
	
	for(int i = 0; i <= a.size() -1; i++){
		for(int j = a.size() -1; j >= i+1; j--){
			if(a[j] < a[j-1]){
				int temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
				bs_count++;
			}
		}
	}
	return bs_count;
}
//--------------------------------------------
void Show(const vector<int> a, const int bs_count){
	for(int i = 0; i < a.size() - 1; i++){
		cout << a[i] << ' ';
	}
	cout << a[a.size() - 1] << endl;
	
	cout << bs_count << endl;
	
}
