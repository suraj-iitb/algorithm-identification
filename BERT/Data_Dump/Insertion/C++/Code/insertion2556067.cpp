#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

void print_vector(vector<int> &num)
{
	for(int i = 0; i < num.size(); i++){
		if(i == 0){
			cout << num[i];
		}
		else{
			cout << " " << num[i];
		}
	}
	cout << endl;
}
void insertionSort(vector<int> &num)
{
	print_vector(num);

	for(int i = 1; i <= num.size() - 1; i++){
		int a = num[i];
		int j = i - 1;
		while(j >= 0 && num[j] > a){
			num[j + 1] = num[j];
			j--;
		}
		num[j + 1] = a;
		print_vector(num);
	}
}
int main(void)
{	
	int n;//??°????????????
	cin >> n;
	
	vector<int> num(n);
	
	for(int i = 0; i < n; i++){
		cin >> num[i];
	}
	
	insertionSort(num);
		
	return 0;
}
