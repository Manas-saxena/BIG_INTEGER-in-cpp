#include<bits/stdc++.h>

using namespace std;
#define pow_big BIG_INT::power_big
#define fact_big BIG_INT::factorial_big
#define max BIG_INT::maxcompare
#define min BIG_INT::mincompare
#define abs BIG_INT::abs_big
#define rev BIG_INT::rev_big
#define n_count BIG_INT::count_num
#define check_palin BIG_INT::isPalin
#define n_erase BIG_INT:: erase_num 
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
    static bool input_valid(string number)
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
    // to remove prec. zeros
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
        if (!input_valid(a) || !input_valid(b))
        {
            cerr << "Invalid Input.. Please Use Valid BIGINTEGER" << endl;
            exit(0);
        }
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
    static string mincompare(string s1, string s2)
    {
        if(!input_valid(s1) || !input_valid(s2))
        {
          cerr << "Invalid Input.. Please Use Valid BIGINTEGER" << endl;
                exit(0);
          
        }
        string ans;
        ans = maxcompare(s1, s2);
        if (ans == s1)
        {
            return s2;
        }
        return s1;
    }

    static string maxcompare(int a , int b)
    {
        ostringstream convert;
        convert << a;
        string s1 = convert.str();
        convert<<b;
        string s2 = convert.str();

        return maxcompare(s1 ,s2);
    }
    static string maxcompare(const BIG_INT& a, const BIG_INT& b)
    {
        return maxcompare(a.get_num(), b.get_num());
    }
    static string mincompare(int a, int b)
    {
        ostringstream convert;
        convert << a;
        string s1 = convert.str();
        convert << b;
        string s2 = convert.str();

        return mincompare(s1, s2);
    }
    static string mincompare(const BIG_INT &a, const BIG_INT &b)
    {
        return mincompare(a.get_num(), b.get_num());
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
   static string multiply (string a , string b) 
    {
        int flag = 0;
        int m = a.length();
        int n = b.length();
        int A[m + n] = {0};
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                int mul = (a[i] - '0') * (b[j] - '0');
                int sum = A[i + j + 1] + mul;
                A[i + j] += sum / 10;
                A[i + j + 1] = sum % 10;
            }
        }

        string answer = "";
        for (int i = 0; i < m + n; i++)
        {
            if (A[i] == 0 && flag == 0)
            {
            }
            else if (A[i] != 0)
                flag = 1;

            if (flag == 1)
               answer += (char)(A[i] + 48);
        }
        if (answer.length() == 0)
           answer = "0";

        return answer;
    }
    static string division(string s1 , long long div)
    {
        string result;
        int index = 0;
        long long int temp = s1[index] - '0';
        while (temp < div)
        {
            temp = temp * 10 + (s1[++index] - '0');

            if (index >= s1.length())
                break;
        }

        while (s1.length() > index)
        {
            result += (temp / div) + '0';
            temp = (temp % div) * 10 + s1[++index] - '0';
        }

        if (result.length() == 0)
            return "0";

        return result;
    }
    static string division(string s1 , int div )
    {
        string result;
        int index = 0;
        int temp = s1[index] - '0';
        while (temp < div)
        {
            temp = temp * 10 + (s1[++index] - '0');

            if (index >= s1.length())
                break;
        }

        while (s1.length() > index)
        {
            result += (temp / div) + '0';
            temp = (temp % div) * 10 + s1[++index] - '0';
        }

        if (result.length() == 0)
            return "0";

        return result;
    }
    static string power(string a , string b)
    {
        if(b == "0")
        {
            return "1";
        }
        else if (a == "0")
        {
            if (b[0] == '-')
                return to_string((long long int)std::pow(0, -5));
            return "0";
        }
        else if (a[0] == '-' && b[0] == '-')
        {
            if (a == "-1" && b == "-1")
            {
                return "-1";
            }
            else if (a == "-1")
            {
                if ((((int)b[b.length() - 1]) - 48) & 1)
                {
                    return "-1";
                }
                else
                {
                    return "1";
                }
            }
            else
            {
                return "0";
            }
        }
        else if (a[0] == '-')
        {
            if ((((int)b[b.length() - 1]) - 48) & 1)
                return '-' + power(a.erase(0, 1), b);
            return power(a.erase(0, 1), b);
        }
        else if (b[0] == '-')
        {
            if (a == "1")
            {
                return a;
            }
            else
            {
                return "0";
            }
        }
        else
        {
            string init_a = a;
            while (b != "1")
            {
                a = multiply(a, init_a);
                b = subtract(b, "1");
            }
            return a;
        }
    }
    BIG_INT operator - (BIG_INT const & bigb) const
    {
        return subtract(this->num , bigb.num);
    }
    void operator -=(BIG_INT const & bigb)
    {
        this->num = subtract (this->num , bigb.num);
    }
    BIG_INT operator+(BIG_INT const &bigb) const
    {
        return add(this->num  , bigb.num);
    }
    void operator +=(BIG_INT const & bigb)
    {
        this->num =add(this->num , bigb.num);
    }
    BIG_INT operator*(BIG_INT const &bigb) const
    {
        return multiply(this->num , bigb.num);
    }
    void operator*=(BIG_INT const &bigb){
        this->num = multiply(this->num , bigb.num);
    }

    BIG_INT operator /(BIG_INT const & bigb )
    {
        BIG_INT ans ;
        string s1 = num ;
        string s2 = bigb.num;

        stringstream convertnum(s2);

        long long int div = 0;
        convertnum>>div;

        ans.num = division(s1,div);

        return ans;
    }

    void operator /=(BIG_INT const & bigb )
    {
        string s2 = bigb.num;
        stringstream convertnum(s2);
        long long int div =0;
        convertnum>>div;
        this->num = division(this->num , div );

    }

    BIG_INT operator++ ()
    {
        string temp = "1";
        this->num = add(this->num ,temp);
        return *this;
    }

    BIG_INT operator ++ (int)
    {
        BIG_INT prev ;
        prev = *this;
        string temp = "1";
        this->num = add(this->num , temp);
        return prev;
    }
    BIG_INT operator --()
    {
        string temp ="1";
        this->num = subtract(this->num , temp);
        return *this;
    }

    BIG_INT operator -- (int)
    {
        BIG_INT prev = *this;
        string temp = "1";
        this->num = subtract(this->num , temp);
        return prev;
    }

    bool operator ==( BIG_INT const & bigb)
    {
        if(this->num == bigb.num)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
    bool operator != (BIG_INT const &bigb)
    {
        return this->num != bigb.num;
    }

    static BIG_INT power_big(BIG_INT const &a, BIG_INT const  &b)
    {
        BIG_INT temp ;
        temp.num = power(a.num , b.num);
        return temp;
    }

    static string factorial(int n )
    {
        int i = 2;
        int j = 0;
        int len = 1;
        int A[100000] = {0};
        A[0] = 1;
        int num = 0;
        while (i <= n)
        {
            j = 0;
            num = 0;
            while (j < len)
            {
                A[j] = A[j] * i;
                A[j] = A[j] + num;
                num = A[j] / 10;
                A[j] = A[j] % 10;
                j++;
            }
            while (num != 0)
            {
                A[len] = num % 10;
                num = num / 10;
                len++;
            }
            i++;
        }
        len--;
        string y = "";
        while (len >= 0)
        {
            y += (char)(A[len] + '0');
            len = len - 1;
        }
        return y;
    }

    static BIG_INT factorial_big(int n)
    {
        BIG_INT ans ;
        ans = factorial(n);
        return ans;
    }

    static BIG_INT factorial_big( const BIG_INT&  n)
    {
        BIG_INT ans ;
        string s = n.num;
        stringstream convertnum(s);
        int p =0;
        convertnum>>p;
        ans= factorial(p);
        return  ans ;
    }

    static BIG_INT factorial_big(string s)
    {
        if (!input_valid(s))
        {
            cerr << "Invalid Input.. Please Use Valid BIGINTEGER" << endl;
            exit(0);
        }

        BIG_INT ans ;
        stringstream convertnum(s);
        int p = 0;
        convertnum >> p;
        ans = factorial(p);
        return ans;
    }
    static BIG_INT abs_big( BIG_INT &num)
    {
        string ansstring =num.get_num();
        BIG_INT ans;
        if(ansstring.size()!=0 and ansstring[0] =='-')
        {
            ans = ansstring.substr(1);
            return ans;
        }
        else
        {
            ans = ansstring;
            return ans ;
        }
        
    }
    static BIG_INT rev_big(BIG_INT num)
    {
        string s2 = "", s1 = num.get_num();
        for (int i = s1.length() - 1; i >= 0; i--)
            s2 += s1[i];
        BIG_INT ans(s2);
        return ans;
    }

    static int count_num(BIG_INT biga, int n)
    {
        char c = (char)(n + '0');
        int counti = 0;
        for (int i = 0; i < biga.num.length(); i++)
        {
            if (biga.num[i] == c)
                counti++;
        }
        return counti;
    }

    static string removeZero(string str)
    {
        int i = 0, flag = 0;
        if (str[0] == '-')
        {
            flag = 1;
            i++;
        }
        while (str[i] == '0')
            i++;
        if (flag)
            str.erase(1, i);
        else
            str.erase(0, i);
        return str;
    }

    static BIG_INT erase_num(BIG_INT biga, int n)
    {
        char c = (char)(n + '0');
        string s2 = "";
        int counti = 0;
        for (int i = 0; i < biga.num.length(); i++)
        {
            if (biga.num[i] != c)
                s2 += biga.num[i];
        }
        s2 = removeZero(s2);
        if (s2 == "" or s2 == "-")
        {
            BIG_INT bigb(0);
            return bigb;
        }
        else
        {
            BIG_INT bigb(s2);
            return bigb;
        }
    }
    static bool isPalin(BIG_INT const & biga)
    {
        string s1 = biga.num;
        int i = 0, j = s1.length() - 1;
        if (s1[0] == '-')
            i++;
        while (i < j)
        {
            if (s1[i] != s1[j])
                return false;
            i++;
            j--;
        }
        return true;
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