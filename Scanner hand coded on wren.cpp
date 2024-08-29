#include<iostream>
#include<fstream>
#include<ctype.h>
#include<string>
using namespace std;

enum Token { 
PROGRAM_SY, IS_SY, BEGIN_SY, END_SY, VAR_SY, INTEGER_SY, BOOLEAN_SY, READ_SY, 
WRITE_SY, IF_SY, THEN_SY, ELSE_SY, WHILE_SY, DO_SY, OR_SY, AND_SY, TRUE_SY,
FALSE_SY, NOT_SY, LPARN_SY, RPARN_SY, COMMA_SY, MINUS_SY, LOE_SY, 
LESS_SY, EQUALS_SY, GREATER_SY, GOE_SY, DNE_SY, PLUS_SY, 
MULT_SY, DIVI_SY, COLON_SY, SEMICOL_SY,
END_SOURCE_SY, NUMBER_SY, 
ID_SY, ASSIGNMENT_SY,
ERROR_SY
};

class Scanner{
	private:
		ifstream f;
	    Token check_reserved(string s){
			if      (s== "program") return PROGRAM_SY;
			else if (s== "is")return IS_SY;
			else if (s== "begin")return BEGIN_SY;
			else if (s== "end")return END_SY;
			else if (s== "var")return VAR_SY;
			else if (s== "int")return INTEGER_SY;
			else if (s== "boolean")return BOOLEAN_SY;
			else if (s== "read")return READ_SY;
			else if (s== "write")return WRITE_SY;
			else if (s== "if")return IF_SY;
			else if (s== "then")return THEN_SY;
			else if (s== "else")return ELSE_SY;
			else if (s== "while")return WHILE_SY;
			else if (s== "do")return DO_SY;
			else if (s== "or")return OR_SY;
			else if (s== "and") return AND_SY;
			else if (s== "true")return TRUE_SY;
			else if (s== "false")return FALSE_SY;
			else if (s== "not")return NOT_SY;
			else return ID_SY;
		}
//*****************************************************//
	public:
		Scanner(string filename){
		f.open(filename);
		}
//*****************************************************//
		~Scanner(void){
		f.close();
		}
//*****************************************************//
Token get_token(void){
		char ch;
		string s;
		f.get(ch);
		while (isspace(ch)) f.get(ch);
		if (f.eof()) return END_SOURCE_SY;
		else if (ch == '=')return EQUALS_SY;
		else if (ch == ',')return COMMA_SY;
		else if (ch == ';')return SEMICOL_SY;
		else if (ch == '(')return LPARN_SY;
		else if (ch == ')')return RPARN_SY;
		else if (ch == '+')return PLUS_SY;
		else if (ch == '-')return MINUS_SY;
		else if (ch == '*')return MULT_SY;
		else if (ch == '/')return DIVI_SY;

		else if (ch == ':'){
			f.get(ch);
			if (ch == '=')return ASSIGNMENT_SY;
			else{
				f.putback(ch);
				return COLON_SY;
			}
		}
		
		else if (ch == '<'){
			f.get(ch);
			if (ch == '=')return LOE_SY;
			else if (ch == '>')return DNE_SY;
			else {
				f.putback(ch);
				return LESS_SY;
			}
		}
		
		else if (ch == '>'){
			f.get(ch);
			if (ch == '=')return GOE_SY; 
			else {
				f.putback(ch);
				return GREATER_SY;
			}
		}
	
		else if (isalpha(ch)){
			s = ch; f.get(ch);
			while (isalnum(ch)) { 
				s += ch; 
				f.get(ch); 
			}
			f.putback(ch);
			return check_reserved(s);
		}
		
		else if (isdigit(ch)) {// real or integer
			s = ch; f.get(ch);
			while (isdigit(ch)){
				s += ch; 
				f.get(ch);
			}
				f.putback(ch);
				return NUMBER_SY;
		}
		
		else {return ERROR_SY;}
	}
//*****************************************************//
void display_tokens(void){
		Token t;
		if (f.eof())cout << "end_of_file " << endl;
		while (!f.eof()){
			t = get_token();
			switch (t){
				case PROGRAM_SY: cout << "program token" << endl; break;
				case IS_SY: cout << "is token" << endl; break;
				case BEGIN_SY: cout << "begin token" << endl; break;
				case END_SY: cout << "end token" << endl; break;
				case VAR_SY: cout << "var token" << endl; break;
				case ID_SY: cout << "ident token" << endl; break;
				case PLUS_SY: cout << "+ token" << endl; break;
				case MINUS_SY: cout << "- token" << endl; break;
				case MULT_SY: cout << "* token" << endl; break;
				case DIVI_SY: cout << "/ token" << endl; break;
				case LOE_SY: cout << "<= token" << endl; break;
				case LESS_SY: cout << "< token" << endl; break;
				case EQUALS_SY: cout << "= token" << endl; break;
				case GREATER_SY: cout << "> token" << endl; break;
				case GOE_SY: cout << ">= token" << endl; break;
				case DNE_SY: cout << "<> token" << endl; break;
				case NUMBER_SY: cout << "number token" << endl; break;
				case INTEGER_SY: cout << "integer token" << endl; break;
				case END_SOURCE_SY: cout << "end_of_file " << endl; break;
				case LPARN_SY: cout << "(  token" << endl; break;
				case RPARN_SY: cout << ")  token" << endl; break;
				case BOOLEAN_SY: cout << "boolean  token" << endl; break;
				case READ_SY: cout << "read token" << endl; break;
				case WRITE_SY: cout << "write token" << endl; break;
				case IF_SY: cout << "if token" << endl; break;
				case THEN_SY: cout << "then token" << endl; break;
				case ELSE_SY: cout << "else token" << endl; break;
				case DO_SY: cout << "do token" << endl; break;
				case WHILE_SY: cout << "while token" << endl; break;
				case COMMA_SY: cout << ", token" << endl; break;
				case COLON_SY: cout << ": token" << endl; break;
				case ASSIGNMENT_SY: cout << ":= token" << endl; break;
				case SEMICOL_SY: cout << "; token" << endl; break;
				case AND_SY: cout << "and token" << endl; break;
				case OR_SY: cout << "or token" << endl; break;
				case NOT_SY: cout << "not token" << endl; break;
				case TRUE_SY: cout << "true token" << endl; break;
				case FALSE_SY: cout << "false token" << endl; break;
				default : cout <<"ERROR_SY"<<endl;
			}
		}
	
	}
};




int main(){
	string Filename;
	cout << "Enter Name of input File : ";
	cin >> Filename;
	Scanner SC(Filename);
	SC.display_tokens();
	SC.~Scanner();
}
