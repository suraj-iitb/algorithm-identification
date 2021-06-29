#include<iostream>
#include<vector>
using namespace std;

void printa(vector<int> a, int n)
{
    for (int i = 0; i < n - 1 ; i++) cout << a.at(i) << " ";
    cout << a.at(n-1) << endl;
}
int main()
{
    int n;
    vector<int> a;
    
    cin >> n;
    for (int i = 0; i < n; i++) { int tmp; cin >> tmp; a.push_back(tmp); }
    printa(a, n);
    for (int i = 1; i < n; i++) {
        int v = a.at(i); 
        int j;
        for (j = i - 1; j >= 0 && v < a.at(j); j--) a.at(j+1) = a.at(j);
        a.at(j+1) = v;
        printa(a, n);
  }

  return 0; 
}
