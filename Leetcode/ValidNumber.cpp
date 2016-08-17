 class Solution {
 public:
     bool isNumber(string s) {
         enum InputType{
             INVALID,SPACE,SIGN,DOT,E,DIGIT
         };
         int trans[9][6] = {
             {-1,0,2,3,-1,1},
             {-1,8,-1,4,5,1},
             {-1,-1,-1,3,-1,1},
             {-1,-1,-1,-1,-1,4},
             {-1,8,-1,-1,5,4},
             {-1,-1,6,-1,-1,7},
             {-1,-1,-1,-1,-1,7},
             {-1,8,-1,-1,-1,7},
             {-1,8,-1,-1,-1,-1},
         };
         int state = 0;
         int input = INVALID;
         for(auto c : s){
             if (isspace(c)){
                 input = SPACE;
             }else if (c=='+'||c=='-'){
                 input = SIGN;
             }else if(c=='.'){
                 input = DOT;
             }else if(c=='e'){
                 input = E;
             }else if(isdigit(c)){
                 input = DIGIT;
             }else{
                 input = INVALID;
             }
             state = trans[state][input];
             if (state==-1){
                 return false;
             }
         }
         return state==1||state==4||state==7||state==8;
     }
 };