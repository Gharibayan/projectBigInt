#include <bigInt/BigInt.h>
#include <iostream>
#include <vector>
using namespace std;

namespace ACA
{
inline void reversing(std::string& s) {
	unsigned int n = s.size();
	for (int i = 0; i < n / 2; i++) {
		std::swap(s[i], s[n - i - 1]);
	}
}
inline int charToInt(char ch) {
	return ch - 48;
}
inline int intToChar(int a) {
	return a + 48;
}



	BigInt::BigInt(const string &s)
	{
		digits = s;
		reversing(digits);
	}

	BigInt::BigInt(unsigned long long nr)
	{
		string str = to_string(nr);
		reversing(str);
		digits = str;
	
	}

	BigInt::BigInt(const BigInt& other)
	{
		digits = other.digits;
	}

	BigInt& BigInt::operator=(const BigInt& other)
	{
		
		if (this == &other)
		{
			return *this;
		}
		digits.clear();
		digits = other.digits;

		return *this;
	}


	bool operator==(const BigInt& lhs, const BigInt& rhs)
	{
		return lhs.digits == rhs.digits;
	}

	bool operator!=(const BigInt& lhs, const BigInt& rhs)
	{
		return !(lhs == rhs);
	}

	bool operator<(const BigInt& lhs, const BigInt& rhs)
	{
		if (lhs.digits.size() < rhs.digits.size()) {
			return true;
		}
		else if(lhs.digits.size() > rhs.digits.size()) {
			return false;
		}
		else {
			string l = lhs.digits;
			reversing(l);
			string r = rhs.digits;
			reversing(r);
			return l < r;


		}
		
	}

	bool operator>(const BigInt& lhs, const BigInt& rhs)
	{
		return rhs < lhs;
	}

	bool operator>=(const BigInt& lhs, const BigInt& rhs)
	{
		return !(lhs < rhs);
	}

	bool operator<=(const BigInt& lhs, const BigInt& rhs)
	{
		return !(lhs > rhs);
	}

	BigInt& BigInt::operator++()
	{

		*this=*this+BigInt("1");
		return *this;
	}

	BigInt BigInt::operator++(int )
	{
		BigInt old = *this;
		operator++(); 
		return old;
	}

	BigInt& BigInt::operator--()
	{
		*this=*this-1;
		return *this;
	}

	BigInt BigInt::operator--(int )
	{
		BigInt old = *this;
		operator--(); 
		return old;
	}

	BigInt& BigInt::operator+=(const BigInt& rhs)
	{
		string str = rhs.digits;
		if (this->digits.size() < str.size()) {
			while (this->digits.size() != str.size()) {
				digits.push_back('0');
			}
		}
		else if (this->digits.size() > str.size()) {
			while (this->digits.size() != str.size()) {
			str.push_back('0');
			}
		}
		int t = 0;
		for (int i = 0; i < digits.size(); ++i) {
			int a= charToInt(digits[i]);
			int b= charToInt(str[i]);
			digits[i] = intToChar((a + b+t) % 10);
			t = (a + b+t) / 10;
		}
		if (t) {
			digits.push_back(intToChar(t));
		}
		return *this;
	}

	BigInt operator+(BigInt lhs, const BigInt& rhs)
	{
		lhs += rhs;
		return lhs;
	}

	BigInt& BigInt::operator-=(const BigInt& rhs)
	{
		if (*this < rhs) {
			throw("It  will be negative, I dont keep negative numbers");
		}
		else {
			string str = rhs.digits;

			if (this->digits.size() > str.size()) {
				while (this->digits.size() != str.size()) {
					str.push_back('0');
				}
			}
			int t = 0;
			int a, b;
			for (int i = 0; i < digits.size(); ++i) {
				 a = charToInt(digits[i]);
				 b = charToInt(str[i]);
				if (t < 0 && a>0) {
					a--;
					t = 0;
				}
				if ((a - b+t) < 0) {
					if (t < 0) {
						digits[i] = intToChar(a - b + t + 10);
						
					}
					else {
						digits[i] = intToChar(a - b + 10);
						t=-1;
					}
				}
				else {
					int a1 = a - b + t;
					digits[i] = intToChar(a1);
				}
			}
			
			while((digits.back() == '0')&&(digits.size()>1)) {
				digits.pop_back();
			}
			return *this;
		}
	}
	

	BigInt operator-(BigInt lhs, const BigInt& rhs)
	{
		lhs -= rhs;
		return lhs;
	}

	BigInt& BigInt::operator*=(const BigInt& rhs)
	{
		if(rhs==0||(*this)==0){
			*this=0;
			return *this;
		}
		BigInt temp(rhs);
		BigInt temp1(*this);
		while(temp>2){
			*this+=temp1;
			*this+=temp1;
			temp-=2;
		}
		if(temp==2){
			*this+=temp1;
		}
		return *this;
	}

	BigInt operator*(BigInt lhs, const BigInt& rhs)
	{
		lhs *= rhs;
		return lhs;
	}

	BigInt& BigInt::operator/=(const BigInt& rhs)
	{
		BigInt temp(rhs);
		BigInt temp1(*this);
        *this=0;
		while(temp1>=temp){
          (*this)++;
		  temp1-=temp;

		}
		return *this;
	}

	BigInt operator/(BigInt lhs, const BigInt& rhs)
	{
		lhs /= rhs;
		return lhs;
	}

	BigInt& BigInt::operator%=(const BigInt& rhs)
	{
		BigInt temp(rhs);
		while(*this>=temp){
			*this-=temp;
		}

		return *this;
	}

	BigInt operator%(BigInt lhs, const BigInt& rhs)
	{
		lhs %= rhs;
		return lhs;
	}

	BigInt& BigInt::operator^=(const BigInt& rhs)
	{
		if (rhs == 0) {
			digits = "1";
			return *this;
		}

		BigInt temp(rhs);
		BigInt temp1(*this);
		while (temp > 2) {
			*this *= temp1;
			*this *= temp1;
			temp -= 2;
		}
		if (temp == 2) {
			*this *= temp1;
		}
		return *this;
	}

	BigInt operator^(BigInt lhs, const BigInt& rhs)
	{
		lhs ^= rhs;
		return lhs;
	}

	istream& operator>>(istream& in, BigInt& a)
	{
		std::cout<<"input Biginteger"<<endl;
		in>>a.digits;
		reversing(a.digits);
		return in;
	}

	ostream& operator<<(ostream& out, const BigInt& a)
	{
		string str=a.digits;
		reversing(str);

		out << str;
		return out;
	}

} 
