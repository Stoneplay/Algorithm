#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* MakeList();
void PrintList(ListNode*);

ListNode* insertionSortList(ListNode* head);

int main() {
	ListNode *l = MakeList();
	ListNode *p = insertionSortList(l);
	PrintList(p);

	return 0;
}

ListNode* MakeList() {
	int num;

	ListNode *head = NULL;
	ListNode *tmp = head;
	while (cin >> num) {
		if (!head) {
			head = new ListNode(num);
			tmp = head;
		}
		else {
			tmp->next = new ListNode(num);
			tmp = tmp->next;
		}

		if (cin.get() == '\n') break;
	}
	return head;
}

void PrintList(ListNode* head) {
	if (!head) return;

	while (head) {
		cout << head->val << ' ';
		head = head->next;
	}
}

ListNode* insertionSortList(ListNode* head) {
	if (!head || !head->next) return head;

	ListNode *dummy = new ListNode(-1);
	dummy->next = head;

	ListNode *p = head->next;
	head->next = NULL;

	while (p) {		// 遍历待插入元素
		ListNode *tmp = dummy, *node = p->next;
		while (tmp->next) {
			if (p->val < tmp->next->val) {	// 找到插入位置
				ListNode *tnode = tmp->next;
				tmp->next = p;
				p->next = tnode;
				p = node;
				break;
			}
			else {
				tmp = tmp->next;
			}
		}
		if (!tmp->next) {	// 未找到插入位置,则插在已排序链表尾部
			tmp->next = p;
			p->next = NULL;
			p = node;
		}
	}
	return dummy->next;
}
