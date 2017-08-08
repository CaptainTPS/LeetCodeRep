#include <algorithm>

using namespace std;

class Solution223 {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int a = compare(A, C, E, G);
		int b = compare(B, D, F, H);
		int sizea = (C - A) * (D - B);
		int sizeb = (G - E) * (H - F);
		return sizea + sizeb - a*b;
	}

	int compare(int a1, int a2, int b1, int b2){
		if (a2 <= b1 || b2 <= a1)
			return 0;
		else
		{
			return min(a2, b2) - max(a1, b1);
		}
	}
};