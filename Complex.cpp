#include <iostream>
#include <cmath>

using namespace std;

class Complex // ����� "����������� �����"
{

private:
	double re, im; // �������������� � ������ �����

public:
	Complex()
	{
	};

	Complex(double r)
	{
		re = r;
		im = 0;
	}

	Complex(double r, double i)
	{
		re = r;
		im = i;
	}

	Complex(const Complex& c) // ����������� �����������
	{
		re = c.re;
		im = c.im;
	}

	// ����������
	~Complex()
	{
	}

	// ��������� �������
	// ������ ������������ �����
	double abs()
	{
		return sqrt(re * re + im * im);
	}

	// �������� ������������
	Complex& operator = (Complex& c)
	{
		re = c.re;
		im = c.im;
		return (*this);
	}

	// �������� +=
	Complex& operator += (Complex& c)
	{
		re += c.re;
		im += c.im;
		return *this;
	}

	// �������� ��������
	Complex operator + (const Complex& c)
	{
		return Complex(re + c.re, im + c.im);
	}

	// �������� ���������
	Complex operator - (const Complex& c)
	{
		return Complex(re - c.re, im - c.im);
	}

	// �������� ���������
	Complex operator * (const Complex& c)
	{
		return Complex(re * c.re - im * c.im, re * c.im + im * c.re);
	}

	// �������� �������
	Complex operator / (const Complex& c)
	{
		Complex temp;
		double r = c.re * c.re + c.im * c.im;
		temp.re = (re * c.re + im * c.im) / r;
		temp.im = (im * c.re - re * c.im) / r;
		return temp;
	}

	// ������ ������������� ���������, ������� �� ��������� ������
	// � ������ (private) ������
	friend ostream& operator<< (ostream&, const Complex&);
	friend istream& operator>> (istream&, Complex&);
};

// ���������� ��������� <<
ostream& operator<< (ostream& out, const Complex& c)
{
	out << "(" << c.re << ", " << c.im << ")";
	return out;
}

// ���������� ��������� >>
istream& operator>> (istream& in, Complex& c)
{
	in >> c.re >> c.im;
	return in;
}

int main()
{
	Complex a(0, 1);
	Complex b(1, 2);
	Complex c(1, 1);
	Complex d(2, 1);
	cout << "a = " << a << "i; b =" << b << "i; c= " << c << "i; d= " << d << "i;" << endl;
	Complex e = ((a + b) / c) - d;
	cout << endl << "((i+(1+2i))/(1+i)) - (2+i) = " << e << endl;
	return 0;
}