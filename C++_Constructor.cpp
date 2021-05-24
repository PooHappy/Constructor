#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Book {
	char* title;   // 제목 문자열
	int price;     // 가격
public:
	Book(Book& b);
	Book(const char* title, int price);
	~Book();
	void set(const char* title, int price);
	void show()
	{
		cout << title << ' ' << price << "원" << endl;
	}
};
Book::Book(const char* title, int price) { // (1) 정답
	this->price = price;
	int len = strlen(title);
	this->title = new char[len + 1];
	strcpy(this->title, title);
}
Book::~Book() { // (1) 정답
	delete[] title;
}
void Book::set(const char* title, int price) { // (1) 정답
	if (this->title)
		delete this->title;
	this->price = price;
	int len = strlen(title);
	this->title = new char[len + 1];
	strcpy(this->title, title);
}
Book::Book(Book& b) { // (3) 정답. 깊은 복사 생성자
	price = b.price;
	int len = strlen(b.title);
	title = new char[len + 1];
	strcpy(this->title, title);
}

int main() {
	Book cpp("명품C++", 10000);
	cpp.show();
	Book java = cpp;
	java.set("명품자바", 12000);
	cpp.show();
	java.show();
}