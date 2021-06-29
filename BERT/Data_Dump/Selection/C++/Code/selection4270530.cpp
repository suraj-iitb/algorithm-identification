#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
    int n, count = 0;
    vector<int> a;
    
    cin >> n;
    for (int i = 0; i < n; i++) { int tmp; cin >> tmp; a.push_back(tmp); }
    
    for (int i = 0; i < n; i++) {
        int minj = i;
        for (int j = i+1; j < n; j++)
            if (a.at(minj) > a.at(j)) minj = j;
        if (i != minj) {
            swap(a.at(i), a.at(minj));
            count++;
        }
    }
    for (int i = 0; i < n-1; i++) cout << a.at(i) << " ";
    cout << a.at(n-1) << endl;
    cout << count << endl;
    
    return 0;

}

