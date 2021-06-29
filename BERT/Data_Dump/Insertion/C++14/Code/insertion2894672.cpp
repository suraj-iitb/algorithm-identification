#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <numeric>
#include <ctype.h>
using namespace std;
void print(vector<int> v);
int main(void){
    int N, num;
    vector<int> v;
    cin >> N;
    for(int i = 0; i < N; i++){
	cin >> num;
	v.push_back(num);
    }
    for(int i = 1; i < N; i++){
	print(v);
	int x = v[i];
	int j = i - 1;
	while(j >= 0 && v[j] > x){
	    v[j + 1] = v[j];
	    j--;
	    v[j + 1] = x;
	}
    }
    print(v);
}

void print(vector<int> v){
    for(int i = 0; i < v.size(); i++){
	cout << v[i];
	if(i != v.size() - 1) cout << ' ';
    }
    cout << endl;
}

