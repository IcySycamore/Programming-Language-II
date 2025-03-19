#include "HugeInt.h"
#include <iostream>
#include <stdexcept>
HugeInt::HugeInt(long a) : integer{ 0 }
{
	for (int i = 0; i < digit; ++i)
	{
		integer[i] = a % 10;
		a /= 10;
	}//�ӵ�λ����λ��������,long 155->HugeInt [551000...]
}

HugeInt::HugeInt(const char* p) : integer{ 0 }
{
	size_t len = strlen(p);
	for (int i = 0; i < digit && *p != '\0'; ++i, ++p)
	{
		integer[len - 1 - i] = *p - '0';
	}
}

HugeInt HugeInt::operator+(const HugeInt& n) const
{
	HugeInt temp;
	int carry = 0;
	for (int i = 0; i < digit; ++i)
	{
		int sum = integer[i] + n.integer[i] + carry;
		temp.integer[i] = sum % 10;
		carry = sum / 10;
	}
	return temp;
}

HugeInt HugeInt::operator+(int num) const
{
	HugeInt temp_1(num);
	return (*this) + temp_1;
}

HugeInt HugeInt::operator+(const char* num) const
{
	HugeInt temp_2(num);
	return (*this) + temp_2;
}

HugeInt HugeInt::operator-(const HugeInt& n)const
{
	if ((*this) < n)
	{
		throw std::invalid_argument("С��������");
	}
	HugeInt temp;
	int borrow = 0;
	for (int i = 0; i < digit; ++i)
	{
		int diff = integer[i] - n.integer[i] - borrow;
		if (diff < 0)
		{
			diff += 10;
			borrow = 1;
		}
		else
		{
			borrow = 0;
		}
		temp.integer[i] = diff;
	}
	return temp;
}

HugeInt HugeInt::operator*(const HugeInt& n) const//����a*b
{
	int slen = getLength();//a��С��self length��
	int nlen = n.getLength();//b��С��n length��
	HugeInt temp;
	for (size_t d1 = 0; d1 < nlen; ++d1)//��������a
	{
		short carry = 0;
		for (size_t d2 = 0; d2 < slen; ++d2)//����������b
		{
			short product = integer[d2] * n.integer[d1] + carry + temp.integer[d1 + d2];
			temp.integer[d1 + d2] = product % 10;
			carry = product / 10;
		}
		temp.integer[d1 + slen] += carry;//b������carry�п����н�λֵ��Ϊ����temp.arr��
	}
	temp.carry_unit();
	/*�����㷽���õ���nlen����ͬλ����Ӻ���ܳ���ʮ����:
			  1   2   3   4   1   2   3   4
			X                 7   8   8   8
		___________________________________
			  9   8   7   2   9   8   7   2
		  9   8   7   2   9   8   7   2
	  9   8   7   2   9   8   7   2
  8   6   3   8   8   6   3   8
______________________________________________
  8  15  20  32  25  24  22  32  17   9   2    <--����λ�����ֳ���ʮ
					|
			 <carry_unit()>
					|
  9   7   3   4   7   6   5   3   7   9   2

	*/
	return temp;
#if 0
	int slen = getLength();
	int nlen = n.getLength();
	if (nlen == slen && nlen == 1) // һλ����һλ��
	{
		return HugeInt(integer[digit - 1] * n.integer[digit - 1]);
	}
	else if (nlen == 1) // ��λ����һλ��
	{
		HugeInt temp;
		int carry = 0;
		for (int i = 0; i < slen; ++i)
		{
			int sum = integer[digit - 1 - i] * n.integer[digit - 1] + carry;
			temp.integer[digit - 1 - i] = sum % 10;
			carry = sum / 10;
		}
		temp.integer[digit - 1 - slen] = carry;
		return temp;
	}
	else if (slen == 1) // һλ���˶�λ��������ʹ����һ����
	{
		return n * (*this);
	}
	else // ��λ���˶�λ��
	{
		HugeInt sum(0L);
		for (int i = 0; i < nlen; ++i)
		{
			HugeInt aInt = HugeInt(static_cast<long>(n.integer[digit - 1 - i]));
			HugeInt m = ((*this) * aInt);
			HugeInt temp_multiply = m.shifter(i);
			sum = sum + temp_multiply;
		}
		return sum;
	}
#endif
}

HugeInt HugeInt::operator/(const HugeInt& n) const
{
	int nlen = n.getLength();
	int slen = getLength();

	if (slen < nlen)
		return HugeInt(0L);
	else
	{
		HugeInt result(0L);
		HugeInt temp(0L);
		for (int i = 0; i < nlen; ++i)
		{
			temp.integer[nlen - 1 - i] = integer[slen - 1 - i];//����ͬλ����temp
		}
		/*
index:                   ��ʼm=slen-nlen
		 nlen-1 0   slen-1 |     0
		  |     |   _|_____|_____|_____
		  7 8 8 8  /(1 2 3 4)1 2 3 4
				  /     |
					  ��һ��temp



		temp.integer[]<--  0 1 5 6 4
					___________________
	 n<-- 7 8 8 8  /(1 2 3 4)1 2 3 4    -->(*this)
				  /        0            ---c*n=0<1234<c*(n+1)=7888,��n=0,����¼0��temp.integer[m(slen-nlen)]�У�++m
				  ______________________
					 1 2 3 4 1
					   7 8 8 8          ---c*n=7888<12341<c*(n+1)=15776,��n=1
				  ______________________
					   4 4 5 3 2
					   3 9 4 4 0        ---...
				  ______________________
						   5 0 9 2 3
						   4 7 3 2 8
				  ______________________
						   3 5 9 5 4
						   3 1 5 5 2
				  ��������������������������������������������
							 4 4 0 2

		*/
		for (int m = slen - nlen; m >= 0; --m)//��λ���λ��m slen-nlen
		{
			for (short c = 0; c < 10; ++c)//0-9 �ĳ���
			{
				HugeInt c_x_n = HugeInt(static_cast<long>(c)) * n;
				HugeInt cplus1_x_n = HugeInt(static_cast<long>(c + 1)) * n;
				if (temp > c_x_n && temp < cplus1_x_n)
				{
					result.integer[m] = c;//c=temp/n,remain=temp-c*n
					if (m > 0)
					{
						temp = (temp - HugeInt(c) * n) * 10 + integer[m - 1];
					}
					break;
				}
			}
		}
		return result;
	}
}

int HugeInt::getLength() const
{
	for (int i = digit - 1; i >= 0; --i)
	{
		if (integer[i] != static_cast<short>(0))
		{
			return i + 1;
		}
	}
	return 1;
}

bool HugeInt::operator==(const HugeInt& n)const
{
	for (int i = 0; i < digit; ++i)
		if (integer[i] != n.integer[i])
			return false;
	return true;
}

bool HugeInt::operator!=(const HugeInt& n)const
{
	return !((*this) == n);
}

bool HugeInt::operator>(const HugeInt& n)const
{
	for (int i = digit - 1; i >= 0; --i)
	{
		if (integer[i] < n.integer[i])
			return false;
		if (integer[i] > n.integer[i])
			return true;
	}
	return false;
}

bool HugeInt::operator<(const HugeInt& n)const
{
	return !((*this) > n);
}

bool HugeInt::operator>=(const HugeInt& n)const
{
	return (*this) > n || (*this) == n;
}

bool HugeInt::operator<=(const HugeInt& n)const
{
	return !((*this) >= n);
}

HugeInt HugeInt::shifter(int i) const
{
	int slen = getLength();
	HugeInt temp(0L);
	for (int c = slen - 1; c >= 0; --c)
	{
		temp.integer[c + i] = integer[c];
	}
	return temp;
}

void HugeInt::carry_unit()
{
	HugeInt temp(0L);
	for (size_t c = 0; c < getLength(); ++c)
	{
		if (integer[c] > 9)
		{
			integer[c + 1] += integer[c] / 10;
			integer[c] = integer[c] % 10;
		}
	}
}

bool HugeInt::isEmpty()const
{
	return (*this == HugeInt(0L));
}

ostream& operator<<(ostream& output, const HugeInt& num)
{
	for (int i = num.getLength() - 1; i >= 0; --i)
		output << num.integer[i];
	return output;
}
