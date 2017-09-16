class Solution357 {
public:
    int countNumbersWithUniqueDigits(int n) {
		vector<int> dp(11);
		dp[0] = 1;
		for(int i = 1; i<=10;i++){
			dp[i] = i * dp[i-1];
		}

		vector<int> dpc9(10);
		for(int i = 0; i<=9;i++){
			dpc9[i] = dp[9] /(dp[i] * dp[9-i]);
		}

		vector<int> dpc10(11);
		for(int i = 0; i<=10;i++){
			dpc10[i] = dp[10] /(dp[i] * dp[10-i]);
		}

		int sum = 1;
		for(int x = 1; x <= n && x<=10;x++){
			sum += dpc10[x] * dp[x] - dpc9[x-1] * dp[x-1];
		}
		return sum;
    }
};