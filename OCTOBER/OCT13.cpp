#include <iostream>
#include <string>
using namespace std;

struct Person {// ����ü ����
	double height;
	float weight;
	int age;
	string name = "fuckyou";


	// �ƿ� ����ü �ȿ� �Լ� ����������� ����
	void print() {
		cout << age << " " << height << " " << weight << " " <<name;	

	}
}; 

void PrintPerson(Person human) {
	cout << human.age << " "<<human.height<<" "<<human.weight <<" "<< human.name << endl;
}

struct Family {
	Person me, mom, dad;
}; // ����ü �ȿ� ����ü�� ����

//struct Employee{}; -> �Լ�ó�� ���� �̸� �صδ°� �ȵǳ����� ? ����ü��


struct Employee {
	short id; // 2byte
	int age; // 4
	double wage; // 8

};

int main() {
	//Person me;
	Person Mother;
	Person Father;
	
	/*	me.age = 20;
	me.name = "John kim";
	me.height = 2.0;
	me.weight = 78.3;
	�� �� �� �� �� �� ��*/

	Person me{ 2.0,78.3,20,"John kim" };
	PrintPerson(me); // �̰ų�
	me.print();		 // �̰ų� ���� me.print()�� ���� ���ϱ�����.����ü �ȿ� print�� �����ϱ�
	Family k;
	cout <<" " <<k.mom.name << endl; // �̷���,, ���� ����ü �ȿ��� ������ name�� fuckyou�� ��������.



	Employee emp1;
	cout << sizeof(emp1) << endl; // 2 + 4 + 8 -> 2+ (2) + 4 + 8 // short + �� ���� (2����Ʈ) + .. 4����Ʈ�� �� ���� �����𰡺�
	
}
