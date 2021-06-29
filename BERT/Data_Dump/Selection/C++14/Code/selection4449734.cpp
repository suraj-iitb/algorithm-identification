#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N,temp;
    int count = 0;
    cin>>N;
    vector<int> rt;
    while(cin>>temp){
        rt.push_back(temp);
    }
    for(int i =0;i<N;i++){
        int mini = i;
        for(int j = i;j<N;j++){
            if(rt[j]<rt[mini]){
                mini = j;
            }
        }
        if (i!=mini) {
            count++;
            temp = rt[i];
            rt[i] = rt[mini];
            rt[mini] = temp;
        }
        if(i!=N-1)
           cout<<rt[i]<<" ";
        else
            cout<<rt[i]<<endl;
    }
    cout<<count<<endl;
}

