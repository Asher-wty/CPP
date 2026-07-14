//StudybarCommentBegin
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

class HugeInt
{
    friend ostream &operator<<( ostream &, const HugeInt & );
public:
    static const int digits = 30;
    HugeInt( long = 0 );
    HugeInt( const char * );
    HugeInt operator+( const HugeInt & ) const;
    HugeInt operator+( int ) const;
    HugeInt operator+( const char * ) const;
    int getLength() const;
private:
    short integer[ digits ];
};
//StudybarCommentEnd

HugeInt::HugeInt( long val )
{
    for ( int i = 0; i < digits; ++i )
        integer[i] = 0;
    int idx = 0;
    while ( val > 0 && idx < digits )
    {
        integer[idx] = val % 10;
        val /= 10;
        ++idx;
    }
}

HugeInt::HugeInt( const char * str )
{
    for ( int i = 0; i < digits; ++i )
        integer[i] = 0;
    int len = strlen( str );
    int idx = 0;
    for ( int i = len - 1; i >= 0 && idx < digits; --i )
    {
        if ( isdigit( str[i] ) )
            integer[idx++] = str[i] - '0';
    }
}

HugeInt HugeInt::operator+( const HugeInt & other ) const
{
    HugeInt result;
    int carry = 0;
    for ( int i = 0; i < digits; ++i )
    {
        int sum = integer[i] + other.integer[i] + carry;
        result.integer[i] = sum % 10;
        carry = sum / 10;
    }
    return result;
}

HugeInt HugeInt::operator+( int val ) const
{
    return *this + HugeInt( val );
}

HugeInt HugeInt::operator+( const char * str ) const
{
    return *this + HugeInt( str );
}

int HugeInt::getLength() const
{
    for ( int i = digits - 1; i >= 0; --i )
    {
        if ( integer[i] != 0 )
            return i + 1;
    }
    return 1;
}

ostream & operator<<( ostream & os, const HugeInt & h )
{
    int len = h.getLength();
    bool allZero = true;
    for ( int i = 0; i < len; ++i )
    {
        if ( h.integer[i] != 0 )
        {
            allZero = false;
            break;
        }
    }
    if ( allZero )
    {
        os << '0';
        return os;
    }
    for ( int i = len - 1; i >= 0; --i )
        os << h.integer[i];
    return os;
}

//StudybarCommentBegin
int main()
{
    HugeInt n1( 7654321 );
    HugeInt n2( 7891234 );
    HugeInt n3( "99999999999999999999999999999" );
    HugeInt n4( "1" );
    HugeInt result;
    
    cout << "n1 is " << n1 << "\nn2 is " << n2
    << "\nn3 is " << n3 << "\nn4 is " << n4
    << "\nresult is " << result << "\n\n";
    
    
    result = n1 + n2;
    cout << n1 << " + " << n2 << " = " << result << "\n\n";
    
    cout << n3 << " + " << n4 << "\n= " << ( n3 + n4 ) << "\n\n";
    
    result = n1 + 9;
    cout << n1 << " + " << 9 << " = " << result << endl;
    
    result = n2 + "10000";
    cout << n2 << " + " << "10000" << " = " << result << endl;
    return 0;
}
//StudybarCommentEnd