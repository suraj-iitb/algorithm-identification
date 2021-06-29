#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<algorithm>
#include<cmath>

using namespace std;
void print(vector<int> a);

int main(){
    int n; cin >> n;
    vector<int> a(n); for (int i=0;i<n;i++) cin >> a[i];
    for (int i = 0;i<n;i++){
        int v = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        print(a);
    }

    return 0;
}

void print(vector<int> a){
    int n = a.size();
    for (int j=0;j<n;j++) {
        if (j != n-1) cout << a[j] << " ";
        else cout << a[j] << endl;
    }
}

//Sum accumulate(v.begin(),v.end(),0);
//Sort sort(v.begin(),v.end())
//Power pow(base, e)
//Min min = *std::min_element(vec.begin(), vec.end());
//Max max = *std::max_element(vec.begin(), vec.end());

