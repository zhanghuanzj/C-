string a[] = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve" ,
				"Thirteen", "Fourteen", "Fifteen" ,"Sixteen" ,"Seventeen", "Eighteen", "Nineteen" };
string b[] = {"","","Twenty","Thirty", "Forty", "Fifty" , "Sixty" ,"Seventy" , "Eighty" , "Ninety"};
string c[] = {"","Thousand","Million","Billion"};
class ToString {
public:
	string toString(int x) {
		string result;
		int index = 0;
		while(x){
			string temp = getNumber(x%1000);
			if(!temp.empty()&&index>0){
				temp += " "+c[index];
			}
			if(!temp.empty()){
				if(result.empty()) result = temp;
				else result = temp + "," + result;
			}
			++index;
			x /= 1000;
		}
		if (result.empty())
		{
			result = "Zero";
		}
		return result;
	}

	string getNumber(int n){
		string number;
		int x = n/100;
		int y = n%100/10;
		int z = n%10;
		if(x){
			number += a[x] + " Hundred";
		}
		if((n%100)>=10&&(n%100)<=19) {
			if(number.empty()) number += a[n%100];
			else number += " "+a[n%100];
		}
		else{
			if(y){
				if(!number.empty()) number += " ";
				number += b[y];
			}
			if(z){
				if(!number.empty()){
					number += " ";
					//if (y==0){
					//	number += "And ";
					//}
				}
				number += a[z];
			}
		}
		return number;
	}
};