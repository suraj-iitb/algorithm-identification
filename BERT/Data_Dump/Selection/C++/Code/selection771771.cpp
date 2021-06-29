#include <iostream>
using namespace std;

void swap(int* a,int* b)
{
 int tmp;
 tmp = *a;
 *a = *b;
 *b = tmp;
}
int main()
{
 int n;
 cin >> n;
 int nums[10000];
 int i;
 for(i=0;i<n;i++)
 {
  cin >> nums[i];
 }

 int j;
 int count = 0;
 int mini;
 for(i = 0;i<n;i++)
 {
  mini = i;
  for(j=i;j<n;j++)
  {
   if(nums[j]<nums[mini]){mini = j;}
  }
  if(mini!=i){swap(nums[i],nums[mini]);count++;}
 }
 
 cout << nums[0];
 for(i=1;i<n;i++)
 {
  cout << " " << nums[i];
 }
 cout << "\n" << count << endl;

}
