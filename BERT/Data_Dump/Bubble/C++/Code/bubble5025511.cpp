#include<bits/stdc++.h>
using namespace std;
void cout_array(int n,int* arrays){
    for(int i=0;i<n;i++){
        if(i != n-1){
            cout<<arrays[i]<<" ";
        }else{
            cout<<arrays[i]<<endl;
        }
        
    }
}
int *bubble_sort(int n,int *unsorted){
    bool flag = 0;
    int changetimes = 0;
    for(int i=0;i<n;i++){
        flag=1;
        for(int j=n-2;j>=i;j--){
            if(unsorted[j]>unsorted[j+1]){
                flag=0;
                int v=unsorted[j];
                unsorted[j]=unsorted[j+1];
                unsorted[j+1]=v;
                changetimes++;
            }
        }
        //cout_array(n,unsorted);
        if(flag){
            break;
        }
    }
    cout_array(n,unsorted);
    cout<<changetimes<<endl;
    return unsorted;
}

int main(){
    int the_len;
    cin>>the_len;
    int *unsorted = new int[the_len];
    for(int item=0;item<the_len;item++){
        cin>>unsorted[item];
    }
    int *sorted = new int[the_len];
    sorted=bubble_sort(the_len,unsorted);
    return 0;
}
