#include<iostream>
#include<vector>
using namespace std;
int main(){
int a;
cin >> a;
vector<int> list(a);
for(int i = 0; i < a; i++){
    cin >> list.at(i);
}
for(int i = 0; i < a; i++){
    cout << list[i];
    if(i != a - 1)
    cout << " ";
    if(i == a - 1)
    cout << endl;
}
for(int i = 1; i < a; i++){
    int v = list[i];
    int j = i - 1;
    while(j >= 0 && list[j] > v){
        list[j + 1] = list[j];
        j--;
        list[j + 1] = v;
    }
for(int k = 0; k < a; k++){
if(k <= a - 2)
cout << list[k] << " ";
else
{
    cout << list[k] << endl; 
}

}
}
}
