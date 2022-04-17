#include <iostream>
using namespace std;

const int MAXSIZE = 5; // ��ϣ��������󳤶�
struct Node {
	int data;
	Node* next;
};

Node** my_hashTable = new Node*[MAXSIZE]; // ��ʼ��һ����ϣ��,����洢����ڵ�

bool isEmpty(Node* nd) {
	return nd == nullptr; // ��ǰ�ڵ��Ƿ�Ϊ��
}
void Insert(int key) {
	int index = key % MAXSIZE; // ��ϣ������ȡ��
	if (isEmpty(my_hashTable[index])) { // ��λ�õ�����ͷ�ڵ���Ϊ��
		my_hashTable[index] = new Node;
		my_hashTable[index]->data = key;
		my_hashTable[index]->next = nullptr;
	}
	else { // �����˹�ϣ��ͻ����ͬkey������ϣ����֮���index��ͬ����ϣ��indexλ���Ѿ����ڽڵ㣬�ѵ�ǰ�Ľڵ����ԭ��indexλ�������β��
		Node* last = my_hashTable[index];
		while (last->next != nullptr) {
			last = last->next;
		}
		// ��ǰlast->next == nullptr
		last->next = new Node;
		last->next->data = key;
		last->next->next = nullptr;
	}
}

bool Search(int key) {
	int index = key % MAXSIZE;
	if (my_hashTable[index] == nullptr) return false;

	Node* curHead = my_hashTable[index];
	// if (curHead->data == key) return true;
	while (curHead != nullptr) {
		if (curHead->data == key) {
			return true;
		}
		curHead = curHead->next;
	}
	return false;
}