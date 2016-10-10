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
	 *
	 * Definition for singly-linked list.
	 * struct ListNode {
	 *     int val;
	 *     ListNode *next;
	 *     ListNode(int x) : val(x), next(NULL) {}
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
无重复

	 class Solution {
	 public:
		 int search(int A[], int n, int target) {
			 int left = 0,right = n-1;
			 while(left<=right){
				 int mid = (left+right)/2;
				 if(A[mid]==target) return mid;
				 if(A[mid]<A[right])     //右有序
				 {
					 if(A[mid]<target&&target<=A[right]) left = mid+1;
					 else right = mid-1;
				 }
				 else                    //左有序
				 {
					 if(A[mid]>target&&target>=A[left]) right = mid-1;
					 else left = mid+1;
				 }
			 }
			 return -1;
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
## 62.Valid Number ##
	"0"=>true
	" 0.1 "=>true
	"abc"=>false
	"1 a"=>false
	"2e10"=>true
**Code:**

	 class Solution {
	 public:
		 bool isNumber(const char *s) {
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
			 while(*s!='\0'){
				 if (isspace(*s)){
					 input = SPACE;
				 }else if (*s=='+'||*s=='-'){
					 input = SIGN;
				 }else if(*s=='.'){
					 input = DOT;
				 }else if(*s=='e'){
					 input = E;
				 }else if(isdigit(*s)){
					 input = DIGIT;
				 }else{
					 input = INVALID;
				 }
				 state = trans[state][input];
				 if (state==-1){
					 return false;
				 }
	             ++s;
			 }
			 return state==1||state==4||state==7||state==8;
		 }
	 };
## 63.Add Binary ##
	a ="11"
	b ="1"
	Return"100".

**Code:**

	class Solution {
	public:
		string addBinary(string a, string b) {
			int aIndex = a.size()-1;
			int bIndex = b.size()-1;
			int carry = 0;
			string result;
			while(bIndex>=0&&aIndex>=0){
				int sum = a[aIndex]-'0'+b[bIndex]-'0'+carry;
				result = (char)(sum%2+'0')+result;
				carry = sum/2;
				--aIndex,--bIndex;
			}
			while (bIndex>=0){
				int sum = b[bIndex]-'0' + carry;
				result = (char)(sum%2+'0')+result;
				carry = sum/2;
				--bIndex;
			}
			while (aIndex>=0){
				int sum = a[aIndex]-'0' + carry;
				result = (char)(sum%2+'0')+result;
				carry = sum/2;
				--aIndex;
			}
			if(carry) result = "1"+result;
			return result;
		}
	};

## 64.Merge Two Sorted Lists ##
	class Solution {
	public:
	    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
	        ListNode head(0);
	        ListNode *p = &head;
	        while(l1&&l2){
	            if(l1->val < l2->val){
	                p->next = l1;
	                l1 = l1->next;
	            }else{
	                p->next = l2;
	                l2 = l2->next;
	            }
	            p = p->next;
	        }
	        if(l1) p->next = l1;
	        if(l2) p->next = l2;
	        return head.next;
	    }
	};
## 65.Minimum Path Sum ##
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
**Note:** You can only move either down or right at any point in time.

	class Solution {
	public:
	    int minPathSum(vector<vector<int> > &grid) {
	        if(grid.empty()) return 0;
	        int n = grid.front().size();
	        vector<int> dp(n);
	        dp[0] = grid[0][0];
	        for(int i=1;i<n;++i){
	            dp[i] = dp[i-1]+grid[0][i];
	        }
	        for(int i=1;i<grid.size();++i){
	            for(int j=0;j<n;++j){
	                if(j==0) dp[j] += grid[i][j];
	                else{
	                    dp[j] = min(dp[j],dp[j-1])+grid[i][j];
	                }
	            }
	        }
	        return dp[n-1];
	    }
	};
## 66.Unique Paths ##
![](http://i.imgur.com/wb5IPnE.png)
**无障碍**

	class Solution {
	public:
	    int uniquePaths(int m, int n) {
	        if(n<1||m<1) return 0;
	        vector<int> dp(n,1);
	        for(int i=1;i<m;++i){
	            for(int j=1;j<n;++j){
	                dp[j] += dp[j-1];
	            }
	        }
	        return dp[n-1];
	    }
	};

**有障碍**

	class Solution {
	public:
	    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
	        if(obstacleGrid.empty()) return 0;
	        int m = obstacleGrid.size();
	        int n = obstacleGrid.front().size();
	        vector<int> dp(n,0);
	        dp[0] = 1;
	        for(int i=0;i<m;++i){
	            for(int j=0;j<n;++j){
	                if(obstacleGrid[i][j]==1){
	                    dp[j] = 0;
	                }else if(j>0){
	                    dp[j] += dp[j-1];
	                }
	            }
	        }
	        return dp[n-1];
	    }
	};
## 67.Rotate List ##
Given1->2->3->4->5->NULLand k =2,
return4->5->1->2->3->NULL.

	class Solution {
	public:
	    ListNode *rotateRight(ListNode *head, int k) {
	        if(head==nullptr||head->next==nullptr) return head;
	        int size = 0;
	        for(ListNode *p=head;p;p=p->next){
	            ++size;
	        }
	        k = k%size;
	        if(k==0) return head;
	        ListNode *slow = head,*fast = head;
	        for(int i=0;i<k;++i) fast = fast->next;
	        while(fast->next){
	            slow = slow->next;
	            fast = fast->next;
	        }
	        ListNode* pNode = slow->next;
	        fast->next = head;
	        slow->next = nullptr;
	        return pNode;
	    }
	};
## 68.Permutation Sequence ##
获取第k个全排列，n[1,9]

	 class Solution {
	 public:
		 string getPermutation(int n, int k) {
			 if(n<1||k<1) return "";
			 string s;
			 for(int i=1;i<=n;++i) s += to_string(i);
	         vector<int> x(n,1);
	         for(int i=2;i<n;++i){     //N!
	             x[i] = x[i-1]*i;
	         }  
	         --k;     //第一次不用算
			 for (int i=1;i<n;++i) {
				 int index = i-1+k/x[n-i];
	             char c = s[index];
	             for(int j=index;j>=i;--j){//调整
	                 s[j] = s[j-1];
	             }
	             k %= x[n-i];
	             s[i-1] = c;
			 }
			 return s;
		 }
	 };
## 69.Spiral Matrix ##
填充矩阵

	 class Solution {
	 public:
		 vector<vector<int> > generateMatrix(int n) {
			 vector<vector<int>> m(n,vector<int>(n));
			 int dx[] = {0,1,0,-1};
			 int dy[] = {1,0,-1,0};
			 int x = n, y = n,num = 1,dir = 0;
			 int px = 0,py = -1;
			 while(num<=n*n){
				 if(dir&1){
					 for(int i=0;i<y;++i){
						 px += dx[dir];
						 py += dy[dir];
						 m[px][py] = num++;
					 }
					 --x;
				 }else{
					 for(int i=0;i<x;++i){
						 px += dx[dir];
						 py += dy[dir];
						 m[px][py] = num++;
					 }
					 --y;
				 }
				 dir = (dir+1)%4;
			 }
			 return m;
		 }
	 };

螺旋打印

	class Solution {
	public:
	    vector<int> spiralOrder(vector<vector<int> > &matrix) {
	        vector<int> result;
	        if(matrix.empty()) return result;
	        int y = matrix.size(),x = matrix.front().size();
	        int dx[] = {0,1,0,-1};
	        int dy[] = {1,0,-1,0};
	        int num = 1,dir = 0;
	        int px = 0,py = -1;
	        int size =x*y;
	        while(result.size()<size){
	            if(dir&1){
	                for(int i=0;i<y;++i){
	                    px += dx[dir];
	                    py += dy[dir];
	                    result.push_back(matrix[px][py]);
	                }
	                --x;
	            }else{
	                for(int i=0;i<x;++i){
	                    px += dx[dir];
	                    py += dy[dir];
	                    result.push_back(matrix[px][py]);
	                }
	                --y;
	            }
	            dir = (dir+1)%4;
	        }
	        return result;
	    }  
	};
## 70.Lenght of Last Word ##
求由' '分隔的字符串中最后一个单词的长度，没有返回0

	class Solution {
	public:
		int lengthOfLastWord(const char *s) {
			int len = 0,pre = 0,cur = 0;
			while(s[cur]!='\0'){
				if(s[cur]==' '){
					if (cur-pre){
						len = cur-pre;
					}
					pre = cur+1;
				}
				++cur;
			}
			if (cur-pre){
				len = cur-pre;
			}
			return len;
		}
	};
## 71.Insert Interval ##
有序区间插入合并

	class Solution {
	public:
	    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
	        vector<Interval> result;
	        int index = 0;
	        bool isInsert = false;
	        for(index=0;index<intervals.size();++index){
	            if(isInsert){
	                if(result.back().end<intervals[index].start){
	                    result.push_back(intervals[index]);
					}else{
	                    result.back().end = max(result.back().end,intervals[index].end);
	                }
	            }else{
	                if(intervals[index].end<newInterval.start){
	                    result.push_back(intervals[index]);
	                }else if(intervals[index].start>newInterval.end){
	                    result.push_back(newInterval);
	                    result.push_back(intervals[index]);
	                    isInsert = true;
	                }else{
	                    Interval temp = intervals[index];
	                    temp.start = min(temp.start,newInterval.start);
	                    temp.end = max(temp.end,newInterval.end);
	                    result.push_back(temp);
	                    isInsert = true;
	                }
	            }
	        }
	        if(!isInsert) result.push_back(newInterval);
	        return result;
	    }
	};

## 72.Merge Intervals ##
Given[1,3],[2,6],[8,10],[15,18],
return[1,6],[8,10],[15,18].

	class Comp{
	  public:
	    bool operator()(const Interval& a,const Interval& b)const{
	        if(a.start < b.start) return true;
	        else if(a.start==b.start) return a.end<b.end;
	        return false;
	    }
	};
	class Solution {
	public:
	    vector<Interval> merge(vector<Interval> &intervals) {
	        vector<Interval> result;
	        if(intervals.empty()) return result;
	        sort(intervals.begin(),intervals.end(),Comp());
	        Interval temp = intervals.front();
	        for(int i=1;i<intervals.size();++i){
	            if(intervals[i].start<=temp.end){
					temp.end = max(temp.end,intervals[i].end);
				}else{
					result.push_back(temp);
					temp = intervals[i];
				}
	        }
			result.push_back(temp);
			return result;
	    }
	};
## 73.Jump Game ##
判断是否可以到达
For example:
A =[2,3,1,1,4], return true.
A =[3,2,1,0,4], return false.

	class Solution {
	public:
	    bool canJump(int A[], int n) {
	        int i = 0,index = 0;
	        while(i<=index){
	            index = max(index,i+A[i]);
	            if(index >= n-1) return true;
	            ++i;
	        }
	        return false;
	    }
	};
计算到达最后索引所需的最小步数

	class Solution {
	public:
	    int jump(int A[], int n) {
	        int step = 0,maxIndex = 0,nextIndex = 0;
			for (int i=0;i<n-1;++i) {
				if (i>maxIndex){
					maxIndex = nextIndex;
					++step;
				}
				nextIndex = max(nextIndex,A[i]+i);
				if(nextIndex>=n-1) return step+1;
			}
			return step;
	    }
	};

## 74.Maximum Subarray ##
	class Solution {
	public:
	    int maxSubArray(int A[], int n) {
	        int sum = 0,result = INT_MIN;
	        for(int i=0;i<n;++i){
	            if(sum<=0){
	                sum = A[i];
	            }else{
	                sum += A[i];
	            }
	            result = max(result,sum);
	        }
	        return result;
	    }
	};
## 75.Pow x-n ##

	class Solution {
	public:
		double pow(double x, int n) {
			double result = 1.0;
			long long p = n;
			if(n<0){
				x = 1.0/x;
				p = -p;
			}
			while(p){
				if(p&1) result *= x;
				x = x*x;
				p = p>>1;
			}
			return result;
		}
	};
## 76.N Queens ##
![](http://i.imgur.com/l2Ffb2D.png)
**所有方案**

	class Solution {
	public:
		vector<vector<string> > solveNQueens(int n) {
			if(n<1) return vector<vector<string>>();
			vector<vector<int>> solves;
			vector<vector<string>> result;
			vector<int> rows(n,-1);       //每行对应的列索引
			solve(solves,0,n,rows);
			fillQueens(solves,result,n);
			return result;
		}
	    //dfs 每次填充一行
		void solve(vector<vector<int>> &solves,int row,int n,vector<int> &rows){
			if(row==n) {
				solves.push_back(rows);
				return;
			}
			for(int j=0;j<n;++j){     //列
				rows[row] = j;
				if(check(rows,row,j)){
					solve(solves,row+1,n,rows);
				}
				rows[row] = -1;
			} 
		}
		bool check(vector<int> &rows,int row,int col){           //check摆放是否可以
			for(int i=row-1;i>=0;i--){
				if(rows[i]==col||abs(col-rows[i])==row-i){   //垂直与对角线
					return false;
				}
			}
			return true;
		}
		void fillQueens(vector<vector<int>>& solves,vector<vector<string>>& result,int n){
			for(int i=0;i<solves.size();++i){
				vector<string> board(n,string(n,'.'));
				for(int j=0;j<n;++j){
					board[j][solves[i][j]] = 'Q';
				}
				result.push_back(board);
			}
		}
	};

**方案数**

	class Solution {
	public:
		int totalNQueens(int n) {
			if(n<1) return 0;
			count = 0;
			vector<int> rows(n,-1);       //每行对应的列索引
			solve(0,n,rows);
			return count;
		}
		void solve(int row,int n,vector<int> &rows){
			if(row==n) {
				++count;
				return;
			}
			for(int j=0;j<n;++j){     //列
				rows[row] = j;
				if(check(rows,row,j)){
					solve(row+1,n,rows);
				}
				rows[row] = -1;
			} 
		}
		bool check(vector<int> &rows,int row,int col){           //check摆放是否可以
			for(int i=row-1;i>=0;i--){
				if(rows[i]==col||abs(col-rows[i])==row-i){   //垂直与对角线
					return false;
				}
			}
			return true;
		}
	private:
		int count;
	};
## 77.Anagrams ##
"abc","bca","bac"

	class Solution {
	public:
	    vector<string> anagrams(vector<string> &strs) {
	        map<string,vector<int>> record;
	        vector<string> result;
	        for(int i=0;i<strs.size();++i){
	            string key = strs[i];
	            sort(key.begin(),key.end());
	            record[key].push_back(i);
	        }
	        for(auto p : record){
	            if(p.second.size()>1){
	                for(auto i : p.second){
	                    result.push_back(strs[i]);
	                }
	            }
	        }
	        return result;
	    }
	};
## 78.Rotate Image ##
You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).

	class Solution {
	public:
	    void rotate(vector<vector<int> > &matrix) {
	        if(matrix.empty()) return;
	        int n = matrix.size();
	    	for(int i=0;i<n/2;++i){
	            int m = n/2;
	            if(n&1) ++m;
	            for(int j=0;j<m;++j){
	                int x=i,y=j;
	                int var = matrix[i][j];
	                for(int k=0;k<4;++k){
	                    int temp = x;
	                    x = y,y=n-temp-1;
	                    swap(var,matrix[x][y]);
	                }
	            }
	        }
	    }
	};
## 79.Permutations ##
	class Solution {
	public:
	    vector<vector<int> > permuteUnique(vector<int> &num) {
	        vector<vector<int>> result;
	        sort(num.begin(),num.end());
	        result.push_back(num);
	        while(!permutation(num))
	            result.push_back(num);
	        return result;
	    }
	    bool permutation(vector<int> &num){
	        int i = num.size()-1;
	        while(i>0 && num[i]<=num[i-1]) --i;
	        if(i==0) return true;
	        int j = num.size()-1;
	        while(num[j]<=num[i-1]) --j;
	        swap(num[j],num[i-1]);
	        reverse(num.begin()+i,num.end());
	        return false;
	    }
	};
## 80.wildcard-matching ##
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

## 81.Multiply Strings ##
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
## 82.Trapping Rain Water ##
![](http://i.imgur.com/LktQEBY.png)

	class Solution {
	public:
	    int trap(int A[], int n) {
	        int maxIndex = 0;
	        for(int i=1;i<n;++i){
	            if(A[i]>A[maxIndex]) maxIndex = i;
	        }
	        int water = 0,left = 0,right = 0;
	        for(int i=0;i<maxIndex;++i){
	            if(left<A[i]) left = A[i];
	            else water += left-A[i];
	        }
	        for(int i=n-1;i>maxIndex;--i){
	            if(right<A[i]) right = A[i];
	            else water += right-A[i];
	        }
	        return water;
	    }
	};
## 83.First Missing Positive ##
Given[1,2,0]return 3,
and[3,4,-1,1]return 2.

将数字移到相应的位置使之有序，再找到不符合的第一个数（由于可以有重复值，所以无法异或求取）

	class Solution {
	public:
	    int firstMissingPositive(int A[], int n) {
	        int index = 0;
	        while(index<n){
	            if(A[index]>0&&A[index]<n&&A[A[index]-1]!=A[index]){
	                swap(A[index],A[A[index]-1]);
	            }else{
	                ++index;
	            }
	        }
	        index = 0;
	        while(index<n && A[index]==index+1){
	            ++index;
	        }
	        return index+1;
	    }
	};
## 84.Combination Sum ##
给定正整数集合（无重复值），找到所有和为target的组合

	class Solution {
	public:
	  vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		  sort(candidates.begin(),candidates.end());
		  vector<int> combine;
		  vector<vector<int>> result;
		  solve(combine,result,candidates,0,target,0);
		  return result;
	  }
	  void solve(vector<int> &combine,vector<vector<int>> &result,vector<int> &candidates,int sum,int target,int index){
		  if(sum==target){
			  result.push_back(combine);
			  return ;
		  }else{
			  for(int i=index;i<candidates.size();++i){
				  if(sum+candidates[i]<=target){
					  combine.push_back(candidates[i]);
					  solve(combine,result,candidates,sum+candidates[i],target,i); //i表示同一个数可以多次取
					  combine.pop_back();
				  }
			  }
		  }
	  }
	};

给定正整数集合（有重复值），找到所有和为target的组合

	class Solution {
	public:
	  vector<vector<int> > combinationSum2(vector<int> &num, int target) {
		  sort(num.begin(),num.end());
		  vector<int> combine;
		  vector<vector<int>> result;
		  solve(combine,result,num,0,target,0);
		  return result;
	  }
	  void solve(vector<int> &combine,vector<vector<int>> &result,vector<int> &candidates,int sum,int target,int index){
		  if(sum==target){
			  result.push_back(combine);
			  return ;
		  }else{
			  for(int i=index;i<candidates.size();++i){
				  if(sum+candidates[i]<=target){
					  if(i==index || candidates[i]!=candidates[i-1]){
						  combine.push_back(candidates[i]);
						  solve(combine,result,candidates,sum+candidates[i],target,i+1);
						  combine.pop_back();
					  } //第一次可以，第二次有重复
				  }
			  }
		  }
	  }
	};
## 85.Count and Say ##
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

## 86.Sudoku Solver ##
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
	            if(board[x][i]==c || board[i][y]==c) return false;//水平&垂直
	        }
	        int row = x - x%3,col = y - y%3;	//所在矩形块
	        for(int i=0;i<3;++i){
	            for(int j=0;j<3;++j){
	                if(board[row+i][col+j]==c) return false;
	            }
	        }
	        return true;
	    }
	};

**Valid Sudoku**
判断一个数独是否有效，行，列，9个子矩阵
## 87.Longest Valid Parentheses ##
在仅含有'('和')'的字符串中求最长的有效括号匹配。
For"(()", the longest valid parentheses substring is"()", which has length = 2.
")()())", where the longest valid parentheses substring is"()()", which has length = 4.

	class Solution {
	public:
	    int longestValidParentheses(string s) {
	        int result = 0,left = 0;    //left表示左边是否有剩余的'('
	        stack<int> st;      		//记录索引
	        for(int i=0; i<s.size(); ++i){
	            if(s[i]==')'&&left){
	                while(s[st.top()]!='('){
	                    st.pop();
	                }
	                st.pop();
	                --left;
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
## 88.Next Permutation ##
	class Solution {
	public:
	    void nextPermutation(vector<int> &num) {
	        if(num.size()<=1) return;
	        int i = num.size()-1;
	        while(i>0 && num[i]<=num[i-1]) --i;
	        if(i==0) {                           //5,4,3,2,1
	            reverse(num.begin(),num.end());
	        }else{
	            int j = num.size()-1;
	            while(num[j]<=num[i-1]) --j;
	            swap(num[j],num[i-1]);
	            reverse(num.begin()+i,num.end());
	        }
	    }
	};
## 89.Substring with Concatenation of all Words ##
You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.
For example, given:
S:"barfoothefoobarman"
L:["foo", "bar"]
You should return the indices:[0,9].

	class Solution {
	public:
	    vector<int> findSubstring(string S, vector<string> &L) {
	        vector<int> index;
	        map<string,int> record;
	        for(auto word : L)
	            record[word]++;
	        int size = L.size(),len = L.front().size();
	        for(int i=0;i<=(int)S.size()-size*len;++i){
	            map<string,int> seen;
	            int n = 0;
	            while(n < size){ //小于单词集合数
	                string word = S.substr(i+n*len,len);
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
## 90.Divide Two Integers ##
不用乘法

	class Solution {
	public:
		int divide(int dividend, int divisor) {
			if(divisor==0 || (dividend==INT_MIN&&divisor==-1))
				return INT_MAX;
			int sign = ((dividend<0)^(divisor<0))?-1:1;
			long long a = dividend;
			long long b = divisor;
			a = a>0?a:-a;
			b = b>0?b:-b;
			long long result = 0;
			while(a>=b){
				int count = 1;
				long long d = b;
				while(a>=(d<<1)){
					count <<= 1;
					d <<= 1;
				}
				a -= d;
				result += count;
			}
			return sign==1?result:-result;
		}
	};

## 91.KMP
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

## 92.Reverse Nodes in k-Group

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
## 93.Swap Nodes in Pairs ##
Given1->2->3->4, you should return the list as2->1->4->3.

	class Solution {
	public:
	    ListNode *swapPairs(ListNode *head) {
	        ListNode node(0);
	        node.next = head;
	        ListNode *cur = &node;
	        while(cur && cur->next &&cur->next->next){
	            ListNode *next = cur->next->next->next;
	            ListNode *p = cur->next;
	            ListNode *q = cur->next->next;
	            cur->next = q;
	            q->next = p;
	            p->next = next;
	            cur = p;
	        }
	        return node.next;
	    }
	};
## 94.Merge k Sorted Lists
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
## 95.Generate Parentheses
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
## 96.Valid Parentheses ##
()"and"()[]{}"are all valid but"(]"and"([)]"are not.

	class Solution {
	public:
	    bool isValid(string s) {
	        stack<char> st;
	        map<char,char> hash;
	        hash[')'] = '(';
	        hash[']'] = '[';
	        hash['}'] = '{';
	        for(auto c : s){
	            if(c=='(' || c=='{' || c=='['){
	                st.push(c);
	            }else if(c==')'||c==']'||c=='}'){
	                if(!st.empty() && st.top()==hash[c]){
	                    st.pop();
	                }else{
	                    return false;
	                }
	            }
	        }
	        return st.empty();
	    }
	};
## 97.Search Insert Position ##
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

## 98.Search for a Range ##
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

## 99.Remove Nth Node from End of List ##
删除倒数第N个节点

	class Solution {
	public:
	    ListNode *removeNthFromEnd(ListNode *head, int n) {
	        if(head==nullptr || n<1) return head;
	        ListNode *p = head;
	        for(int i=1;i<n;++i){
	            p = p->next;
	            if(p==nullptr) return head;
	        }
	        ListNode node(0);
	        node.next = head;
	        ListNode *cur = &node;
	        while(p->next){
	            p = p->next;
	            cur = cur->next;
	        }
	        ListNode *temp = cur->next;
	        cur->next = cur->next->next;
	        delete temp;
	        return node.next;
	    }
	};
## 100.Letter Combinations of a Phone Number ##
![](http://i.imgur.com/KquTcME.png)

	string s[10] = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	class Solution {
	public:
		vector<string> letterCombinations(string digits) {
			vector<string> result;
			solve(digits,result,"",0);
			return result;
		}
		void solve(string digits,vector<string> &result,string str,int index){
	        if(index == digits.size()) {
	            result.push_back(str);
	            return;
	        }
			string combine = s[digits[index]-'0'];
			for(int i=0;i<combine.size();++i){
				solve(digits,result,str+combine[i],index+1);
			}
		}
	};

## 101.3Sum ##
a + b + c = 0

	class Solution {
	public:
		vector<vector<int> > threeSum(vector<int> &num) {
			vector<vector<int>> result;
			sort(num.begin(),num.end());
			for(int i=0;i<num.size();++i){
				if(i>0 && num[i]==num[i-1]) continue;
				int j = i+1,k = num.size()-1;
				while(j<k){
					if(num[i]+num[j]+num[k]>0){
						--k;
					}else if(num[i]+num[j]+num[k]<0){
						++j;
					}else{
						vector<int> res;
						res.push_back(num[i]);
						res.push_back(num[j]);
						res.push_back(num[k]);
						result.push_back(res);
						do {
							++j;
						} while (j<k && num[j]==num[j-1]);
						do {
							--k;
						} while (j<k && num[k]==num[k+1]);
					}
				}
			}
			return result;
		}
	};
**3Sum Closest**
Find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers.

	class Solution {
	public:
	    int threeSumClosest(vector<int> &num, int target) {
	        sort(num.begin(),num.end());
	        int result = num[0]+num[1]+num[3];
	        for(int i=0;i<num.size();++i){
	            int j = i+1,k = num.size()-1;
	            while(j<k){
	                if( abs(result-target) > abs(num[i]+num[j]+num[k]-target) ){
	                    result = num[i]+num[j]+num[k];
	                }
	                if(num[i]+num[j]+num[k]>target){
	                    --k;
	                }else if(num[i]+num[j]+num[k]<target){
	                    ++j;
	                }else{
	                    return target;
	                }
	            }
	        }
	        return result;
	    }
	};

**4Sum**

	class Solution {
	public:
		vector<vector<int> > fourSum(vector<int> &num, int target) {
			vector<vector<int>> result;
			if(num.size()<4) return result;
			set<vector<int>> res_set;
			sort(num.begin(),num.end());
			for(int i=0;i<num.size();++i){
				for(int j=i+1;j<num.size();++j){
					int left = j+1,right = num.size()-1;
					int remain = target-num[i]-num[j];
					while(left<right){
						if(num[left]+num[right]==remain){
							vector<int> res;
							res.push_back(num[i]);
							res.push_back(num[j]);
							res.push_back(num[left]);
							res.push_back(num[right]);
							res_set.insert(res);
							++left,--right;
						}else if(num[left]+num[right]>remain){
							--right;
						}else{
							++left;
						}
					}
				}
			}
			result.insert(result.begin(),res_set.begin(),res_set.end());
			return result;
		}
	};
## 102.Longest Common Prefix ##
字符串数组的最长公共前缀

	class Solution {
	public:
		string longestCommonPrefix(vector<string> &strs) {
			if (strs.empty()){
				return "";
			}
			string prefix = strs.front();
			int size = prefix.size();
			for(int i=1;i<strs.size();++i){
				size = min(size,(int)strs[i].size());
				string s = strs[i];
				for(int j=0;j<size;++j){
					if(prefix[j] != s[j]){
						size = j;
						break;
					}
				}
			}
			return prefix.substr(0,size);
		}
	};
## 103.Container with Most Water ##
	class Solution {
	public:
	    int maxArea(vector<int> &height) {
	        int result = 0;
	        int left=0,right=height.size()-1;
	        while(left<right){
	            int h = min(height[left],height[right]);
	            result = max(result,h*(right-left));
	            while(left<right && height[left]<=h) ++left;
	            while(left<right && height[right]<=h) --right;
	        }
	        return result;
	    }
	};
## 104.Regular Expression Matching
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
## 105.Palindrome Number ##
	class Solution {
	public:
	    bool isPalindrome(int x) {
	        if(x<0||(x!=0&&x%10==0)) return false;
	        int y = 0;
	        while(x>y){
	            y = y*10+x%10;
	            x /= 10;
	        }
	        return x==y||(y/10==x);
	    }
	};
## 106.String to Integer atoi ##

	class Solution {
	public:
	    int atoi(const char *str) {
	        long result = 0;
	        int sign = 1;
	        while(*str!='\0'&&*str==' ') ++str;
	       	if(*str=='-'){
	            sign = -1;
	        }
	        if(*str=='-'||*str=='+') ++str;
	        while(*str!='\0'){
	            if(*str<='9'&&*str>='0'){
	                result = result*10+(*str-'0');
	                if(result*sign>=INT_MAX||result*sign<=INT_MIN){
	                    return sign==1?INT_MAX:INT_MIN;
	                }
	            }else{
	                break;
	            }
	            ++str;
	        }
	        return result*sign;
	    }
	};
## 107.Reverse Integer ##
	class Solution {
	public:
	    int reverse(int x) {
	        long var = 0, n = x;
	        int sign = 1;
	        if(n<0){
	            n = -n;
	            sign = -1;
	        }
	        while(n){
	            var = var*10 + n%10;
	            n /= 10;
	        }
	        if(var*sign>=INT_MAX || var*sign<=INT_MIN){
	            return 0;
	        }
	        return var*sign;
	    }
	};
## 108.Zigzag Conversion ##
The string"PAYPALISHIRING"is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

	P   A   H   N
	A P L S I I G
	Y   I   R
And then read line by line:"PAHNAPLSIIGYIR"

	class Solution {
	public:
	    string convert(string s, int nRows){
	        if(nRows == 1) return s;
	        vector<string> result(nRows);
	        int i = 0;
	        while (i<s.size()){
	            for (int j=0;j<nRows&&i<s.size();++j) {
	                result[j] += s[i++];
	            }
	            for (int j=nRows-2;j>0&&i<s.size();--j) {
	                result[j] += s[i++];
	            }
	        }
	        string str;
	        for (int i=0;i<nRows;++i) {
	            str += result[i];
	        }
	        return str;
		}
	};
## 109.Longest Palindromic Substring(最长回文字串)
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

## 110.Two Sum ##
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

## 111.Longest Substring without Repeating Characters ##
	class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			vector<int> record(26,0);
			int left = 0;
			int maxLen = 0;
			for(int i=0;i<s.size();++i){
				int index = s[i]-'a';
				++record[index];
				if(record[index]==1){
					maxLen = max(maxLen,i-left+1);
				} else{
					while(record[index]>1){
						--record[s[left++]-'a'];
					}
				}
			}
			return maxLen;
		}
	};
## 112.Median of Two Sorted Arrays ##
	class Solution {
	public:
		double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
			int size = nums1.size()+nums2.size(); 
			if (size%2==1){
				return findKth(nums1,nums2,0,0,size/2+1);
			}else{
				return ((double)findKth(nums1,nums2,0,0,size/2)+findKth(nums1,nums2,0,0,size/2+1))/2;
			}
		}
		int findKth(vector<int>& v1,vector<int>& v2,int s1,int s2,int k)
		{
			int m = v1.size()-s1;
			int n = v2.size()-s2;
			if (m>n){
				return findKth(v2,v1,s2,s1,k);
			}
			if (m==0){
				return v2[s2+k-1];
			}
			if (k==1){
				return min(v1[s1],v2[s2]);
			}
			int s1_num = min(k/2,m);
			int s2_num = k-s1_num;
			if (v1[s1+s1_num-1] > v2[s2+s2_num-1]){
				return findKth(v1,v2,s1,s2+s2_num,k-s2_num);
			}else if (v1[s1+s1_num-1] < v2[s2+s2_num-1]){
				return findKth(v1,v2,s1+s1_num,s2,k-s1_num);
			}else{
				return v1[s1+s1_num-1];
			}
		}
	};
## 113.Add Two Numbers ##
**Input:** (2 -> 4 -> 3) + (5 -> 6 -> 4)
**Output:** 7 -> 0 -> 8

	class Solution {
	public:
	    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
	        ListNode head(0);
	        ListNode *p = &head;
	        int carry = 0;
	        while(l1||l2||carry){
	            int v1 = l1?l1->val:0;
	            int v2 = l2?l2->val:0;
	            int sum = carry+v1+v2;
	            p->next = new ListNode(sum%10);
	            p = p->next;
	            l1 = l1?l1->next:l1;
	            l2 = l2?l2->next:l2;
	            carry = sum/10;
	        }
	        return head.next;
	    }
	};
## 114.数组中找唯一重复元素 ##
[1,n]范围的元素放入大小为n+1的数组中，其中有一个重复值，找出该重复值
1. 位图法
2. 求和取差法
3. 异或法


	int duplicateValue(vector<int> vec){ 
		int result = 0;
		for (auto e : vec) {     //A^A^B
			result ^= e;
		}
		for (int i=1;i<vec.size();++i) {     //(A^B)^(A^A^B) = A
			result ^= i;
		}
		return result;
	}
## 115.Maximum Gap ##
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
Try to solve it in linear time/space.
Return 0 if the array contains less than 2 elements.

	class Solution {
	public:
		int maximumGap(vector<int>& nums) {
			int size = nums.size();
			if (size<2) return 0;
			int maxV = *max_element(nums.begin(),nums.end());
			int minV = *min_element(nums.begin(),nums.end());
			if (maxV==minV) return 0;
			double slotGap = (double)(maxV-minV)/(size-1);
			vector<int> slotMax(size,INT_MIN);
			vector<int> slotMin(size,INT_MAX);
			for (auto v : nums) {
				int index = (v-minV)/slotGap;
				slotMin[index] = min(v,slotMin[index]);
				slotMax[index] = max(v,slotMax[index]);
			}
			int maxGap = INT_MIN,pre = minV;
			for (int i=0;i<size;++i) {       //最大gap肯定在槽之间
				if (slotMax[i]==INT_MIN) continue;
				maxGap = max(maxGap,slotMin[i]-pre);
				pre = slotMax[i];
			}
			return maxGap;
		}
	};

## 116.Maximum Product Subarray ##
Given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.

	class Solution {
	public:
		int maxProduct(vector<int>& nums) {
			int result = INT_MIN;
			int rmin_pre = nums[0],rmin_next;
			int rmax_pre = nums[0],rmax_next;
			result = max(result,rmax_pre);
			for(int i=1;i<nums.size();++i){
				rmax_next = max(max(rmax_pre*nums[i],rmin_pre*nums[i]),nums[i]);
				rmin_next = min(min(rmax_pre*nums[i],rmin_pre*nums[i]),nums[i]);
				result = max(result,rmax_next);
				rmin_pre = rmin_next;
				rmax_pre = rmax_next;
			}
			return result;
		}
	};

## 117.Find Minimum in Rotated Sorted Array ##
旋转有序数组中的最小值

	class Solution {
	public:
		int findMin(vector<int>& nums) {
			int left=0,right=nums.size()-1;
			int mid;
			while(left<right){
				mid = (left+right)/2;
				if (nums[mid]>nums[right]){
					left = mid+1;
				}else{
					right = mid;
				}
			}
			return nums[right];
		}
	};

带重复元素
	
	class Solution {
	public:
		int findMin(vector<int>& nums) {
			int left=0,right=nums.size()-1;
			int mid;
			while(left<right){
				while(left<right&&nums[left]==nums[left+1])
					++left;
				while(left<right&&nums[right]==nums[right-1])
					--right;
				mid = (left+right)/2;
				if (nums[mid]>nums[right]){
					left = mid+1;
				}else{
					right = mid;
				}
			}
			return nums[right];
		}
	};

## 118.Excel Sheet Column Title ##
	    1 -> A
	    2 -> B
	    3 -> C
	    ...
	    26 -> Z
	    27 -> AA
	    28 -> AB 
Code：

	class Solution {
	public:
		string convertToTitle(int n) {
			string result;
			while (n){
				--n;
				result = (char)(n%26+'A')+result;
				n /= 26;
			}
			return result;
		}
	};

反过来：

	class Solution {
	public:
		int titleToNumber(string s) {
			int result=0;
			for (char c:s){
				result = result*26+(c-'A'+1);
			}
			return result;
		}
	};

## 119.Majority Element ##
The majority element is the element that appears more than ⌊ n/2 ⌋ times.

	class Solution {
	public:
		int majorityElement(vector<int>& nums) {
			int result;
			int count=0;
			for(int i=0;i<nums.size();++i) {
				if (count==0){
					result = nums[i];
					++count;
				} else if (result==nums[i]) {
					++count;
				} else {
					--count;
				}
			}
			return result;
		}
	};

## 120.Fraction to Recurring Decimal ##
Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".

	class Solution {
	public:
		string fractionToDecimal(int numerator, int denominator) {
			if (numerator==0) return "0";
			string result;
			if (numerator<0 ^ denominator<0)
				result += "-";
			long long num = numerator,den = denominator;
			num = num<0?-num:num;
			den = den<0?-den:den;
			result += to_string(num/den);  //整数部分
			num = num%den;            
			if (num) result += ".";
			map<int,int> record;
			int index = 0;
			while (num) {               //小数部分
				if (record.count(num)){
					result.insert(result.begin()+record[num],'(');
					result += ")";
					break;
				}else{
					record[num] = result.size();
					num *= 10;
					result += (char)(num/den+'0');
					num = num%den;
				}
			}
			return result;
		}
	};

## 121.Factorial Trailing Zeroes ##
N!阶乘尾部0的个数

	 class Solution {
	 public:
		 int trailingZeroes(int n) {
			 int zeroes = 0;
			 while(n){
			 	zeroes += n/5;
			 	n /= 5;
			 }
			 return zeroes;
		 }
	 };

## 122.数组调整 ##

	[7,6,5,4,3,2,1] return 
	[1,7,2,6,3,5,4]
要求：时间复杂度O(n),空间复杂度O（1）

	void solve(vector<int> &v)
	{
		for (auto &e : v){   //用新增的一位表示是否被替换过
			e = e<<1;
		}
		int storedIndex = v.size()-1,storedValue = v.back();
		int index = storedIndex,count = v.size();
		while (count--) {
			if (index&1) { //奇，直接用index/2索引所对应的值替换
				v[index] = v[index/2]|1;
				index /= 2;
			}else {        //偶，从后往前找第index/2+1个数替换
				int newIndex = v.size()-(1+index/2);
				if (newIndex==storedIndex){
					v[index] = storedValue|1;  //打上标记
					while (storedIndex>=0 && v[storedIndex]&1 ){ //更新storedIndex
						--storedIndex;
					}
					index = storedIndex;
					if (storedIndex>=0){ //如果还有未替换的值
						storedValue = v[storedIndex];
					}
				}else{
					v[index] = v[newIndex]|1; //打上标记
					index = newIndex;
				}
			}
		}
		for (auto &e : v) {  //恢复，去除标记位
			e = e>>1;
		}
	}

## 123.Binary Search Tree Iterator ##
next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

	class BSTIterator {
	public:
	    BSTIterator(TreeNode *root) {
	       store(root);
	    }
	    bool hasNext() {
	        return !s.empty();
	    }
	    int next() {
	        TreeNode *node = s.top();
	        s.pop();
	        int result = node->val;
	        store(node->right);
	        return result;
	    }
	private:
	    stack<TreeNode*> s;
	    void store(TreeNode *node){
	         while(node){
	            s.push(node);
	            node = node->left;
	        }
	    }
	};

## 124.Dungeon Game ##
![](http://i.imgur.com/s1KUaHh.png)
地牢救公主                                                                                                           

	class Solution {
	public:
		int calculateMinimumHP(vector<vector<int>>& dungeon) {
			int size = dungeon.front().size();
			vector<int> hp(size+1,INT_MAX);  //到达目的所需的最小生命值
			hp[size-1] = 1;
			for (int i=dungeon.size()-1;i>=0;--i) {
				for (int j=size-1;j>=0;--j) {
					hp[j] = max(1,min(hp[j],hp[j+1])-dungeon[i][j]);
				}
			}
			return hp[0];
		}
	};

## 125.Largest Number ##
For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

	bool compare(string &s1,string &s2){
	    return s1+s2>s2+s1;
	}
	class Solution {
	public:
	    string largestNumber(vector<int>& nums) {
	        vector<string> number;
	        for(int i=0;i<nums.size();++i){
	            number.push_back(to_string(nums[i]));
	        }
	        sort(number.begin(),number.end(),compare);
	        string result;
	        for(int i=0;i<number.size();++i){
	            result += number[i];
	        }
	        return result[0]=='0'?"0":result;
	    }
	};

## 126.Repeated DNA Sequences ##
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
For example,

	Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
	Return:
	["AAAAACCCCC", "CCCCCAAAAA"].

Code:

	class Solution {
	public:
		vector<string> findRepeatedDnaSequences(string s) {
			vector<string> result;
			map<string,int> record;
			int size = s.length();
			for (int i=0;i<size-9;++i){
				if (record.count(s.substr(i,10))==0){
					record.insert(make_pair(s.substr(i,10),1));
				}else{
					record[s.substr(i,10)]++;
				}
			}
			for (auto v : record){
				if (v.second>1){
					result.push_back(v.first);
				}
			}
			return result;
		}
	};

## 127.Reverse Bits ##
00000010100101000001111010011100
00111001011110000010100101000000

	class Solution {
	public:
		uint32_t reverseBits(uint32_t n) {
			uint32_t result = 0;
			for (int i=0;i<32;++i){
				if (n&1){
					result |= 1<<(31-i);
				}
				n = n>>1;
			}
			return result;
		}
	};

## 128.Number of 1 Bits ##
Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.

	class Solution {
	public:
	    int hammingWeight(uint32_t n) {
	        int result = 0;
	        while(n){
	            ++result;
	            n &= n-1;
	        }
	        return result;
	    }
	};

## 129.House Robber ##
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

	class Solution {
	public:
	    int rob(vector<int>& nums) {
	        int preTake = 0, preNTake = 0;
	        for(auto n : nums){
	            int money = preTake;
	            preTake = preNTake + n;  //只能在前面没偷的基础上进行
	            preNTake = max(money,preNTake);
	        }
	        return max(preTake,preNTake);
	    }
	};

带环的

	class Solution {
	public:
	    int rob(vector<int>& nums) {
	        if(nums.size()==1) return nums[0];
	        int preTake1 = 0,preNTake1 = 0;
	        for(int i=0;i<(int)(nums.size()-1);++i){
	            int take = preTake1;
	            preTake1 = preNTake1+nums[i];
	            preNTake1 = max(preNTake1,take);
	        }
	        int preTake2 = 0,preNTake2 = 0;
	        for(int i=1;i<nums.size();++i){
	            int take = preTake2;
	            preTake2 = preNTake2+nums[i];
	            preNTake2 = max(preNTake2,take);
	        }
	        return max(max(preTake1,preNTake1),max(preTake2,preNTake2));
	    }
	};
## 130.Bitwise AND of Numbers Range ##
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
For example, given the range [5, 7], you should return 4.

	class Solution {
	public:
		int rangeBitwiseAnd(int m, int n) {
			int step = 0;
			while(m!=n){
			    m >>= 1;
			    n >>= 1;
			    ++step;
			}
			return m<<step;
		}
	};

## 131.Happy Number ##
A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number


\\(1^2 + 9^2 = 82\\)
\\(8^2 + 2^2 = 68\\)
\\(6^2 + 8^2 = 100\\)
\\(1^2 + 0^2 + 0^2 = 1\\)

	class Solution {
	public:
	    bool isHappy(int n) {  //快慢指针的思想
	        int slow = n,fast = squareSum(n);
	        while(slow!=fast){
	            slow = squareSum(slow);
	            fast = squareSum(squareSum(fast));
	        }
	        return slow==1?true:false;
	    }
	private:
	    int squareSum(int n){
	        int sum = 0;
	        while(n){
	            sum += pow(n%10,2);
	            n /= 10;
	        }
	        return sum;
	    }
	};

## 132.Count Primes ##
Count the number of prime numbers less than a non-negative number, n.
埃式筛选法

	class Solution {
	public:
	    int countPrimes(int n) {
	        vector<bool> arr(n,true);
	        int result = 0;
	        for(int i=2;i<n;++i){
	            if(arr[i]){
	                ++result;
	                for(int j=2*i;j<n;j+=i){
	                    arr[j] = false;
	                }
	            }
	        }
	        return result;
	    }
	};
## 133.Course Schedule ##
There are a total of n courses you have to take, labeled from 0 to n - 1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
For example:

	2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

	2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

类似于编译依赖的问题，也可以用入度出度来做

	class Solution {
	public:
		bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
			vector<set<int>> course(numCourses,set<int>());
			vector<bool> visited(numCourses,false);
			for(int i=0;i<prerequisites.size();++i){
				course[prerequisites[i].first].insert(prerequisites[i].second);
			}
			for(int i=0;i<numCourses;++i){
				if(isLoop(course,i,visited)){
					return false;
				}
			}
			return true;
		}
	private:
		bool isLoop(vector<set<int>> &course,int x,vector<bool> &visited){
			if (visited[x]){
				return true;
			}
			visited[x] = true;
			for (auto i : course[x]) {
				if (isLoop(course,i,visited))
				{
					visited[x] = false;
					return true;
				}
			}
			visited[x] = false;
			return false;
		}
	};

**Course Schedule II**
获取上课的顺序表

	class Solution {
	public:
		vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
			vector<int> result,degree(numCourses,0);
			vector<set<int>> graph(numCourses,set<int>());
			for(int i=0;i<prerequisites.size();++i){
				if (!graph[prerequisites[i].second].count(prerequisites[i].first)){
					graph[prerequisites[i].second].insert(prerequisites[i].first);
					degree[prerequisites[i].first]++;
				}
			}
			int preSize = 0;
			while(result.size()<numCourses){
				for(int i=0;i<numCourses;++i){
					if(degree[i]==0){
						result.push_back(i);
						degree[i] = -1;
						for(auto c : graph[i]){
							degree[c]--;
						}
					}
				}
				if (preSize==result.size()){
					return vector<int>();
				}
				preSize = result.size();
			}
			return result;
		}
	};
## 134.Kth Largest Element in an Array ##

	class Solution {
	public:
	    int findKthLargest(vector<int>& nums, int k) {
	        return solve(nums,0,nums.size()-1,k);
	    }
	    int solve(vector<int> &nums,int left,int right,int k){
	        int v = nums[left];
	        int i = left;
	        for(int j=i+1;j<=right;++j){
	            if(nums[j]>v){
	                swap(nums[++i],nums[j]);
	            }
	        }
	        swap(nums[left],nums[i]);
	        int count = i-left+1;
	        if(count==k) {
	            return nums[i];
	        }else if(count<k){
	            return solve(nums,i+1,right,k-count);
	        }else{
	            return solve(nums,left,i-1,k);
	        }
	    }
	};

## 135.Contains Duplicate ##

Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.

	class Solution {
	public:
		bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
			set<int> window;
			for (int i=0;i<nums.size();++i) {
				if (i>k){
					window.erase(nums[i-k-1]);
				}
				auto it = window.lower_bound(nums[i]-t);
				if (it!=window.end() && abs(*it - nums[i])<=t){
					return true;
				}
				window.insert(nums[i]);
			}
			return false;
		}
	};

## 136.Verify Preorder Serialization of a Binary Tree ##
	"9,3,4,#,#,1,#,#,2,#,6,#,#"
Return true

	"1,#"
Return false

	class Solution {
	public:
		bool isValidSerialization(string preorder) {
			stack<char> st;
			for (int i=preorder.size()-1;i>=0;--i){
				if(preorder[i]==','){
					continue;
				}else if(preorder[i]=='#'){
					st.push('#');
				}else{
					while (i>0&&preorder[i-1]!=','&&preorder[i-1]!='#'){//数字可能不止一位
						--i;
					}
					if(st.size()>=2){
						st.pop();
					}else{
						return false;
					}
				}
			}
			return st.size()==1;
		}
	};

## 137. Count Complete Tree Nodes ##

Given a complete binary tree, count the number of nodes.

	class Solution {
	public:
	    int countNodes(TreeNode* root) {
	        if(!root) return 0;
	        int leftHeight = 0,rightHeight = 0;
	        TreeNode *left = root,*right = root;
	        while(left){
	            ++leftHeight;
	            left = left->left;
	        }
	        while(right){
	            ++rightHeight;
	            right = right->right;
	        }
	        if(leftHeight==rightHeight) return pow(2,leftHeight)-1;
	        return countNodes(root->left)+countNodes(root->right)+1;
	    }
	};

## 138.Number of Digit One ##
	class Solution {
	public:
	    int countDigitOne(int n) {
	        if(n<=0) return 0;
	        long long count = 0;
	        long long d = 1;
	        while(n/d){
	            long long left = n/(d*10);
	            long long cur = n/d-left*10;
	            long long right = n%d;
	            if(cur==0){
	                count += left*d;
	            }else if(cur==1){
	                count += left*d+right+1;
	            }else{
	                count += (left+1)*d;
	            }
	            d *= 10;
	        }
	        return count;
	    }
	};

## 139.Palindrome Linked List ##
Given a singly linked list, determine if it is a palindrome.

	class Solution {
	public: 
	    bool isPalindrome(ListNode *head) {
	        left = head;
			return check(head);
	    }
		bool check(ListNode *right){
			if (right==nullptr){
				return true;
			}
			bool result = check(right->next)&&(right->val==left->val);
			left = left->next;
			return result;
		}
	private:
		ListNode *left;
	};

## 140.Basic Calculator II ##
	"3+2*2" = 7
	" 3/2 " = 1
	" 3+5 / 2 " = 5

Code：

	 class Solution {
	 public:
		 int calculate(string s) {
			 istringstream is('+'+s+'+');
			 char op;
			 int result=0,n,prevalue=0;
			 while (is>>op){
				 if (op=='+'||op=='-'){
					 result+=prevalue;
					 is>>prevalue;
					 prevalue *= （op=='+')?1:-1;
				 }else{
					 is>>n;
					 prevalue = (op=='*'?)prevalue*n:prevalue/n;
				 }
			 }
			 return result;
		 }
	 };

## 141.Lowest Common Ancestor of a Binary Tree ##
**BST：**

	class Solution {
	public:
	    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
			if(root->val<p->val&&root->val<q->val){
				return lowestCommonAncestor(root->right,p,q);
			}else if(root->val>q->val&&root->val>p->val){
				return lowestCommonAncestor(root->left,p,q);
			}
			return root;
	    }
	};

**普通二叉树：**

	class Solution {
	public:
	    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	        if(root==nullptr||root==p||root==q) return root;
	        TreeNode *left = lowestCommonAncestor(root->left,p,q);
	        TreeNode *right = lowestCommonAncestor(root->right,p,q);
	        if(left&&right) return root;
	        return left==nullptr?right:left;
	    }
	};

## 142.Sliding Window Maximum ##

Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

	Window position                Max
	---------------               -----
	[1  3  -1] -3  5  3  6  7       3
	 1 [3  -1  -3] 5  3  6  7       3
	 1  3 [-1  -3  5] 3  6  7       5
	 1  3  -1 [-3  5  3] 6  7       5
	 1  3  -1  -3 [5  3  6] 7       6
	 1  3  -1  -3  5 [3  6  7]      7
Therefore, return the max sliding window as [3,3,5,5,6,7].

	class Solution {
	public:
		vector<int> maxSlidingWindow(vector<int>& nums, int k) {
			vector<int> result;
			if(!(nums.size()>=k&&k>0)) return result;
			deque<int> dq;
			for(int i=0;i<k&&i<nums.size();++i){
				while(!dq.empty()&&nums[dq.back()]<=nums[i]){ //不为空，且元素<=当前元素
					dq.pop_back();
				}
				dq.push_back(i);
			}
			for(int i=k;i<nums.size();++i){
				result.push_back(nums[dq.front()]);
				while(!dq.empty()&&nums[dq.back()]<=nums[i]){
					dq.pop_back();
				}
				dq.push_back(i);
				if(i-dq.front()>=k) dq.pop_front();
			}
			result.push_back(nums[dq.front()]);
			return result;
		}
	};

## 143.Ugly Number II ##
	class Solution {
	public:
		int nthUglyNumber(int n) {
			vector<int> ugly(1,1);
			int index2 = 0,index3 = 0,index5 = 0;
			for(int i=1;i<n;++i){
				int value = min(min(ugly[index2]*2,ugly[index3]*3),ugly[index5]*5);
				ugly.push_back(value);
				if(value==ugly[index2]*2) ++index2;
				if(value==ugly[index3]*3) ++index3;
				if(value==ugly[index5]*5) ++index5;
			}
			return ugly.back();
		}
	};

## 144.Serialize and Deserialize Binary Tree ##
	class Codec {
	public:
		string serialize(TreeNode* root) {
			string str;
			serial(root,str);
			return str.substr(1);
		}
		void serial(TreeNode *root,string &s){
			if(root==nullptr) {
				s += ",#";
			}else{
				s = s + "," + to_string(root->val);
				serial(root->left,s);
				serial(root->right,s);
			}
		}
	
		TreeNode* deserialize(string data) {
			deque<string> dq;
			int pre = 0;
			for (int i=0;i<data.size();++i) {
				if (data[i]==','){
					dq.push_back(data.substr(pre,i-pre));
					pre = i+1;
				}
			}
			dq.push_back(data.substr(pre));
			return deserial(dq);
		}
		TreeNode* deserial(deque<string>& dq){
			string s = dq.front();
			dq.pop_front();
			if (s=="#"){
				return nullptr;
			}else{
				TreeNode *node = new TreeNode(stoi(s));
				node->left = deserial(dq);
				node->right = deserial(dq);
				return node;
			}
		}
	};
## 145.Different Ways to Add Parentheses ##
Input: "2-1-1".

	((2-1)-1) = 0
	(2-(1-1)) = 2
Output: [0, 2]

	class Solution {
	public:
	    vector<int> diffWaysToCompute(string input) {
	        if(record.find(input)!=record.end()) return record[input];
	        vector<int> result;
	        for(int i=0;i<input.size();++i){
	            if(input[i]=='*'||input[i]=='+'||input[i]=='-'){
	                vector<int> left = diffWaysToCompute(input.substr(0,i));
	                vector<int> right = diffWaysToCompute(input.substr(i+1));
	                for(auto v1 : left){
	                    for(auto v2 : right){
	                        int value = 0;
	                        switch(input[i]){
	                            case '*':
	                                value = v1*v2;
	                                break;
	                            case '+':
	                                value = v1+v2;
	                                break;
	                            case '-':
	                                value = v1-v2;
	                                break;
	                        }
	                        result.push_back(value);
	                    }
	                }
	            }
	        }
	        if(result.empty()) result.push_back(stoi(input));
	        record[input] = result;
	        return result;
	    }
	    
	private:
	    map<string,vector<int>> record;
	};

## 146.Range Sum Query - Mutable ##
Given nums = [1, 3, 5]

	sumRange(0, 2) -> 9
	update(1, 2)
	sumRange(0, 2) -> 8
![](http://i.imgur.com/3FjUEif.png)
Code:

	class NumArray {
	public:
		NumArray(vector<int> &nums):num(nums.size()+1,0),bit(nums.size()+1,0) {
			for(int i=0;i<nums.size();++i){
				update(i,nums[i]);
			}
		}
	
		void update(int i, int val) {
			int index = i+1,diff = val - num[i+1];
			while(index<num.size()){
				bit[index] += diff;
				index += (index&(-index)); //补末尾1
			}
			num[i+1] = val;
		}
	
		int sumRange(int i, int j) {
			return getSum(j)-getSum(i-1);
		}
	
		int getSum(int i){
			int index = i+1,sum = 0;
			while(index){
				sum += bit[index];
				index &= index-1; //去末尾1
			}
			return sum;
		}
	private:
		vector<int> num;
		vector<int> bit;
	};

## 147. Water and Jug Problem ##
You are given two jugs with capacities x and y litres. There is an infinite amount of water supply available. You need to determine whether it is possible to measure exactly z litres using these two jugs.
**Example 1:** 

	Input: x = 3, y = 5, z = 4
	Output: True
**Example 2:**

	Input: x = 2, y = 6, z = 5
	Output: False
Code:

	class Solution {
	public:
	    bool canMeasureWater(int x, int y, int z) {
	        int k = gcd(x,y);
	        if(z<=x+y&&(k==0||z%k==0))return true;//x=y=z=0
	        return false;
	    }
	    int gcd(int a,int b){
	        if(a<b) return gcd(b,a);
	        if(b==0) return a;
	        return gcd(b,a%b);
	    }
	};

## 148.Largest Divisible Subset ##
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.
If there are multiple solutions, return any subset is fine.

**Example 1:**

	nums: [1,2,3]
	Result: [1,2] (of course, [1,3] will also be ok)
**Example 2:**

	nums: [1,2,4,8]
	Result: [1,2,4,8]
Code:

	class Solution {
	public:
	    vector<int> largestDivisibleSubset(vector<int>& nums) {
	        vector<int> result;
	        if(nums.empty()) return result;
	        sort(nums.begin(),nums.end(),greater<int>());
	        vector<int> dp(nums.size(),1);
	        vector<int> parent(nums.size(),-1);
	        int index = 0;
	        for(int i=1;i<nums.size();++i){
	            for(int j=0;j<i;++j){
	                if(nums[j]%nums[i]==0){
	                    if(dp[i]<dp[j]+1){
	                        dp[i] = dp[j]+1;
	                        parent[i] = j;
	                    }
	                    if(dp[i]>dp[index]) index = i;
	                }
	            }
	        }
	        while(index!=-1){
				result.push_back(nums[index]);
				index = parent[index];
			}
	        return result;
	    }
	};

## 149.Sum of Two Integers ##
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

	class Solution {
	public:
	    int getSum(int a, int b) {
	        while(b){
	            int temp = a^b;
	            b = (a&b)<<1;
	            a = temp;
	        }
	        return a;
	    }
	};
## 150.Wiggle Subsequence ##
摇摆序列，即一大一小...
**Examples:**

	Input: [1,7,4,9,2,5]
	Output: 6
	The entire sequence is a wiggle sequence.
	
	Input: [1,17,5,10,13,15,10,5,16,8]
	Output: 7
	There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].
	
	Input: [1,2,3,4,5,6,7,8,9]
	Output: 2

Code：

	class Solution {
	public:
	    int wiggleMaxLength(vector<int>& nums) {
	        if(nums.size()<2) return nums.size();
	        int index = 1;
	        while(index<nums.size()-1&&nums[index-1]==nums[index]){
	            ++index;
	        }
	        if(nums[index]==nums[index-1]) return 1;
	        bool small = nums[index]>nums[index-1];
	        int count = 2;
	        for(int i=index+1;i<nums.size();++i){
	            if((nums[i]>nums[index]&&!small)||(nums[i]<nums[index]&&small)){
	                ++count;
	                small = !small;
	            }
	            index = i;
	        }
	        return count;
	    }
	};
## 151.Combination Sum IV ##
Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

	nums = [1, 2, 3]
	target = 4
	
	The possible combination ways are:
	(1, 1, 1, 1)
	(1, 1, 2)
	(1, 2, 1)
	(1, 3)
	(2, 1, 1)
	(2, 2)
	(3, 1)

Note that different sequences are counted as different combinations.
Therefore the output is 7.

	class Solution {
	public:
		int combinationSum4(vector<int>& nums, int target) {
			sort(nums.begin(),nums.end());
			vector<int> dp(target+1,0);
			dp[0] = 1;
			for(int i=1;i<=target;++i){
			    for(auto v : nums){
			        if(v<=i){
			            dp[i] += dp[i-v];
			        }
			    }
			}
			return dp[target];
		}
	};