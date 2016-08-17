 class Solution {
 public:
	 string addBinary(string a, string b) {
		 int aIndex = a.size()-1;
		 int bIndex = b.size()-1;
		 int carry = 0;
		 string result;
		 while(bIndex>=0&&aIndex>=0){
			 if(carry==0){
				 if(a[aIndex]=='1'&&b[bIndex]=='1'){
					 result = result+"0";
					 carry = 1;
				 }else if(a[aIndex]=='1'||b[bIndex]=='1'){
					 result = result+"1";
				 }else{
					 result = result+"0";
				 }
			 }else{
				 if(a[aIndex]=='1'&&b[bIndex]=='1'){
					 result = result+"1";
					 carry = 1;
				 }else if(a[aIndex]=='1'||b[bIndex]=='1'){
					 result = result+"0";
					 carry = 1;
				 }else{
					 result = result+"1";
					 carry = 0;
				 }
			 }
			 --aIndex,--bIndex;
		 }
		 while (bIndex>=0){
			 if(carry){
				 if(b[bIndex]=='1'){
					result = result+"0";
					carry = 1;
				 }else{
					result = result+"1";
					carry = 0;
				 }
			 }else{
				 result += b[bIndex];
			 }
			 --bIndex;
		 }
		 while (aIndex>=0){
			 if(carry){
				 if(a[aIndex]=='1'){
					 result = result+"0";
					 carry = 1;
				 }else{
					 result = result+"1";
					 carry = 0;
				 }
			 }else{
				 result += a[aIndex];
			 }
			 --aIndex;
		 }
		 if(carry) result += "1";
		 reverse(result.begin(),result.end());
		 return result;
	 }
 };