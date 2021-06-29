#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX = 1000000001;

void merge(vector<pair<char,int>> &array,int left,int mid,int right){
    vector<pair<char,int>> left_array,right_array;
    for(int i=left;i<mid;i++){
        left_array.push_back(array.at(i));
    }
    for(int i=mid;i<right;i++){
        right_array.push_back(array.at(i));
    }
    left_array.push_back(make_pair('Z',MAX));
    right_array.push_back(make_pair('Z',MAX));
    int li=0, ri=0;
    for(int i=left;i<right;i++){
        if(left_array.at(li).second <= right_array.at(ri).second){
            array.at(i) = left_array.at(li);
            li++;
        }else{
            array.at(i) = right_array.at(ri);
            ri++;
        }
    }
}

void mergeSort(vector<pair<char,int>> &array,int left,int right){
    if(left+1 < right){
        int mid = (left + right) / 2;
        mergeSort(array,left,mid);
        mergeSort(array,mid,right);
        merge(array,left,mid,right);
    }
}

 int partition(vector<pair<char,int>> &array,int s,int g){
    int x = array.at(g).second;
    int j = s-1;
    for(int i=s;i<g;i++){
        if(array.at(i).second <= x){
            j++;
            swap(array.at(i),array.at(j));
        }
    }
    swap(array.at(j+1),array.at(g));
    return j+1;
}


void quickSort(vector<pair<char,int>> &array,int s,int g){
    if(s < g){
        int p = partition(array,s,g);
        quickSort(array,s,p-1);
        quickSort(array,p+1,g);
    }
}

int main(){
    int n;
    cin >> n;
    vector<pair<char,int>> array(n),copy(n);
    for(int i=0;i<n;i++){
        cin >> array.at(i).first >> array.at(i).second;
    }
    copy = array;
    mergeSort(copy,0,n);
    quickSort(array,0,n-1);
    //for(int i=0;i<n;i++) printf("%c %d\n",copy.at(i).first,copy.at(i).second);
    if(copy == array){
        cout << "Stable" << endl;
    }else{
        cout << "Not stable" << endl;
    }
    for(int i=0;i<n;i++) printf("%c %d\n",array.at(i).first,array.at(i).second);
}
