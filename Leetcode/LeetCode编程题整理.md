	/**
	 * Definition for undirected graph.
	 * struct UndirectedGraphNode {
	 *     int label;
	 *     vector<UndirectedGraphNode *> neighbors;
	 *     UndirectedGraphNode(int x) : label(x) {};
	 * };
	 *
	 * Definition for binary tree
	 * struct TreeNode {
	 *     int val;
	 *     TreeNode *left;
	 *     TreeNode *right;
	 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	 * };
	 */
## 1.Minimum depth of binary tree ##
二叉树的最小深度

	class Solution {
	public:
	    int run(TreeNode *root) {
	        if(root == nullptr) return 0;
	        int left = run(root->left);
	        int right = run(root->right);
	        if(left==0 || right==0)
	            return left==0?(right+1):(left+1);
	        return min(left,right)+1;
	    }
	};

二叉树的最大深度

	class Solution {
	public:
	    int maxDepth(TreeNode *root) {
	        if(root==nullptr) return 0;
	        return max(maxDepth(root->left),maxDepth(root->right))+1;
	    }
	};
## 2.Evaluate reverse polish notation ##
逆波兰表达式求值

	  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
	  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
**Code：**

	class Solution {
	public:
	    int evalRPN(vector<string> &tokens) {
	        stack<int> record;
	        for(auto e : tokens){
	            if(e=="+" || e=="-" || e=="*" || e=="/"){
	                int x = record.top();
	                record.pop();
	                int y = record.top();
	                record.pop();
	                record.push(cal(x,y,e));
	            }else{
	                record.push(stoi(e));
	            }
	        }
	        return record.top();
	    } 
	    int cal(int x,int y,string op){
	        if(op=="*"){
	            return x*y;
	        }else if(op=="+"){
	            return x+y;
	        }else if(op=="-"){
	            return y-x;
	        }else if(op=="/"){
	            return y/x;
	        }
	        return 0;
	    }
	};
## 3.Max points on a line ##
平面上共线最多的点数
**Code:**

	class Solution {
	public:
	    int maxPoints(vector<Point> &points) {
	        int result = 0;
	        for(int i=0;i<points.size();++i){
	            map<double,int> record;
	            int count = 0;
	            int dup = 0;
	            int cur = 1;
	            for(int j=0;j<points.size();++j){
	                if(i==j) continue;
	                int dy = points[j].y-points[i].y;
	                int dx = points[j].x-points[i].x;
	                if(dx==0 && dy==0){ 	//点位置一样
	                    ++dup;
	                }else if(dx==0){		//竖直的共线点单独记录
	                    count = count==0?2:(count+1);
	                    cur = max(cur,count);
	                }else{
	                    double k = ((double)dy)/dx;
	                    record[k] = record[k]==0?2:(record[k]+1);
	                    cur = max(cur,record[k]);
	                }
	            }
	            result = max(result,cur+dup);//加入位置一样的点
	        }
	        return result;
	    }
	};
## 4.Sort list ##
Sort a linked list in O(n log n) time using constant space complexity.

	class Solution {
	public:
	    ListNode *sortList(ListNode *head) {
	        if(head==NULL||head->next==NULL) return head;
	        ListNode *slow = head;
	        ListNode *fast = head;
	        while(fast->next&&fast->next->next){
	            fast = fast->next->next;
	            slow = slow->next;
	        }
	        ListNode *right = slow->next;
	        slow->next = NULL;
	        ListNode *l1 = sortList(head);
	        ListNode *l2 = sortList(right);
	        return merge(l1,l2);
	    }
	    ListNode *merge(ListNode* l1,ListNode* l2){
	        ListNode head(0);
	        ListNode *p = &head;
	        while(l1&&l2){
	            if(l1->val<l2->val){
	                p->next = l1;
	                l1 = l1->next;
	            }else{
	                p->next = l2;
	                l2 = l2->next;
	            }
	            p = p->next;
	        }
	        if(l1){
	            p->next = l1;
	        }
	        if(l2){
	            p->next = l2;
	        }
	        return head.next;
	    }
	};
## 5.Insertion sort list ##
链表插入排序
## 6.Binary tree postorder traversal ##

	class Solution {
	public:
	    vector<int> postorderTraversal(TreeNode *root) {
	        vector<int> result;
	 		if(root==NULL) return result;
	        stack<TreeNode*> record;
	        record.push(root);
	        while(!record.empty()){
	            TreeNode* node = record.top();
	            record.pop();
	            result.push_back(node->val);
	            if(node->left){
	                record.push(node->left);
	            }
	            if(node->right){
	                record.push(node->right);
	            }
	        }
	        reverse(result.begin(),result.end());
	        return result;
	    }
	};
## 7.Binary tree preorder traversal ##
	class Solution {
	public:
	    vector<int> preorderTraversal(TreeNode *root) {
	        vector<int> result;
	        if(root==NULL) return result;
	        stack<TreeNode*> record;
	        record.push(root);
	        while(!record.empty()){
	            TreeNode* node = record.top();
	            record.pop();
	            result.push_back(node->val);
	            if(node->right){
	                record.push(node->right);
	            }
	            if(node->left){
	                record.push(node->left);
	            }
	        }
	        return result;
	    }
	};
**Binary tree inorder traversal**

	class Solution {
	public:
	    vector<int> inorderTraversal(TreeNode *root) {
	        vector<int> result;
	        if(root==nullptr) return result;
	        stack<TreeNode*> s1;
	        stack<TreeNode*> s2;
	        s1.push(root);
	        while(!s1.empty()||!s2.empty()){
	            if(!s1.empty()){
	                TreeNode* node = s1.top();
	                s1.pop();
	                if(node->left){
	                    s2.push(node);
	                    s1.push(node->left);
	                }else{
	                    result.push_back(node->val);
	                    if(node->right){
	                        s1.push(node->right);
	                    }
	                }
	            }else if(!s2.empty()){
	                TreeNode *node = s2.top();
	                s2.pop();
	                result.push_back(node->val);
	                if(node->right){
	                    s1.push(node->right);
	                }
	            }
	        }
	        return result;
	    }
	};
## 8.Reorder list ##
L0→L1→…→Ln-1→Ln,
L0→Ln→L1→Ln-1→L2→Ln-2→…
Given{1,2,3,4}, reorder it to{1,4,2,3}.
先对后半部分逆转，再合并
## 9.Linked list cycle ##
链表判环

	class Solution {
	public:
	    bool hasCycle(ListNode *head) {
	        if(head==nullptr)
	            return false;
	        ListNode* slow = head;
	        ListNode* fast = head;
	        while(fast->next && fast->next->next){
	            fast = fast->next->next;
	            slow = slow->next;
	            if(slow==fast)
	                return true;
	        }
	        return false;
	    }
	};
## 10.Linked list cycle II ##
链表环入口
## 11.Word break ##

    s ="leetcode",
    dict =["leet", "code"].
因为leetcode可以由字典中单词组成，返回true

	class Solution {
	public:
		bool wordBreak(string s, unordered_set<string> &dict) {
			if (s.empty()){
				return false;
			}
			vector<bool> indics(s.size(),false);  //indics[i]:[0,i)是否可以由字典单词组成
			for(int i=1;i<=s.size();++i){
				for(int pre=0;pre<i;++pre){
					if(((pre==0)||indics[pre-1])&&dict.count(s.substr(pre,i-pre))){
						indics[i-1] =true;
					}
				}
			}
			return indics.back();
		}
	};
## 12.Word break II ##

    s = "catsanddog",
    dict = ["cat", "cats", "and", "sand", "dog"].

solution is ["cats and dog", "cat sand dog"].

    class Solution {
    private:
    	unordered_map<string,vector<string>> record;	//相应字符串的分解数组
    	vector<string> combine(vector<string> pre,string word){
    		for(int i=0;i<pre.size();++i){
    			pre[i] += " " + word;
    		}
    		return pre;
    	}
    public:
    	vector<string> wordBreak(string s, unordered_set<string> &dict) {
    		if(record.count(s)) return record[s];
    		vector<string> result;
    		if(dict.count(s)){
    			result.push_back(s);
    		}
    		for(int i=1;i<s.size();++i){
    			string word = s.substr(i);
    			if(dict.count(word)){
    				vector<string> subResult = combine(wordBreak(s.substr(0,i),dict),word);
    				result.insert(result.end(),subResult.begin(),subResult.end());
    			}
    		}
    		record[s] = result;
    		return result;
    	}
    };
## 13. Copy List with Random Pointer##
	class Solution {
	public:
	    RandomListNode *copyRandomList(RandomListNode *head) {
	        cloneList(head);        //尾后插入复制节点
	        randomAdjust(head);     //随机指针调整
	        return seperateList(head);//分解返回
	    }
	private:
	    void cloneList(RandomListNode *head){   
	        while (head){
	            RandomListNode *cloneNode = new RandomListNode(head->label);
	            cloneNode->next = head->next;
	            head->next = cloneNode;
	            head = cloneNode->next;
	        }
	    }
	    void randomAdjust(RandomListNode *head){
	        while (head){
	            RandomListNode *cloneNode = head->next;
	            if (head->random){
	                cloneNode->random = head->random->next;
	            }
	            head = cloneNode->next;
	        }
	    }
	    RandomListNode* seperateList(RandomListNode *head){
	        RandomListNode cloneHead(0);
	        RandomListNode *cloneNode = &cloneHead;
	        while (head){
	            cloneNode->next = head->next;
	            cloneNode = cloneNode->next;
	            head->next = cloneNode->next;
	            head = head->next;
	        }
	        return cloneHead.next;
	    }
	};
## 14.Single Number ##
数组中仅出现一次的数，其它数出现两次

	class Solution {
	public:
	    int singleNumber(vector<int>& nums) {
	        int result = 0;
	        for(auto v : nums){
	            result ^= v;
	        }
	        return result;
	    }
	};
## 15.Single Number II ##
数组中仅出现一次的数，其它数出现三次

	class Solution {
	public:
	    int singleNumber(vector<int>& nums) {
	        int result = 0;
	        for(int i=0;i<32;i++){
	            int count = 0;
	            for(auto v : nums){
	                count += (1<<i)&v?1:0;
	            }
	            result += (count%3)<<i;
	        }
	        return result;
	    }
	};
## 16.Single Number III ##
数组中仅出现一次的两个数，其它数出现两次

	class Solution {
	public:
	    vector<int> singleNumber(vector<int>& nums) {
	        int dif = 0;
	        for(auto v : nums){
	            dif ^= v;
	        }
	        dif &= -dif;    //保留第一位1用以区分
	        vector<int> result(2,0);
	        for(auto v : nums){
	            if(dif&v){
	                result[0] ^= v;
	            }else{
	                result[1] ^= v;
	            }
	        }
	        return result;
	    }
	};
## 17.Candy ##
There are N children standing in a line. Each child is assigned a rating value.
You are giving candies to these children subjected to the following requirements:
Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

	class Solution {
	public:
	    int candy(vector<int> &ratings) {
	        vector<int> record(ratings.size(),1);
	        for(int i=1;i<ratings.size();++i){
	            if(ratings[i]>ratings[i-1]){
	                record[i] = record[i-1]+1;
	            }
	        }
	        int result = record.back();
	        for(int i=ratings.size()-2;i>=0;--i){
	            if(ratings[i]>ratings[i+1]&&record[i]<=record[i+1]){
	                record[i] = record[i+1]+1;   
				}
	            result += record[i];
	        }
	        return result;
	    }
	};
## 18.Gas Station ##
There are N gas stations along a circular route, where the amount of gas at station i isgas[i].
You have a car with an unlimited gas tank and it costscost[i]of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
**Note: **
The solution is guaranteed to be unique.
转换为最大连续子序列和

	class Solution {
	public:
	    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
	        int n = gas.size();
	        vector<int> record(2*n);
	        for(int i=0;i<n;++i){
	            record[i] = record[n+i] = gas[i]-cost[i];
	        }
	        int start = 0;
	        int sum = 0;
	        for(int i=0;i<2*n;++i){
	            if(sum<=0){
	                start = i;
	                sum = record[i];
	            }else{
	                sum += record[i];
	            } 
	            if(sum>=0&&i-start+1==n){
	                return start;
	            }
	        }
	        return -1;
	    }
	};
## 19.Clone Graph ##
Clone an undirected graph.
Nodes are labeled uniquely.

	class Solution {
	public:
	    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
	        if(node==nullptr) return nullptr;
	        if(!record.count(node->label)){
	            UndirectedGraphNode *p = new UndirectedGraphNode(node->label);
	            record[node->label] = p;
	            for(int i=0;i<node->neighbors.size();++i){
	                p->neighbors.push_back(cloneGraph(node->neighbors[i]));
	            }
	            return p;
	        }else{
	            return record[node->label];
	        }  
	    }
	private:
	    map<int,UndirectedGraphNode*> record;
	};

## 20.Palindrome Partitioning ##
**Example:**

	s ="aab",
	Return
	[
	  ["aa","b"],
	  ["a","a","b"]
	]
递归加回溯
**Code:**

	class Solution {
	public:
		vector<vector<string>> partition(string s) {
			vector<vector<string>> result;
			vector<string> palindrome;
			getPalindrome(s,palindrome,result);
			return result;
		}
	private:
		void getPalindrome(string s,vector<string> &palindrome,vector<vector<string>> &result){
			if (s.size()==0){
				result.push_back(palindrome);
				return;
			}
			for (int i=0;i<s.size();++i){
				int begin = 0;
				int end = i;
				while (s[begin]==s[end]&&begin<end){
					++begin,--end;
				}
				if (begin>=end){
					palindrome.push_back(s.substr(0,i+1));
					getPalindrome(s.substr(i+1),palindrome,result);
					palindrome.pop_back();
				}
			}
		}
	};
## 21.Palindrome Partitioning II ##
	"aab" return 1
**Code:**

    class Solution {
    public:
    	int minCut(string s) {
    		int len = s.size();
    		vector<int> cuts(len);
    		for (int i=0;i<len;++i){
    			cuts[i] = i;
    		}
    		vector<vector<bool>> dp(len,vector<bool>(len,false));
    		for (int i=0;i<len;++i){
    			for (int j=i;j>=0;--j){
    				if ( s[i]==s[j] && ( i-j<2 || dp[j+1][i-1]) ){//判断所划的区域是否为回文
    					dp[j][i] = true;
    					if (j>0){
    						cuts[i] = min(cuts[i],cuts[j-1]+1);
    					}else{
    						cuts[i] = 0;
    					}
    				}
    			}
    		}
    		return cuts[len-1];
    	}
    };

## 22.Surrounded Regions ##
	X X X X        X X X X  
	X O O X        X X X X
	X X O X        X X X X
	X O X X        X O X X
**Code:**

	class Solution {
	public:
		void solve(vector<vector<char>> &board) {
			int n = board.size();
			if (n==0) {
				return;
			}
			int m = board.front().size();
			for (int i=0;i<n;++i){
				for (int j=0;j<m;++j){
					if ((board[i][j]=='O') && (i==0||i==n-1||j==0||j==m-1)){
						dfs(board,i,j);
					}
				}
			}
			for (int i=0;i<n;++i){
				for (int j=0;j<m;++j){
					if (board[i][j]=='O'){
						board[i][j] = 'X';
					}else if (board[i][j]=='T'){
						board[i][j] = 'O';
					}
				}
			}
		}
	private:
		void dfs(vector<vector<char>> &board,int x,int y){
			board[x][y] = 'T';
			int dx[] = {1,-1,0,0};
			int dy[] = {0,0,-1,1};
			for (int i=0;i<4;++i){
				int nx = x+dx[i];
				int ny = y+dy[i];
				if ((nx>=0&&nx<board.size()&&ny>=0&&ny<board.front().size())&&board[nx][ny]=='O'){
					dfs(board,nx,ny);
				}
			}
		}
	};
## 23.Sum Root to Leaf Numbers ##
	    1
	   / \
	  2   3        return 25
**Code:**

	class Solution {
	public:
	    int sumNumbers(TreeNode *root) {
			int result = 0;
			getValue(root,0,result);
			return result;
	    }
	private:
		void getValue(TreeNode *root,int pre,int &result){
			if (root==nullptr){
	            return;
	        }
			pre = pre*10+root->val;
	        if(!root->left && !root->right){
	            result += pre;
	        }else{
	            getValue(root->left,pre,result);
				getValue(root->right,pre,result);
			}
		}
	};

## 24.Longest Consecutive Sequence ##
**Example:**
	
	Given[100, 4, 200, 1, 3, 2],
	The longest consecutive elements sequence is[1, 2, 3, 4]. Return its length:4.
**Code:**

	class Solution {
	public:
		int longestConsecutive(vector<int> &num) {
			map<int,int> record;
			int result = 0;
			for (int i=0;i<num.size();++i){
				if (!record.count(num[i])){
					int left = record.count(num[i]-1)?record[num[i]-1]:0;
					int right = record.count(num[i]+1)?record[num[i]+1]:0;
					int cur = left+right+1;
					record.insert(make_pair(num[i],cur));
					record[num[i]-left] = cur;
					record[num[i]+right] = cur;
					result = max(result,cur);
				}
			}
			return result;
		}
	};
## 25.Word Ladder ##
**Example:**

	start ="hit"
	end ="cog"
	dict =["hot","dot","dog","lot","log"]
	As one shortest transformation is"hit" -> "hot" -> "dot" -> "dog" -> "cog",
	return its length 5.
**Code:**

	class Solution {
	public:
	    int ladderLength(string start, string end, unordered_set<string> &dict) {
	        if (start==end) return 1;
	        queue<string> words;
	        words.push(start);
	        dict.erase(start);
	        int depth = 1,remain = 1,newRemain = 0;
	        while (!words.empty()){
	            string word = words.front();
	            words.pop();
	            for (auto it = dict.begin();it!=dict.end();){
	                if (isDiffOne(word,*it)){
	                    if (*it==end) return depth+1;
	                    words.push(*it);
	                    it = dict.erase(it);
	                    ++newRemain;
	                }else{
	                    ++it;
	                }
	            }
	            --remain;
	            if (remain==0){
	                remain = newRemain;
	                newRemain = 0;
	                ++depth;
	            }
	        }
	        return 0;
	    }
	private:
	    bool isDiffOne(const string &s1,const string &s2){
	        int count = 0;
	        for (int i=0;i<s1.size();++i){
	            if (s1[i]!=s2[i]){
	                ++count;
	            }
	        }
	        return count==1;
	    }
	};
层次遍历原理类似
## 26.Word Ladder II ##
**Example:**

	start ="hit"
	end ="cog"
	dict =["hot","dot","dog","lot","log"]
	Return
	  [
	    ["hit","hot","dot","dog","cog"],
	    ["hit","hot","lot","log","cog"]
	  ]
**Code:**

	class Solution {
	public:
	    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
	        dict.insert(end);
	        dict.erase(start);
	        unordered_map<string,unordered_set<string>> record;  //图
	        vector<vector<string>> result;
	        unordered_set<string> cur,next;
	        cur.insert(start);
	        while (!cur.empty()){
	            for (auto word : cur){
	                for (int i=0;i<word.size();++i){
	                    for (int j=0;j<26;++j){       
	                        string temp = word;
	                        temp[i] = 'a'+j;
	                        if (dict.find(temp)!=dict.end()){
	                            next.insert(temp);
	                            record[temp].insert(word);   //反向边
	                        }
	                    }
	                }
	            }
	            cur = next;
	            next.clear();
	            for (auto word : cur){
	                dict.erase(word);
	                if (word==end){   //找到目标
	                    vector<string> path;
	                    getPaths(record,end,start,result,path);
	                    break;
	                }
	            }
	        }
	        for (auto& path:result){
	            reverse(path.begin(),path.end());
	        }
	        return result;
	    }
	private:
	    void getPaths(const unordered_map<string,unordered_set<string>> &record,const string &start,
	                  const string &end,vector<vector<string>> &result,vector<string> &path){
	        path.push_back(start);
	        if (start==end){
	            result.push_back(path);
	            path.pop_back();
	            return;
	        }
	        for (auto word : record.at(start)){
	            getPaths(record,word,end,result,path);
	        }
	        path.pop_back();
	    }
	};
## 27.Valid Palindrome ##
"A man, a plan, a canal: Panama"is a palindrome.
"race a car"is not a palindrome.

	class Solution {
	public:
		bool isPalindrome(string s) {
			int left = 0;
			int right = s.size()-1;
			while (left<right){
				while (left<right&&!isalnum(s[left]))
					++left;
				while (left<right&&!isalnum(s[right]))
					--right;
				if (!(tolower(s[left])==tolower(s[right])))
					return false;
				++left,--right;
			}
			return true;
		}
	};
## 28.Binary Tree Maximum Path sum ##
The path may start and end at any node in the tree.

       1
      / \
     2   3   start from 2-->1-->3
**Code:**

	class Solution {
	public:
	    int maxPathSum(TreeNode *root) {
	        int maxsum = INT_MIN;
	        getPathSum(root,maxsum);
	        return maxsum;
	    }
	    int getPathSum(TreeNode *root,int &maxSum){     
	        if (root==nullptr) return 0;
	        int left = max(0,getPathSum(root->left,maxSum));    //若和为负则不算入
	        int right = max(0,getPathSum(root->right,maxSum));
	        maxSum = max(maxSum,left+right+root->val);          //计算最大路径和
	        return max(left,right)+root->val;    //返回无跨度最大和路径
	    }
	};
## 29.Best Time to Buy and Sell Stock ##
仅有一次交易机会

	class Solution {
	public:
	    int maxProfit(vector<int>& prices) {
	        int miniPrice = INT_MAX;
	        int maxprofit = 0;
	        for(int i=0;i<prices.size();++i){
	          miniPrice = min(miniPrice,prices[i]);
	          maxprofit = max(maxprofit,prices[i]-miniPrice);
	        }
	        return maxprofit;
	    }
	};

任意次机会

	class Solution {
	public:
		int maxProfit(vector<int> &prices) {
			int result = 0;
			for(auto i=1;i<prices.size();++i){
				if(prices[i]>prices[i-1]){
					result += prices[i]-prices[i-1];
				}
			}
			return result;
		}
	};

最多两次机会

	class Solution {
	public:
		int maxProfit(vector<int> &prices) {
			if (prices.size()==0) return 0;
			int n = prices.size();
			vector<int> left(n,0) 		//left[i]:[0,i]的最大收益
			vector<int> right(n,0); 	  //right[i]:[i,n)的最大收益
			int mini = prices.front(),maxi = prices.back();
			for (int i=1;i<n;++i){
				left[i] = max(left[i-1],prices[i]-mini);
				mini = min(mini,prices[i]);
	
				right[n-i-1] = max(right[n-i],maxi-prices[n-i-1]);
				maxi = max(maxi,prices[n-i-1]);
			}
			int result = 0;
			for (int i=0;i<n;++i){
				result = max(result,left[i]+right[i]);
			}
			return result;
		}
	};

最多k次机会

	class Solution {
	public:
		int maxProfit(int k, vector<int>& prices) {
			int n = prices.size();
			if (n<2) return 0;
			if (k>n/2){          //一个数组最多需要n/2次交易
				int result = 0;
				for (int i=1;i<n;++i){
					if (prices[i]>prices[i-1]){
						result += prices[i]-prices[i-1];
					}
				}
				return result;
			}
			vector<int> buy(k+1,INT_MIN);
			vector<int> sell(k+1,0);
			for (int i=0;i<n;++i){
				for (int j=k;j>0;--j){
					sell[j] = max(sell[j],buy[j]+prices[i]);
					buy[j] = max(buy[j],sell[j-1]-prices[i]);
				}
			}
			return sell[k];
		}
	};
## 30.Triangle ##
最小路径和

	[
	     [2],
	    [3,4],
	   [6,5,7],
	  [4,1,8,3]
	]			is 11(2+3+5+1=11)
**Code:**

	class Solution {
	public:
		int minimumTotal(vector<vector<int> > &triangle) {
			if(triangle.empty()) return 0;
			vector<int> dp(triangle.back().size(),0);
			for(int i=0;i<triangle.size();++i){
				if(i>0) dp[i] = dp[i-1] + triangle[i][i];  	//尾
				for(int j=triangle[i].size()-2;j>0;--j){
					dp[j] = min(dp[j],dp[j-1])+triangle[i][j];
				}
				dp[0] += triangle[i][0]; 					//首
			}
			int mini = INT_MAX;
			for(int i=0;i<dp.size();++i){
				mini = min(mini,dp[i]);
			}
			return mini;
		}
	};
Pascals Trianglel类似求解
## 31.Populating next right pointers in each node ##
         1						 1 -> NULL
       /  \					   /  \
      2    3				     2 -> 3 -> NULL
     / \  / \				   / \  / \
    4  5  6  7				 4->5->6->7 -> NULL
**Code:**

	class Solution {
	public:
		void connect(TreeLinkNode *root) {
			if (root==nullptr) return;
			queue<TreeLinkNode*> record;
			record.push(root);
			int remain = 1;
			int newRemain = 0;
			while (!record.empty()){
				TreeLinkNode *node = record.front();
				record.pop();
				--remain;
				if (node->left){
					record.push(node->left);
					newRemain++;
				}
				if (node->right){
					record.push(node->right);
					newRemain++;
				}
				if (remain==0){
					node->next = nullptr;
					remain = newRemain;
					newRemain = 0;
				}else{
					node->next = record.front();
				}
			}
			return;
		}
	};

## 32.Distinct Subsequences ##
(ie,"ACE"is a subsequence of"ABCDE"while"AEC"is not).
**Example:**

	S ="rabbbit", T ="rabbit"
	Return 3.
dp[i][j]:表示长为i的S与长为j的T所表示的最多子序列
当S[i]==T[j]时：dp[i][j] = dp[i-1][j]+dp[i-1][j-1];
不同时：dp[i][j] = dp[i-1][j];
**Code:**

	class Solution {
	public:
	    int numDistinct(string S, string T) {
	        vector<int> dp(T.size()+1,0);
	        dp[0] = 1;
	        for(int i=0;i<S.size();++i){
	            for(int j=T.size();j>0;--j){
	                if (S[i]==T[j-1]){
	                    dp[j] += dp[j-1];
	                }
	            }
	        }
	        return dp.back();
	    }
	};
## 33.Path Sum ##
判断是否存在根节点到叶子节点和为sum的路径

	class Solution {
	public:
	    bool hasPathSum(TreeNode *root, int sum) {
	        if(root==nullptr) return false;
	        if(root->left==nullptr&&root->right==nullptr&&root->val==sum) return true;
	        return hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val); 
	    }
	};
如果要返回所有符合条件的路径则构造相应的数组保存并回溯即可
## 34.Balances Binary Tree ##
判断是否为平衡二叉树

	 class Solution {
	 public:
		 bool isBalanced(TreeNode* root) {
			 int deep;
			 return check(root,deep);
		 }
		 bool check(TreeNode *node,int &deep){
			 if (node==NULL){
				 deep = 0;
				 return true;
			 }
			 int ld=0,rd=0;
			 if(!check(node->left,ld)||!check(node->right,rd)) return false;
			 deep = max(ld,rd)+1;
			 return abs(ld-rd)<2;
		 }
	 };
## 35.Convert Sorted List to Binary Search Tree ##
	class Solution {
	public:
	    TreeNode* sortedListToBST(ListNode* head) {
	        int size = 0;
	        this->list = head;
	        while(head!=nullptr){	//计算长度
	            ++size;
	            head = head->next;
	        }
	        return generate(size);
	    }
	    TreeNode* generate(int n) {
	        if (n==0) return nullptr;
	        TreeNode *node = new TreeNode(0);
	        node->left = generate(n/2);		//左子树
	        node->val = list->val;			//根节点调整
	        list = list->next;				//右子树
	        node->right = generate(n-n/2-1);
	        return node;
	    }
	private:
	    ListNode *list;
	};
Convert sorted array to binary search tree 类似
## 36.construct binary tree from inorder and postorder traversal ##
	class Solution {
	public:
	    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
	        return solve(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
	    }
	    TreeNode *solve(vector<int> &inorder,int il,int ir,vector<int> &postorder,int pl,int pr){
	        if(il>ir) return nullptr;
	        int v = postorder[pr];
	        int index = il;
	        while(inorder[index]!=v)
	            ++index;
	        int offset = index-il;
	        TreeNode *node = new TreeNode(v);
	        node->left = solve(inorder,il,index-1,postorder,pl,pl+offset-1);
	        node->right = solve(inorder,index+1,ir,postorder,pl+offset,pr-1);
	        return node;
	    }
	};
## 37.Symmetric Tree ##
	    1
	   / \
	  2   2
	 / \ / \
	3  4 4  3
	
	But the following is not:
	    1
	   / \
	  2   2
	   \   \
	   3    3
**Code:**

	class Solution {
	public:
	    bool isSymmetric(TreeNode *root) {
	        if(root==nullptr) return true;
	        return solve(root->left,root->right);
	    }
	    bool solve(TreeNode *left,TreeNode *right){
	        if(left==nullptr && right==nullptr) return true;
	        if(left==nullptr || right==nullptr) return false;
	        if(left->val != right->val) return false;
	        return solve(left->left,right->right)&&solve(left->right,right->left);
	    }
	};
判断两棵树是否相同类似
## 38.Recover Binary Search Tree ##
BST中两个节点发生了交换

	class Solution {
	public:
		void recoverTree(TreeNode *root) {
			if(root==nullptr) return;
			vector<TreeNode*> record;
			TreeNode* pre = nullptr;
			solve(pre,root,record);
			swap(record[0]->val,record[1]->val);
		}
		void solve(TreeNode *&pre,TreeNode *root,vector<TreeNode*> &record){
			if(root==nullptr) return;
			solve(pre,root->left,record);
			check(pre,root,record);
			pre = root;
			solve(pre,root->right,record);
		}
		void check(TreeNode *pre,TreeNode *root,vector<TreeNode*> &record){
			if(pre==nullptr) return;
			if(pre->val>root->val){
				if(record.empty()){
					record.push_back(pre);
					record.push_back(root);
				}else{
					record[1] = root;
				}
			}
		}
	};

## 39.Validate Binary Search Tree ##
判断是否为BST

	class Solution {
	public:
	    bool isValidBST(TreeNode *root) {
	        TreeNode* pre = nullptr;
	        return solve(pre,root);
	    }
	    bool solve(TreeNode *&pre,TreeNode *root){
	        if(root==nullptr) return true;
	        bool result = solve(pre,root->left);
	        if(pre!=nullptr && pre->val >= root->val) 
	            return false;
	        pre = root;
	        return result && solve(pre,root->right);  
	    }
	};
## 40.Interleaving String ##
s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

	s1 ="aabcc",
	s2 ="dbbca",
	When s3 ="aadbbcbcac", return true.
	When s3 ="aadbbbaccc", return false.
**Code:**

	class Solution {
	public:
	    bool isInterleave(string s1, string s2, string s3) {
	        if(s1.size()+s2.size()!=s3.size()) return false;
	        vector<vector<bool>> dp(s1.size()+1,vector<bool>(s2.size()+1,false));
	        dp[0][0] = true;  //dp[i][j]:表示s1和s2能否组成长为i+j的s3
	        for(int i=0;i<=s1.size();++i){
	            for(int j=0;j<=s2.size();++j){
	                if(i>0 && s1[i-1]==s3[i+j-1]){
	                    dp[i][j] = dp[i-1][j];
	                }
	                if(j>0 && s2[j-1]==s3[i+j-1]){
	                    dp[i][j] = dp[i][j]|dp[i][j-1];
	                }
	            }
	        }
	        return dp[s1.size()][s2.size()];
	    }
	};
## 41.Unique Binary Search Trees ##
Given n = 3, there are a total of 5 unique BST's.

	   1         3     3      2      1
	    \       /     /      / \      \
	     3     2     1      1   3      2
	    /     /       \                 \
	   2     1         2                 3
**Code:**

	class Solution {
	public:
		int numTrees(int n) {
			if(n<=0) return 0;
			vector<int> dp(n+1,0);
			dp[0]=dp[1] = 1;
			for(int i=2;i<=n;++i){
				for(int j=1;j<=i;++j){
					dp[i] += dp[j-1]*dp[i-j];
				}
			}
			return dp.back();
		}
	};

创建所有的BST

	class Solution {
	public:
	    vector<TreeNode *> generateTrees(int n) {
	        return solve(1,n);
	    }
	    vector<TreeNode*> solve(int left,int right){
	        vector<TreeNode*> result;
	        if(left>right){
	            result.push_back(nullptr);
	        }else if(left==right) {
	            result.push_back(new TreeNode(left));
	        }else {
	            for(int i=left;i<=right;++i){
	            	vector<TreeNode*> leftTree = solve(left,i-1);
	                vector<TreeNode*> rightTree = solve(i+1,right);
	                for(int x=0;x<leftTree.size();++x){
	                    for(int y=0;y<rightTree.size();++y){
	                        TreeNode *node = new TreeNode(i);
	                        node->left = leftTree[x];
	                        node->right = rightTree[y];
	                        result.push_back(node);
	                    }
	                }
	       		}
	        }
	        return result;
	    }   
	};
## 42.Restore IP Addresses ##

	Given"25525511135",
	return["255.255.11.135", "255.255.111.35"]
**Code:**

	class Solution {
	public:
		vector<string> restoreIpAddresses(string s) {
			vector<string> result;
			solve(s,0,1,"",result);
			return result;
		}
		void solve(const string &s,int index,int depth,string ip,vector<string> &result){
			if(depth==4){
				if (s.size()-index<=3){
					string sub = s.substr(index);
					if (sub[0]=='0'&&sub.size()>1) return;//只能是0，不能是"00","01"这种
					if (stoi(sub)<256) result.push_back(ip+sub);
				}
			}
			else{
				for (int i=1;i<=3&&index+i<s.size();++i){
					string sub = s.substr(index,i);
					if (sub[0]=='0'&&sub.size()>1) break; //只能是0，不能是"00","01"这种
					if (stoi(sub)<256) solve(s,index+i,depth+1,ip+sub+".",result);
				}
			}
		}
	};
## 43.Reverse Linked List ##
Given1->2->3->4->5->NULL, m = 2 and n = 4,
return1->4->3->2->5->NULL.

	class Solution {
	public:
	    ListNode *reverseBetween(ListNode *head, int m, int n) {
	        ListNode preHead(0);
			preHead.next = head;
			head = &preHead;
			ListNode *pre=nullptr,*post=nullptr;
			for (int i=1;i<=n;++i){
				if (i==m) pre = head;
				if (i==n) post = head->next;
				head = head->next;
			}
	        while (pre->next!=post){ //区域内还有节点要往post后面插入
				ListNode *p = pre->next; //需要转移的节点
				pre->next = p->next;
				p->next = post->next;
				post->next = p;
			}
			return preHead.next;
	    }
	};

## 44.Subsets ##

	If S =[1,2,2], a solution is:
	[
	  [2],
	  [1],
	  [1,2,2],
	  [2,2],
	  [1,2],
	  []
	]
**Code:**

	class Solution {
	public:
	    vector<vector<int> > subsetsWithDup(vector<int> &S) {
	        sort(S.begin(),S.end());
	        vector<vector<int>> result;
	        result.push_back(vector<int>());
	        int pre;
	        for(int i=0;i<S.size();++i){
	            if(i==0){
	                result.push_back(vector<int>(1,S[i]));
	            }else{
	                int size = result.size();
	                for(int j=0;j<size;++j){
	                    if((pre==S[i]&&check(S,i,result[j]))||pre!=S[i]){
	                        vector<int> temp = result[j];
	                        temp.push_back(S[i]);
	                        result.push_back(temp);
	                    }
	                }
	            }
	            pre = S[i];
	        }
	        return result;
	    }
	private:
	    bool check(const vector<int> &S,const int index,const vector<int> &V){ //判断在数字重复时是否可以插入
	        int count = 0;
	        int i = index-1;
	        while(i>=0&&S[i]==S[index]){  	//重复出现的个数
	            --i;
	            ++count;
	        }
	        for(int j=V.size()-1;j>=0;--j){	//相应子序列出现重复的个数抵消
	            if(V[j]==S[index]){
	                --count;
	            }
	        }
	        return count==0;	//相同的个数表示可以插入
	    }
	};
若取数组（没有重复元素）的所有子集，可以用累插法或位取法。
## 45.Decode Ways ##
	'A' -> 1
	'B' -> 2
	...
	'Z' -> 26
求数字字符串可以拆分的组合数，如“12”，return 2

	class Solution {
	public:
		int numDecodings(string s) {
			if (s.empty()||s[0]=='0') return 0;
			vector<int> dp(s.size()+1,0);
			dp[0] = dp[1] = 1;
			for (int i=2;i<=s.size();++i){
				int pre = s[i-2]-'0';
				int cur = s[i-1]-'0';
	            if (cur==0){ 	//10,20，必须组合		
					if ((pre==1||pre==2))//否则为0
						dp[i] = dp[i-2];
				}else{
					if (pre==1||(pre==2&&cur<=6)) //1X,2X，可分可组
						dp[i] = dp[i-1]+dp[i-2];
	                else  //X 必须分开
	                   dp[i] = dp[i-1]; 
				}
			}
			return dp[s.size()];
		}
	};

## 46.Gray Code ##
	For example, given n = 2, return[0,1,3,2]. Its gray code sequence is:
	00 - 0
	01 - 1
	11 - 3
	10 - 2
**Code:**

	class Solution {
	public:
		vector<int> grayCode(int n) {
			vector<int> result(pow(2,n));
			for (int i=1;i<=n;++i){
				int size = 1<<i;
				int flag = 1<<(i-1);
				int index = 0;
				for (int j=size-1;2*j>=size;--j){
					result[j] = result[index++]|flag;  //左部插入1
				}
			}
			return result;
		}
	};
## 47.Merge Sorted Array ##
将两个有序数组A,B归并到A,从尾部比较，并从A的尾部插入即可。
## 48.Scramble String ##
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
Below is one possible representation of s1 ="great":

	    great
	   /    \
	  gr    eat
	 / \    /  \
	g   r  e   at
	           / \
	          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.
For example, if we choose the node"gr"and swap its two children, it produces a scrambled string"rgeat".

	    rgeat
	   /    \
	  rg    eat
	 / \    /  \
	r   g  e   at
	           / \
	          a   t
We say that"rgeat"is a scrambled string of"great".
Similarly, if we continue to swap the children of nodes"eat"and"at", it produces a scrambled string"rgtae".

	    rgtae
	   /    \
	  rg    tae
	 / \    /  \
	r   g  ta  e
	       / \
	      t   a
We say that"rgtae"is a scrambled string of"great".
Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

	 class Solution {
	 public:
		 bool isScramble(string s1, string s2) {
			 if(s1.size()!=s2.size()) return false;
			 if(s1==s2 ) return true;
			 vector<int> record(26,0);
			 for (int i=0;i<s1.size();++i){
				 record[s1[i]-'a'] ++;
				 record[s2[i]-'a'] --;
			 }
			 for (auto n : record){
				 if (n!=0)
					 return false;
			 }
			 for (int mid=1;mid<s1.size();++mid){
				 if (isScramble(s1.substr(0,mid),s2.substr(0,mid))&&isScramble(s1.substr(mid),s2.substr(mid))||
					 isScramble(s1.substr(0,mid),s2.substr(s2.size()-mid))&&isScramble(s1.substr(mid),s2.substr(0,s2.size()-mid))){
					 return true;
				 }
			 }
			 return false;
		 }
	 };
## 49.Partition List ##
将小于X的节点放在大于X的节点的前面
Given1->4->3->2->5->2and x = 3,
return1->2->2->4->3->5.

	class Solution {
	public:
	    ListNode *partition(ListNode *head, int x) {
	        ListNode lessHead(0);
	        ListNode greatHead(0);
	        ListNode *less = &lessHead,*great = &greatHead;
	        while(head){
	            ListNode *temp = head;
	            head = head->next;
	            if(temp->val < x){
	                less->next = temp;
	                less = less->next;
	            }else{
	                great->next = temp;
	                great = great->next;
	            }
	        }
	        great->next = nullptr;
	        less->next = greatHead.next;
	        return lessHead.next;
	    }
	};
## 50.Maximal Rectangle ##

	 class Solution {
	 public:
	     int maximalRectangle(vector<vector<char> > &matrix) {
	         if(matrix.empty()) return 0;
	         int m = matrix.size();
	         int n = matrix.front().size();
	         int result = 0;
	         vector<int> height(n,0);
	         for(int i=0;i<m;++i){
	             for(int j=0;j<n;++j){
	                 if(matrix[i][j]=='0'){
	                     height[j] = 0;
	                 }else{
	                     height[j]++;
	                 }
	             }
	             result = max(result,solve(height));
	         }
	         return result;
	     } 
	     int solve(vector<int> &height){    //求直方图围成的最大矩阵
	         int result = 0;
	         stack<int> s;
	         for(auto v : height){
	             int count = 1;
	             while(!s.empty() && s.top()>v){ //比之前的小
	                 result = max(result,s.top()*count);
	                 ++count;
	                 s.pop();
	             }
	             for(int i=0;i<count;++i)
	                 s.push(v); 
	         }
	         int count = 1;
	         while (!s.empty()){
	             result = max(result,s.top()*count);
	             ++count;
	             s.pop();
	         }
	         return result;
	     }
	 };
## 51.Remove Duplicates From Sorted List ##
删除重复的元素，重复的只留一个（pre,cur）
删除重复的元素，重复的一个都不留,先添加一个无关头结点(bef,pre,cur)
## 52.Search in Rotated Sorted Array ##
带重复的

	 class Solution {
	 public:
		 bool search(int A[], int n, int target) {
			 int left = 0,right = n-1;
			 while(left<=right){
				 while(left<right&&A[left]==A[left+1]) ++left;
				 while(left<right&&A[right]==A[right-1]) --right;
				 int mid = (left+right)/2;
				 if(A[mid]==target) return true;
	             if(A[mid]<A[right]){     //右有序
					 if(A[mid]<target&&target<=A[right]) left = mid+1;
					 else right = mid-1;
	             }else {                   //左有序
					 if(A[mid]>target&&target>=A[left]) right = mid-1;
					 else left = mid+1;
				 }
			 }
			 return false;
		 }
	 };
## 53.Word Search ##

	Given board =
	[
	  ["ABCE"],
	  ["SFCS"],
	  ["ADEE"]
	]
	word ="ABCCED", -> return strue,
	word ="SEE", -> returns true,
	word ="ABCB", -> returns false.
dfs加回溯
## 54.Combinations ##
从1到n的数字中取k个数的所有取法。

	n = 4 and k = 2, a solution is:
	[
	  [2,4],
	  [3,4],
	  [2,3],
	  [1,2],
	  [1,3],
	  [1,4],
	]
Code：

	 class Solution {
	 public:
		 vector<vector<int>> combine(int n, int k) {
			 vector<int> path;
			 vector<vector<int>> result;
			 solve(1,n,k,result,path);
			 return result;
		 }
		 void solve(int left,int right,int k,vector<vector<int>> &result,vector<int>&path){
			 if(right-left+1<k) return;  //无法满足
			 if (k==0){
				 result.push_back(path);
			 }else if(right-left+1==k){
				 for(int i=left;i<=right;++i){
					 path.push_back(i);
				 }
				 result.push_back(path);
				 for(int i=left;i<=right;++i){
					 path.pop_back();
				 }
			 }else{
				 for(int i=left;i<=right-k+1;++i){
					 path.push_back(i);
					 solve(i+1,right,k-1,result,path);
					 path.pop_back();
				 }
			 }
		 }
	 };
## 55.Minimum Window Substring ##
求S中包含T所有字符的最小窗口

	S ="ADOBECODEBANC"
	T ="ABC"
	Minimum window is"BANC".
尺取法
Code：

	 class Solution {
	 public:
		 string minWindow(string S, string T) {
			 string result;
			 map<char,int> TM,SM;
			 for (auto c : T) TM[c]++;
			 int count = 0,left = 0;
			 for (int right=0;right<S.size();++right){
				 if (TM[S[right]]!=0){
					 SM[S[right]]++;
					 if (SM[S[right]]<=TM[S[right]]) ++count;
					 while (count==T.size()){
						 if(result.empty()||result.size()>right-left+1){
							 result = S.substr(left,right-left+1);
						 }
						 if (TM[S[left]]){
							 SM[S[left]]--;
							 if (SM[S[left]]<TM[S[left]]) count--;				 
						 }
						 ++left;
					 }
				 }
			 }
			 return result;
		 }
	 };
## 56.Search a 2d Matrix ##

	class Solution {
	public:
	    bool searchMatrix(vector<vector<int>> &matrix, int target) {
	        if(matrix.empty()) return false;
	        int m = 0;
	        int n = matrix.front().size()-1;
	        while(m<matrix.size()&&n>=0){
	            if(matrix[m][n]==target){
	                return true;
	            }else if(matrix[m][n]>target){  //往左走
	                --n;
	            }else{		//往下走
	                ++m;
	            }
	        }
	        return false;
	    }
	};
## 57.Set Matrix Zeroes ##
若一个元素为0，则所在行和列都置为0

	 class Solution {
	 public:
		 void setZeroes(vector<vector<int> > &matrix) {
			 if(matrix.empty()) return;
			 int m = matrix.size();
			 int n = matrix.front().size();
			 bool right = false,down = false;
			 for(int i=0;i<m;++i){
				 for(int j=0;j<n;++j){
					 if(matrix[i][j]==0){
						 if (j==0) down = true;
						 if (i==0) right = true;
						 matrix[i][0] = 0;
						 matrix[0][j] = 0;
					 }
				 }
			 }
			 for(int i=1;i<m;++i){
				 if(matrix[i][0]==0){
					 fill_n(matrix[i].begin(),n,0);
				 }
			 }
			 for(int i=1;i<n;++i){
				 if(matrix[0][i]==0){
					 for (int j=1;j<m;++j)
						matrix[j][i] = 0;
				 }
			 }
	         //第一行第一列特殊处理
			 if (right) fill_n(matrix[0].begin(),n,0);
			 if(down) {
				 for (int j=1;j<m;++j)
					 matrix[j][0] = 0;
			 }
		 }
	 };
## 58.Edit Distance ##
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
You have the following 3 operations permitted on a word:
a) Insert a character
b) Delete a character
c) Replace a character

	class Solution {
	public:
	    int minDistance(string word1, string word2) {
	        int m = word1.size(),n = word2.size();
	        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
	        for(int i=0;i<=n;++i)
	            dp[0][i] = i;
	        for(int i=0;i<=m;++i)
	            dp[i][0] = i;
	        for(int i=1;i<=m;++i){
	            for(int j=1;j<=n;++j){
	                if(word1[i-1]==word2[j-1]){
	                    dp[i][j] = dp[i-1][j-1];
	                }else{
	                    dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
	                }
	            }
	        }
	        return dp[m][n];
	    }
	};
## 59.Simplify Path ##
path ="/home/", =>"/home"
path ="/a/./b/../../c/", =>"/c"

	 class Solution {
	 public:
		 string simplifyPath(string path) {
			 vector<string> str = split(path,'/');
			 stack<string> s;
			 for (int i=0;i<str.size();++i){
				 if (str[i].empty()||str[i]==".") continue;
				 else if (str[i]==".."){
					 if (!s.empty()){
						 s.pop();
					 }
				 }else{
					 s.push(str[i]);
				 }
			 }
			 string result;
			 while (!s.empty()){
				 result = "/"+s.top()+result;
				 s.pop();
			 }
			 return result.empty()?"/":result;
		 }
		 vector<string> split(string s,char c)
		 {
			 vector<string> str;
			 s = s+"//";
			 int pre = 0;
			 for (int i=0;i<s.size();++i){
				 if (s[i]=='/'){
					 str.push_back(s.substr(pre,i-pre));
					 pre = i+1;
				 }
			 }
			 return str;
		 }
	 };
## 60.Climbling Stairs ##
	class Solution {
	public:
	    int climbStairs(int n) {
	        if(n<1) return 0;
	        if(n==1||n==2) return n;
	        int x = 1,y = 2;
	        int result = 0;
	        for(int i=3;i<=n;++i){
	            result = x+y;
	            x = y;
	            y = result;
	        }
	        return result;
	    }
	};
## 61.Sqrtx ##
牛顿迭代法

	 class Solution {
	 public:
		 int sqrt(int x) {
			 if(x==0) return 0;
			 double x0=x,x1;
			 do 
			 {
				 x1 = x0;
				 x0 = (x/x0+x0)/2;
			 } while (abs(x0-x1)>0.1);
			 return x0;
		 }
	 };
## wildcard-matching ##
Implement wildcard pattern matching with support for'?'and'*'.   

**Example:** 

	isMatch("ab", "?*") → true  
	isMatch("aab", "c*a*b") → false

**Code:**

	class Solution {
	public:
		bool isMatch(const char *s, const char *p) {
			int sLen = strlen(s),sIndex = 0;
			int pLen = strlen(p),pIndex = 0;
			int ppre = 0,ipre = 0;
			bool flag = false;
			while (sIndex<sLen) {
				if (s[sIndex]==p[pIndex] || p[pIndex]=='?'){
					++sIndex,++pIndex;
				}else if (p[pIndex]=='*'){    //跳过并记录*后面开始匹配的索引
					ppre = ++pIndex;
					ipre = sIndex;            //记录s中开始与*后面匹配的索引
					flag = true;
				}else{
					if (flag){                //无法匹配，在出现*情况下用*弥补
						sIndex = ++ipre;
						pIndex = ppre;
					}else{
						return false;
					}
				}
			}
			while (p[pIndex]=='*') {          //将剩余的*匹配掉
				++pIndex;
			}
			return pIndex==pLen&&sIndex==sLen;
		}
	};

## Multiply Strings ##
Given two numbers represented as strings, return multiplication of the numbers as a string.

**Code:**

	class Solution {
	public:
		string multiply(string num1, string num2) {
			int carry = 0;
			string result(num1.size()+num2.size(),'0');  //结果存放
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
			while (i<result.size()&&result[i]=='0') ++i;   //从第一位非0值开始
			return i==result.size()?"0":result.substr(i);  //如果全为0，返回"0"
		}
	};

## Count and Say ##
The count-and-say sequence is the sequence of integers beginning as follows:

    1, 11, 21, 1211, 111221, ...  
Given an integer n, generate the nth sequence.

**Code:**

	class Solution {
	public:
	    string countAndSay(int n) {
	        string result = "1";
	        for(int i=1;i<n;++i){
	            int count = 1;
	            char pre = result[0];
	            string temp;
	            for(int j=1;j<result.size();++j){
	                if(result[j]!=pre){
	                    temp = temp + to_string(count) + to_string(pre-'0');
	                    count = 1;
	                    pre = result[j];
	                }else{
	                    ++count;
	                }
	            }
	            if(count) temp = temp + to_string(count) + to_string(pre-'0');
	            result = temp;
	        }
	        return result;
	    }
	};

## Sudoku Solver ##
Write a program to solve a Sudoku puzzle by filling the empty cells.  
Empty cells are indicated by the character '.'.  

![](http://i.imgur.com/qM0iZ5o.png) 　　　　　　　　![](http://i.imgur.com/c6yPCPd.png)  
**Code:**    
  
	class Solution {
	public:
	    void solveSudoku(vector<vector<char>> &board) {
	        solve(board,0,0);
	    }
	    bool solve(vector<vector<char>> &board,int i,int j){          //DFS
	        if(i==9) return true;
	        if(j==9) return solve(board,i+1,0);
	        if(board[i][j]!='.') return solve(board,i,j+1);
	        for(char c='1';c<='9';++c){
	            if(check(board,i,j,c)){
	                board[i][j] = c;
	                if(solve(board,i,j+1)) return true;
	                board[i][j] = '.';
	            }
	        }
	        return false;
	    }
	    bool check(vector<vector<char>> &board,int x,int y,char c){  //判断是否可以填入
	        for(int i=0;i<9;++i){
	            if(board[x][i]==c || board[i][y]==c) return false;
	        }
	        int row = x - x%3,col = y - y%3;
	        for(int i=0;i<3;++i){
	            for(int j=0;j<3;++j){
	                if(board[row+i][col+j]==c) return false;
	            }
	        }
	        return true;
	    }
	};

## Valid Sudoku ##
判断一个数独是否有效，行，列，9个子矩阵
## Search Insert Position ##
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.  
**Code:**      
   
	class Solution {
	public:
	    int searchInsert(int A[], int n, int target) {
	        int left = 0,right = n-1;
	        while(left<right){
	            int mid = (left+right)/2;
	            if(A[mid]==target) return mid;
	            else if(A[mid]>target) right = mid;
	            else left = mid+1;
	        }
	        if(right==-1) return 0;
	        if(A[left]<target) return left+1;
	        return left;
	    }
	};

## Search for a Range ##
Given a sorted array of integers, find the starting and ending position of a given target value.   
If the target is not found in the array, return [-1, -1].   
**Example:**

	[5, 7, 7, 8, 8, 10] ,8
	[3, 4]
**Code:** 

	class Solution {
	public:
		vector<int> searchRange(int A[], int n, int target) {
			vector<int> result(2,0);
			result[0] = searchFirst(A,n,target);
			result[1] = searchLast(A,n,target);
			return result;
		}
		int searchFirst(int A[],int n,int target){
			int left = 0,right = n-1;
			while(left<right){
				int mid = (left+right)/2;
				if(A[mid]==target) right = mid;
				else if(A[mid]>target) right = mid-1;
				else left = mid+1;
			}
	        if(n<=0 || A[left]!=target) return -1;
	        return left;
		}
		int searchLast(int A[],int n,int target){
			int left = 0,right = n-1;
			while(left<right){
				int mid = (left+right+1)/2;       //防止[2,2]死循环
				if(A[mid]==target) left = mid;
				else if(A[mid]>target) right = mid-1;
				else left = mid+1;
			}
			if(n<=0 || A[left]!=target) return -1;
	        return left;
		}
	};

## Longest Valid Parentheses ##
Given a string containing just the characters'('and')', find the length of the longest valid (well-formed) parentheses substring.  
**Example:**  

    "())"  		2
    ")()())"	4

**Code:** 


	class Solution {
	public:
	    int longestValidParentheses(string s) {
	        int result = 0,left = 0;
	        stack<int> st;
	        for(int i=0; i<s.size(); ++i){
	            if(s[i]==')'&&left){
	                while(!st.empty()){
	                    int index = st.top();
	                    st.pop();
	                    if(s[index]=='('){
	                        --left;
	                        break;
	                    }
	                }
	            }else{
	                if(s[i]=='(') ++left;
	                st.push(i);
	            }
	        }
	        int size = s.size();
	        while(!st.empty()){            //计算最大区间
	            result = max(result,size-st.top()-1);
	            size = st.top();
	            st.pop();
	        }
	        result = max(result,size);  
	        return result;
	    }
	};

## Substring with Concatenation of All Words
You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

**Example:**

	s: "barfoothefoobarman"
	words: ["foo", "bar"]
	return the indices: [0,9].
**Code:**  

	class Solution {
	public:
	    vector<int> findSubstring(string s, vector<string> &words) {
	        vector<int> index;
	        map<string,int> record;
	        for(auto word : words)
	            record[word]++;
	        int size = words.size(),len = words.front().size();
	        for(int i=0;i<=(int)s.size()-size*len;++i){
	            map<string,int> seen;
	            int n = 0;
	            while(n < size){
	                string word = s.substr(i+n*len,len);
	                seen[word]++;
	                if(seen[word]>record[word])
	                    break;
	                ++n;
	            }
	            if(n==size) index.push_back(i);
	        }
	        return index;
	    }
	};

## KMP


	vector<int> generateNext(const string &s)
	{
		vector<int> next(s.size(),-1);           //第一位为标记位
		for (int i = 0,j = -1; i < s.size()-1;)
		{
			if (j==-1||s[i]==s[j])				//j为第一个未匹配上标志
				next[++i] = ++j;
			else
				j = next[j];
		}
		return next;
	}
	
	int kmp(const string &s1,const string &s2)
	{
		vector<int> next = generateNext(s2);
		int i=0,j=0;
		int size1 = s1.size();
		int size2 = s2.size();
		while(i<size1&&j<size2)
		{
			if (j==-1||s1[i]==s2[j]) //第一个未匹配上或字串相匹
			{
				++i,++j;
			}
			else
			{
				j = next[j];
			}
		}
		return j==size2?i-j:-1;
	}

## Reverse Nodes in k-Group

**Example:**

		linked list: 1->2->3->4->5
		For k = 2, you should return: 2->1->4->3->5
		For k = 3, you should return: 3->2->1->4->5
**Code:**

	class Solution {
	public:
	    ListNode *reverseKGroup(ListNode *head, int k) {
	        ListNode node(0);
	        node.next = head;
	        ListNode *cur = node.next;
	        ListNode *pre = &node;
	        while(cur){
	            int count = 0;
	            ListNode *p = nullptr, *q = nullptr;
	            while(count<k){
	                if(cur==nullptr) break;
	                if(count==0) p = cur;
	                if(count==k-1) q = cur;
	                ++count;
	                cur = cur->next;
	            }
	            if(count==k){
	                q->next = nullptr;
	                reverse(p);
	                p->next = cur;
	                pre->next = q;
	                pre = p;
	            }
	        }
	        return node.next;
	    }
	    ListNode *reverse(ListNode *head){
	        ListNode *pre = nullptr;
	        ListNode *next = nullptr;
	        while(head){
	            next = head->next;
	            head->next = pre;
	            pre = head;
	            head = next;
	        }
	        return pre;
	    }
	};


## Merge k Sorted Lists
	class Solution {
	public:
	    ListNode *mergeKLists(vector<ListNode *> &lists) {
	        return merge(lists,0,lists.size()-1);
	    }
	    ListNode *merge(vector<ListNode *> &list,int left,int right){
	        if(left>right) return nullptr;
	        if(left==right) return list[left];
	        int mid = (left+right)/2;
	        ListNode *p = merge(list,left,mid);
	        ListNode *q = merge(list,mid+1,right);
	        ListNode node(0);
	        ListNode *cur = &node;
	        while(q&&p){
	            if(p->val < q->val){
	                cur->next = p;
	                p = p->next;
	            }else{
	                cur->next = q;
	                q = q->next;
	            }
	            cur = cur->next;
	        }
	        if(p) cur->next = p;
	        if(q) cur->next = q;
	        return node.next;
	    }
	};

## Generate Parentheses
**Example:**
 given n = 3, a solution set is:
 
	[
	  "((()))",
	  "(()())",
	  "(())()",
	  "()(())",
	  "()()()"
	]

**Code:**

	class Solution {
	public:
	    vector<string> generateParenthesis(int n) {
	        vector<string> result;
	        solve(result,"",n,n);
	        return result;
	    }
	    void solve(vector<string> &result,string s,int remainLeft,int remainRight){
	        if(remainLeft==0 && remainRight==0){
	            result.push_back(s);
	        }
	        if(remainLeft){
	            solve(result,s+"(",remainLeft-1,remainRight);
	        }
	        if(remainRight && remainLeft<remainRight){
	            solve(result,s+")",remainLeft,remainRight-1);
	        }
	    }
	};

## Regular Expression Matching
Implement regular expression matching with support for '.' and '*'.
**'.'** Matches any single character.
'*' Matches zero or more of the preceding element.
**Examples:**

	isMatch("aa","a") → false
	isMatch("aa","aa") → true
	isMatch("aaa","aa") → false
	isMatch("aa", "a*") → true
	isMatch("aa", ".*") → true
	isMatch("ab", ".*") → true
	isMatch("aab", "c*a*b") → true

**code:**

	class Solution {
	public:
	    bool isMatch(string s, string p) {
	        return solve(s,p,0,0);
	    }
	    bool solve(string s,string p,int si,int pi){
	        if (pi==p.size()){
	            return si==s.size();
	        }
	        if (p[pi+1]!='*'){
	            return (p[pi]==s[si]||(p[pi]=='.'&&si<s.size()))&&solve(s,p,si+1,pi+1);
	        }
	        while (p[pi]==s[si]||(p[pi]=='.'&&si<s.size())){
	            if (solve(s,p,si,pi+2)){
	                return true;
	            }
	            ++si;
	        }
	        return solve(s,p,si,pi+2);
	    }
	};
	
## Longest Palindromic Substring(最长回文字串)
**code:**

	class Solution {
	public:
		string longestPalindrome(string s) {
			string str = init(s);
			vector<int> p = getP(str);
			int index = 0;
			int len = 1;
			for(int i=1;i<p.size();++i){
				if(p[i]>len){
					index = i;
					len = p[i];
				}
			}
			index = (index-len+2)/2-1;
			return s.substr(index,len-1);
		}
		string init(string s){
			string str = "#";
			for(auto c : s){
				str = str + c +"#";
			}
			return "$"+str+"&";
		}
		vector<int> getP(string str){
			vector<int> p(str.size(),1);
			int boundary = 0;
			int currentCenter = 0;
			for(int i=1;i<str.size()-1;++i){
				if(boundary>i){
					p[i] = min(p[2*currentCenter-i],boundary-i);
				}
				while(str[i-p[i]]==str[i+p[i]]) ++p[i];
				if(i+p[i]>boundary){
					boundary = i+p[i];
					currentCenter = i;
				}
			}
			return p;
		}
	};

## Two Sum ##
**Example:**

	Input: numbers={2, 7, 11, 15}, target=9
	Output: index1=1, index2=2
**Code:**
	
	class Solution {
	public:
		vector<int> twoSum(vector<int> &numbers, int target) {
			unordered_map<int,int> hash;
			vector<int> result;
			for(int i=0;i<numbers.size();++i){
				int value = target - numbers[i];
				if(hash.find(value)!=hash.end()){
					result.push_back(hash[value]);
					result.push_back(i+1);
					return result;
				}
				hash[numbers[i]] = i+1;
			}
			return result;
		}
	};