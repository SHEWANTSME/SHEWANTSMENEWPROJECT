#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include<queue>
#include<deque>
using namespace std;
//------------------------------------ �������ϴϱ� �������¡
bool visited[1001];
//int graph[1001];
vector<int>graph[1001];
vector<int>graph2[1001];
bool visiting[1001];
queue<int>q;
//------------------------------------ BFS
void BFS(int x) {// BFS �ʿ��Ѱ� -> bool visited, ���� array, queue
	q.push(x); // �ϴ� queue�� push
	visiting[x] = true; // visit�ϱ� ������ true
	while (!q.empty()) { // q�� ���� ���������� ����Ǵ� while
		int m = q.front();// �տ��ִ°� �ٸ������� ����
		q.pop(); // ��������
		cout << m << " "; // ����Ѵ���
		for (int i = 0; i < graph2[m].size(); i++) { // �տ��ִ³�� ����ȸ�ŭ�� ����� for��������
			int n = graph[m][i];
			if (!visiting[n]) { // �湮��������
				q.push(n); // queue�� ����ְ�
				visiting[n] = true;//�湮�� �ѰŰ�
			}// ���߿� �� �湮�� ������ �̳�if���� �ȵ��״�, 
			// �� pop�Ǿ while ������¡
		}
	}
}
// ---------------------------------- DFS
void DFS(int x) { // DFS �ʿ��Ѱ� -> bool visited, ���� array
	visited[x] = true;// ���� ��� �湮 �ߴٰ� üũ
	cout << x << " "; // ���
	for (int i = 0; i < graph[x].size(); i++) { // ��� ��ȣ�� �����ͺ��� ������� DFS�ϱ�
		int y = graph[x][i];// main���� ������ �� ���¿�����
		if (!visited[y]) DFS(y);// ��������� �湮 �������� �鸮��
	}
}
// ----------------------------------- MAIN
int main() {
	int node, line, start_num;
	cin >> node >> line >> start_num;
	while (line--) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y); // �̷��� ��������� �س��� ������ Ǯ�������
		graph[y].push_back(x);
		graph2[x].push_back(y);
		graph2[y].push_back(x);
	}
	for (int i = 1; i <= node; i++) {
		sort(graph[i].begin(), graph[i].end()); // sort�� ������������ ����� ����ȣ�� �����ͺ���
		sort(graph2[i].begin(), graph2[i].end());// ������ �湮�� ������
	}
	DFS(start_num);
	cout << endl;
	BFS(start_num);
	return 0;
}