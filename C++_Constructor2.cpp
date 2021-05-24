#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Book {
	string title;   // ���� ���ڿ�
	int price;     // ����
public:
	Book(Book& b);
	Book(const string title, int price);
	~Book();
	void set(const string title, int price);
	void show()
	{
		cout << title << ' ' << price << "��" << endl;
	}
};
Book::Book(const string title, int price) { // (1) ����
	this->price = price;
	int len = title.length();
	this->title = title;
}
Book::~Book() { // (1) ����
}
void Book::set(const string title, int price) { // (1) ����
	this->price = price;
	int len = title.length();
	this->title = title;
}
Book::Book(Book& b) { // (3) ����. ���� ���� ������
	price = b.price;
	int len = b.title.length();
	title = b.title;
}

int main() {
	Book cpp("��ǰC++", 10000);
	Book java = cpp;
	java.set("��ǰ�ڹ�", 12000);
	cpp.show();
	java.show();
}