#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define all(obj) (obj).begin(), (obj).end()
#define rall(obj) (obj).rbegin(), (obj).rend()
#define collect(arr, size) rep(i,size) cin >> arr[i];

void print_arr(vector<int> &a){
    rep(i,a.size()-1){
        printf("%d ",a[i]);
    }
    printf("%d\n",a[a.size()-1]);
}

void insertion_sort(vector<int> &a){
    for(int i=1; i<a.size(); i++){
        print_arr(a);
        int v = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
    }
    print_arr(a);
}

int main(){
    int n; cin >> n;
    vector<int> a(n); collect(a, n);
    insertion_sort(a);
    return 0;
}
