#include <string>
#include <map>

using namespace std;

class Solution166 {
public:
	string fractionToDecimal(int numerator, int denominator) {
		string result;
		if (numerator == 0){
			result = "0";
			return result;
		}

		if ((numerator > 0 && denominator < 0) || (numerator < 0 && denominator > 0)){
			result += '-';
		}
		long long num = numerator;
		long long denom = denominator;
		num = abs(num);
		denom = abs(denom);

		result += to_string(num / denom);
		if (num % denom == 0)
			return result;
		
		result += '.';
		long long d = num % denom;
		map<long long, long long> location;
		while (d){
			d *= 10;
			long long temp = d / denom;
			if (location.find(d) != location.end()){
				result.insert(result.begin() + location[d], '(');
				result += ')';
				break;
			}
			location[d] = result.size();
			result += to_string(temp);
			
			d %= denom;
		}
		return result;
	} 
};