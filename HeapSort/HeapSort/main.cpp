#include<iostream>
#include<vector>

using namespace std;

void Print(vector<int>&);
void HeapSort(vector<int>&);

int main() {
	vector<int> nums;
	int num;

	while (cin >> num) {
		nums.push_back(num);
		if (cin.get() == '\n') break;
	}

	HeapSort(nums);
	Print(nums);
}

inline void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void Print(vector<int>& nums) {
	for (size_t i = 0; i < nums.size(); i++) {
		cout << nums[i] << ' ';
	}
	cout << endl;
}

// �洢��Ԫ�ص������±��0��ʼʱ�������������±�Ϊi��Ԫ�أ�����i + 1��Ԫ�أ�
// LeftChild(i) = 2*i + 1
// RightChild(i) = 2*i + 2
// Parent(i) = (i - 1) / 2

/* ���϶��µ�ά���������� */
void SiftDown(vector<int>& nums, int current, int end) {
	int child = 2 * current + 1;	// ��ǰ�ڵ�������
	if (child > end) return;	    // ��ǰ�ڵ����ӽڵ�

	int value = nums[current];	// ���浱ǰ�ڵ��ֵ
	while (child <= end) {
		if (child < end && nums[child] < nums[child + 1]) {
			child++;	// �ҵ��ϴ���ӽڵ�
		}

		if (value > nums[child]) {
			break;		// ���ڵ��ֵ���������ӽڵ��ֵ,�������
		}
		else {
			nums[current] = nums[child];
			current = child;
			child = 2 * current + 1;
		}
	}
	nums[current] = value;		// ��Ԥ�ȱ����ֵ���뵽����
}

void HeapSort(vector<int>& nums) {
	if (nums.size() < 2) return;

	/* �������� */
	for (int i = nums.size() / 2 - 1; i >= 0; i--) {
		SiftDown(nums, i, nums.size() - 1);	// �����һ����Ҷ�ڵ㿪ʼ�����ζ�ÿһ����Ҷ�ڵ�ά����������
	}
	//Print(nums);

	/* �Ӻ���ǰ�����ν�ÿһ��Ԫ����δ�����Ԫ���е����Ԫ�ؽ��н�����Ȼ��ά���������ʣ�ֱ������������������*/
	for (int i = nums.size() - 1; i > 0; i--) {
		swap(nums[0], nums[i]);
		SiftDown(nums, 0, i - 1);
	}
}