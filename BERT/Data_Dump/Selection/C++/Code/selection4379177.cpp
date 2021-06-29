#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void input(vector<int> a){

}

void output(vector<int> x){
    int y = x.size();
    for(int i=0;i<y-1;i++){
        cout << x[i] << " ";
    }
    cout << x[y-1] << endl;;
}

void selectionsort(vector<int> x){
    int y = x.size(),t;
    int cnt=0 ,minj = 0;
    for(int i=0;i<y-1;i++){
        minj = i;
        for(int j=i;j<y;j++){
            if(x[j] < x[minj]){
                minj = j;
            }
        }   
        t = x[i];x[i] = x[minj];x[minj] = t;
        if(i != minj)cnt++;        
    }
    output(x);
    cout << cnt << endl;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    selectionsort(a);
}
