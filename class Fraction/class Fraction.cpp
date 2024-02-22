#include<iostream>
using namespace std;

class Fraction
{
	int numerator;
	int denominator;
	double decimal;
public:
	Fraction();

	Fraction(int numerator, int denominator);

	/*explicit*/ Fraction(int value);

	double GetDecimal() const;

	void Print() const;

	void PrintDecimal() const;


	int GetNumerator() const
	{
		return numerator;
	}

	int GetDenominator() const
	{
		return denominator;
	}

	void SetNumerator(int numerator) {
		this->numerator = numerator;
	}

	void SetDenominator(int denominator) {
		if (denominator == 0) denominator = 1;
		this->denominator = denominator;
	}
	void SetDecimal(const double decimal)
	{
		this->decimal = decimal;
	}
	bool GreaterThan(const Fraction& another) const;
	bool LessThan(const Fraction& another) const;
	bool IsEquals(const Fraction& another) const;
	Fraction operator + (/*const Fraction* this,*/ const Fraction& right)
	{ // this-> - это указатель на левый операнд
		// right. - это ссылка на правый операнд
		// result - это третий объект, который получится в результате взаимодействия левого и правого операнда
		cout << "CLASS METHOD\n";
		Fraction result;
		// теперь будет возможность обращаться к полям класса НАПРЯМУЮ без вызова методов-аксессоров
		result.numerator = this->numerator * right.denominator + right.numerator * this->denominator;
		result.denominator = this->denominator * right.denominator;
		return result;
	}
	Fraction operator - (const Fraction& right)
	{
		cout << "CLASS METHOD\n";
		Fraction result;
		result.numerator = this->numerator * right.denominator - right.numerator * this->denominator;
		result.denominator = this->denominator * right.denominator;
		return result;
	}
	Fraction operator * (const Fraction& right)
	{
		cout << "CLASS METHOD\n";
		Fraction result;
		result.numerator = this->numerator * right.numerator;
		result.denominator = this->denominator * right.denominator;
		return result;
	}
	Fraction operator / (const Fraction& right)
	{
		cout << "CLASS METHOD\n";
		Fraction result;
		result.numerator = this->numerator * right.denominator;
		result.denominator = this->denominator * right.numerator;
		return result;
	}
	Fraction operator - ()
	{
		cout << "CLASS METHOD\n";
		return Fraction(-numerator, denominator);
	}
	Fraction operator + (const int right)
	{
		Fraction result;
		result.numerator = right * this->denominator + this->numerator;
		result.denominator = denominator;
		return result;
	}
	Fraction operator + (const double right)
	{
		Fraction result;
		result.numerator = this->numerator;
		result.denominator = this->denominator;
		result.decimal = (double)this->GetDecimal() + right;
		return result;
	}
	friend istream& operator >> (const istream& i, Fraction& frac);
};
istream& operator >> (const istream& i, Fraction& frac)
{
	cout << "Enter numerator - ";
	cin >> frac.numerator;
	cout << "Enter denominator - ";
	cin >> frac.denominator;
	if (frac.denominator == 0) 
		frac.denominator = 1;
	return cin;
}
ostream& operator << (const ostream& o, const Fraction& frac)
{
	frac.Print();
	return cout;
}
Fraction::Fraction() : Fraction(0, 1)
{
	cout << "DEFAULT C-TOR!\n";
}

Fraction::Fraction(int value)
{
	cout << "конструктор преобразования\n";
	numerator = value;
	denominator = 1;
	SetDecimal((double)numerator / denominator);
}

Fraction::Fraction(int numerator, int denominator)
{
	cout << "PARAM CTOR!\n";
	this->numerator = numerator;
	if (denominator == 0) denominator = 1;
	this->denominator = denominator;
	SetDecimal((double)numerator / denominator);
}

double Fraction::GetDecimal() const
{
	return decimal;
}

void Fraction::Print() const
{
	cout << numerator << "/" << denominator << "\n";
}

void Fraction::PrintDecimal() const
{
	cout << GetDecimal() << "\n";
}

bool Fraction::LessThan(const Fraction& another) const
{
	return GetDecimal() < another.GetDecimal();
}

bool Fraction::GreaterThan(const Fraction& another) const
{
	return GetDecimal() > another.GetDecimal();
}

bool Fraction::IsEquals(const Fraction& another) const
{
	return GetDecimal() == another.GetDecimal();
}

// пример перегрузки операции + с помощью глобальной функции
Fraction operator + (const double left, const Fraction& right)
{
	Fraction result;
	result.SetNumerator(right.GetNumerator());
	result.SetDenominator(right.GetDenominator());
	result.SetDecimal((left + right.GetDecimal()));
	return result;
}
Fraction operator + (const Fraction& left, const Fraction& right)
{
	Fraction result;
	result.SetNumerator(left.GetNumerator() * right.GetDenominator() + right.GetNumerator() * left.GetDenominator());
	result.SetDenominator(left.GetDenominator() * right.GetDenominator());
	return result;
}
Fraction operator - (const Fraction& left, const Fraction& right)
{
	Fraction result;
	result.SetNumerator(left.GetNumerator() * right.GetDenominator() - right.GetNumerator() * left.GetDenominator());
	result.SetDenominator(left.GetDenominator() * right.GetDenominator());
	return result;
}
Fraction operator * (const Fraction& left, const Fraction& right)
{
	Fraction result;
	result.SetNumerator(left.GetNumerator() * right.GetNumerator());
	result.SetDenominator(left.GetDenominator() * right.GetDenominator());
	return result;
}
Fraction operator / (const Fraction& left, const Fraction& right)
{
	Fraction result;
	result.SetNumerator(left.GetNumerator() * right.GetDenominator());
	result.SetDenominator(left.GetDenominator() * right.GetNumerator());
	return result;
}
bool operator > (const Fraction& left, const Fraction& right)
{
	return left.GetDecimal() > right.GetDecimal();
}
bool operator < (const Fraction& left, const Fraction& right)
{
	return left.GetDecimal() < right.GetDecimal();
}
bool operator != (const Fraction& left, const Fraction& right)
{
	return left.GetDecimal() != right.GetDecimal();
}

bool operator == (const Fraction& left, const Fraction& right)
{
	return left.GetDecimal() == right.GetDecimal();
}

bool operator >= (const Fraction& left, const Fraction& right)
{
	return left.GetDecimal() >= right.GetDecimal();
}

bool operator <= (const Fraction& left, const Fraction& right)
{
	return left.GetDecimal() <= right.GetDecimal();
}

Fraction operator -(const Fraction& f)
{
	//Fraction result(-f.GetNumerator(), f.GetDenominator());
	/*result.SetNumerator(-f.GetNumerator());
	result.SetDenominator(f.GetDenominator());*/
	return Fraction(-f.GetNumerator(), -f.GetDenominator());
}
int main()
{
	setlocale(0, "");
	double g = 0.3;
	Fraction a(1, 2);
	Fraction b(1, 4);
	Fraction result = a + g;
	Fraction result1 = g + a;
	result1.PrintDecimal();
	//cout << a.GetDecimal();
	//for(int i = 0; i < ; i++)
	/*Fraction c = g + a;
	c.Print();*/
	//Fraction result = a + b;// Fraction result = operator + (a, b); // код для компилятора :) кстати, он рабочий
	//Fraction result1 = a - b;
	//Fraction result2 = a * b; 
	//Fraction result3 = a / b;// код здорового разработчика
	//Fraction result4 = -a;
	//
	//result.Print();
	//result1.Print();
	//result2.Print();
	//result3.Print();
	//result4.Print();
}