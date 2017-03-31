//
//  lc4.cpp
//  test
//
//  Created by TPS on 2017/3/18.
//  Copyright © 2017年 TPS. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

int min(int a, int b){
	int m = a < b ? a : b;
	return m;
}

double findKth(int *a, int m, int *b, int n, int k)
{
    //always assume that m is equal or smaller than n
    if (m > n)
        return findKth(b, n, a, m, k);
    if (m == 0)
        return b[k - 1];
    if (k == 1)
        return min(a[0], b[0]);
    //divide k into two parts
    int pa = min(k / 2, m), pb = k - pa;
    if (a[pa - 1] < b[pb - 1])
        return findKth(a + pa, m - pa, b, n, k - pa);
    else if (a[pa - 1] > b[pb - 1])
        return findKth(a, m, b + pb, n - pb, k - pb);
    else
        return a[pa - 1];
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int k = nums1.size() + nums2.size();
    int *a = new int[nums1.size()];
    int *b = new int[nums2.size()];
    for (int i = 0; i < nums1.size(); i++) {
        a[i] = nums1[i];
    }
    
    for (int i = 0; i < nums2.size(); i++) {
        b[i] = nums2[i];
    }
    
    if (k % 2 == 0) {
        double x = findKth(a, nums1.size(), b, nums2.size(), k/2);
        double y = findKth(a, nums1.size(), b, nums2.size(), k /2 + 1);
        return (x + y)/2;
    }else{
        double x = findKth(a, nums1.size(), b, nums2.size(), (k +1) /2 );
        return x;
    }
}

int main4(){
    vector<int> nums1;
    vector<int> nums2;
    nums1.push_back(1);
    nums1.push_back(3);
    nums2.push_back(2);
    
    double re =findMedianSortedArrays(nums1, nums2);

    return 0;
}
