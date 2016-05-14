#ifndef LEXER_H
#define LEXER_H
#include <iostream>
#include <string>
#include <sstream>       //int to string | string to int
#include <regex>         //regular expression
#include <memory>        //smart pointer
using namespace std;

class Token
{
public:
	Token(int line):lineNumber(line){}
	int getLineNumber(){return lineNumber;}
	virtual bool isNumber(){return false;}
	virtual bool isString(){return false;}
	virtual bool isIdentifier(){return false;}
	virtual int getNumber(){return 0;}
	virtual string getText(){return "";}
public:
	const static Token ENDOFFILE;
	const static string EOL;
private:
	int lineNumber;
};
const Token Token::ENDOFFILE(-1);
const string Token::EOL  = "\\n";

class NumToken:public Token
{
public:
	NumToken(int line,int n):Token(line),value(n){}
	bool isNumber(){return true;}
	int getNumber(){return value;};
	string getText()
	{
		stringstream ss;
		ss<<value;
		string str;
		ss>>str;
		return str;
	}
private:
	int value;
};

class IdToken:public Token
{
public:
	IdToken(int line,string id):Token(line),text(id){}
	bool isIdentifier(){return true;}
	string getText(){return text;}
private:
	string text;
};

class StrToken :public Token
{
public:
	StrToken(int line,string str):Token(line),literal(str){}
	bool isString(){return true;}
	string getText(){return literal;}
private:
	string literal;
};
#endif