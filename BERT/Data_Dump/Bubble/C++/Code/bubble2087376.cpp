#include <stdio.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int flag=1;
  int nums[101];
  int n;
  int i=0;
  int k;
  int count=0;
  int temp;
  scanf("%d\n",&n );
  while (i<n) {
    scanf("%d",&nums[i]);
    i++;
  }
  while (flag) {
    /* code */
    flag=0;
    for (i =n-1; i >0; i--) {
      if (nums[i]<nums[i-1]) {
        temp=nums[i];
        nums[i]=nums[i-1];
        nums[i-1]=temp;
        flag=1;
        count++;
        /* code */
      }
    }

  }




  k=0;



  while(k<n){
    printf("%d",nums[k]);
    k++;
    if(k!=n)
    printf(" ");
  }
    printf("\n");
    printf("%d\n", count);
    return 0;
}
