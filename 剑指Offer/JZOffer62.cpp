
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    char* Serialize(TreeNode *root) {    
        if (root==NULL)
        {
            return "#,";
        }
        string s =to_string(root->val);
        s.push_back(',');
        char *left = Serialize(root->left);
        char *right = Serialize(root->right);
        char *result = new char[s.size()+strlen(left)+strlen(right)];
        strcpy(result,s.c_str());
        strcat(result,left);
        strcat(result,right);
        return result;
    }
    TreeNode* Deserialize(char *str) {
        return DeserializeHandle(&str);
    }
    TreeNode *DeserializeHandle(char **str)
    {
        if (**str=='#')
        {
            *str = *str+2;
            return NULL;
        }
        int num = 0;
        while(**str!=',')
        {
            num = num*10+(**str)-'0';
            ++(*str);
        }
        ++(*str);
        TreeNode* node = new TreeNode(num);
        node->left = DeserializeHandle(str);
        node->right = DeserializeHandle(str);
        return node;
    }
};