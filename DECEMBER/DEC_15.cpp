#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include<set>
#include <map>
#include <string>
using namespace std;


typedef struct { // ����ü�� vector<pair<int,pair<int,int>>> �̷��� �ص� �Ǳ� ��,, ���� �� �׷��� �׷���
	int age;
	int score;
	string name;
	char kate;
}S; // for this struct's nickname
vector<S>vec; // this vector's �ڷ����� S
// you can make compare func to this struct

bool comp(S a, S b) {
	if (a.score == b.score) {
		return a.age < b.age;
	}
	else a.score < b.score;
	// pair���� first �� second �� ������ ��Ÿ�¾�����
	//�����غ��� ����
}


bool compare(pair<int, int>a, pair<int, int>b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
	// bool�̴ϱ� true, false�� return�ε� 
	// �̰� �׷��� ���������̰���?
	// �ݴ�� �ϸ� �������� 
}
vector<pair<int, int>>v;
//vector<S>vec;
int main() {
	v.push_back(make_pair(3, 4));
	v.push_back({ 1,1 }); // make_pair�Ƚᵵ �̷��� �ص� ��
	v.push_back({ 1,-1 });
	v.push_back({ 2,2 });
	v.push_back({ 3,3 });

	sort(v.begin(), v.end(), compare);
	for (auto &e : v) {
		cout << e.first << " " << e.second << endl;
	}
	vec.push_back({ 3, 30, "june", '0' }); 
	vec.push_back({ 2,20,"kate" ,'1'});
	vec.push_back({ 4,40,"lilly",'3' });
	sort(v.begin(), v.end(), comp);
	for (auto &e : vec) {
		cout << e.age << " " << e.kate << " " << e.name << " " << e.score << endl;
	}


	
	return 0;
}
// if you wanna make more than two elements
// try using struct!




#include <iostream>
#include <queue>
#include <algorithm>
#include<functional>
using namespace std;
// figuring out how to use priority_queue
int main() {
	priority_queue<int>pq; // when using all the variables int type
	// same as priority_queue<int , vector<int>, less<int>>
	queue<int>queue;
	pq.push(4);
	pq.push(3);
	pq.push(7);
	pq.push(1);
	pq.push(10);
	queue.push(4);
	queue.push(3);
	queue.push(7);
	queue.push(1);
	queue.push(10);
	cout << "�켱���� queue ������ " << pq.size() << endl;
	while (!pq.empty()) {
		cout << pq.top() << endl;
		pq.pop();
	}
	cout << "�׳� queue size" << queue.size() << endl;
	while (!queue.empty()) {
		cout << queue.front() << endl;
		queue.pop();
	}



	return 0;
}

#include <iostream>
#include<queue>
using namespace std;
struct Student {
	int id;
	int math, eng;
	Student(int num, int m, int e) : id(num), math(m), eng(e);
	bool operator<(const Student S) const {
		return this->id > S.id;
	}
}; // what the fuck is this?

int main() {
	priority_queue<Student> pq;
	pq.push(Student(3, 100, 40));

	return 0;
}






#include <iostream>
using namespace std;

class Fraction {
public:
	int m_numerator; // these things must be initialized
	int m_denominator;
public:
	void print() {
		cout << m_numerator << " / " << m_denominator << endl;
	}
};

// �� , ������� �ٽ� ���ڸ�
class Frac {
private:
	int m_numerator; // = 0; �̷��� �ٷ� �ص� �ص� ��
	int m_denominator;// = 1;
public:
	Frac() // this is ������ (constructor)
	{ 
		m_numerator = 0;
		m_denominator = 1;
		cout << "when does this work?" << endl;
	}
	Frac(const int& num_in, const int & den_in)
	{
		m_numerator = num_in;
		m_denominator = den_in;
		cout << "Frac() constructor ������ ����?" << endl;
	}
	Frac(const double &x, const double &y) {
		m_numerator = x + 10;
		m_denominator = y + 100;
	}
	void print() {
		cout << m_numerator << " / " << m_denominator << endl;

	}
};
int main() {


/* if you wanna do like this -> this memebers should be announced as public(which is not what I wanted
	Fraction frac;
	frac.m_numerator = 0;
	 frac.m_denominator = 1;
	 �׸��� �׻� �̷��� ��� ��������� �̷����� ����

	//Fraction frac{ 0,1 };
	// public �� ���¿��� �̷��� uniform initialization �ص� ��
*/
	Frac frac; // �����ڴ� ����� ���ÿ� ������ �Ǵ� ������.
	// �׷��� Frac�� ������ �ȿ� �ִ� whendoesthiswork �� ���� �������
	frac.print();
	Frac what(1, 5); // �����ڰ� �������� �����ѵ� ���δ�.
	what.print();
	Frac hey(3.0, 7.0); // ������ �ǳ� �����ű�
	hey.print();

	/*
	when you make no any constructors
	still, there is a constructor(default constructor)
	which looks like this 
	Frac(){} -> ���� ���� �Ƚᵵ �ִ� ����
	�ٵ� �����ڸ� �ϳ��� ��������� ���̻� default�� ������

	*/ 	return 0;
}


#include <iostream>
using namespace std;
class Scnd {
public:
	Scnd() {
		cout << "second class constructor() " << endl;
	}
};
class First {
	// �ƹ��͵� �Ⱦ��� �ڵ� private�̰�
public: // �ٵ� �����ڸ� �����Ҷ� ������ public �ȿ� �־����
	Scnd sec;

	First()
	{
			cout << "first class constructor() " << endl;
			}
};
int main() {
	First fir;
	/*
	class First {
		public: 
			First() {
				cout << "first class constructor() " << endl;
				Scnd sec;
					}
};
�̷����� first�� ���� ����̰� 
Scnd sec�� �� ��Ȳ�϶� �����ϰ� ����ִ�
(public ���̴� public�ȿ��� First()���� ���̴� �ڴ�)
second�� ���� ��µ�
�����尡 first�� ����� �� �־ ���� �ʱ�ȭ ����� �ϱ� ����


	*/
	return 0;
}



#include <iostream>

using namespace std;
class Something {
private:
	int m_i;
	double m_d;
	char m_c;
	int m_arr[10];
public:
	//Something() {
	//	m_i = 1;
	//	m_d = 3.14;
	//	m_c = 'a';
	//	m_arr[0] = 1;
	//}
	Something()
		:m_i(2),/* m_d = 3.14  �ȵ�*/ m_d(3.14), m_c('a'), m_arr{ 1,2,3,4,5,6,7,8,9,10 }{}
};
struct dele {
private: 
	int x=100 ;
	int y=1000;
public:
	dele()
		: x{ 1 }, y{ 2 }
	{
		cout << "does this work?" << endl;
		x = 7;
		cout << x << " " << y << endl;

	}

};

int main() {
	dele del;
	// ���� dele�� �����ڿ� ���� ���� ��Ȳ�ε� 
	//dele del(); �̷��� ������Ÿ�� �Լ��� ȣ����� �ʾҽ��ϴ� ��� ��
	// private ������ ������ �ʱ�ȭ �ص� �����ڿ��� �ʱ�ȭ�Ѱ� �켱�� �ż�
	// 7 2 �� ���� ���� �����ڿ��� �ʱ�ȭ�� �������� private���� �ʱ�ȭ�Ѱ� ������
	// ������ initializer list ( : ���°�)�� �Ϻ��� �ʱ�ȭ -> �״��� ������ ���ο��� �ʱ�ȭ 
	/*
	��� : 
	constructor initializer list
	constructor ����
	---- ���� construtctor �� �ʱ�ȭ��Ͼ���?
	�׷� private�� �ִ� �ʱ�ȭ�� use
	*/

	return 0;
}


#include <iostream>
using namespace std;

class Simple {
private : 
	int m_id;
public:
	Simple(int id) {
		this->setID(id);//ȭ��ǥ operator�� class , struct�� �������϶� member selection operator
	//	(*this).setID(id);
		// (*this).setID(id) == this -> setID(id);
		//this->m_id;
		cout << this << endl; // self �ּ�
	/*	this->getID(); simple���� �Լ��� 
		cout << this << endl; this�� �� �����ּҷ� ����
		this->Simple::getID();  �̰ų� �׳� getID()�� ����*/ 
	}
	void setID(int id) { m_id = id; }
	int getID() {
		return m_id;
	}
};
int main() {
	Simple s1(1), s2(2);
	s1.setID(2);
	s2.setID(4);
	/*Simpel s1(1),s2(2) ���� �ٷ� �����ڷ� ���µ�(������Ҷ�)
	�׷��� this �� ���ؼ� s1,s2�� �ּҰ� ����
	*/
	cout << &s1 << " " << &s2;
	
	return 0;
}