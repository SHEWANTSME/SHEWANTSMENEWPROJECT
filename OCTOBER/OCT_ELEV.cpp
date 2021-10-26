#include <iostream>
#include <bitset> // when do we use this?
using namespace std;
void ThisisBIT( unsigned char A[]) {
	for (int i = 0; i < 8; i++) {
		 A[i] = 1 << i;
		 cout << bitset<8>(A[i]) << endl;
	}
}
/*
int main() {
	/* 이번 내용의 핵심은 이거임. bool type이 true false를 판별하는 놈이잖아,, 근데
	bool type은 사이즈가 1바이트 = 8비트란 말이지, 만약 8개의 아이템들에 대하여
	a1~a8의 아이템 업글 상태 여부를 판별하고 싶을때, 너가 배열을 쓰던 클래스를 쓰던
	지금 이 bitflag를 사용하는것보다 메모리사용, 활용성이 떨어진다 이말이야.
	그니까 사이즈를 1/8로 줄이는것이 쌉가능하다 이말이지. 그걸 이제 해보려고 한다 이말이야.
	*/
	unsigned char A[8];
	ThisisBIT(A);

	// 아무 아이템이 없을때
	unsigned char item = 0;
	cout << "No Item " << bitset<8>(item) << endl;
	// 처음칸에 아이템 생성될때
	item = item | A[0];// item|=A[0];
	cout << "맨처음칸 아이템 생성 " << bitset<8>(item) << endl;
	//네번째칸에 아이템 생성될때
	item |= A[3]; // OR연산 in bitwise operation -> 현재 item의 상태 OR A[3]의 상태
	cout << "네번째칸 아이템 생성" << bitset<8>(item) << endl;
	//네번째칸 아이템 잃을때 --> AND를 쓰면 되겠지?
	item &= ~A[3];//A[3]의 상태의 반대상황(11110111)과 AND를 하면(00001001)
	/*
	1111 0111
				   (AND연산)
	0000 1001
	------------------
	0000    0001
	*/
	cout << "네번째 칸 아이템 소멸 " << bitset<8>(item) << endl;
	// 맨처음칸 아이템 존재?
	if (item&A[0]) cout << "첫째칸 아이템 존재" << endl;
	else cout << "첫째칸 아이템 존재하지않음" << endl;

	//셋번째 넷째칸 아이템 동시존재?
	item |= (A[2] | A[3]); // 생각해보셈 왜 이렇게 될까?
	cout << "세번째 네번째 아이템 존재"<<bitset<8>(item) << endl;

	if ((item&A[2]) && !(item&A[1])) {
		item ^= (A[2]|A[1]);
		//item ^= A[1];, item ^= A[2]; 따로 써도 됨
	}
	cout  << bitset<8>(item) << endl; // 아이템 존재 여부 스위치 존내 헷갈린다

	cout << " " << endl;

	const unsigned int red_mask = 0xFF0000;//0000 0000 1111 1111 0000 0000 0000 0000
	cout << bitset<32>(red_mask) << endl;// FF있는애들이 1111 1111이 있네!

	unsigned int pixel_color = 0xDAA520; // DA-red A5-green 20-blue
	unsigned char red, green, blue;
	cout << pixel_color << endl; // 10진수로 어떤값인지..
	cout << std::bitset<32>(pixel_color) << endl;//16비트로는 다 안나오넹 32로 해야할듯


	return 0;
}

// 오늘은 여기까지,, 머리아프당 2021.10.11-> 10.12 Retried



