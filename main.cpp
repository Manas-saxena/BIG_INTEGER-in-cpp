#include<iostream>
#include "big_int.h"

using namespace std;

int main()
{
  BIG_INT n1;                                  // n1 defined with value 0
  BIG_INT n2(123);                             // n2 defined with value int value
  BIG_INT n3((long long int)1234567898765432); // n3 defined with value long long int value
  BIG_INT n4("7832467326423873423435");        // n4 defined with string value
  BIG_INT n5(n3);                              // n5 defined with values of n3

  /********Converting to BIG_INT*********/
  int num1 = -321;
  long long int num2 = -9876543219876543;
  string str1 = "-2112321321321312421534365777";
  BIG_INT n6 = num1; // converting int to BIG_INT
  BIG_INT n7 = num2; // converting long long int to BIG_INT
  BIG_INT n8 = str1; // converting string to BIG_INT

  /********user Input*********/
  BIG_INT n9;
  cout << "Enter the value for n9: ";
  cin >> n9; // Taking input from user

  cout << "n1: " << n1 << endl; /**           Printing Values        **/
  cout << "n2: " << n2 << endl; /**           Printing Values        **/
  cout << "n3: " << n3 << endl; /**           Printing Values        **/
  cout << "n4: " << n4 << endl; /**           Printing Values        **/
  cout << "n5: " << n5 << endl; /**           Printing Values        **/
  cout << "n6: " << n6 << endl; /**           Printing Values        **/
  cout << "n7: " << n7 << endl; /**           Printing Values        **/
  cout << "n8: " << n8 << endl; /**           Printing Values        **/

  /********Arithmatic Operations*********/
  cout << "Addition: " << n1 + n2 << endl;       // Addition
  cout << "Subtraction: " << n2 - n1 << endl;    // subtraction
  cout << "Multiplication: " << n1 * n2 << endl; // Multiplication
  cout << "Division: " << n4 / n2 << endl;       // Division

  cout << "n2 + 5: " << n2 + 5 << endl;
  cout << "n2 - 5: " << n2 - 5 << endl;
  cout << "n2 * 5: " << n2 * 5 << endl;
  cout << "n2 / 5: " << n2 / 5 << endl;



  /******** other Operations *********/

  // unary operations
  cout << "PreIncrement: " << ++n2 << endl;
  cout << "PreDecrement: " << --n2 << endl;
  cout << "PostIncrement: " << n2++ << endl;
  cout << "PostDecrement: " << n2-- << endl;

  // equality check
  cout << "Check n3 != n5: " << (bool)(n3 != n5) << endl; // Checking if value of both are different
  cout << "Check n3 == n5: " << (bool)(n3 == n5) << endl; // Checking if value of both are same

  n3 += n2;
  cout << "n3 += n2: " << n3 << endl;

  n3 -= n2;
  cout << "n3 -= n2: " << n3 << endl;

  n3 *= n2;
  cout << "n3 *= n2: " << n3 << endl;

  n3 /= n2;
  cout << "n3 /= n2: " << n3 << endl;

  /********Functions*********/

  cout << "Maximum: " << max(n1, n2) << endl;                            // Maximum of two Numbers
  cout << "Minimum: " << min(n1, n2) << endl;                            // Minimum of two Numbers
  cout << "absolute: " << abs(n1) << " " << abs(n2) << endl;         // Absolute value of a number
  cout << "Factorial: " << fact_big(n1) << " " << fact_big(n2) << endl;      // Factorial of a number
  cout << "Reverse: " << rev(n3) << endl;                                // Reverse a number
  cout << "Counting the occurance of a digit: " << n_count(n9, 6) << endl; // Counting the occurance of a digit
  cout << "Erasing all occurance of a digit: " << n_erase(n9, 4) << endl;  // Erasing all occurances of a digit
  cout << "isPaliBhim: " << (bool)check_palin(n9) << endl;                    // Checking if a number is palindrome
  cout << "Finds power: " << pow_big(n3, n2) << endl;                         // finds x to the power y, where x and y is any int. Returns Integer value in form of string
}