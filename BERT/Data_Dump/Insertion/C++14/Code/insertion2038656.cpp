#include <functional>
#include <utility>

template <typename T, typename F = std::less<>>
void InsertionSort(T& a, F comp = F()) {
	int n = a.size();
	
	for(int i = 0; i < n; ++i){
        int j = i - 1;
        while(j >= 0 && comp(a[j + 1], a[j])){
        	std::swap(a[j], a[j + 1]);
            --j;
        }
    }
}

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

template <typename T, typename F = std::less<>>
void f(T& a, F comp = F()) {
	int n = a.size();
	
	for(int i = 0; i < n; ++i){
        int j = i - 1;
        while(j >= 0 && comp(a[j + 1], a[j])){
        	std::swap(a[j], a[j + 1]);
            --j;
        }
        
        for(int i = 0; i < n; ++i) {
        	if(i) cout << ' ';
        	cout << a[i];
        }
        cout << endl;
    }
}

int main()
{
	
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    
    f(v);
    
}
