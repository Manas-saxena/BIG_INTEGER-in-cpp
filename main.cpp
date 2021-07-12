#include<iostream>
#include "big_int.h"

using namespace std;

int main()
{
  BIG_INT a;
  cin>>a;

  BIG_INT b;
  cin>>b;
  
   BIG_INT c = pow_big(a,b);
   
 cout<<c.get_num()<<endl;
}