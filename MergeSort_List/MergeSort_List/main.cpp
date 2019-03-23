#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* MakeList();
void PrintList(ListNode* head);

ListNode* MergeList(ListNode* p1, ListNode* p2);
ListNode* MergeSort(ListNode* head);

int main() {
	ListNode *head = MakeList();
	ListNode *l = MergeSort(head);

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

ListNode* MergeList(ListNode* p1, ListNode* p2) {
	ListNode *dummy = new ListNode(-1);
	ListNode *tmp = dummy;

	while (p1 && p2) {
		if (p1->val < p2->val) {
			tmp->next = p1;
			tmp = tmp->next;
			p1 = p1->next;
		}
		else {
			tmp->next = p2;
			tmp = tmp->next;
			p2 = p2->next;
		}
	}

	if (p1) tmp->next = p1;
	if (p2) tmp->next = p2;

	return dummy->next;
}

/* 归并排序 */
ListNode* MergeSort(ListNode* head) {
	if (!head || !head->next) return head;	// 链表只有一个节点时,停止分离

	ListNode *fast = head, *slow = head;
	while (fast->next && fast->next->next) {
		fast = fast->next->next;	// 链表长度为奇数时,最终fast指向最后一个节点,slow指向中间节点;
		slow = slow->next;			// 链表长度为偶数时,最终fast指向倒数第二个节点,slow指向靠前的中间节点。
	}

	/* 进行Merge操作时,需要遍历两个子链表,故应将两个子链表分离 */
	fast = slow;		// 前半链表的尾节点	
	slow = slow->next;	// 后半链表的首节点
	fast->next = NULL;	// 前后链表分离

	ListNode *t1 = MergeSort(head);
	ListNode *t2 = MergeSort(slow);
	return MergeList(t1, t2);
}