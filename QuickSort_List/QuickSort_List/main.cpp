#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* MakeList();
void PrintList(ListNode* head);

void swap(int& a, int& b);
ListNode* Partion(ListNode* begin, ListNode* end);
void QSort(ListNode* begin, ListNode* end);
ListNode* QuickSort(ListNode* head);

int main() {
	ListNode *head = MakeList();
	ListNode *l = QuickSort(head);
	PrintList(l);

	return 0;
}

ListNode* MakeList() {
	ListNode *head = NULL, *tmp;
	int num;

	while (cin >> num) {
		if (!head) {
			head = new ListNode(num);
			tmp = head;
		}
		else {
			ListNode* node = new ListNode(num);
			tmp->next = node;
			tmp = tmp->next;
		}
		if (cin.get() == '\n') break;
	}

	return head;
}

void PrintList(ListNode* head) {
	if (!head) return;

	ListNode *t = head;
	while (t) {
		cout << t->val << ' ';
		t = t->next;
	}
}

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

ListNode* Partion(ListNode* begin, ListNode* end) {
	if (begin == end || begin->next == end) return begin;

	int key = begin->val;		// �����Ԫ����Ϊ��Ԫ
	ListNode *tmp = begin->next;
	ListNode *flag = begin;		// flagΪС����Ԫ��������һ��λ��
	while (tmp != end) {
		if (tmp->val <= key) {
			flag = flag->next;	// С����Ԫ����������
			swap(tmp->val, flag->val);
		}
		tmp = tmp->next;
	}
	swap(flag->val, begin->val);	// ��Ԫ����С����Ԫ��������һ��λ��

	return flag;
}

void QSort(ListNode* begin, ListNode* end) {
	if (begin == end || begin->next == end) return;

	ListNode *mid = Partion(begin, end);
	QSort(begin, mid);
	QSort(mid->next, end);
}

ListNode* QuickSort(ListNode* head) {
	if (!head || !head->next) return head;

	QSort(head, NULL);
	return head;
}