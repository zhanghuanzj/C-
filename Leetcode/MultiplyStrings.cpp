class Solution {
public:
	string multiply(string num1, string num2) {
		int carry = 0;
		string result(num1.size()+num2.size(),'0');
		for (int i=num1.size()-1;i>=0;--i) {
			int a = num1[i] - '0';
			for (int j=num2.size()-1;j>=0;--j) {
				int b = num2[j] - '0';
				int c = result[i+j+1] - '0';
				int v = a*b+c+carry;
				result[i+j+1] = v%10 + '0';
				carry = v/10;
			}
			if(carry){
				result[i] = carry+'0';
				carry = 0;
			}
		}
		int i = 0;
		while (i<result.size()&&result[i]=='0') ++i;
		return i==result.size()?"0":result.substr(i);
	}
};