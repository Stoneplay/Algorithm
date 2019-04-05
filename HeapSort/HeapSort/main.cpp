#include<iostream>
#include<vector>

using namespace std;

void Adjust(vector<int>&, int, int);
void HeapSort(vector<int>&);

int main() {
	vector<int> nums;
	int num;

	while (cin >> num) {
		nums.push_back(num);
		if (cin.get() == '\n') break;
	}

	HeapSort(nums);
	for (size_t i = 0; i < nums.size(); i++) {
		cout << nums[i] << ' ';
	}
	cout << endl;
}

inline void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

// �洢��Ԫ�ص������±��0��ʼʱ�������������±�Ϊi��Ԫ�أ�����i + 1��Ԫ�أ�
// LeftChild(i) = 2*i + 1
// RightChild(i) = 2*i + 2
// Parent(i) = (i - 1) / 2

void Adjust(vector<int>& nums, int current, int end) {
	int left = 2 * current + 1;		// ��ǰ�ڵ�������
	int right = 2 * current + 2;	// ��ǰ�ڵ���Ҷ���
	int MaxIdx = current;			// ��ǰ�����ķ�Ҷ�ڵ㼰�����Ҷ����У����Ľڵ��

	/* ȷ����ǰ�ڵ㼰�����Ҷ����У����Ľڵ���±꣬����¼ΪMaxIdx */
	if (left <= end && nums[MaxIdx] < nums[left]) {
		MaxIdx = left;
	}
	if (right <= end && nums[MaxIdx] < nums[right]) {
		MaxIdx = right;
	}

	/* �����ڵ㲻�ǵ�ǰ�ڵ㣬�������ӽڵ㣬����Ҫ���� */
	if (MaxIdx != current) {
		swap(nums[MaxIdx], nums[current]);
		Adjust(nums, MaxIdx, end);	// �����µ���,ֱ�����ܵ���(�ڵ��±곬�����鷶Χ)
	}
}

void HeapSort(vector<int>& nums) {
	if (nums.size() < 2) return;

	/* �������� */
	for (int i = nums.size() / 2 - 1; i >= 0; i--) {
		Adjust(nums, i, nums.size() - 1);	// �����һ����Ҷ�ڵ㿪ʼ�����ζ�ÿһ����Ҷ�ڵ�ά����������
	}

	/* �Ӻ���ǰ�����ν�ÿһ��Ԫ����δ�����Ԫ���е����Ԫ�ؽ��н�����Ȼ��ά���������ʣ�ֱ������������������*/
	for (int i = nums.size() - 1; i > 0; i--) {
		swap(nums[0], nums[i]);
		Adjust(nums, 0, i - 1);
	}
}