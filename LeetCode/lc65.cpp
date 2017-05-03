#include <cstdlib>
#include <string>

using std::string;

enum Input{
	invalid,
	space,
	sign,
	digit,
	dot,
	exponent,
};

int transitionTable[9][6] = 
{
	-1, 0, 3, 1, 2, -1,	//0 after space
	-1, 8, -1, 1, 4, 5,	//1 after a digit
	-1, -1, -1, 4, -1, -1, //2 after a dot
	-1, -1, -1, 1, 2, -1, //3 after sign
	-1, 8, -1, 4, -1, 5, //4 accept space digit
	-1, -1, 6, 7, -1, -1, //5 after exponent
	-1, -1, -1, 7, -1, -1, //6 only digit
	-1, 8, -1, 7, -1, -1, //7 digit end
	-1, 8, -1, -1, -1,-1//8 space end
};

bool isNumber(string s) {
	int re = 0;
	for (int i = 0; i < s.length(); i++)
	{
		Input type = invalid;

		if (s[i] == ' ')
		{
			type = space;
		}
		else if (s[i] == '-' ||s[i] == '+')
		{
			type = sign;
		}
		else if (s[i] >= '0' && s[i] <='9')
		{

			type = digit;
		}
		else if (s[i] == '.')
		{
			type = dot;
				
		}
		else if (s[i] == 'e' || s[i] == 'E')
		{
			type = exponent;
		}
		re = transitionTable[re][type];
		if (re == -1)
		{
			return false;
		}
	}
	if (re == 1 || re == 4 || re == 7 || re == 8)
	{
		return true;
	}
	else{
		return false;
	}
}