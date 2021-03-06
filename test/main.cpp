//
//  main.cpp
//  test
//
//  Created by TPS on 2016/11/13.
//  Copyright © 2016年 TPS. All rights reserved.
//

#include <stdio.h>
#include "vector"
#include <iostream>
#include <queue>
#include <sstream>
#include <map>
#include <stack>
#include <list>
#include <cmath>

using namespace std;

static vector<int> global_num;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    string intToRoman(int num) {
        unsigned int val[13]={1000,900, 500,400,100,  90, 50,  40, 10,  9,   5,  4,   1};
        string       r[13]=  {"M", "CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string temp = "";
        while (num >0) {
            for (int i = 0; i<13; i++) {
                if (val[i] <= num) {
                    temp += r[i];
                    num -= val[i];
                    break;
                }
            }
        }
        return temp;
    }
    
public:
    int romanToInt(string s) {
        int sum = 0;
        unsigned int val[13]={1000,900, 500,400,100,  90, 50,  40, 10,  9,   5,  4,   1};
        string       r[13]=  {"M", "CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int m = 0;
        map<string, int> pairs;
        while (m < 13) {
            pairs.insert(map<string, int>::value_type(r[m], val[m]));
            m++;
        }
        int before = 1001;
        for (int i = 0; i<s.length(); i++) {
            stringstream ss;
            ss<<s[i];
            int se = (pairs.find(ss.str()))->second;
            if (se > before) {
                sum = sum + se - before * 2;
                before = 1001;
            }else{
                sum += se;
                before = se;
            }
        }
        return sum;
    }
    
public:
    
    
    
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> temp1, temp2, temp3;
        if (root == NULL) {
            return temp2;
        }
        temp1.push_back(root->val);
        if (root->left != NULL) {
            temp2 = preorderTraversal(root->left);
        }
        
        if(root->right != NULL){
            temp3 = preorderTraversal(root->right);
        }
        
        temp1.insert(temp1.end(), temp2.begin(), temp2.end());
        temp1.insert(temp1.end(), temp3.begin(), temp3.end());
        return temp1;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> m;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size(); j++) {
                if (m.size() < k) {
                    m.push(matrix[i][j]);
                }
                else if(m.top() > matrix[i][j]){
                    m.pop();
                    m.push(matrix[i][j]);
                }
            }
        }
        return m.top();
    }
    
public:
    bool validUtf8(vector<int>& data) {
        for (int i = 0; i < data.size(); i++) {
            int m = -1;
            int count = 0;
            do{
                if (count >= 7) {
                    break;
                }
                m = ((data[i] & (1<<(7-count)))>>(7-count));
                count++;
            }
            while(m == 1);
            
            if (count >= 7 || count == 2 ) {
                return false;
            }
            for (int j = 0; j < count-2; j++) {
                i++;
                if (i >= data.size()) {
                    return false;
                }
                int f = (data[i] & (1<<(7)))>>(7);
                int s = (data[i] & (1<<(6)))>>(6);;
                if (f != 1 || s!=0) {
                    return false;
                }
            }
        }
        return true;
    }
    
    /**
     * Definition for a binary tree node.
     * struct TreeNode {
     *     int val;
     *     TreeNode *left;
     *     TreeNode *right;
     *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     * };
     */

    public:
        TreeNode* invertTree(TreeNode* root) {
            if (root == NULL) {
                return NULL;
            }
            if (root->left != NULL || root->right != NULL) {
                TreeNode* temp = root->left;
                root->left = root->right;
                root->right = temp;
                invertTree(root->left);
                invertTree(root->right);
            }
            return root;
        }
    
public:
    
    vector<vector<int>> allSituations;
    
    //chose  int chooseNum of int totalNum
    void getSituation(vector<int> li, int totalNum, int chooseNum){
        if (totalNum == chooseNum) {
            for (int i = 0 ; i < totalNum; i++) {
                li.push_back(1);
            }
            allSituations.push_back(li);
            return;
        }
        if (chooseNum == 0) {
            for (int i = 0 ; i < totalNum; i++) {
                li.push_back(0);
            }
            allSituations.push_back(li);
            return;
        }
        li.push_back(0);
        getSituation(li, (totalNum-1), chooseNum);
        li.pop_back();
        li.push_back(1);
        getSituation(li, totalNum-1, chooseNum-1);
    }

    
    vector<string> readBinaryWatch(int num) {
        vector<int> li;
        vector<string> all;
        getSituation(li, 10, num);
        for (int i = 0; i< allSituations.size(); i++) {
            int hour = 0;
            hour += allSituations[i][0] * 8;
            hour += allSituations[i][1] * 4;
            hour += allSituations[i][2] * 2;
            hour += allSituations[i][3];
            if (hour > 11) {
                continue;
            }
            int minute = 0;
            minute += allSituations[i][4] * 32;
            minute += allSituations[i][5] * 16;
            minute += allSituations[i][6] * 8;
            minute += allSituations[i][7] * 4;
            minute += allSituations[i][8] * 2;
            minute += allSituations[i][9];
            if (minute > 59) {
                continue;
            }
            string temp = "";
            stringstream ss;
            ss<<hour;
            temp += ss.str();
            temp += ":";
            char m1 = (char)(minute / 10 + 48);
            char m2 = (char)(minute % 10 + 48);
            temp += m1;
            temp += m2;
            all.push_back(temp);
        }
        return all;
    }
    
    /**
     * Definition for singly-linked list.
     * struct ListNode {
     *     int val;
     *     ListNode *next;
     *     ListNode(int x) : val(x), next(NULL) {}
     * };
     */
    public:
        ListNode* reverseList(ListNode* head) {
            ListNode* temp = head;
            vector<ListNode*> store;
            store.push_back(NULL);
            while (temp!= NULL) {
                store.push_back(temp);
                temp = temp->next;
            }
            head = store[store.size() -1];
            temp = head;
            for (int i = store.size()-2; i>=0; i--) {
                temp->next = store[i];
                temp = temp->next;
            }
            return head;
        }
    
    int missingNumber(vector<int>& nums) {
        int temp = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i<nums.size(); i++) {
            if (nums[i] != temp) {
                return temp;
            }
            temp +=1;
        }
        return nums.size();
    }
    
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> local;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int mark1 = 0;
        int mark2 = 0;
        while (mark1 < nums1.size() && mark2 < nums2.size()) {
            if (nums1[mark1] == nums2[mark2]) {
                local.push_back(nums1[mark1]);
                mark1++;
                mark2++;
            }
            if (nums1[mark1] < nums2[mark2]) {
                mark1++;
            }
            if (nums1[mark1] > nums2[mark2]) {
                mark2++;
            }

        }
        return local;
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> local;
        if (root == NULL) {
            return local;
        }
        
        stack<TreeNode*> st;
        TreeNode* p = root;
        do {
            while (p !=NULL) {
                st.push(p);
                p = p->left;
            }
            if (!st.empty()) {
                p = st.top();
                st.pop();
                local.push_back(p->val);
                p = p->right;
            }
        } while (p!=NULL || !st.empty());
        
        return local;
    }
    
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i<nums.size(); i++) {
            if (nums[i] == nums[i-1]) {
                return true;
            }
        }
        return false;
    }
    
    int longestPalindrome(string s) {
        vector<char> temp;
        for (int i = 0 ; i<s.length(); i++) {
            char t = s[i];
            temp.push_back(t);
        }
        sort(temp.begin(), temp.end());
        int count = 0;
        for (int i = 0 ; i<temp.size() -1; i++) {
            if (temp[i] == temp[i+1]) {
                count += 2;
                i++;
            }
        }
        if (count < temp.size()) {
            count++;
        }
        return count;
    }
    
    //if s is subsequence of t.
    bool isSubsequence(string s, string t) {
        if (s.empty()) {
            return true;
        }
        int m = 0;
        for (int i = 0; i<t.length(); i++) {
            if (t[i] == s[m]) {
                m++;
                if (m == s.length()) {
                    return true;
                }
            }
            
        }
        return false;
    }

	public:
		int islandPerimeter(vector<vector<int>>& grid) {
			int count = 0;
			for (int i = 0; i < grid.size(); i++)
			{
				for (int j = 0; j < grid[i].size(); j++)
				{
					if (grid[i][j] == 0)
					{
						continue;
					}
					if (i - 1 < 0 )
					{
						count++;
					}
					else if (grid[i - 1][j] == 0)
					{
						count++;
					}
					if (i + 1 >= grid.size() )
					{
						count++;
					}
					else if (grid[i + 1][j] == 0)
					{
						count++;
					}
					if (j - 1 < 0 )
					{
						count++;
					}
					else if (grid[i][j - 1] == 0)
					{
						count++;
					}
					if (j + 1 >= grid[i].size())
					{
						count++;
					}
					else if (grid[i][j + 1] == 0)
					{
						count++;
					}
				}
			}
			return count;
		}

		bool canWinNim(int n) {
			n = n % 4;
			if (n == 1 || n == 2 || n == 3)
			{
				return true;
			}
			else if (n == 0)
			{
				return false;
			}

			return false;
		}
    
		vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
			list<pair<int, int>> temp;
			list<pair<int, int>>::iterator finder;
			int j = 0;
			while (j < people.size())
			{
				for (size_t i = 0; i < people.size(); i++)
				{
					if (people[i].second != j)
					{
						continue;
					}
					int count = 0;
					for (finder = temp.begin(); finder != temp.end(); finder++)
					{
						if (finder->first >= people[i].first )
						{
							count++;
							if (count > people[i].second)
							{
								break;
							}
						}
					}
					temp.insert(finder, people[i]);
				}

				j++;
				if (temp.size() == people.size())
				{
					break;
				}
			}

			vector<pair<int, int>> out;
			for (finder = temp.begin(); finder != temp.end(); finder++)
			{
				out.push_back(*finder);
				//cout << finder->first << " " << finder->second << endl;
			}
			return out;
		}
    
	//time out
    int minSum(vector<vector<int>>& triangle, int row, int index){
        int m;
        if (row == triangle.size() -1) {
            m = triangle[row][index];
        }else{
            int f =minSum(triangle, row+1, index);
            int s =minSum(triangle, row+1, index+1);
            m = f<s?f:s;
            m += triangle[row][index];
        }
        return m;
    }

    
    int minimumTotal(vector<vector<int>>& triangle) {
		int m;
		//m = minSum(triangle, 0, 0);
		int size = triangle[triangle.size() - 1].size();
		int *vec = new int[size];
		for (int i = 0; i < triangle[triangle.size()-1].size(); i++)
		{
			vec[i] = triangle[triangle.size() - 1][i];
		}
		for (int i = triangle.size()-2; i >= 0; i--)
		{
			for (int j = 0; j < triangle[i].size(); j++)
			{
				int t1 = vec[j];
				int t2 = vec[j + 1];
				vec[j] = t1 < t2 ? t1 : t2;
				vec[j] += triangle[i][j];
			}
		}
		m = vec[0];
		delete[] vec;
        return m;
    }
    
    //lc 461
    int hammingDistance(int x, int y) {
        int count = 0;
        for (int i = 0; i<32; i++) {
            int mask = (int)powf(2, i);
            int t1 = x& mask;
            int t2 = y& mask;
            if (t1 != t2) {
                count++;
            }
        }
        return count;
    }
    
    //lc 476
    int findComplement(int num) {
        int i = 31;
        do {
            int mask = (int)powf(2, i);
            if ((num & mask )!=0) {
                break;
            }
            i--;
        } while (i>=0);
        int re = num ^ ((int)powf(2, i+1) -1);
        return re;
    }
    
    //lc 419
    int countBattleships(vector<vector<char>>& board) {
        int count = 0;
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col< board[row].size(); col++) {
                if (board[row][col] == 'X') {
                    count++;
                
                if (col >= 1) {
                    if (board[row][col -1] == 'X') {
                        count--;
                        continue;
                    }
                }
                if (row >= 1) {
                    if (board[row - 1][col] == 'X') {
                        count--;
                    }
                }
                }
            }
        }
        return count;
    }
    
};



int maintest(){
    Solution temp;
    vector<char> tt;
    vector< vector<char>> ttall;
    tt.clear();
    tt.push_back('X');
    tt.push_back('.');
    tt.push_back('.');
    tt.push_back('X');
    ttall.push_back(tt);
    
    tt.clear();
    tt.push_back('.');
    tt.push_back('.');
    tt.push_back('.');
    tt.push_back('X');
    ttall.push_back(tt);
    
    tt.clear();
    tt.push_back('.');
    tt.push_back('.');
    tt.push_back('.');
    tt.push_back('X');
    ttall.push_back(tt);
    
    int m = temp.countBattleships(ttall);
    
    
    
	return 0;
}







