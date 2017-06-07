#include <cstdlib>
#include <string>
#include <vector>


using namespace std;

class Solution97 {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.length() + s2.length() != s3.length())
		{
			return false;
		}
		
		vector<vector<bool>> flags(s3.length() + 1, vector<bool>(s3.length() + 1, false));
		flags[0][0] = true;
		for (size_t i = 1; i <= s3.length(); i++)
		{
			for (size_t j = 1; j <= s3.length(); j++)
			{
				if (i + j - 2 >= s3.length())
				{
					break;
				}
				if (flags[i-1][j-1])
				{
					if (i- 1 < s1.length() && s3[i+j-2]== s1[i-1])
					{
						flags[i][j - 1] = true;
					}
					if (j - 1 < s2.length() && s3[i+j-2]== s2[j-1])
					{
						flags[i - 1][j] = true;
					}
				}
				
			}
		}
		return flags[s1.length()][s2.length()];
	}
};
