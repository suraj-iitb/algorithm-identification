#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> &v){
    int i = 0;
    vector<int>::iterator ite = v.begin();
    while(ite != v.end()){
        if(i++ != 0)
            cout << " ";
        cout << *ite;
        ite++;
    }
    cout << endl;
}

int bubbleSort(vector<int> &v){
    int size = v.size(), i, cnt = 0;
    bool changed = true;
    while(changed){
        changed = false;
        for(i = 0; i < size-1; i++){
            if(v[i] > v[i+1]){
                int tmp = v[i];
                v[i] = v[i+1];
                v[i+1] = tmp;
                changed = true;
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    int n, x, i;
    vector<int> v;
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }
    int cnt = bubbleSort(v);
    print(v);
    cout << cnt << endl;
    return 0;
}
