#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    bool flag = true;
    int count = 0;
    vector<int> a;
    
    cin >> n;
    for (int i = 0; i < n; i++) { int tmp; cin >> tmp; a.push_back(tmp); }
    
    for (int i = 0; flag && i < n; i++) {
        flag = false;
        for (int j = n-1; j > i; j--) {
            if (a[j] < a[j-1]) {
                swap(a[j], a[j-1]);
                count++;
                flag = true;
            }
        }
    }
    for (int i = 0; i < n-1; i++) cout << a[i] << " ";
    cout << a[n-1] << endl;
    cout << count << endl;

    return 0; 
}
