#include <iostream>
#include<ctime>
using namespace std;

class String
{
	char* text = nullptr;
	unsigned int length = 0;
	unsigned int capacity = 80;

public:
	String() : String("", 80) {}

	String(const char* text) : String(text, 80) {}

	String(unsigned int capacity) : String("", capacity) {}

	String(const String& original) : String(original.text, original.capacity) {}

	// main c-tor
	String(const char* text, unsigned int capacity)
	{
		SetString(text, capacity);
	}

private:
	void SetString(const char* text, unsigned int capacity = 80)
	{
		length = strlen(text);

		// для пустых строк делаем резерв памяти 80
		if (length == 0)
		{
			this->capacity = 80;
		}
		else // для НЕпустых - по ситуации
		{
			// нормализация переданного параметра capacity
			if (capacity > length * 10)
				capacity = length * 10;

			if (capacity <= length)
				capacity = length + 1;

			this->capacity = capacity;
		}

		cout << "\n\n=================\n\n";
		cout << "capacity param: " << this->capacity << "\n";
		cout << "length param: " << this->length << "\n";
		cout << "\n\n=================\n\n";

		if (this->text != nullptr)
			delete[] this->text;

		this->text = new char[this->capacity];
		strcpy_s(this->text, length + 1, text);
	}

public:
	~String()
	{
		if (text != nullptr)
		{
			delete[] text;
			text = nullptr;
		}
		/*else
			cout <<"fgfgfg";*/
	}

	// возвращать из класса указатель на массив чаров нельзя - это нарушит инкапсуляцию и позволит клиенту СЛОМАТЬ содержимое (состояние) объекта
	// если создавать копию массива чаров, то под неё придётся выделять память, а почистить её клиент скорее всего ЗАБУДЕТ 
	// поэтому здесь выдаётся КОПИЯ состояния в виде объекта текущего класса
	String GetString() const
	{
		//char* copy = new char[length + 1];
		//strcpy_s(copy, length + 1, text);
		//return copy;

		String copy = text;
		return copy;
	}

	int GetLength() const
	{
		return length;
	}

	// метода SetLength не должно быть!

	int GetCapacity() const
	{
		return capacity;
	}

	// в целях повшения производительности, не тратится время на:
	// 1) очистку памяти делитом
	// 2) запись в каждый символ пробелов (не запускается цикл фор)
	// 3) не меняется capacity

	// достаточно в начало строки записать \0, и длину выставить в 0
	// многие методы класса ориентируются именно на длину, и если она равна 0, то клиент будет уверен, что строка пустая
	void Clear()
	{
		text[0] = '\0';
		length = 0;
	}
	void FromKeyboard()
	{
		gets_s(text, capacity);
	}
	bool CompareTo(const char* text)
	{
		/*if (_strcmpi(this->text, text))
			return true;
		else
			return false;*/
		if (strlen(text) == length)
		{
			for (int i = 0; i < length; i++)
			{
				if (text[i] == this->text[i])
				{
					return true;
				}
			}
		}
		else
		{
			return false;
		}
	}
	// если резерв памяти стал значительно больше, чем размер строки, то можно вызвать принудительное перевыделение памяти, суть которого в 
	void ShrinkToFit() // том, чтобы сделать резерв такой же длины, как и length
	{
		if (length + 1 <= capacity)
		{
			return;
		}

		capacity = length + 1;
		char* temp = new char[capacity];
		strcpy_s(temp, capacity, text);
		delete[] text;
		text = temp;
	}
	bool Contains(const char* text)
	{
		int count = 0;
		bool ok = false;
		for (int i = 0; i < strlen(this->text); i++)
		{
			if (count < 0)
				count = 0;
			if (count == length)
				break;
			else if (text[count] == this->text[i] && this->text[i + 1] == text[count + 1] || this->text[length - 1] == text[i])
			{

				ok = true;
				count++;
			}
			else
			{
				ok = false;
				count--;
			}
		}
		if (count == strlen(text))
			return true;
		else
			return false;
	}
	void ConCat(String& text)
	{
		int length_text = text.length + strlen(this->text);
		char* temp = new char[length_text + 1];
		for (int i = 0; i < length; i++)
		{
			temp[i] = this->text[i];
		}
		for (int i = 0; i < text.length + 1; i++)
		{
			temp[i + length] = text.text[i];
		}
		delete[] this->text;
		length = length_text;
		this->text = temp;
	}
	void ConCat(const char* text)
	{
		int length_text = strlen(text) + strlen(this->text) + 1;
		char* temp = new char[length_text];
		for (int i = 0; i < length; i++)
		{
			temp[i] = this->text[i];
		}
		for (int i = 0; i < strlen(text) + 1; i++)
		{
			temp[i + length] = text[i];
		}
		delete[] this->text;
		length = length_text;
		this->text = temp;
	}
	void Remove(int index)
	{
		if (index >= 0 && index < length)
		{
			for (int i = 0; i < length; i++)
			{
				if (i == index)
				{
					this->text[i] = '\0';
				}
			}
		}
	}
	void RemoveTo(int start, int end)
	{
		if (start < end && start >= 0 && end < length)
		{
			bool ok = true;
			char* temp = new char[length - (end - start)];
			for (int i = 0; i < length; i++)
			{
				if (i == start)
				{
					ok = false;
				}
				else
				{
					if (ok)
						temp[i] = text[i];
					else
					{ 
						temp[i - 1] = text[i + (end - start)];
					}
				}
				if (temp[i - 1] == '\0')
					break;
			}
			delete[] text;
			length -= (end - start);
			text = temp;
		}
	}
	void Replace(char symbol, char replace)
	{
		for (int i = 0; i < length; i++)
		{
			if (text[i] == symbol)
			{
				text[i] = replace;
			}
		}
	}
	void ToLower(String& text)
	{
		_strlwr_s(text.text, text.length);
	}
	void ToUpper(String& text)
	{
		_strupr_s(text.text, text.length);
	}
	bool StartWith(String& text)
	{
		int count = 0;
		for (int i = 0; i < length; i++)
		{
			if (count == strlen(text.text))
			{
				return true;
			}
			if (text.text[i] == this->text[i])
			{
				count++;
			}
			else
			{
				return false;
			}
		}
		
	}
	bool EndsWith(String& text)
	{
		int count = 0;
		bool ok = false;
		for (int i = strlen(this->text) - 1; i >= 0; i--)
		{
				if (count == strlen(text.text))
				{
					return true;
				}
				if (text.text[strlen(text.text) - (strlen(this->text) - i)] == this->text[i])
				{
					count++;
				}
				else
				{
					return false;
				}
		}
	}
	void Shuffle(String& text)
	{
		for (int i = 0; i < strlen(text.text); i++)
		{					
			int temp;
			temp = text.text[i];
			text.text[i] = text.text[rand() % strlen(text.text)];
			text.text[rand() % strlen(text.text)] = temp;
			
		}
	}
	int IndexOf(char symbol)
	{
		bool ok = false;
		for (int i = 0; i < length - 1; i++)
		{
			if (symbol == text[i])
			{ 
				ok = true;
				return i;
			}
		}
		if (!ok)
		{
			return -1;
		}
	}
	int LastIndexOf(char symbol)
	{
		bool ok = false;
		for (int i = length - 1; i >= 0; i--)
		{
			if (symbol == text[i])
			{
				ok = true;
				return i;
			}
		}
		if (!ok)
		{
			return -1;
		}
	}
	void RandomFill(String& text)
	{
		for (int i = 0; i < text.length - 1; i++)
		{
			text.text[i] = 33 + rand() % (122 - 33);
		}
		//text.text[length] = '\0';
	}
	void Reverse(String& text)
	{
		char* temp = new char[length];
		for (int i = 1; i < text.length; i++)
		{
			temp[i - 1] = text.text[strlen(text.text) - i];
		}
		temp[length - 1] = '\0';
		delete[] text.text;
		text.text = temp;
	}
	void SortAZ(String& text)
	{
		for (int i = 1; i < text.length - 1; i++)
		{
			for (int j = 0; j < text.length - 1; j++)
			{
				if (text.text[j] > text.text[j + 1] && text.text[j + 1] != '\0')
				{
					int temp = text.text[j];
					text.text[j] = text.text[j + 1];
					text.text[j + 1] = temp;
				}
			}
		}
	}
	void SortZA(String& text)
	{
		for (int i = 1; i < text.length - 1; i++)
		{
			for(int j = 0; j < text.length - 1; j++)
				if (text.text[j] < text.text[j + 1] && text.text[j] != '\0')
				{
					int temp = text.text[j];
					text.text[j] = text.text[j + 1];
					text.text[j + 1] = temp;
				}
		}
	}
	char GetCharAt(int symbol)
	{
		for (int i = 0; i < length; i++)
		{
			if (i == symbol)
			{
				//cout << "ok\n";
				return text[i];
			}
			if (length < symbol || i < 0)
			{
				throw "Incorrect index";
			}
		}
	}
	int FirstIndex(String& str)
	{
		for (int i = 0; i < strlen(this->text); i++)
		{
			if (this->text[i] == str.text[0])
			{
				return i;
			}
		}
	}

	int LastIndex(String& str)
	{
		for (int i = 0; i < strlen(this->text); i++)
		{
			if (this->text[i] == str.text[strlen(str.text) - 1])
			{
				return i;
			}
		}
	}

	void Print() const
	{
		cout << "Text: " << text << "\n";
		cout << "Length: " << length << "\n";
		cout << "Capacity: " << capacity << "\n";
	}
	String operator - (String& right)
	{
		if (Contains(right.text))
		{
			RemoveTo(FirstIndex(right), LastIndex(right));
			return text;
		}
	}
	friend istream& operator >> (const istream& i, String& str);
};
istream& operator >> (const istream& i, String& str)
{
	cout << "Enter capacity - ";
	cin >> str.capacity;
	cout << "Enter text - ";
	cin >> str.text;
	return cin;
}
ostream& operator << (const ostream& o, const String& str)
{
	str.Print();
	return cout;
}
String operator + (String& left, String& right)
{
	left.ConCat(right);
	return left;
}
bool operator < (String& left, String& right)
{
	return left.GetLength() < right.GetLength();
}

bool operator > (String& left, String& right)
{
	return left.GetLength() > right.GetLength();
}
bool operator <= (String& left, String& right)
{
	return left.GetLength() <= right.GetLength();
}

bool operator >= (String& left, String& right)
{
	return left.GetLength() >= right.GetLength();
}

bool operator == (String& left, String& right)
{
	return left.GetLength() == right.GetLength();
}

bool operator != (String& left, String& right)
{
	return left.GetLength() != right.GetLength();
}

int main()
{
	srand(time(0));
	String d("SashaMY", -20);
	String g("cat");
	String r("MY");
	d - r;
	d.Print();
	/*if (d >= g)
	{
		cout << "ok\n";
	}
	else
		cout << "no\n";

	if (d <= g)
	{
		cout << "ok\n";
	}
	else
		cout << "no\n";

	if (d > g)
	{
		cout << "ok\n";
	}
	else
		cout << "no\n";
	if (d < g)
	{
		cout << "ok\n";
	}
	else
		cout << "no\n";
	if (d == g)
	{
		cout << "ok\n";
	}
	else
		cout << "no\n";

	if (d != g)
	{
		cout << "ok\n";
	}
	else
		cout << "no\n";*/

	//d.Remove(3);
	/*d.ConCat(g);
	d.ConCat("MY");*/

	/*d.Shuffle(d);*/
	//cout << d.EndsWith(r) << "\n";
	/*if (d.EndsWith(r) == 1)
	{
		cout << "True\n";
	}
	else
	{
		cout << "False\n";
	}*/
	//cout << d.StartWith(r) << "\n";
	/*if (d.StartWith(r) == 1)
	{
		cout << "True\n";
	}
	else
	{
		cout << "False\n";
	}*/
	//cout << d.IndexOf('t') << "\n";
	//cout << d.LastIndexOf('t') << "\n";
	//d.RandomFill(d);
	//d.Reverse(d);
	//d.Replace('a', 'A');
	//d.SortZA(d);
	//d.SortAZ(d);
	//d.ToUpper(d);
	//d.ToLower(d);
	//d.RemoveTo(5, 8);
	/*if (d.Contains("svjfSSashaaghg") == 1)
	{
		cout << "This string has this word\n";
	}
	else
	{
		cout << "Without this word\n";
	}
	if (d.CompareTo("Sashha") == 1)
	{
		cout << "Simple\n";
	}
	else
	{
		cout << "Different\n";
	}*/
	d.Print();
	//d.Clear();
	//d.Print();
	//cout << d.GetCharAt(2);
	/*String e = d;
	e.Print();*/
}