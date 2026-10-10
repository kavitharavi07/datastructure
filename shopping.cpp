#include <iostream>
using namespace std;
int main()
{
  string a[10]={"pen","book"};
  int n=2;
  a[n++]="pencil";
  for(int i=0;i<n;i++)
    cout<<a[i]<<endl;
  return 0;
}
