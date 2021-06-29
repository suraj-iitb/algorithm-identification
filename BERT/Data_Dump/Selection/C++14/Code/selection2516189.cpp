#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>
#include <sstream>
#include <string>
#include <cstdio>
#include <array>

using namespace std;

//???????????°??????TEST????????????????????¬???????????????????????????????????¢????????????
//#define TEST //*******************************************************************************************************************************************

//?????????????????¨??§?????\????????????????????????????????°?????????????¨???????????????????dout???????????????????????§???????????¬??????????????????????????????????????????
#ifdef TEST
    #define dout cout
#else
    stringstream dummy; //???????????°??????dout?????????????????????????????????
    #define dout dummy
#endif


int main(void) {
    int NumOfData;
    cin >> NumOfData;
    
    int cnt = 0; //swap?????°??????????????¨
    
    int a[NumOfData];
    for(int i=0; i<NumOfData; i++) {
        cin >> a[i];
    }
    
    //display a[]
    for(int k=0; k<NumOfData; k++) {
        if(k==0) dout << a[k];
        else dout << " " << a[k];
    }
    dout << endl;
    
    
    
    //selection sort procedure
    
    for(int i=0; i<NumOfData-1; i++){
        
        //i??????????????????i???????°????????????????????????§??????????°???????j_min?????¢???
        int j_min = i;
        for(int j=i+1; j<NumOfData; j++){
            if(a[j_min]>a[j]){
                j_min = j;
            }
        } //end of j-loop
        
        //swap i & j_min
        if( i != j_min ) cnt++; //?????????swap???????????¨?????????swap?????°????????????
        int tmp = a[i];
        a[i] = a[j_min];
        a[j_min] = tmp;

        //display a[]
        for(int k=0; k<NumOfData; k++) {
            if(k==0) dout << a[k];
            else dout << " " << a[k];
        }
        dout << endl;
        
    } //end of i-loop
    
    
    //display a[]
    for(int k=0; k<NumOfData; k++) {
        if(k==0) cout << a[k];
        else cout << " " << a[k];
    }
    cout << endl;
    
    cout << cnt << endl;
    
    return 0;
}
