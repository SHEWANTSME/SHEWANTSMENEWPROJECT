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
	/* �̹� ������ �ٽ��� �̰���. bool type�� true false�� �Ǻ��ϴ� �����ݾ�,, �ٵ�
	bool type�� ����� 1����Ʈ = 8��Ʈ�� ������, ���� 8���� �����۵鿡 ���Ͽ�
	a1~a8�� ������ ���� ���� ���θ� �Ǻ��ϰ� ������, �ʰ� �迭�� ���� Ŭ������ ����
	���� �� bitflag�� ����ϴ°ͺ��� �޸𸮻��, Ȱ�뼺�� �������� �̸��̾�.
	�״ϱ� ����� 1/8�� ���̴°��� �԰����ϴ� �̸�����. �װ� ���� �غ����� �Ѵ� �̸��̾�.
	*/
	unsigned char A[8];
	ThisisBIT(A);

	// �ƹ� �������� ������
	unsigned char item = 0;
	cout << "No Item " << bitset<8>(item) << endl;
	// ó��ĭ�� ������ �����ɶ�
	item = item | A[0];// item|=A[0];
	cout << "��ó��ĭ ������ ���� " << bitset<8>(item) << endl;
	//�׹�°ĭ�� ������ �����ɶ�
	item |= A[3]; // OR���� in bitwise operation -> ���� item�� ���� OR A[3]�� ����
	cout << "�׹�°ĭ ������ ����" << bitset<8>(item) << endl;
	//�׹�°ĭ ������ ������ --> AND�� ���� �ǰ���?
	item &= ~A[3];//A[3]�� ������ �ݴ��Ȳ(11110111)�� AND�� �ϸ�(00001001)
	/*
	1111 0111
				   (AND����)
	0000 1001
	------------------
	0000    0001
	*/
	cout << "�׹�° ĭ ������ �Ҹ� " << bitset<8>(item) << endl;
	// ��ó��ĭ ������ ����?
	if (item&A[0]) cout << "ù°ĭ ������ ����" << endl;
	else cout << "ù°ĭ ������ ������������" << endl;

	//�¹�° ��°ĭ ������ ��������?
	item |= (A[2] | A[3]); // �����غ��� �� �̷��� �ɱ�?
	cout << "����° �׹�° ������ ����"<<bitset<8>(item) << endl;

	if ((item&A[2]) && !(item&A[1])) {
		item ^= (A[2]|A[1]);
		//item ^= A[1];, item ^= A[2]; ���� �ᵵ ��
	}
	cout  << bitset<8>(item) << endl; // ������ ���� ���� ����ġ ���� �򰥸���

	cout << " " << endl;

	const unsigned int red_mask = 0xFF0000;//0000 0000 1111 1111 0000 0000 0000 0000
	cout << bitset<32>(red_mask) << endl;// FF�ִ¾ֵ��� 1111 1111�� �ֳ�!

	unsigned int pixel_color = 0xDAA520; // DA-red A5-green 20-blue
	unsigned char red, green, blue;
	cout << pixel_color << endl; // 10������ �������..
	cout << std::bitset<32>(pixel_color) << endl;//16��Ʈ�δ� �� �ȳ����� 32�� �ؾ��ҵ�


	return 0;
}

// ������ �������,, �Ӹ������� 2021.10.11-> 10.12 Retried



