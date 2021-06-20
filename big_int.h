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

    // add and subtract
    static string add (string a , string b)
    {
        int carry =0;
        string answer;
        int asize = a.size();
        int bsize = b.size();
        int i=asize-1;
        int j=bsize-1;
        while(i>=0 and j>=0)
        {
            int result = (a[i]-'0') + (b[j]-'0') +carry ;  
            char to_push = ('0'+ (result%10));
            result /=10;
            carry =  result%10;
            answer.push_back(to_push);
            i--;
            j--;

        }

        while(i>=0)
        {
            int result = (a[i] - '0') + carry;
            char to_push = ('0' +(result%10));
            result/=10;
            carry = result %10;
            answer.push_back(to_push);
            i--;
        }

        while(j>=0)
        {
            int result = (b[j] - '0') + carry;
            char to_push = ('0' + (result % 10));
            result /= 10;
            carry = result % 10;
            answer.push_back(to_push);
            j--;
        }
        if(carry >0)
        {
            char to_push = ('0' + carry );
            answer.push_back(to_push);
        }
        reverse(answer.begin() , answer.end());
        return answer ; 
    }

    string operator + ( BIG_INT const & bigb)
    {
        return add(this->num  , bigb.num);
    }
    
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