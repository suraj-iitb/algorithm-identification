#include <iostream>
#include <vector>

using namespace std;


void SelectionSort(vector<int> v){
    int cnt=0;
    for(int i=0;i<v.size();i++){
        int mini=i;
        for(int j=i;j<v.size();j++){
            if(v[j]<v[mini]){
                mini=j;
            }
        }

        if(i!=mini){
            int tmp=v[i];
            v[i]=v[mini];
            v[mini]=tmp;
            cnt++;
        }
       
    }
    for(int i=0;i<v.size()-1;i++){
        cout<<v[i]<<" ";
    }
    cout<<v[v.size()-1]<<endl;
    cout<<cnt<<endl;
}


int main(){
    int n;
    vector<int> v;
    cin>>n;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    SelectionSort(v);
    return 0;
}
