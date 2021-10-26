#include <iostream>
#include <string>
using namespace std;

struct Person {// 구조체 선언
	double height;
	float weight;
	int age;
	string name = "fuckyou";


	// 아예 구조체 안에 함수 집어넣을수도 있음
	void print() {
		cout << age << " " << height << " " << weight << " " <<name;	

	}
}; 

void PrintPerson(Person human) {
	cout << human.age << " "<<human.height<<" "<<human.weight <<" "<< human.name << endl;
}

struct Family {
	Person me, mom, dad;
}; // 구조체 안에 구조체도 ㄱㄴ

//struct Employee{}; -> 함수처럼 선언만 미리 해두는게 안되나본데 ? 구조체는


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
	라 고 써 도 되 지 만*/

	Person me{ 2.0,78.3,20,"John kim" };
	PrintPerson(me); // 이거나
	me.print();		 // 이거나 같음 me.print()가 좀더 편하긴하지.구조체 안에 print가 있으니까
	Family k;
	cout <<" " <<k.mom.name << endl; // 이러면,, 내가 구조체 안에서 정의한 name인 fuckyou가 나오겠지.



	Employee emp1;
	cout << sizeof(emp1) << endl; // 2 + 4 + 8 -> 2+ (2) + 4 + 8 // short + 빈 공간 (2바이트) + .. 4바이트가 젤 작은 사이즌가봐
	
}
