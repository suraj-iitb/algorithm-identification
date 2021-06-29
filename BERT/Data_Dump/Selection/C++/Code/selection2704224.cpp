#include<iostream>
using namespace std;

int main(){
    int n, a[100];
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    // selecion sort
    int m_ind, swap_num = 0;
    for(int i=0;i<n;i++){
        m_ind = i;
        for(int j=i+1;j<n;j++){
            if(a[j] < a[m_ind]) m_ind = j;
        }
        swap(a[i], a[m_ind]);
        if(i!=m_ind) swap_num++;
    }
    // disp result
    for(int i=0;i<n;i++){
        if(i) cout << ' ';
        cout << a[i];
    }
    cout << endl;
    cout << swap_num << endl;
    return 0;
}

