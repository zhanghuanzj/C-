#include "Lexer.h"
#include <fstream>
class Lexer
{
public:
	Lexer();
	void LexicalAnalysis(string s,int line);
	void showTokens();
private:
	string pSpace;      //��>=0���ո�ͷ���ַ���
	string pComment;    //ע��(2)
	string pNumber;     //����(3)
	string pLiteral;    //�����ַ���(4,5)
	string pIdentifier; //��ʶ��(6)
	string pPunc;
	string pPattern;
	regex regularExpression;
	vector<shared_ptr<Token>> tokens;
};

Lexer::Lexer()
{
	pSpace =  "\\s*";         //��>=0���ո�ͷ���ַ���
	pComment = "(//.*)";      //ע��(2)
	pNumber = "([0-9]+)";     //����(3)
	pLiteral = "(\"(\\\\\"|\\\\\\\\|\\\\n|[^\"])*\")";  //�����ַ���(4,5)
	pIdentifier = "([A-Z_a-z][A-Z_a-z0-9]*|==|<=|>=|&&|\\|\\|";
	pPunc = "[!\"#$%&'()*+,-./:;<=>?@^_`{|}~[\\]])"; 
	pIdentifier = pIdentifier+"|"+pPunc;   //��ʶ��(6)
	pPattern = pSpace+"("+pComment+"|"+pNumber+"|"+pLiteral+"|"+pIdentifier+")?";
	regularExpression = regex(pPattern);
}

void Lexer::LexicalAnalysis(string s,int line)
{
	smatch match;
	int left = 0;
	int right = s.size();
	while (left<right)
	{
		string str = s.substr(left);
		if (regex_search(str,match,regularExpression))
		{
			if (match[1].matched)
			{
				if (match[2].matched)              //Comment
				{
					cout<<"COM:"<<match[1]<<endl;
				}
				else if (match[3].matched)         //Number
				{
					cout<<"NUM:"<<match[1]<<endl;
					stringstream ss;
					ss<<match[1];
					int value;
					ss>>value;
					tokens.push_back(shared_ptr<Token>(new NumToken(line,value)));
				}
				else if (match[4].matched)         //Literal
				{
					cout<<"STR:"<<match[1]<<endl;
					tokens.push_back(shared_ptr<Token>(new StrToken(line,match[1])));
				}
				else if (match[6].matched)         //Identifier
				{
					cout<<"ID:"<<match[1]<<endl;
					tokens.push_back(shared_ptr<Token>(new IdToken(line,match[1])));
				}
			}
			left += match.length();
		}
	}
	cout<<"-----------------------------------------------------------"<<endl;
}

void Lexer::showTokens()
{
	for (auto &token : tokens)
	{
		cout<<token->getLineNumber()<<":";
		if (token->isNumber())
		{
			cout<<token->getNumber()<<endl;
		}
		else
		{
			cout<<token->getText()<<endl;
		}
	}
}

int main()
{
	//1.Lexical Analysis
	Lexer lexer;
	int line = 1;
	fstream fio = fstream("test.txt");
	fstream fio2 = fstream("out.txt");

	while (!fio.eof())
	{
		string s;
		getline(fio,s);
		++line;
		lexer.LexicalAnalysis(s,line);
	}
	lexer.showTokens();
}


