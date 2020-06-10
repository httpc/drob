#include<iostream>
using std::cin;
using std::cout;
using std::endl;

//	Inheritance
//	Polymorphism

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	//			Constructors:
	/*Point()
	{
		x = y = double();
		cout << "DefultConstructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = double();
		cout << "Constructor:\t" << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:" << this << endl;
	}
	void operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//			Methods:
	double distance(const Point& other)
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance*x_distance + y_distance * y_distance);
		return distance;
	}
	void print()const
	{
		cout << "X = " << x << ", Y = " << y << endl;
	}
};

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance*x_distance + y_distance * y_distance);
	return distance;
}

class Point3D :public Point
{
	double z;
public:
	double get_z() const
	{
		return z;
	}
	void set_z(double z)
	{
		this->z = z;
	}


};

/*
	�������� ��������� ��� �����, �� ������� ����� ��� ������.

	����� - ��� ��� ������!!!
	��������� - ��� ��� ������!!!
*/

/*
------------------------
Special members:
1. Constructor - ��� �����, ������� ������� ������;
2. ~Destructor - ��� �����, ������� ������ ������, �� ��������� ��� ������� �����;
3. Operator=   - ������� �������� ��������, � ����������� ��� �������� ������� �������;

Constructors:
1. � �����������;
2. ��� ����������;
3. �� ���������;
4. �����������;
5. ��������;
------------------------
*/

#define ENCAPSULATION
//#define CONSTRUCTORS
//#define COPY_METHODS

void main()
{
	setlocale(LC_ALL, "");

#ifdef ENCAPSULATION
	int a;	//���������� ���������� 'a', ���� 'int'.
	Point A;//���������� ���������� 'A', ���� 'Point'.
			//�������� ���������� 'A', ��������� 'Point'.

	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	cout << "\n--------------------------------------------------\n";
	//Point* pA = &A;
	//cout << pA->get_x() << "\t" << pA->get_y() << endl;

	Point B;
	B.set_x(4);
	B.set_y(5);
	cout << B.get_x() << "\t" << B.get_y() << endl;
	cout << "\n--------------------------------------------------\n";
	cout << "���������� �� ����� 'A' �� ����� 'B':" << A.distance(B) << endl;
	cout << "\n--------------------------------------------------\n";
	cout << "���������� �� ����� 'B' �� ����� 'A':" << B.distance(A) << endl;
	cout << "���������� ����� ������� 'A' � 'B':  " << distance(A, B) << endl;
	cout << "���������� ����� ������� 'B' � 'A':  " << distance(B, A) << endl;

	//for (int i = 0; i < 5; i++)
	//{
	//	//Point A;
	//	//cout << i << "\t";
	//}
	////cout << i << endl;
#endif // ENCAPSULATION

#ifdef CONSTRUCTORS
	/*
	Default constructor - ��� �����������, ������� ����� ���� ������ ��� ����������.
	https://docs.microsoft.com/en-us/cpp/cpp/constructors-cpp?view=vs-2019#default_constructors
	(implicit)
	*/

	Point A;	//Default constructor
	A.print();

	Point B = 2;//Single argument constructor
	B.print();

	Point C(3);	//Single argument constructor
	C.print();

	Point D(2, 3);//Constructor
	D.print();

	/*
	1. Copy constructor (����������� �����������) - �������� ������;
	2. Single argument constructor (����������� � ����� ����������) - ����� ���� �����������
		��� �������������� �����;
	*/
#endif

#ifdef COPY_METHODS
	//CopyConstructor
//CopyAssignment (Assignment operator = )
//CopyMethods �������� ���������, 
//���� � ������ ����������� ������������ ������.
/*Class(const Class& other)
{
	group - of - statements;
}*/

	Point A = 2;	//Single argument constructor
	A.print();

	Point B = A;	//CopyConstructor
	B.print();

	Point C;	//Default constuctor
	C = A;	//CopyAssignment
#endif // COPY_METHODS

}

/*

.  - �������� ������� ������� (Point operator).
-> - �������� ���������� ������� (Arrow operator).

*/