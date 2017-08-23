#include <vector>
#include <algorithm>

using namespace std;

class Solution324 {
public:

// Index-rewiring.
#define A(i) nums[(1+2*(i)) % (n|1)]

	void wiggleSort(vector<int>& nums) {
		int n = nums.size();

		// Find a median.
		auto midptr = nums.begin() + n / 2;
		nth_element(nums.begin(), midptr, nums.end());
		int mid = *midptr;



		// 3-way-partition-to-wiggly in O(n) time with O(1) space.
		int i = 0, j = 0, k = n - 1;
		while (j <= k) {
			if (A(j) > mid)
				swap(A(i++), A(j++));
			else if (A(j) < mid)
				swap(A(j), A(k--));
			else
				j++;
		}
	}

#if 0
	void wiggleSort(vector<int>& nums) {
		int n = nums.size();
		if (n <= 1)
			return;
		int mid = (n - 1) / 2;
		nth_element(nums.begin(), nums.begin() + mid, nums.end());

		vector<int> re(n);
		for (int i = 0; 2 * i < n; i++){
			re[2 * i] = nums[i];
		}
		int ptr = 1;
		for (int i = mid + 1; i < n; i++){
			re[ptr] = nums[i];
			ptr += 2;
		}
		nums = re;
	}

#endif
};

#if 0
class Solution324 {
public:
	int partition(vector<int>& nums, int l, int r){
		int left = l;
		int right = r;
		int temp = nums[l];
		while (left < right){
			while (left < right && nums[right] > temp){
				right--;
			}
			if (left < right)
				nums[left++] = nums[right];
			while (left< right && nums[left] < temp){
				left++;
			}
			if (left < right)
				nums[right--] = nums[left];
		}
		nums[left] = temp;
		return left;
	}

	void wiggleSort(vector<int>& nums) {
		int n = nums.size();

		int mid = n  / 2;

		int left = 0; 
		int right = n - 1;
		int index = -1;
		while (index != mid){
			index = partition(nums, left, right);
			if (index < mid)
				left = index + 1;
			else if (index > mid)
				right = index - 1;
		}

		int ptr1 = 1;
		int ptr2 = mid;
		if (mid % 2 == 1)
			ptr2++;
		while (ptr1 < mid){
			swap(nums[ptr1], nums[ptr2]);
			ptr1 += 2;
			ptr2 += 2;
		}
	}
};

#endif