#include <cstdlib>
#include <iostream>
#include <queue>

using namespace std;

int count = 0;

int marge(int array[], int left, int mid, int right){
    queue<int> r;
    for(int i=left; i < mid; i++){
        r.push(array[i]);
    }
    r.push(1000000001);

    queue<int> l;
    for(int i=mid; i < right; i++){
        l.push(array[i]);
    }
    l.push(1000000001);

    int count = 0;
    for(int i=left; i<right; i++){
        if( l.front() < r.front() ){
            array[i] = l.front();
            l.pop();
        }else{
            array[i] = r.front();
            r.pop();
        }
        count++;
    }

    return count;
}

int margeSort(int array[], int left,int right){
    int count = 0;
    if(right - left >= 2){
        int mid = (left + right) / 2;
        count += margeSort(array,left,mid);
        count += margeSort(array,mid,right);
        count +=  marge(array,left,mid,right);
    }

    return count;
}
       

int main(){
    int n;
    int s[500000];
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s[i];
    }

    int count = margeSort(s,0,n);

    for(int i=0; i<n; i++){
        cout << s[i];
        if(i != (n-1)){
            cout << " ";
        }
    }
    cout << endl;
    cout << count << endl;

    return 0;
}
