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

void bubble_sort(vector<int> &a){
    bool flag = true;
    int swaps = 0;
    while(flag){
        flag = false;
        for(int i=(int)a.size()-1; i>0; i--){
            if(a[i] < a[i-1]){
                int temp = a[i];
                a[i] = a[i-1];
                a[i-1] = temp;
                flag = true;
                swaps++;
            }
        }
    }
    print_arr(a);
    cout << swaps << endl;
}

int main(){
    int n; cin >> n;
    vector<int> a(n); collect(a, n);
    bubble_sort(a);
    return 0;
}
