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
      set_num(number);
    }
    BIG_INT( BIG_INT const &big)
    {
        if (!input_valid(big.get_num()))
        {
            cerr << "Invalid Input.. Please Use Valid BIGINTEGER" << endl;
            exit(0);
        }
      set_num(big.get_num());
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
        int i = 0;
        if(number[0] == '-' and number.size()!=1)
        {
            i = 1;
        }
        for (; i < number.length(); ++i)
        {
            if ((int)number[i] < 48 || (int)number[i] > 57)
                return false;
        }
        return true;
    }

    //friend function for cin and cout
    friend ostream & operator << (ostream& out ,const BIG_INT & big);
    friend istream & operator >> (istream& in ,  BIG_INT & big);
    static string removezero(string number){
        int i = 0, flag = 0;
        if (number[0] == '-')
        {
            flag = 1;
            i++;
        }
        while (number[i] == '0')
            i++;
        if (flag)
            number.erase(1, i);
        else
            number.erase(0, i);
        return number;
    }
    static string maxcompare(string a , string b )
    {
        string answer = "";
        int i;
        if (a[0] == '-' and b[0] != '-')
        {
            return b;
        }
        else if (a[0] != '-' and b[0] == '-')
        {
            return a;
        }
        else if (a[0] != '-' and b[0] != '-' and a.length() > b.length())
        {
            return a;
        }
        else if (a[0] != '-' and b[0] != '-' and b.length() > a.length())
        {
            return b;
        }
        else if (a[0] == '-' and b[0] == '-' and a.length() > b.length())
        {
            return b;
        }
        else if (a[0] == '-' and b[0] == '-' and b.length() > a.length())
        {
            return a;
        }
        else if (a[0] != '-' and b[0] != '-' and b.length() == a.length())
        {
            for (i = 0; i < a.length(); i++)
            {
                if (a[i] - '0' < b[i] - '0')
                {
                    return b;
                }
                else if (a[i] == b[i])
                {
                    continue;
                }
                else if (a[i] - '0' > b[i] - '0')
                {
                    return a;
                }
            }
        }
        else if (a[0] == '-' and b[0] == '-' and b.length() == a.length())
        {
            for (i = 0; i < a.length(); i++)
            {
                if (a[i] - '0' < b[i] - '0')
                {
                    return a;
                }
                else if (a[i] == b[i])
                {
                    continue;
                }
                else if (a[i] - '0' > b[i] - '0')
                {
                    return b;
                }
            }
        }
    }
    // add and subtract
    static string add (string a , string b)
    {
        int carry =0;
        string answer;
        int asize = a.size();
        int bsize = b.size();
        int i=asize-1;
        int j=bsize-1;

        if(asize==0 && bsize==0)
        {
            answer ="0";

            return answer; 
        }
        else if(a[0] == '-' and b[0]== '-')
        {
            answer = add(a.substr(1) , b.substr(1));
            answer = '-'+ answer;
            return answer;
        }
        else if(a[0] =='-')
        {
            answer = subtract(b , a.substr(1));
            return answer;
        }
        else if(b[0]=='-')
        {
            answer = subtract(a , b.substr(1));
            return answer;
        }
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

    static string subtract(string a , string b )
    {
        string answer = "", ans, temp;
        int carry = 0, i, j, k, y = 0, flag = 0, flag1 = 0;
        int sum = 0;
        if (a == b)
        {
            return "0";
        }
        else if (a[0] == '-' and b[0] == '-')
        {
            flag1 = 1;
            a = a.substr(1);
            b = b.substr(1);
        }
        else if (a[0] == '-' and b[0] != '-')
        {
            a = a.substr(1);
            answer = add(a, b);
            answer = '-' + answer;
            return answer;
        }
        else if (a[0] != '-' and b[0] == '-')
        {
            b = b.substr(1);
            answer = add(a, b);
            return answer;
        }
        ans = maxcompare(a, b);
        if (ans == b)
        {
            temp = a;
            a = b;
            b = temp;
            flag = 1;
        }
        int m = a.length();
        int n = b.length();
        if (m > n)
            k = m;
        else
            k = n;
        int A[k + 1] = {0};
        for (i = m - 1, j = n - 1; i >= 0 || j >= 0; i--, j--)
        {
            sum = 0;
            if (i >= 0)
            {
                sum += a[i] - '0';
            }
            if (j >= 0)
            {
                if (sum < b[j] - '0' + carry)
                {
                    sum += 10;
                    sum -= b[j] - '0' + carry;
                    carry = 1;
                }
                else
                {
                    sum -= b[j] - '0' + carry;
                    carry = 0;
                }
            }
            if (carry != 0 and j < 0)
            {
                if (sum < carry)
                {
                    sum += 10;
                    sum -= carry;
                    carry = 1;
                }
                else
                {
                    sum -= carry;
                    carry = 0;
                }
            }
            A[y++] = sum;
            //carry=sum/10;
        }
        for (i = k - 1; i >= 0; i--)
        {
            answer += (char)(A[i] + 48);
        }
        answer = removezero(answer);
        if (flag1 == 1 and flag == 0)
        {
            answer = '-' + answer;
        }
        else if (flag1 == 0 and flag == 1)
        {
            answer = '-' + answer;
        }
        return answer;
    }

    string operator - (BIG_INT const & bigb)
    {
        return subtract(this->num , bigb.num);
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