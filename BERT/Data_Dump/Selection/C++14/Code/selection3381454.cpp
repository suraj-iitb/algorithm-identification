#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define debug(x) cerr << x << "\n"
#define all(x) (x).begin(),(x).end()
#define exist(s, e)((s).find(e) != (s).end())

void selectionSort(vector<int>&, int&);

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, tmp, i, c = 0;
    vector<int> a;
    
    cin >> n;
    for (i=0;i<n;i++) {
        cin >> tmp;
        a.push_back(tmp);
    }
    
    selectionSort(a, c);
    for (i=0;i<n;i++) cout << a[i] << ((i==n-1) ? '\n' : ' ');
    cout << c << '\n';

    return 0;
}

void selectionSort(vector<int>& a, int& c) {
    size_t N = a.size();
    int minj;
    for (int i = 0;i < N;i++) {
        minj = i;
        for (int j = i;j < N;j++) {
            if (a[j] < a[minj]) minj = j;
        }
        using std::swap;
        swap(a[minj], a[i]);
        if(minj != i)c++;
    }
}
