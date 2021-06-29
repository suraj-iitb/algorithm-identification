#include <iostream>
#include <vector>
using namespace std;
//---------------------------------------
int SelectionSort(vector<int>& a);
void Show(const vector<int> a, const int ss_count);
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
	
	int ss_count = SelectionSort(a); //????????????(???????????????)
	Show(a, ss_count);
	
	return 0;
}

//------------------------------------------
int SelectionSort(vector<int>& a){
	
	int ss_count = 0;
	
	for(int i = 0; i < a.size(); i++){
		int minj = i;
		for(int j = i; j < a.size(); j++){
			if(a[j] < a[minj]){
				minj = j;
			}
		}
		if(i == minj){
			continue; //??\???????????????for????????????
		}
		int temp = a[i];
		a[i] = a[minj];
		a[minj] = temp;
		ss_count++;
	}
	return ss_count;
}
//--------------------------------------------
void Show(const vector<int> a, const int ss_count){
	for(int i = 0; i < a.size() - 1; i++){
		cout << a[i] << ' ';
	}
	cout << a[a.size() - 1] << endl;
	
	cout << ss_count << endl;
	
}
