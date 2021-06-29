#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

struct card {
    char face;
    int num, id;
};

// void merge(vector<pair<char, int> >&v, int l, int m, int r){
//     int l1 = m -l;
//     int r1 = r-m;
//     vector<pair<char, int> >lv(l1), rv(r1);
//     for(int i=0; i<l1; i++) lv[i] = v[l+i];
//     for(int i=0; i<r1; i++) rv[i] = v[m+i];
    
//     int i = 0, j = 0;
//     for(int k=l; k<r; k++){
//         if(i<l1 and (j>=r1 || lv[i].second<=rv[j].second)) v[k] = lv[i++];
//         else v[k] = rv[j++];
//     }
// }

// void mergeSort(vector<pair<char, int> >&v, int l, int r){
//     if(l+1<r){
//         int m = (l+r)/2;
//         mergeSort(v, l ,m);
//         mergeSort(v, m, r);
//         merge(v, l, m, r);
//     }
// }

int partition(vector<card>&v, int p, int r){
    int x = v[r].num;
    int i = p-1;
    for(int j=p;j<r;j++) if(v[j].num <= x) swap(v[++i], v[j]);
    swap(v[++i],v[r]);
    return i;
}

void quickSort(vector<card>&v, int p, int r){
    if(p<r){
        int q = partition(v, p, r);
        quickSort(v, p, q-1);
        quickSort(v, q+1, r);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<card> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i].face >> v[i].num;
        v[i].id = i;
    }
    quickSort(v, 0, n-1);
    bool stable = true;
    for(int i=1; i<n; i++){
        if(v[i].num == v[i-1].num and v[i].id < v[i-1].id) stable = false;
    }
    if(stable) cout << "Stable" << endl;
    else cout << "Not stable" << endl;
    for(int i=0; i<n; i++) cout << v[i].face << " " << v[i].num << endl;
    
    return 0;
}
