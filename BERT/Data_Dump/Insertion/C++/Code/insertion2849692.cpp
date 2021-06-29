#include <iostream>
#include <vector>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

using namespace std;

void printVec(vector<int> v){
    int size = v.size()-1;
    REP(i,size){
        if(i==v.size()) cout << v[i];
        else cout << v[i] << " " ;
    }
    cout << v[size] << endl;
}

void insertionSort(vector<int> vector, int n){ // N個の要素を含む0-オリジンの配列A
//   for i が 1 から N-1 まで
    FOR(i,0,n){
//      v = A[i]
        int v = vector[i];
//      j = i - 1
        int j = i-1;
//      while j >= 0 かつ A[j] > v
        while(j>=0 && vector[j]>v){
//        A[j+1] = A[j]
            vector[j+1] = vector[j];
            //printVec(vector);
//        j--
            j--;
        }

//      A[j+1] = v
        vector[j+1] = v;
        printVec(vector);
    }

}

signed main(){
    int n;
    cin >> n;

    vector<int> v;
    REP(_,n){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    insertionSort(v, n); 
    
}
