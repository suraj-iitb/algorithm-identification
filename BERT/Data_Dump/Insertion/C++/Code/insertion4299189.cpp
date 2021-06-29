#include <iostream>
#include <vector>
using namespace std;

void output(vector<int> a, int n){
    for(int i = 0; i < n-1; i++) cout << a.at(i) << " ";
    cout << a.at(n-1) << endl;
}

void isort(vector<int> a, int n){
    for(int i = 1; i < n; i++){
        int tmp = a.at(i);
        int j = i-1;
        for(; j >= 0 && a.at(j) > tmp; j--) a.at(j+1) = a.at(j);
        a.at(j+1) = tmp;
        output(a, n);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a.at(i);

    output(a, n);
    isort(a, n);
    
    return 0;
}
