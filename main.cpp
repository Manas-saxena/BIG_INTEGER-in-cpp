#include<iostream>
#include "big_int.h"

using namespace std;

int main()
{
  BIG_INT big="123456";
    BIG_INT big2=big;
    big2 = 2000;
  cout<<big.get_num();
    cout<<big2.get_num();
}