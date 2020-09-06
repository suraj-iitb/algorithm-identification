  #include <iostream>
const int num = 105;
using namespace std;

int main(){//我自己的冒泡
    int a[num];
    int n;
    cin>>n;
    for(int i = 0;i<n; ++i) cin>>a[i];
    int count = 0;
    int x=0;//外层循环次数
    int flag = 1;
    while(flag){
        x++;
        flag = 0;
        for(int i = n-1;i>0;--i){
            if(a[i]<a[i-1]){
                int temp = a[i];
                a[i] = a[i-1];
                a[i-1] = temp;
                flag = 1;
                count++;
            }
        }
    }

     //输出
        for(int i =0;i<n;++i) {
            if(i!=0) cout<<' ';
            cout<<a[i];
        }
        cout<<endl;
        cout<<count<<endl;
        //cout<<x<<endl;
    return 0;
}
