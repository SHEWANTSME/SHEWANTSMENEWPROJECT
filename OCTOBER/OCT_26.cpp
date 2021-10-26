#include<iostream>
#include<vector>
using namespace std;

int main() {
	int cnt=1, rising=0;
	int num;
	cin >> num;
	vector<int>vec(num);
	for (int i = 0; i < num; i++) {
		cin >> vec[i];
	}

	for (int i = 0; i < num-1; i++) {
		if (vec[i] >= rising ) { 
			if (vec[i + 1] < rising) rising = 0;
			rising = vec[i];
			cnt++;

		}
		//if (vec[num] >= rising) cnt++;
	}
	//if (vec[num-1] >= rising) cnt++;
	cout << cnt<< endl;
	


}