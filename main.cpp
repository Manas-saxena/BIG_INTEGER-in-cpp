#include<iostream>
#include "big_int.h"

using namespace std;

int main()
{
  BIG_INT a;
  cin>>a;

  BIG_INT b;
  cin>>b;
  string ans = a+b;
  cout<<ans<<endl;
}