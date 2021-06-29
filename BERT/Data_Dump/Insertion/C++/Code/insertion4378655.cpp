#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void output(vector<int> x){
    int y = x.size();
    for(int i=0;i<y-1;i++){
        cout << x[i] << " ";
    }
    cout << x[y-1] << endl;;
}
void insertionSort(vector<int> x){
    int n = x.size();
    int v;
    for(int i=1;i<n;i++){
        v = x[i];
        int j = i-1;
        while(j>=0&&x[j]>v){
            x[j+1] = x[j];
            j--;
            x[j+1] = v;  
        }
        output(x);
    }
}


int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    output(a);
    insertionSort(a);
    return 0;
}
