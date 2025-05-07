#ifndef __PARSER_H
#define __PARSER_H

#include <iostream>
#include <vector>
#include <list>

using namespace std;

#define _VOID_SIZE 0
#define _FUNC_SIZE 0
#define _CHAR_SIZE 1
#define _INT_SIZE 4
#define _POINT_SIZE 4
#define _FLOAT_SIZE 8

extern char* yytext;
extern int yyparse();

class Symbol;
class Label; 
class SymbolTable;                                                                                                                                        
     
class quad;                                                                       
class quadArray;

class SymbolType;                                                                          
class Expression;                                                                         

typedef Symbol s;
typedef SymbolType symtyp;
typedef Expression* Exps;

extern SymbolTable* ST;                
extern SymbolTable* globalST;                                                                
extern SymbolTable* parST;                                                                  
extern s* currSymbolPtr;                                                                  
extern quadArray Q;                                                                        
extern long long int table_count;                                                          
extern bool debug_on;                                                                      
extern string loop_name;                                                                
extern vector<Label>label_table;          
extern string id;

class Label                                                                                
{
public:
    int addr;                                                                          
    list<int> nextlist; 
    string name;   

    Label(string _name, int _addr = -1);                                               
};

class Symbol 
{                                                                                          
public:
    int size;                                                                          
    int offset; 
    string name;                                                                       
    SymbolType *type;                                                                                                                                         
    SymbolTable* nested;                                                          
    string val;  
    Symbol* update(SymbolType*);                                                               
      
    Symbol (string , string t="int", SymbolType* ptr = NULL, int width = 0);                                                             
};

class SymbolType 
{                                                                                           
public:
    string type;                                                              
    int width;                                                                          
    SymbolType* arrtype;                                                               
    SymbolType(string , SymbolType* ptr = NULL, int width = 1);                         
};

class SymbolTable 
{                                                                                           
public:
    string name;                                                               
    int count;                                                                          
    list<Symbol> table;                                                                    
    SymbolTable* parent;                                                                
    
    SymbolTable (string name="NULL");                                                      
    s* lookupIdentifier (string);
    s* lookupDeclarator (string);                                                      
    void print();                                                                      
    void update();                                                                      
};

class quad 
{                                                                                            
public:
    string res;                                                                         
    string op;                                                                           
    string arg1;                                                                         
    string arg2;                                                                           
    quad (string , string , string op = "=", string arg2 = "");         
    quad (string , int , string op = "=", string arg2 = "");                
    quad (string , float , string op = "=", string arg2 = "");  
    void print();	
    void print_generic_tac();                                                                       
    void print_if_jump_tac();                                                                        
};

class quadArray 
{                                                                                            
public:
    vector<quad> Array;                                                                 
    void print();                                                                        
};

struct Expression {
    s* loc;                                                                                  
    string type;                                                                            
    list<int> truelist;                                                                  
    list<int> falselist;      
    list<int> nextlist;       
};

struct Array {
    string atype;                                                                    
    s* loc;                                                                            
    s* Array;                                                                               
    SymbolType* type;                                                                        
};

struct Statement {
    list<int> nextlist;                                                                     
};

string convertIntToString(int);                                                              
string convertFloatToString(double x);      
Expression* convertIntToBool(Exps);                                                           
int convertBoolToInt(Exps);  

void emit(string , string , string arg1="", string arg2="");  
void emit(string , string , int, string arg2="");		  
void emit(string , string , float , string arg2="");   

s* gentemp (SymbolType* , string init = "");

void backpatch (list <int> , int );                                                           
list<int> makelist (int );                                                              
list<int> merge (list<int> &l1, list <int> &l2);                                             

string printType(SymbolType *);                                                              
void generateSpaces(int);

Label* find_label(string name);                                

s* convertType(Symbol*, string);                                                 
int computeSize (SymbolType *);                                                             
void changeTable (SymbolTable* );      

bool compareSymbolType(Symbol* &s1, Symbol* &s2);                                                 
bool compareSymbolType(SymbolType*, SymbolType*);                                          

int nextinstr();                                                                             

#endif