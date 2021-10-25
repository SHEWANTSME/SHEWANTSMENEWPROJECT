#include <iostream>
using namespace std;
/*
void swap(int *num_1, int *num_2) { // int *num = &element[]
	int temp = *num_1;
	*num_1 = *num_2;
	*num_2 = temp;
}

int main() {
	int n;
	cin >> n;
	int element[50];
	for (int i = 0; i < n; i++) {
		cin >> element[i];
	}
	int natural_num;
	cin >> natural_num;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 1) {
			swap(&element[i - 1], &element[i]);
			cnt++;
		}
		if (cnt == natural_num) break;

	}

	for (int i = 0; i < n; i++) {
		cout << element[i] << " ";
	}


}*/
int main() {
	double num = 3.1415;
	double* numaddress = &num;
	cout << num << endl; // 3.1415
	cout << (uintptr_t)&num << endl; // 17824264
	cout << (uintptr_t)numaddress << endl; //17824264 
	cout << (uintptr_t)&numaddress << endl;//17824252
	cout << *numaddress << endl;//3.1415
	cout <<*&num << endl;//3.1415
	
//	cout << *num << endl;

	int arr[5] = { 1,2,3,3,4 };
	char ar[] = "fuck you";
	const int list[5] = { 33,44,55,66,77 };
	const char *name = "jack jack"; // const ¾øÀ¸¸é ¾ÈµÊ const°¡ ÀÖ¾î¼­ name¸¸À¸·Î ¤¡¤¤
	cout << arr << endl; // 010FF9E0
	cout << ar << endl; // fuck you
	cout << *ar << endl;// f
	cout << list << endl;// 010FF9B0
	cout << *list << endl; // 33
	cout << *name << endl; //j
	cout << name << 3<< endl; // jack jack3    ¶ç¾î¼­ Ãâ·Â¾ÈµÊ
	int(*arrpointer)[5] = &arr;
	cout << arrpointer << endl; // 0135F9C4
	cout << *arrpointer << endl; //0135F9C4
	//sizeof(**arrpointer)¶û sizeof(*arrpointer) ´Ù¸§,,  20,4³ª¿È

	cout << arr[0] << endl;//1
	cout << (*arrpointer)[0] << endl;//1
	cout << arrpointer[0] << endl; // 013F9C4
	cout << arr[1] << endl;//2
	cout << (*arrpointer)[1] << endl;//2
	cout << **arrpointer << endl; //1
	cout << (*&*arrpointer) << endl;//0135F9C4

	

}





























