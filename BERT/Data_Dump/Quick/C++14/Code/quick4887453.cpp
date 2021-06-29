#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void merge(int l,int m,int r,vector<pair<char,int>> &array){
    vector<pair<char,int>> left_array,right_array;
    for(int i=l;i<m;i++){
        left_array.push_back(array.at(i));
    }
    for(int i=m;i<r;i++){
        right_array.push_back(array.at(i));
    }
    left_array.push_back(make_pair('Z',1000000001));
    right_array.push_back(make_pair('Z',1000000001));
    int li = 0, ri = 0;
    for(int i=l;i<r;i++){
        if(left_array.at(li).second <= right_array.at(ri).second){
            array.at(i) = left_array.at(li);
            li++;
        }else{
            array.at(i) = right_array.at(ri);
            ri++;
        }
    }
}

void mergeSort(int l,int r,vector<pair<char,int>> &array){
    if(l+1<r){
        int mid = (l+r) / 2;
        mergeSort(l,mid,array);
        mergeSort(mid,r,array);
        merge(l,mid,r,array);
    }
}

int partition(int s,int g,vector<pair<char,int>> &array){
    int x = array.at(g).second;
    int j = s - 1;
    for(int i=s;i<g;i++){
        if(array.at(i).second <= x){
            j++;
            swap(array.at(i),array.at(j));
        }
    }
    swap(array.at(j+1),array.at(g));
    return j+1;
}

void quickSort(int s,int g,vector<pair<char,int>> &array){
    if(s < g){
        int p = partition(s,g,array);
        quickSort(s,p-1,array);
        quickSort(p+1,g,array);
    }
}



int main(){
    int n;
    cin >> n;
    vector<pair<char,int>> array(n),copy(n);
    for(int i=0;i<n;i++) cin >> array.at(i).first >> array.at(i).second;
    copy = array;
    mergeSort(0,n,copy);
    quickSort(0,n-1,array);
    //cout << "!!!" << endl;
    if(array == copy){
        cout << "Stable" << endl;
    }else{
        cout << "Not stable" << endl;
    }
    for(int i=0;i<n;i++){
        cout << array.at(i).first << " " << array.at(i).second << endl;
    }
}
