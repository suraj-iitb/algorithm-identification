#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void show(int n,vector<int> v);
void insertionSort(int n,vector<int> v);

int main(){
    int n,tmp;
    vector<int> v;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    show(n,v);

    insertionSort(n,v);

    return 0;
}

void show(int n,vector<int> v){
    for(int i=0;i<n;i++){
        cout << v[i] << (i+1 < n ? ' ':'\n');
    }
}

void insertionSort(int n,vector<int> v){
    int tmp;
    bool flag = false;

    for(int i=1;i<n;i++){
        tmp = v[i];
        int j=i-1;
        while(j>=0&&tmp<v[j]){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = tmp;
        show(n,v);
    }
}
