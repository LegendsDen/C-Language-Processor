#include <bits/stdc++.h>

using namespace std;

#define T_RECORD_MAX 30

// struct to store the arguments of parsed instructions
struct instruction
{
    string label;
    string mnemonic;
    string operand;
    string address;
};

// struct to store info of text records
struct t_record
{
    string start;
    string object;
    int length;
};

map<string, string> symtab, optable;
// map<string, string> littab;  // Literal Table

string prog_length;

typedef struct instruction instruction;
typedef struct t_record t_record;


instruction parseInstruction(const string& line, bool isIntermediate = false) {
    instruction instruction;
    vector<string> tokens;
    stringstream ss(line);
    string token;
    
    // Skip comments
    if (line[0] == '.') {
        return instruction;
    }
    
    // Split line into tokens
    while (ss >> token) {
        tokens.push_back(token);
    }
    
    if (tokens.empty()) {
        return instruction;
    }
    if (isIntermediate) {
        // Parse intermediate file format
        if (tokens.size() >= 4) {
            instruction.address = tokens[0];
            instruction.label = tokens[1];
            instruction.mnemonic = tokens[2];
            instruction.operand = tokens[3];
        } else {
            instruction.address = tokens[0];
            instruction.label = "";
            instruction.mnemonic = tokens[1];
            instruction.operand = (tokens.size() == 3) ? tokens[2] : "";
        }
    } else {
        // Parse source file format
        if (tokens.size() == 3) {
            instruction.label = tokens[0];
            instruction.mnemonic = tokens[1];
            instruction.operand = tokens[2];
        } else {
            instruction.label = "";
            instruction.mnemonic = tokens[0];
            instruction.operand = (tokens.size() == 2) ? tokens[1] : "";
        }
    }

    return instruction;
}



map<int,string>maps;
void initialization()
{
    optable.insert(pair<string, string>("LDA", "00"));
    optable.insert(pair<string, string>("LDX", "04"));
    optable.insert(pair<string, string>("LDL", "08"));
    optable.insert(pair<string, string>("STA", "0C"));
    optable.insert(pair<string, string>("STX", "10"));
    optable.insert(pair<string, string>("STL", "14"));
    optable.insert(pair<string, string>("LDCH", "50"));
    optable.insert(pair<string, string>("STCH", "54"));
    optable.insert(pair<string, string>("ADD", "18"));
    optable.insert(pair<string, string>("SUB", "1C"));
    optable.insert(pair<string, string>("MUL", "20"));
    optable.insert(pair<string, string>("DIV", "24"));
    optable.insert(pair<string, string>("COMP", "28"));
    optable.insert(pair<string, string>("J", "3C"));
    optable.insert(pair<string, string>("JLT", "38"));
    optable.insert(pair<string, string>("JEQ", "30"));
    optable.insert(pair<string, string>("JGT", "34"));
    optable.insert(pair<string, string>("JSUB", "48"));
    optable.insert(pair<string, string>("RSUB", "4C"));
    optable.insert(pair<string, string>("TIX", "2C"));
    optable.insert(pair<string, string>("TD", "E0"));
    optable.insert(pair<string, string>("RD", "D8"));
    optable.insert(pair<string, string>("WD", "DC"));

    maps[0]="0";
    maps[1]="1";
    maps[2]="2";
    maps[3]="3";
    maps[4]="4";
    maps[5]="5";
    maps[6]="6";
    maps[7]="7";
    maps[8]="8";
    maps[9]="9";
    maps[10]="A";
    maps[11]="B";
    maps[12]="C";
    maps[13]="D";
    maps[14]="E";
    maps[15]="F";
}

string decToHex(int n, int pad = 0)
{
    
    string ans = "";

    while (n != 0)
    { 
        int rem = 0;

        rem = n % 16;
        string beta=maps[rem];
        beta+=ans;
        ans=beta;
        n = n / 16;
    }
    while (ans.size() < pad)
        ans.insert(0, 1, '0');
    return ans;
}


int hexToDec(string str)
{
    int y;
    stringstream stream;
    stream << str;
    stream >> hex >> y;
    return y;
}


string add(string str, string adder, int isHex)
{
  
    if (isHex)
    {
        int num1 = hexToDec(str);
        int num2 = hexToDec(adder);
        int sum = num1 + num2;
        return decToHex(sum);
    }
    else
    {
        int num1 = hexToDec(str);
        int num2 = atoi(adder.c_str());
        int sum = num1 + num2;

        return decToHex(sum);
    }
}




string opcode(string mnemonic)
{

    if (optable.find(mnemonic) == optable.end())
        return "-1";
    return optable[mnemonic];
}

string get_addr(string label_x){

    size_t commaPos = label_x.find(',');
    string label = (commaPos != string::npos) ?
                   label_x.substr(0, commaPos) : label_x;
   
    if (symtab.find(label) == symtab.end()) {
        return "-1";
    }
   
    string addr = symtab[label];
    if (commaPos != string::npos) {
        addr = add(addr, "8000", true);
    }
    return addr;
}

void pass_1(string file)
{
    ifstream inFile(file);
    ofstream intermediateFile("intermediate.txt");

    if (!inFile.is_open()) {
        cout << "Error: Cannot open input file" << endl;
        return;
    }

    string str;
    instruction instruction;
    string  current_location;

    string location, start_addr = "0000";
    string line;

    getline(inFile, line);

    instruction = parseInstruction(line);
    
    if (instruction.mnemonic == "START")
    {
       
        start_addr = instruction.operand;

        intermediateFile << start_addr << " " << instruction.label << " "
                        << instruction.mnemonic << " " << instruction.operand << endl;
       
    }
    
    location = start_addr;
    
  
   
    while (getline(inFile,line))
    {
        instruction = parseInstruction(line);
        if (instruction.mnemonic.empty()) continue;
       
        if (instruction.mnemonic == "END") break;
    
        current_location = location;

        // if (!instruction.operand.empty() && instruction.operand[0] == '=') {
        //     if (littab.find(instruction.operand) == littab.end()) {
        //         littab[instruction.operand] = ""; // Address not yet assigned
        //     }
        // }

        // if (instruction.mnemonic == "LTORG" || instruction.mnemonic == "END") {
        //     for (auto& literal : littab) {
        //         if (literal.second.empty()) {
        //             literal.second = location;  // Assign address
        //             location = add(location, "3", 0);  // Increment memory for each literal
        //         }
        //     }
        // }
        
        
        if (instruction.label != "")
        {
            if (symtab.find(instruction.label) != symtab.end())
            {
               cout << "Error: Duplicate symbol '" << instruction.label << "'" << endl;
                return;
            }
            symtab[instruction.label] = location;
            
        }
        
        if (opcode(instruction.mnemonic) != "-1")  location = add(location, "3", 0);
       
        else if (instruction.mnemonic == "RESB")
        {
            int reserve = atoi(instruction.operand.c_str());
            string hexaReserve = decToHex(reserve);
            location = add(location, hexaReserve, 1);
        }
       
        else if (instruction.mnemonic == "BYTE")
        {
            int bytes;
            string label2 = instruction.operand;
            char ch = label2[0];
          
            if (ch == 'X'){
                if (!((label2.size() - 3) &1))  bytes = (label2.size() - 3) / 2;
                else  bytes = ((label2.size() - 3) / 2) + 1;
                  
            }
            else  bytes = (label2.size() - 3);
            location = add(location, to_string(bytes), 1);
        }
        else if (instruction.mnemonic == "WORD")  location = add(location, "3", 0);

        else if (instruction.mnemonic == "RESW"){
        
            int reserve = 3 * atoi(instruction.operand.c_str());
            string hexaReserve = decToHex(reserve);
            location = add(location, hexaReserve, 1);
        }
        else {
            cout << "Error: Invalid operation code '" << instruction.mnemonic << "'" << endl;
            return;
        }
        intermediateFile << current_location << ' ' << setw(8) << left << instruction.label << setw(8) << left << instruction.mnemonic << instruction.operand << endl;
    }
    prog_length = decToHex(hexToDec(location) - hexToDec(start_addr), 4);

   
    inFile.close();
    intermediateFile.close();


        // // Print the Symbol Table after Pass 1
        // cout << "\nSymbol Table after Pass 1:\n";
        // cout << "--------------------------------\n";
        // cout << setw(10) << left << "Symbol" << setw(10) << "Address" << endl;
        // cout << "--------------------------------\n";
    
        // for (const auto& entry : symtab) {
        //     cout << setw(10) << left << entry.first << setw(10) << entry.second << endl;
        // }
    
        // cout << "--------------------------------\n";
}

void pass_2()
{
    
    ifstream intermediateFile("intermediate.txt");
    ofstream objectFile("output.txt");

    string line;
    t_record t_record;
    instruction instruction;
    string start_addr,object;

    getline(intermediateFile, line);
    instruction =parseInstruction(line, true);
   
   start_addr = instruction.operand.empty() ? "000000" : instruction.operand;
    objectFile << "H" << setw(6) << left << (instruction.label.empty() ? "PROG" : instruction.label)
               << setfill('0') << setw(6) << right << start_addr
               << setw(6) << prog_length << endl;
    

    t_record.start = start_addr;
    t_record.length = 0;
    t_record.object = "";
   

   while (getline(intermediateFile, line)) {
        instruction = parseInstruction(line, true);
        if (instruction.mnemonic.empty()) continue;

        object = "";
        
        // if (instruction.operand[0] == '=') {
        //     if (littab.find(instruction.operand) != littab.end()) {
        //         object += littab[instruction.operand];
        //     } else {
        //         cout << "Error: Undefined literal '" << instruction.operand << "'" << endl;
        //         return;
        //     }
        // }
        
        if (instruction.mnemonic == "END") {
            break;
        }

        // Generate object code based on instruction type
        if (optable.find(instruction.mnemonic) != optable.end()) {
            object = optable[instruction.mnemonic];
            // cout<<object<<endl;
            if (!instruction.operand.empty()) {

                string addr = get_addr(instruction.operand);
                if (addr == "-1") {
                    cout << "Error: Undefined symbol '" << instruction.operand << "'" << endl;
                    return;
                }

                object += addr;

            } else {
                object += "0000";
            }
        } else if (instruction.mnemonic == "BYTE") {

            if (instruction.operand[0] == 'C') {

                for (size_t i = 2; i < instruction.operand.length() - 1; i++) {
                    object += decToHex(int(instruction.operand[i]), 2);
                }
            } else if (instruction.operand[0] == 'X') {

                object = instruction.operand.substr(2, instruction.operand.length() - 3);
                if (object.length() % 2 != 0) {
                    object = "0" + object;
                }
            }
        } else if (instruction.mnemonic == "WORD") {

            object = decToHex(stoi(instruction.operand), 6);

        } else if (instruction.mnemonic == "RESW" || instruction.mnemonic == "RESB") {

            if (t_record.length) {

                objectFile << "T" << setfill('0') << setw(6) << t_record.start
                          << setw(2) << hex << t_record.length
                          << t_record.object << endl;
                t_record.length = 0;
                t_record.object = "";
            }
            continue;
        }

        // Handle text record
        if (t_record.length + (object.length() / 2) > T_RECORD_MAX) {

            objectFile << "T" << setfill('0') << setw(6) << t_record.start
                      << setw(2) << hex << t_record.length
                      << t_record.object << endl;

            t_record.length = 0;
            t_record.object = "";
            t_record.start = instruction.address;
        }

        if (t_record.length == 0) {
            t_record.start = instruction.address;
        }
        t_record.object += object;
        t_record.length += object.length() / 2;
    }
  
    if (t_record.length)
        objectFile << "T"
             << "00" << t_record.start << decToHex(t_record.length, 2) << t_record.object << endl;
    string prog_start;
    
    objectFile << "E" << setfill('0') << setw(6) << start_addr << endl;
    
    intermediateFile.close();
    objectFile.close();


}



int main(int argc, char **argv)
{
    
    if (argc != 2)
    {
        cout << "Enter input file name \n";
        return 0;
    }
    
    // run the  2-pass assembler
    string input = argv[1];
    initialization();
    pass_1(input);
    pass_2();
    return 0;
}




