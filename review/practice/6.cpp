#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class TeamWorkBigInt {
private:
    string val;       // 绝对值（数字字符串，无前导零）
    bool sign;        // true 表示负数，false 表示正数

    // 去除前导零，保留至少一位 '0'
    static string trim(const string& s) {
        size_t pos = s.find_first_not_of('0');
        return (pos == string::npos) ? "0" : s.substr(pos);
    }

    // 两个正数字符串比较大小（a >= b ?）
    static bool absGreaterEqual(const string& a, const string& b) {
        if (a.size() != b.size()) return a.size() > b.size();
        return a >= b;
    }

    // 两个正数字符串相加
    static string absAdd(const string& a, const string& b) {
        string res;
        int carry = 0;
        int i = a.size()-1, j = b.size()-1;
        while (i>=0 || j>=0 || carry) {
            int sum = carry;
            if (i>=0) sum += a[i--] - '0';
            if (j>=0) sum += b[j--] - '0';
            carry = sum / 10;
            res.push_back(sum % 10 + '0');
        }
        reverse(res.begin(), res.end());
        return res;
    }

    // 两个正数字符串相减（要求 a >= b）
    static string absSub(const string& a, const string& b) {
        string res;
        int borrow = 0;
        int i = a.size()-1, j = b.size()-1;
        while (i>=0 || j>=0) {
            int diff = -borrow;
            if (i>=0) diff += a[i--] - '0';
            if (j>=0) diff -= b[j--] - '0';
            if (diff < 0) { diff += 10; borrow = 1; }
            else borrow = 0;
            res.push_back(diff + '0');
        }
        reverse(res.begin(), res.end());
        return trim(res);
    }

    // 两个正数字符串相乘
    static string absMul(const string& a, const string& b) {
        if (a=="0" || b=="0") return "0";
        int n = a.size(), m = b.size();
        vector<int> tmp(n + m, 0);
        for (int i = n-1; i >= 0; --i) {
            for (int j = m-1; j >= 0; --j) {
                int mul = (a[i]-'0') * (b[j]-'0');
                int pos = i + j + 1;
                tmp[pos] += mul;
                tmp[pos-1] += tmp[pos] / 10;
                tmp[pos] %= 10;
            }
        }
        string res;
        for (int x : tmp) {
            if (!(res.empty() && x==0))
                res.push_back(x + '0');
        }
        return res.empty() ? "0" : res;
    }

    // 两个正数字符串相除（返回商，忽略余数）
    static string absDiv(const string& a, const string& b) {
        if (b == "0") return "0"; // 简单处理
        if (!absGreaterEqual(a, b)) return "0";
        string remainder = a.substr(0, b.size());
        string quotient;
        for (size_t i = b.size(); i <= a.size(); ++i) {
            int q = 0;
            while (true) {
                string prod = absMul(b, to_string(q+1));
                if (!absGreaterEqual(remainder, prod)) break;
                ++q;
            }
            quotient.push_back(q + '0');
            if (q > 0) {
                string prod = absMul(b, to_string(q));
                remainder = absSub(remainder, prod);
            }
            if (i < a.size()) {
                if (remainder == "0") remainder = a[i];
                else remainder += a[i];
            }
        }
        return trim(quotient);
    }

    // 内部构造函数（符号+数字）
    TeamWorkBigInt(bool s, const string& v) : sign(s), val(trim(v)) {
        if (val == "0") sign = false;
    }

public:
    // 从整数构造（支持负数）
    TeamWorkBigInt(long long n = 0) {
        if (n < 0) { sign = true; n = -n; }
        else sign = false;
        val = to_string(n);
        if (val == "0") sign = false;
    }

    // 拷贝构造
    TeamWorkBigInt(const TeamWorkBigInt& other) : sign(other.sign), val(other.val) {}

    // 赋值
    TeamWorkBigInt& operator=(const TeamWorkBigInt& other) {
        if (this != &other) { sign = other.sign; val = other.val; }
        return *this;
    }

    // 一元负号
    TeamWorkBigInt operator-() const {
        if (val == "0") return *this;
        return TeamWorkBigInt(!sign, val);
    }

    // 加法
    TeamWorkBigInt operator+(const TeamWorkBigInt& other) const {
        if (sign == other.sign) {
            return TeamWorkBigInt(sign, absAdd(val, other.val));
        } else {
            // 异号：比较绝对值大小
            if (absGreaterEqual(val, other.val))
                return TeamWorkBigInt(sign, absSub(val, other.val));
            else
                return TeamWorkBigInt(other.sign, absSub(other.val, val));
        }
    }

    // 减法：转化为加法
    TeamWorkBigInt operator-(const TeamWorkBigInt& other) const {
        return *this + (-other);
    }

    // 乘法
    TeamWorkBigInt operator*(const TeamWorkBigInt& other) const {
        bool resSign = sign ^ other.sign;
        string prod = absMul(val, other.val);
        return TeamWorkBigInt(resSign, prod);
    }

    // 除法（向零取整）
    TeamWorkBigInt operator/(const TeamWorkBigInt& other) const {
        if (other.val == "0") return TeamWorkBigInt(0);
        if (val == "0") return TeamWorkBigInt(0);
        bool resSign = sign ^ other.sign;
        string quot = absDiv(val, other.val);
        TeamWorkBigInt res(resSign, quot);
        return res;
    }

    // 复合赋值（简单重用）
    TeamWorkBigInt& operator+=(const TeamWorkBigInt& other) { *this = *this + other; return *this; }
    TeamWorkBigInt& operator-=(const TeamWorkBigInt& other) { *this = *this - other; return *this; }
    TeamWorkBigInt& operator*=(const TeamWorkBigInt& other) { *this = *this * other; return *this; }
    TeamWorkBigInt& operator/=(const TeamWorkBigInt& other) { *this = *this / other; return *this; }

    // 输出
    friend ostream& operator<<(ostream& os, const TeamWorkBigInt& x) {
        if (x.sign && x.val != "0") os << '-';
        os << x.val;
        return os;
    }

    // 全局 pow 函数（快速幂）
    friend TeamWorkBigInt pow(TeamWorkBigInt base, int exp) {
        TeamWorkBigInt result(1);
        while (exp > 0) {
            if (exp & 1) result = result * base;
            base = base * base;
            exp >>= 1;
        }
        return result;
    }
};
//StudybarCommentBegin
int main()
{	int i,N;
    TeamWorkBigInt  n=10,b,x1,x2,s,t,pi;
    cin>>N;
	N--;  
	b=pow(n,N+10);
	x1=b*4/5;
	x2=b/-239;
	s=x1+x2;
	
	for(i=3;i<=N*2;i+=2)
	{	x1/=-25;
		x2/=-57121;
		t=(x1+x2)/i;
		s+=t;	
	}
	pi=s*4;
	cout<< (pi/pow(n,10))<<endl;
    return 0;
}
//StudybarCommentEnd