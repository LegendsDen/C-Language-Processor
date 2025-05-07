#include "A9_220101096_translator.h"
#include <bits/stdc++.h>
using namespace std;

// Add file output stream for writing to file
ofstream outFile;                                                   

SymbolType::SymbolType(string type,SymbolType* arrtype,int width)                                 
{
    this->type = type;
    this->width = width;
    this->arrtype= arrtype;
}

Symbol::Symbol(string name, string t, SymbolType* arrtype, int width) 
{
    this->name = name;
    type = new SymbolType(t,arrtype,width);                                               
    size = computeSize(type);                                                                      
    offset = 0;                                                                                    
    val = "-";                                                                                     
    nested = NULL;                                                                                 
}

quad::quad(string res,string arg1,string op,string arg2)
{
    this->op=op;
    this->arg1=arg1;
    this->arg2=arg2;
    this->res=res;
}

quad::quad(string res,int arg1,string op,string arg2)
{   
    this->op=op;
    this->arg1=convertIntToString(arg1);
    this->arg2=arg2;
    this->res=res;    
}

quad::quad(string res,float arg1,string op,string arg2)
{
    this->op=op;
    this->arg1=convertFloatToString(arg1);
    this->arg2=arg2;
    this->res=res;
}

void quad::print() 
{
    if(op=="+" || op=="-" || op=="*" || op=="/" || op=="%" || 
       op=="|" || op=="^" || op=="&" || op=="<<" || op==">>") 
        this->print_generic_tac();
    else if(op=="==" || op=="!=" || op=="<=" || op=="<" || 
            op==">" || op==">=") 
        this->print_if_jump_tac();
    else if(op=="goto") outFile<<"goto "<<res;
    else if(op=="=") outFile<<res<<" = "<<arg1;  
    else if(op=="=&") outFile<<res<<" = &"<<arg1;
    else if(op=="=*") outFile<<res<<" = *"<<arg1;
    else if(op=="*=") outFile<<"*"<<res<<" = "<<arg1;
    else if(op=="uminus") outFile<<res<<" = -"<<arg1;
    else if(op=="~") outFile<<res<<" = ~"<<arg1;
    else if(op=="!") outFile<<res<<" = !"<<arg1;
    else if(op=="=[]") outFile<<res<<" = "<<arg1<<"["<<arg2<<"]";
    else if(op=="[]=") outFile<<res<<"["<<arg1<<"]"<<" = "<< arg2;
    else if(op=="return") outFile<<"return "<<res;
    else if(op=="param") outFile<<"param "<<res;
    else if(op=="call") outFile<<res<<" = "<<"call "<<arg1<<", "<<arg2;
    else if(op=="Label") outFile<<res<<": ";
    else if(op=="if") outFile<<"if "<<arg1<<" goto "<<res; 
    else outFile<<"Can't find the operator"<<op;      
    outFile<<endl;
}

void quad::print_generic_tac()                                                                           
{
    outFile<<res<<" = "<<arg1<<" "<<op<<" "<<arg2;    
}

void quad::print_if_jump_tac()                                                                               
{
    outFile<<"if "<<arg1<< " "<<op<<" "<<arg2<<" goto "<<res; 
}

quadArray Q;                                                                                 
SymbolTable* ST;  
bool debug_on;                                                                                     
string var_type;                                                                                   
SymbolTable* globalST;                                                                                
SymbolTable* parST;                                                                                   
Symbol* currSymbolPtr;                                                                                
long long int table_count;                                                                         
string loop_name;                                                                                  
vector<Label>label_table;
string id; 

Symbol* Symbol::update(SymbolType* t) 
{
    type=t;                                                                                       
    this->size=computeSize(t);                                                                   
    return this;                                                                                   
}

Label::Label(string _name, int _addr):name(_name),addr(_addr){}

SymbolTable::SymbolTable(string name)                                                                   
{
    this->name=name;                                                                             
    count=0;                                                                                      
}

Symbol* SymbolTable::lookupIdentifier(string name)                                                
{
    Symbol* symbol;
    list<Symbol>::iterator it;                                                                        
    it=table.begin();                                                                            
    while(it!=table.end()) 
    {
        if(it->name==name) 
            return &(*it);                                                                         
        it++;                                                                                      
    }

    Symbol *ptr = nullptr;
    if(this->parent)ptr = this->parent->lookupIdentifier(name);
    return ptr;
}

Symbol* SymbolTable::lookupDeclarator(string name)                                                
{
    Symbol *symbol = new Symbol(name);
    table.push_back(*symbol);                                                                  
    return &table.back(); 
}

void SymbolTable::update()                                                                           
{
    list<SymbolTable*> tb;                                                                           
    int off;
    list<Symbol>::iterator it;                                                                        
    it=table.begin();
    while(it!=table.end()) 
    {
        if(it==table.begin()) 
        {
            it->offset=0;                                                                           
            off=it->size;
        }
        else 
        {
            it->offset=off;
            off=it->offset+it->size;                                                                
        }
        if(it->nested!=NULL) 
            tb.push_back(it->nested);
        it++;
    }

    list<SymbolTable*>::iterator it1;                                                                  
    it1=tb.begin();
    while(it1 !=tb.end())                                                                            
    {
        (*it1)->update();
        it1++;
    }
}

void quadArray::print()                                                                               
{
    outFile<<"THREE ADDRESS CODE : "<<endl;                                                       
    for(int i=0;i<60;i++) outFile<<"**";
    outFile<<endl;    
    
    int j=0;
    vector<quad>::iterator it;                                                                        
    it=Array.begin();
    while(it!=Array.end()) 
    {
        if(it->op=="Label")                                                                     
        {
            outFile<<endl<<j<<": ";
            it->print();
        }
        else {                                                                                          
            outFile<<j<<": ";
            generateSpaces(4);
            it->print();
        }
        it++;j++;
    }
    for(int i=0;i<65;i++) outFile<<"**";                                                             
    outFile<<endl;
}

void emit(string op, string res, string arg1, string arg2) 
{
    quad *q1 = new quad(res, arg1, op, arg2);
    Q.Array.push_back(*q1);
    
    // For conditional jumps, ensure the result (jump target) is set
    if(op == "==" || op == "!=" || op == "<=" || op == "<" || op == ">" || op == ">=") {
        // If res is empty, it's a placeholder that will be filled in by backpatch
        if(res.empty()) {
            res = "0";  // Default target, will be updated by backpatch
        }
    }
}

void emit(string op, string res, int arg1, string arg2) 
{
    quad *q2= new quad(res,arg1,op,arg2);
    Q.Array.push_back(*q2);
}

void emit(string op, string res, float arg1, string arg2) 
{
    quad *q3= new quad(res,arg1,op,arg2);
    Q.Array.push_back(*q3);
}

Symbol* gentemp(SymbolType* t, string str_new) 
{                                                                                                      
    string tmp_name = "t"+convertIntToString(ST->count++);                                              
    Symbol* s = new Symbol(tmp_name);
    s->type = t;
    s->size=computeSize(t);                                                                          
    s->val = str_new;
    ST->table.push_back(*s);                                                                            
    return &ST->table.back();
}

Label* find_label(string _name){
    for(vector<Label>::iterator it=label_table.begin(); it!=label_table.end(); it++){
        if(it->name==_name)return &(*it);
    }
    return nullptr;
}

void backpatch(list<int> lst, int target) 
{
    if (lst.empty()) return;  // No instructions to backpatch
    
    string label = convertIntToString(target);
    for(int loc : lst) {
        if (loc >= 0 && loc < Q.Array.size()) {
            Q.Array[loc].res = label;
        }
    }
}

list<int> makelist(int init) 
{
    list<int> newlist(1,init);                                                                          
    return newlist;                                                                                     
}

list<int> merge(list<int> &a,list<int> &b)
{
    a.merge(b);                                                                                        
    return a;                                                                                           
}

string convertIntToString(int a)     
{
    return to_string(a);
}

string convertFloatToString(double x)                                                                    
{
    std::ostringstream buff;
    buff << x;
    return buff.str();
}
int convertBoolToInt(Expression* e)                                                           
{	
    int res = 0;
	if(e->type=="bool") 
    {
        e->loc=gentemp(new SymbolType("int"));                                                        
        backpatch(e->truelist,nextinstr());
        emit("=",e->loc->name,1);
        e->nextlist = makelist(nextinstr());
        emit("goto","");
        backpatch(e->falselist,nextinstr());
        emit("=",e->loc->name,0);
        list<int> temp = makelist(nextinstr());
        e->nextlist = merge(e->nextlist, temp);
        emit("goto","");
        res = 1;
    }
    return res;
}

Expression* convertIntToBool(Expression* e)                                                          
{
    if(e->type!="bool")                
    {
        e->falselist=makelist(nextinstr());                                                             
        emit("==", "", e->loc->name,"0");                                                                 
        e->truelist=makelist(nextinstr());                                                              
        emit("goto", "");
        e->type = "bool";
    }
    return e;
}

Symbol* convertType(Symbol* s, string rettype)                                                                
{
	Symbol* temp=gentemp(new SymbolType(rettype));	
    if(s->type->type=="float")                                                                        
    {
        if(rettype=="int")                                                                              
        {
            emit("=",temp->name,"float2int("+s->name+")");
            return temp;
        }
        else if(rettype=="char")                                                                       
        {
            emit("=",temp->name,"float2char("+s->name+")");
            return temp;
        }
        return s;
    }
    else if(s->type->type=="int")                                                                    
    {
        if(rettype=="float")                                                                          
        {
            emit("=",temp->name,"int2float("+s->name+")");
            return temp;
        }
        else if(rettype=="char")                                                                        
        {
            emit("=",temp->name,"int2char("+s->name+")");
            return temp;
        }
        return s;
    }
    else if(s->type->type=="char")                                                                   
    {
        if(rettype=="int")                                                                             
        {
            emit("=",temp->name,"char2int("+s->name+")");
            return temp;
        }
        if(rettype=="double")                                                                           
        {
            emit("=",temp->name,"char2double("+s->name+")");
            return temp;
        }
        return s;
    }
    return s;
}

void changeTable(SymbolTable* newtable)                                                                   
{
    ST = newtable;
} 

void generateSpaces(int n)                                                                              
{
    while(n--) outFile<<" ";
}

int nextinstr() 
{
    return Q.Array.size();                                                                              
}

int computeSize(SymbolType* t)                                                                          
{
    if(t->type.compare("void")==0) return _VOID_SIZE;
    else if(t->type.compare("char")==0) return _CHAR_SIZE;
    else if(t->type.compare("int")==0) return _INT_SIZE;
    else if(t->type.compare("float")==0) return _FLOAT_SIZE;
    else if(t->type.compare("ptr")==0) return _POINT_SIZE;
    else if(t->type.compare("func")==0) return _FUNC_SIZE;
    else if(t->type.compare("arr")==0) return t->width*computeSize(t->arrtype);                         
    else return -1;
}

string printType(SymbolType* t)                                                                         
{
    if(t==NULL) return "null";
    if(t->type.compare("void")==0)	return "void";
    else if(t->type.compare("char")==0) return "char";
    else if(t->type.compare("int")==0) return "int";
    else if(t->type.compare("float")==0) return "float";
    else if(t->type.compare("ptr")==0) return "ptr("+printType(t->arrtype)+")";                
    else if(t->type.compare("arr")==0) 
    {
        string str=convertIntToString(t->width);                                                        
        return "arr("+str+","+printType(t->arrtype)+")";
    }
    else if(t->type.compare("func")==0) return "func";
    else if(t->type.compare("block")==0) return "block";
    else return "NA";
}

void SymbolTable::print()                                                                               
{
    int next_instr=0;
    list<SymbolTable*> tb;                                                                               
    for(int t1=0;t1<60;t1++) outFile<<"**";                                                        
    outFile<<endl;

    outFile << "Name: " << this->name;
    generateSpaces(53-this->name.length());
    outFile << " Parent Table: ";                                                                    
    if((this->parent==NULL)) outFile<<"NULL"<<endl;                                           
    else outFile<<this->parent->name<<endl;                                                  
    for(int x=0; x<60; x++) outFile<<"__";                                                          
    outFile<<endl;
    
    outFile<<"Name";                                                                               
    generateSpaces(36);

    outFile<<"Type";                                                                                
    generateSpaces(16);

    outFile<<"Init Value";                                                                     
    generateSpaces(7);

    outFile<<"Size";                                                                                
    generateSpaces(11);

    outFile<<"Offset";                                                                              
    generateSpaces(9);

    outFile<<"Nested"<<endl;                                                                   
    generateSpaces(100);
    outFile<<endl;

    for(list<Symbol>::iterator it=table.begin(); it!=table.end(); it++) {                               
    
        outFile << it->name;                                                                      
        generateSpaces(40-it->name.length());

        string rec_type=printType(it->type);                                                          
        outFile << rec_type;
        generateSpaces(20-rec_type.length());

        outFile << it->val;                                                                         
        generateSpaces(20-it->val.length());

        outFile<<it->size;                                                                         
        generateSpaces(15-to_string(it->size).length());

        outFile<<it->offset;                                                                       
        generateSpaces(15-to_string(it->offset).length());

        if(it->nested==NULL) {                                                                       
            outFile<<"NULL"<<endl;
        }
        else {
            outFile<<it->nested->name<<endl; 
            tb.push_back(it->nested);                                                                 
        }
    }
 
    for(int i=0;i<60;i++) outFile<<"--";
    outFile<<"\n\n";
    for(list<SymbolTable*>::iterator it=tb.begin(); it !=tb.end();++it) 
    {
        (*it)->print();
    }
}

int main()
{
    // Create output file with roll number in filename
    outFile.open("220101096quads.out");
    if (!outFile.is_open()) {
        cerr << "Error: Could not open output file!" << endl;
        return 1;
    }

    label_table.clear();
    table_count = 0;                                                                                    
    debug_on= 0;                                                                                  
    globalST=new SymbolTable("Global");                                                                    
    ST=globalST;
    parST=nullptr;
    loop_name = "";

    yyparse();                                                                                         
    globalST->update();                                                                                
    outFile<<"\n";

    Q.print();                                                                                         
    globalST->print();
    
    // Close the output file
    outFile.close();
    
    cout << "Output successfully written to 220101096quads.out" << endl;
    
    return 0;
}