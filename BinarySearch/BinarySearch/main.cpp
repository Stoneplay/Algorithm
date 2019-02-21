#include<iostream>
#include<vector>

using namespace std;

int BinarySearch(vector<int> nums, int target);
int BinarySearch_first(vector<int> nums, int target);
int BinarySearch_last(vector<int> nums, int target);
int BinarySearch_count(vector<int> nums, int target);

int main() {
	vector<int> nums;
	int target;

	cout << "Please input a array in ascending order : " << endl;
	int num;
	while (cin >> num) {
		nums.push_back(num);
		if (cin.get() == '\n') {
			break;
		}
	}
	cout << "The number you want to search : " << endl;
	cin >> target;

	cout << "\nThe arbitrary position of target : " << BinarySearch(nums, target) << endl;
	cout << "The first position of target : " << BinarySearch_first(nums, target) << endl;
	cout << "The last position of target : " << BinarySearch_last(nums, target) << endl;
	cout << "The quantity of target : " << BinarySearch_count(nums, target) << endl;

	return 0;
}

/* ����ĳ�������±�(���Ԫ���ظ�ʱ��������һ��Ԫ�ص��±�) */
int BinarySearch(vector<int> nums, int target) {
	int low = 0, high = nums.size() - 1;
	int mid = low + ((high - low) >> 1);
	
	while (low <= high) {
		mid = low + ((high - low) >> 1);
		if (nums[mid] == target) {
			return mid;
		}
		else if(nums[mid] > target) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}

	return -1;
}

/* ����ĳ�������±�(���Ԫ���ظ�ʱ���ص�һ��Ԫ�ص��±�) */
/* �ȼ��ڲ��Ҵ��ڵ���ĳ�����ĵ�һ���±� */
int BinarySearch_first(vector<int> nums, int target) {
	int low = 0, high = nums.size() - 1;
	int mid = low + ((high - low) >> 1);

	while (low < high) {	// low == highʱֹͣ����
		mid = low + ((high - low) >> 1);
		/* �����������򣬿ɽ���һ������target��Ԫ����ΪС�ڵ���target��Ԫ�� */
		if (nums[mid] >= target) {	// ȥ���Ⱥ�����Ҵ���ĳ�����ĵ�һ���±�
			high = mid;
		}
		else {
			low = mid + 1;
		}
	}

	if (nums[low] == target) {
		return low;
	}
	else {
		return -1;
	}
}

/* ����ĳ�������±�(���Ԫ���ظ�ʱ�������һ��Ԫ�ص��±�) */
/* �ȼ��ڲ���С�ڵ���ĳ���������һ���±� */
int BinarySearch_last (vector<int> nums, int target) {
	int low = 0, high = nums.size() - 1;
	int mid = low + ((high - low) >> 1);

	// low + 1 == highʱֹͣ����:����������ֻʣ����Ԫ��ʱ,���ǵ�Ŀ��Ӧ���ұ߽磬
	// ��������������������ȡ�������ټ���mid�ó��Ľ������߽磬��Ӧֹͣ����mid��ת���������������Ԫ�ؽ����ж�
	while (low + 1 < high) {	
		mid = low + ((high - low) >> 1);
		/* �����������򣬿ɽ����һ������target��Ԫ����Ϊ���ڵ���target��Ԫ�� */
		if (nums[mid] > target) {	
			high = mid - 1;
		}
		else {	// ȥ���Ⱥ������С��ĳ���������һ���±�
			low = mid;
		}
	}

	if (nums[high] == target) {
		return high;
	}
	else if (nums[low] == target) {
		return low;
	}
	else {
		return -1;
	}
}

/* ����������ĳ�������ֵĴ��� */
int BinarySearch_count(vector<int> nums, int target) {
	int first = BinarySearch_first(nums, target);
	int last = BinarySearch_last(nums, target);

	if (first == -1) {
		return 0;
	}
	else {
		return last - first + 1;
	}
}