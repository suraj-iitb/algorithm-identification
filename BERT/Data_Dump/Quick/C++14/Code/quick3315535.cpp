#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int partition(pair<int,char> *A, int p, int r){
    int x=A[r].first;
    int i=p-1;
    for(int j=p;j<r;j++){
        if(A[j].first<=x){
            i++;
            auto tmp=A[i];
            A[i]=A[j];
            A[j]=tmp;
        }
    }
    auto tmp=A[i+1];
    A[i+1]=A[r];
    A[r]=tmp;

    return i+1;
}

void quick_sort(pair<int,char> *A, int p, int r){
    if(p<r){
        int q = partition(A, p , r);
        quick_sort(A, p, q-1);
        quick_sort(A, q+1, r);
    }
}

int main(){
    unordered_map<int, queue<char>> suit;
    int n;
    pair<int,char> A[100000];
    cin >> n;
    for(int i=0;i<n;i++){
        char s;
        int  num;
        cin >> s >> num;
        A[i]=make_pair(num, s);
        suit[num].push(s);
    }

    quick_sort(A, 0, n-1);
    for(int i=0;i<n;i++){
        if(A[i].second!=suit[A[i].first].front()){
            cout << "Not stable" << endl;
            break;
        }
        suit[A[i].first].pop();
        if(i==n-1) cout << "Stable" << endl;
    }
    for(int i=0;i<n;i++) cout << A[i].second << ' ' << A[i].first << endl;
    
    return 0;
}
