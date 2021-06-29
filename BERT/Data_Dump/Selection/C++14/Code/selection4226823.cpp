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

void selection_sort(vector<int> &a){
    int swaps = 0;
    for(int i=0; i<a.size(); i++){
        int min_idx = i;
        for(int j=i; j<a.size(); j++){
            if(a[j]<a[min_idx]){
                min_idx = j;
            }
        }
        if(min_idx==i) continue;
        int temp = a[i];
        a[i] = a[min_idx];
        a[min_idx] = temp;
        swaps++;
    }
    print_arr(a);
    cout << swaps << endl;
}

int main(){
    int n; cin >> n;
    vector<int> a(n); collect(a, n);
    selection_sort(a);
    return 0;
}
