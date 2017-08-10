#include <string>
#include <stack>


using namespace std;

class Solution273 {
public:
	string transform(int n){
		static string under20[20] = {
			"",
			"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
			"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
		};
		static string up20[8] = {
			"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
		};
		static string scale[4] = {
			"Hundred", "Thousand", "Million", "Billion"
		};

		string re = "";

		int h = n / 100;
		if (h)
			re = re + under20[h] +" " + scale[0] + " ";
		n = n % 100;
		if (n < 20){
			if (n)
				re += under20[n] + " ";
		}
		else{
			h = n / 10;
			re += up20[h - 2] + " ";
			n = n % 10;
			if (n)
				re += under20[n] + " ";
		}
		return re;
	}

	string numberToWords(int num) {
		if (num == 0)
			return "Zero";

		static string scale[4] = {
			"Hundred", "Thousand", "Million", "Billion"
		};

		stack<int> nums;

		while (num > 0){
			int m = num % 1000;
			nums.push(m);
			num /= 1000;
		}
		string result = "";
		while (!nums.empty()){
			int now = nums.top(); nums.pop();
			if (now == 0)
				continue;
			result += transform(now);
			if (nums.size() >= 1)
				result += scale[nums.size()] + " ";
		}
		if (!result.empty())
			result.pop_back();
		return result;
	}
};