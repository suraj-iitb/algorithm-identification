#include<iostream>
#include<vector>
using namespace std;

int selectionSort(vector<int> &v){
    int cnt = 0, size = v.size(), i, j, min;
    for(i = 0; i < size; i++){
        min = i;
        for(j = i; j < size; j++){
            min = v[j] < v[min] ? j : min;
        }
        if(i != min){
            int tmp = v[i];
            v[i] = v[min];
            v[min] = tmp;
            cnt++;
        }
    }
    return cnt;
}
void print(vector<int> &v){
    vector<int>::iterator ite = v.begin();
    while(ite != v.end()){
        if(ite != v.begin())
            cout << " ";
        cout << *ite;
        ite++;
    }
    cout << endl;
}
int main(){
    int n, x, i, cnt;
    vector<int> v;
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }
    cnt = selectionSort(v);
    print(v);
    cout << cnt << endl;
    return 0;
}
