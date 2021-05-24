#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Book {
	char* title;   // ���� ���ڿ�
	int price;     // ����
public:
	Book(Book& b);
	Book(const char* title, int price);
	~Book();
	void set(const char* title, int price);
	void show()
	{
		cout << title << ' ' << price << "��" << endl;
	}
};
Book::Book(const char* title, int price) { // (1) ����
	this->price = price;
	int len = strlen(title);
	this->title = new char[len + 1];
	strcpy(this->title, title);
}
Book::~Book() { // (1) ����
	delete[] title;
}
void Book::set(const char* title, int price) { // (1) ����
	if (this->title)
		delete this->title;
	this->price = price;
	int len = strlen(title);
	this->title = new char[len + 1];
	strcpy(this->title, title);
}
Book::Book(Book& b) { // (3) ����. ���� ���� ������
	price = b.price;
	int len = strlen(b.title);
	title = new char[len + 1];
	strcpy(this->title, title);
}

int main() {
	Book cpp("��ǰC++", 10000);
	cpp.show();
	Book java = cpp;
	java.set("��ǰ�ڹ�", 12000);
	cpp.show();
	java.show();
}