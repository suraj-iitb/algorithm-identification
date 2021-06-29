#include<iostream>
#include<vector>

using namespace std;

void show(vector<int> &array,int size){
    int cnt = 0;
    for(int a: array){
        cout << a;
        cnt++;
        if(cnt == size) break;
        else cout << " ";
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(100);
    for(int i=0;i < n;i++){
        cin >> a.at(i);
    }
    for(int i=0;i < n;i++){
        int v = a.at(i);
        int j=i-1;
        while(j >= 0 && a.at(j) > v){
            a.at(j+1) = a.at(j);
            j--;
        }
        a.at(j+1) = v;
        show(a,n);
    }
    return 0;
}
