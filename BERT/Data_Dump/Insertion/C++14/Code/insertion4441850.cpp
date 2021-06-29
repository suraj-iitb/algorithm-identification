#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    int temp;
    vector<int> rt;
    for(int m = 0;m<n-1;m++){
       cin>>temp;
       rt.push_back(temp);
       cout<<temp<<" ";
    }
    cin>>temp;
    rt.push_back(temp);
    cout<<temp<<endl;
    int key;
    for(int i = 1;i<n;i++){
        key = rt[i];
        int j = i-1;
        while(j>=0&&rt[j]>key){
            rt[j+1] = rt[j];
            j--;
        }
        rt[j+1] = key;
        for (int m = 0;m<n-1;m++){
            cout<<rt[m]<<" ";
        }
        cout<<rt[n-1]<<endl;
    }
}

