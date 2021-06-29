//
//  main.cpp
//  AutoAnswerSheets
//
//  Created by Niko@LOS on 2017/03/07.
//
//

#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
    // insert code here...
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++)cin>>vec[i];
    for(int j=0;j<vec.size();j++)cout<<vec[j]<<(j==vec.size()-1?"":" ");
    cout<<endl;
    for(int i=1;i<n;i++){
        int j,cur=i;
        for(j=cur-1;j>=0;j--){
            if(vec[j]<vec[cur])break;
            swap(vec[cur--],vec[j]);
        }
        for(int j=0;j<vec.size();j++)cout<<vec[j]<<(j==vec.size()-1?"":" ");
        cout<<endl;
    }
    return 0;
}
