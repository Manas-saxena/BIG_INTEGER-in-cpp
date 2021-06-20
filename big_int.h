#include<bits/stdc++.h>

using namespace std;

class BIG_INT{
    private:
     string num ;
    
    public:

    //consturctors 
    BIG_INT(){
        num="0";
    }
    BIG_INT(int number)
    {
        ostringstream convert;
        convert<<number;
        num = convert.str();
    }
    BIG_INT(long long number)
    {
        ostringstream convert;
        convert<<number;
        num = convert.str();
    }
    BIG_INT(char const number[])
    {
        for(int i=0;number[i]!='\0';i++)
        {
            num.push_back(number[i]);
        }
        if(!input_valid(num))
        {
            cerr << "Invalid Input.. Please Use Valid BIGINTEGER" << endl;
            exit(0);
        }
    }
    BIG_INT(string number){
    if(!input_valid(number))
    {
        cerr << "Invalid Input.. Please Use Valid BIGINTEGER" << endl;
        exit(0);
    }
       num = number;
    }
    BIG_INT( BIG_INT const &big)
    {
        if (!input_valid(big.get_num()))
        {
            cerr << "Invalid Input.. Please Use Valid BIGINTEGER" << endl;
            exit(0);
        }
       num = big.get_num();
    }

    // get num and set num
    void set_num(string number) {
        num = number;
    }
    string get_num() const{
        return num ;
    }
    //check for valid input 
    bool input_valid(string number)
    {
        for (int i = 0; i < number.length(); ++i)
        {
            if ((int)number[i] < 48 || (int)number[i] > 57)
                return false;
        }
        return true;
    }

    //friend function for cin and cout
    friend ostream & operator << (ostream& out ,const BIG_INT & big);
    friend istream & operator >> (istream& in ,  BIG_INT & big);

    
};

ostream & operator << (ostream &out, const BIG_INT &big)
{
    out<<big.num;
    return out;
}

istream & operator >> (istream &in ,  BIG_INT &big)
{
    in>>big.num;
    return in;
}