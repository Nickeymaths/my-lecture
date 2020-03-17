#include <iostream>
using namespace std;

struct SinglyLinkedListNode {
	int data;
	SinglyLinkedListNode* next;

	SinglyLinkedListNode(int _a = 0) {
		this->data = _a;
		this->next = nullptr;
	}
};
struct SinglyLinkedList {
	SinglyLinkedListNode* head;
	SinglyLinkedListNode* tail;
	int size;
	SinglyLinkedList() {
		this->head = nullptr;
		this->tail = nullptr;
		size = 0;
	}

	void insertNode(int nodeData) {
		SinglyLinkedListNode* newNode = new SinglyLinkedListNode(nodeData);
		if (!this->head) {
			this->head = newNode;
		}
		else {
			tail->next = newNode;
		}
		tail = newNode;
		this->size++;
	}
	SinglyLinkedListNode* deleteNode(int position) {
		if (!this->head);
		else if (!this->head->next) {
			delete this->head;
			this->head = nullptr;
			this->tail = nullptr;
		}
		else {
			SinglyLinkedListNode* p = this->head;


			for (int count = 1; p != nullptr, count < position - 1; p = p->next, count++);
			SinglyLinkedListNode* temp = p->next;
			if (position == this->size) {
				p->next = nullptr;
			} else {
				p->next = p->next->next;
			}
			delete temp;
			
			(this->size)--;
		}
		return this->head;
	}
	void printList() {
		for (SinglyLinkedListNode* p = this->head; p != nullptr; p = p->next) {
			cout << p->data << ' ';
		}
	}

	~SinglyLinkedList() {
		for (; head != nullptr;) {
			SinglyLinkedListNode* p = this->head;
			this->head = this->head->next;
			delete p;
		}
	}
};
int main() {
	int numberOfstudent;
	cin >> numberOfstudent;
	SinglyLinkedList* llist = new SinglyLinkedList;
	for (int i = 0; i < numberOfstudent; i++) {
		int scor;
		cin >> scor;
		llist->insertNode(scor);
	}

	// Them diem cua sinh vien
	int value_inserted;
	cin >> value_inserted;
	llist->insertNode(value_inserted);
	while (llist->deleteNode(llist->size)) {
		llist->printList();
		cout << endl;
		cout << llist->size << endl;
	}
	delete llist;
	return 0;
}
