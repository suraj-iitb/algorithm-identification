#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#define MAXSIZE 200000
#define PI 3.141592653589
using namespace std;


int main(){
    int n;
    std::cin >> n;
    int a[MAXSIZE]={0};
    for(int i=0;i<n;i++){
      std::cin >> a[i];
    }

    for(int i=1;i<n;i++){
      for(int j=0;j<n-1;j++){
        std::cout << a[j]<<" ";
      }

      std::cout << a[n-1] << '\n';
      int v=a[i];
      int j=i-1;
      while (j>=0&&a[j]>v) {
        a[j+1]=a[j];
        j--;
      }
      a[j+1]=v;


    }

    for(int j=0;j<n-1;j++){
      std::cout  << a[j]<<" ";
    }
    std::cout << a[n-1] << '\n';



}
