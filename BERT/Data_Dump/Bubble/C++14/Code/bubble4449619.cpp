#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N,temp;
    int count = 0;
    vector<int> rt;
    cin>>N;
    while(cin>>temp){
        rt.push_back(temp);
    }
    for(int i = 0;i<N;i++){
        for (int j=N-1;j>i;j--){
            if(rt[j]<rt[j-1]){
                count++;
                temp = rt[j];
                rt[j] = rt[j-1];
                rt[j-1] = temp;
            }
        }
        if(i!=N-1)
            cout<<rt[i]<<" ";
        else
            cout<<rt[i]<<endl;
    }
    cout<<count<<endl;
}
