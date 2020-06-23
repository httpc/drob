#include<iostream>
using namespace std;

class Fraction
{
	int integer;	//Целая часть
	int numerator;	//Числитель
	int denominator;//Знаменатель
public:
	const int get_integer()const
	{
		return integer;
	}
	const int get_numerator()const
	{
		return numerator;
	}
	const int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}


	//		Constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefConstructor:\t" << this << endl;
	}
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "SingleArConstructor:\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "TwoArConstructor:\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "ThreeArConstructor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//		Operators overload:
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment: " << this << endl;
		return *this;
	}
	Fraction& operator*=(Fraction other)
	{
		this->reduce().to_improper();
		other.reduce().to_improper();
		this->numerator *= other.numerator;
		this->denominator *= other.denominator;
		return this->reduce().to_proper();
	}
	Fraction& operator/=(Fraction other)
	{
		this->reduce().to_improper();
		other.reduce().to_improper();
		this->numerator /= other.numerator;
		this->denominator /= other.denominator;
		return this->reduce().to_proper();
	}
	Fraction& operator+=(Fraction other)
	{
		this->reduce().to_improper();
		other.reduce().to_improper();
		this->numerator = (this->numerator * other.denominator) + (this->denominator * other.numerator);
		this->denominator *= other.denominator;
		return this->reduce().to_proper();
	}
	Fraction& operator-=(Fraction other)
	{
		this->reduce().to_improper();
		other.reduce().to_improper();
		this->numerator = (this->numerator * other.denominator) - (this->denominator * other.numerator);
		this->denominator *= other.denominator;
		return this->reduce().to_proper();
	}
	
	//Fraction operator*(const Fraction& other) const
	//{
	//	Fraction result;
	//	Fraction left = this->to_improper();
	//	Fraction right = other.to_improper();
	//	/*left.to_improper();
	//	right.to_improper();*/
	//	result.numerator = left.numerator * right.numerator;
	//	result.denominator = left.denominator * right.denominator;
	//	result.reduce();
	//	result.to_proper();
	//	return result;
	//}

	explicit operator int()const
	{
		return integer;
	}
	explicit operator double()const
	{
		return integer + (double)numerator / denominator;
	}
	Fraction(double decimal)
	{
		integer = decimal;
		decimal -= integer;
		decimal *= 100000000;
		numerator = decimal;
		denominator = 100000000;
		reduce();
	}

	//		Methods:
	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "+";
			//if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			//if (integer)cout << ")";
		}
		else if (integer == 0)
			cout << 0;
		cout << endl;
	}
	/*void to_proper()
	{
		while (numerator >= denominator)
		{
			integer++;
			numerator -= denominator;
		}
	}*/
	Fraction& to_proper()
	{
		while (numerator >= denominator)
		{
			integer++;
			numerator -= denominator;
		}
		return *this;
	}
	Fraction& to_improper() 
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	/*Fraction to_improper()const
	{
		Fraction result = *this;
		result.numerator += integer * denominator;
		result.integer = 0;
		return result;
	}*/
	/*void to_improper()
	{
		while (integer > 0)
		{
			integer--;
			numerator += denominator;
		}
	}*/
	//void reduce()
	//{
	//	int ost=32,temp,camp;
	//	temp = numerator;
	//	camp = denominator;
	//	while (ost > 0)
	//	{
	//		ost = camp % temp;
	//		if (ost == 0)
	//		{
	//			denominator /= temp;
	//			numerator /= temp;
	//		}
	//		camp = temp;
	//		temp = ost;
	//	}
	//}
	Fraction& reduce()
	{

		int ost = 32, temp, camp;
		temp = numerator;
		camp = denominator;
		if (numerator == 0)
		{
			denominator = 1;
			return *this;
		}
		while (ost > 0)
		{
			ost = camp % temp;
			if (ost == 0)
			{
				denominator /= temp;
				numerator /= temp;
			}
			camp = temp;
			temp = ost;
		}
		return *this;
	}

	Fraction& operator++()	//Prefix
	{
		integer++;
		return *this;
	}	  
	Fraction operator++(int) //Suffix
	{
		Fraction temp = *this;
		integer++;
		return temp; 
	}

	Fraction operator()(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		cout << "Operator()\t" << this << endl;
	}

	//Type-cast operators
	operator int()
	{
		return integer;
	}
	operator Fraction()
	{
		set_integer(int());
		set_numerator((double() - int()));
	}
};

Fraction operator*(Fraction left, Fraction right)
{
	//Fraction result;
	left.to_improper();
	right.to_improper();
	Fraction result(left.get_numerator() * right.get_numerator(), left.get_denominator() * right.get_denominator());
	/*result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());*/
	result.reduce();
	result.to_proper();
	return Fraction(left.get_numerator() * right.get_numerator(), left.get_denominator() * right.get_denominator()).to_proper().reduce();
}
Fraction operator/(Fraction left, Fraction right)
{
	//Fraction result;
	left.to_improper();
	right.to_improper();
	//Fraction result(left.get_numerator() * right.get_denominator(), left.get_denominator() * right.get_numerator());
	/*result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());*/
	//result.reduce();
	//result.to_proper();
	return Fraction(left.get_numerator() * right.get_denominator(), left.get_denominator() * right.get_numerator()).to_proper().reduce();
}
Fraction operator-(Fraction left, Fraction right) 
{
	Fraction result,temp;
	result.set_integer( left.get_integer() + right.get_integer());
	result.set_denominator ( left.get_denominator() * right.get_denominator());
	temp.set_denominator(left.get_numerator() * right.get_denominator());
	temp.set_numerator(left.get_denominator() * right.get_numerator());
	result.set_numerator (temp.get_denominator()-temp.get_numerator());
	return result.to_proper().reduce();
}
Fraction operator+(Fraction left, Fraction right) 
{
	Fraction result,temp;
	result.set_integer( left.get_integer() + right.get_integer());
	result.set_denominator ( left.get_denominator() * right.get_denominator());
	temp.set_denominator(left.get_numerator() * right.get_denominator());
	temp.set_numerator(left.get_denominator() * right.get_numerator());
	result.set_numerator (temp.get_denominator()+temp.get_numerator());
	return result.reduce().to_proper();
}

bool operator==(const Fraction& right, const Fraction& left)
{
	return right.get_integer() + double(right.get_numerator() / right.get_denominator()) == left.get_integer() + double(left.get_numerator() / left.get_denominator()) ? 1 : 0;
}
bool operator!=(const Fraction& right, const Fraction& left)
{
	return right.get_integer() + double(right.get_numerator() / right.get_denominator()) != left.get_integer() + double(left.get_numerator() / left.get_denominator()) ? 1 : 0;
}
bool operator>(const Fraction& right, const Fraction& left)
{
	return right.get_integer() + double(right.get_numerator() / right.get_denominator()) > left.get_integer() + double(left.get_numerator() / left.get_denominator()) ? 1 : 0;
}
bool operator<(const Fraction& right, const Fraction& left)
{
	return right.get_integer() + double(right.get_numerator() / right.get_denominator()) < left.get_integer() + double(left.get_numerator() / left.get_denominator()) ? 1 : 0;
}
bool operator>=(const Fraction& right, const Fraction& left)
{
	return right.get_integer() + double(right.get_numerator() / right.get_denominator()) >= left.get_integer() + double(left.get_numerator() / left.get_denominator()) ? 1 : 0;
}
bool operator<=(const Fraction& right, const Fraction& left)
{
	return right.get_integer() + double(right.get_numerator() / right.get_denominator()) <= left.get_integer() + double(left.get_numerator() / left.get_denominator()) ? 1 : 0;
}

ostream& operator<<(ostream& os, const Fraction& other)
{
	if (other.get_integer()) cout << other.get_integer();
	if (other.get_numerator())
	{
		//if (integer) cout << "(";
		if (other.get_integer()) cout << "+";
		cout << other.get_numerator() << "/" << other.get_denominator();
		//if (integer) cout << ")";
	}
	else if (other.get_integer() == 0)
	{
		cout << 0;
	}
	return os;
}

//#define CONSTRUCTORS_CHECK
//#define ASSIGMENT_CHECK
//#define ARIFMETIC_OPERATOPS_CHECK
//#define INCREMENT_CHECK
//#define METHODS_CHECK
#define PRIMITIVE_TYPE_CONVERSION
void main()
{
#ifdef CONSTRUCTORS_CHECK
	Fraction A;
	A.print();
	Fraction B = 3;
	B.print();
	Fraction C(4, 5);
	C.print();
	Fraction D(5, 4, 7);
	Fraction E = D;//CopyConstructor
	E.print();
	Fraction F;		//DefaultConstructor
	F = E;
	F.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ASSIGMENT_CHECK
	Fraction A(1, 2);
	A.print();
	Fraction B;
	B.print();
	cout << "\n-------------------------------------------\n";
	B = A;
	cout << "\n-------------------------------------------\n";
#endif // ASSIGMENT_CHECK

#ifdef ARIFMETIC_OPERATOPS_CHECK
	Fraction A(0, 3, 4);
	Fraction B(0, 7, 8);
	A.print();
	B.print();
	Fraction C = A + B;
	A.print();
	B.print();
	C.print();
	(A += B).print();
#endif // ARIFMETIC_OPERATOPS_CHECK

#ifdef INCREMENT_CHECK
	for (double i = 2.5; i < 10; i++)cout << i << "\t"; cout << endl;
	Fraction A(1, 2);
	cout << "\n---------------------------------------------------\n";
	Fraction B = A++;
	B.print();
	cout << "\n---------------------------------------------------\n";
	A.print();
	cout << A + B << endl;
#endif // INCREMENT_CHECK
	
#ifdef METHODS_CHECK
	
	double weight = 3.35;
	//Explicit conversion - явное преобразование типов
	cout << (int)weight << endl;	//C-like cast notation
	cout << int(weight)<< endl;	//Functional notation
	
	int a = 2;
	cout << a + weight << endl;	//implicit conversio 'a' to double

	double pi = 3.14;
	int b = pi;	//Conversion from more lo less with loss of data
	cout << pi << '\n' << b << endl;

	double c = 5;
	int d = c;	//Преобразование от большего к меньшему без потери данных
	double e = d;	//Преобразование от меньшего к большему

	unsigned short f = 100000;
	cout << f << endl;

#endif // METHODS_CHECK

#ifdef PRIMITIVE_TYPE_CONVERSION
	double a = 5;
	cout << a << endl;
	Fraction A;	//Single argument constryctor
	cout << A << endl;
	A = (Fraction)8;
	cout << A << endl;

	Fraction B(2, 1, 2);
	double b = B;
	cout << b << endl;
	//int c = B;

	Fraction C = 3.14;
	cout << C << endl;


#endif // PRIMITIVE_TYPE_CONVERSION

}