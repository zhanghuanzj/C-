class BinDecimal {
public:
	string printBin(double num) {
		if(num>=1||num<=0) return "Error";
		string result="0.";
		double flag = 0.5;
		while(num>0){
			if(result.size()>32) return "Error";
			if(num>=flag){
				num -= flag;

				result.append("1");
			}
			else{
				result.append("0");
			}
							flag /= 2;
		}
		return result;
	}
};