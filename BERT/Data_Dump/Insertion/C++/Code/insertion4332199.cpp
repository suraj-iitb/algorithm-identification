#include <iostream>
#include <vector>

using namespace std;

vector<int> A;

void InsertSort(vector<int> a, int b){
    for(int i=1;i<b;i++){
        int v=a[i];
        int j=i-1;
        while(v<a[j]&&j>=0){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=v;
        for(int t=0;t<a.size();t++){
            if(t==a.size()-1){
                cout << a[t] << endl;
                break;
            }
            cout << a[t] << " ";
        }
    }
}

int main(){
    int n;
    cin >> n;
    A.resize(n);
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    for(int i=0;i<A.size();i++){
            if(i==A.size()-1){
                cout << A[i] << endl;
                break;
            }
            cout << A[i] << " ";
        }
    InsertSort(A, n);
}
