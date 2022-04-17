#include <iostream>
using namespace std;

const int MAXSIZE = 5; // 哈希表数组最大长度
struct Node {
	int data;
	Node* next;
};

Node** my_hashTable = new Node*[MAXSIZE]; // 初始化一个哈希表,数组存储链表节点

bool isEmpty(Node* nd) {
	return nd == nullptr; // 当前节点是否为空
}
void Insert(int key) {
	int index = key % MAXSIZE; // 哈希函数，取余
	if (isEmpty(my_hashTable[index])) { // 该位置的链表头节点仍为空
		my_hashTable[index] = new Node;
		my_hashTable[index]->data = key;
		my_hashTable[index]->next = nullptr;
	}
	else { // 发生了哈希冲突，不同key经过哈希函数之后的index相同，哈希表index位置已经存在节点，把当前的节点放在原来index位置链表的尾部
		Node* last = my_hashTable[index];
		while (last->next != nullptr) {
			last = last->next;
		}
		// 当前last->next == nullptr
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