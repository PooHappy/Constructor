#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Book {
	string title;   // 제목 문자열
	int price;     // 가격
public:
	Book(Book& b);
	Book(const string title, int price);
	~Book();
	void set(const string title, int price);
	void show()
	{
		cout << title << ' ' << price << "원" << endl;
	}
};
Book::Book(const string title, int price) { // (1) 정답
	this->price = price;
	int len = title.length();
	this->title = title;
}
Book::~Book() { // (1) 정답
}
void Book::set(const string title, int price) { // (1) 정답
	this->price = price;
	int len = title.length();
	this->title = title;
}
Book::Book(Book& b) { // (3) 정답. 깊은 복사 생성자
	price = b.price;
	int len = b.title.length();
	title = b.title;
}

int main() {
	Book cpp("명품C++", 10000);
	Book java = cpp;
	java.set("명품자바", 12000);
	cpp.show();
	java.show();
}