#include <iostream>

using namespace std;

class Point {
private:
	int x, y;
public:
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	Point& SetX(int x) {
		this->x = x;
		return *this;
	}
	Point& SetY(int y) {
		this->y = y;
		return *this;
	}
	void Print() {
		cout << "(" << x << ", " << y << ")" << endl;
	}
	bool isSame(const Point& other) const {
		return (this->x == other.x) && (this->y == other.y);
	}
};

class Counter {
private:
	int value;
public:
	Counter(int value = 0) {
		this->value = value;
	}
	Counter& increment(int v) {
		value += v;
		return *this;
	}
};

class Task5 {
private:
	int* date;
public:
	Task5(int d) {
		date = new int(d);
	}

	Task5& assign(const Task5& other) {
		if (this == &other) 
			return *this;
		*date = *(other.date);

	}

	~Task5() {
		delete date;
	}

};

//class SimpleString {
//private:
//	char* data;
//public:
//	SimpleString(const char* str = "") {
//		data = new char[strlen(str) + 1];
//		strcpy(data, str);
//	}
//	
//	~SimpleString() {
//		delete[] data;
//	}
//};

class Vector2D {
private:
	double x, y;
public:
	Vector2D(double x = 0, double y = 0) : x(x), y(y) {}
	
	Vector2D(const Vector2D& other) {
		x = other.x;
		y = other.y;
	}
	void setX(double x) {
		this->x = x;
	}
	void setY(double y) {
		this->y = y;
	}
	void print() const {
		cout << "(" << x << ", " << y << ")" << endl;
	}

};

class Book {
private:
	string title;
public:
	Book(string t) : title(t) {}
	Book(const Book& other) {
		title = other.title;
	}
	void print() const {
		cout << title << endl;
	}
	~Book() {
		delete[] &title;
	}
};

class Array {
private:
	int* data;
	size_t size;
public:
	Array(size_t s, int d) : size(s) {
		this->data = new int(d);
	}
	Array(Array& other) {
		size = other.size;
		data = new int[size];
		for (int i = 0; i < size; i++) {
			data[i] = other.data[i];
		}
	}
	void print() const {
		for (int i = 0; i < size; i++) {
			cout << data[i] << " ";
		}
		cout << endl;
	}
	~Array() {
		delete[] data;
	}
};

//class Task10 {
//private:
//	char* buf;
//public:
//	Task10(const char* str) {
//		buf = new char[strlen(str) + 1];
//		strcpy(buf, str);
//	}
//	Task10(const Task10& other) {
//		buf = new char[strlen(other.buf) + 1];
//		strcpy(buf, other.buf);
//	}
//	~Task10() {
//		delete[] buf;
//	}
//};

class BadString {
private:
	char* data;
public:
	BadString(const char* d) {
		data = new char[strlen(d) + 1];
		strcpy(data, d);
	}
	~BadString() {
		delete[] data;
	}
};

class BadDouble {
private:
	double* data;
public:
	BadDouble(double d) {
		data = new double(d);
	}

	~BadDouble() {
		delete data;
	}
};

class GoodString {
private:
	char* data;
public:
	GoodString(const char* d) {
		data = new char[strlen(d) + 1];
		strcpy(data, d);
	}
	GoodString(const GoodString& other) {
		data = new char[strlen(other.data) + 1];
		strcpy(data, other.data);
	}
	~GoodString() {
		delete[] data;
	}
};

class GoodDouble {
	private:
		double* data;
public:
	GoodDouble(double d) {
		data = new double(d);
	}
	GoodDouble(const GoodDouble& other) {
		data = new double(*(other.data));
	}
	~GoodDouble() {
		delete data;
	}
};

int main()
{
	Point a(10, 20);
	Point b(23, 10);
	a.Print();
	if (a.isSame(b))
		cout << "a = b" << endl;
	else
		cout << "a != b" << endl;
	a.SetX(23).SetY(10);
	a.Print();
	if (a.isSame(b))
		cout << "a = b" << endl;
	else
		cout << "a != b" << endl;

	Vector2D d(3.0, 4.0);
	Vector2D c = d;
	c.print();
	c.setX(10);
	d.print();
	c.print();

	Book e("C++");
	Book f = e;
	f.print();

	Array arr1(5, 10);
	Array arr2 = arr1;
	arr2.print();

	/*BadString bs1("ll");
	BadString bs2 = bs1;*/

	/*BadDouble bd1(4.2);
	BadDouble bd2 = bd1;*/

	GoodString gs1("ww");
	GoodString gs2 = gs1;
	GoodDouble gd1(6.7);
	GoodDouble gd2 = gd1;
}

