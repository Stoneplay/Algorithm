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

// 存储堆元素的数组下标从0开始时，对于数组中下标为i的元素，及第i + 1个元素：
// LeftChild(i) = 2*i + 1
// RightChild(i) = 2*i + 2
// Parent(i) = (i - 1) / 2

void Adjust(vector<int>& nums, int current, int end) {
	int left = 2 * current + 1;		// 当前节点的左儿子
	int right = 2 * current + 2;	// 当前节点的右儿子
	int MaxIdx = current;			// 当前遍历的非叶节点及其左右儿子中，最大的节点的

	/* 确定当前节点及其左右儿子中，最大的节点的下标，并记录为MaxIdx */
	if (left <= end && nums[MaxIdx] < nums[left]) {
		MaxIdx = left;
	}
	if (right <= end && nums[MaxIdx] < nums[right]) {
		MaxIdx = right;
	}

	/* 若最大节点不是当前节点，而是其子节点，则需要调整 */
	if (MaxIdx != current) {
		swap(nums[MaxIdx], nums[current]);
		Adjust(nums, MaxIdx, end);	// 逐级向下调整,直至不能调整(节点下标超出数组范围)
	}
}

void HeapSort(vector<int>& nums) {
	if (nums.size() < 2) return;

	/* 建立最大堆 */
	for (int i = nums.size() / 2 - 1; i >= 0; i--) {
		Adjust(nums, i, nums.size() - 1);	// 从最后一个非叶节点开始，依次对每一个非叶节点维护最大堆性质
	}

	/* 从后往前，依次将每一个元素与未排序的元素中的最大元素进行交换，然后维护最大堆性质，直至完成整个数组的排序*/
	for (int i = nums.size() - 1; i > 0; i--) {
		swap(nums[0], nums[i]);
		Adjust(nums, 0, i - 1);
	}
}