#include <bits/stdc++.h>
using namespace std;

#define T_RECORD_MAX 30

// Instruction structure to store parsed instruction components
struct Instruction {
    string label;
    string mnemonic;
    string operand;
    string address;
};

// Text record structure for object code generation
struct TextRecord {
    string start;
    string objectCode;
    int length;
};

// Global variables
map<string, string> symbolTable, opTable;
string programLength;
map<int, string> hexMap;

// Initialize opcodes and hex mapping
void initializeAssembler() {
    // Initialize operation codes
    opTable = {
        {"LDA", "00"}, {"LDX", "04"}, {"LDL", "08"},
        {"STA", "0C"}, {"STX", "10"}, {"STL", "14"},
        {"LDCH", "50"}, {"STCH", "54"}, {"ADD", "18"},
        {"SUB", "1C"}, {"MUL", "20"}, {"DIV", "24"},
        {"COMP", "28"}, {"J", "3C"}, {"JLT", "38"},
        {"JEQ", "30"}, {"JGT", "34"}, {"JSUB", "48"},
        {"RSUB", "4C"}, {"TIX", "2C"}, {"TD", "E0"},
        {"RD", "D8"}, {"WD", "DC"}
    };

    // Initialize hex mapping
    for (int i = 0; i < 16; i++) {
        if (i < 10) {
            hexMap[i] = to_string(i);
        } else {
            hexMap[i] = string(1, char('A' + (i - 10)));
        }
    }
}

// Convert decimal to hexadecimal
string decToHex(int n, int pad = 0) {
    if (n == 0) return string(pad, '0');
    
    string result = "";
    while (n > 0) {
        result = hexMap[n % 16] + result;
        n /= 16;
    }
    
    while (result.length() < pad) {
        result = "0" + result;
    }
    return result;
}

// Convert hexadecimal to decimal
int hexToDec(string hex) {
    int result = 0;
    for (char c : hex) {
        result = result * 16;
        if (c >= '0' && c <= '9') {
            result += (c - '0');
        } else {
            result += (toupper(c) - 'A' + 10);
        }
    }
    return result;
}

// Add two numbers (hex or decimal)
string addHex(string num1, string num2, bool isHex = true) {
    int val1 = hexToDec(num1);
    int val2 = isHex ? hexToDec(num2) : stoi(num2);
    return decToHex(val1 + val2);
}



// Get address for a symbol
string getSymbolAddress(const string& labelExpr) {
    size_t commaPos = labelExpr.find(',');
    string label = (commaPos != string::npos) ? 
                   labelExpr.substr(0, commaPos) : labelExpr;
    
    if (symbolTable.find(label) == symbolTable.end()) {
        return "-1";
    }
    
    string addr = symbolTable[label];
    if (commaPos != string::npos) {
        addr = addHex(addr, "8000", true);
    }
    return addr;
}

// Pass 1: Generate symbol table and intermediate file
Instruction parseInstruction(const string& line) {
    Instruction inst;
    
    // Skip empty or comment lines
    if (line.empty() || line[0] == '.') {
        return inst;
    }

    // Remove leading and trailing whitespaces
    string trimmedLine = line;
    trimmedLine.erase(0, trimmedLine.find_first_not_of(" \t"));
    trimmedLine.erase(trimmedLine.find_last_not_of(" \t") + 1);

    // Split line into tokens
    vector<string> tokens;
    istringstream iss(trimmedLine);
    string token;
    while (iss >> token) {
        tokens.push_back(token);
    }

    // Parse based on number of tokens
    if (tokens.empty()) return inst;

    if (tokens.size() == 1) {
        // Single token (likely mnemonic)
        inst.mnemonic = tokens[0];
    } else if (tokens.size() == 2) {
        // Two tokens: either (label, mnemonic) or (mnemonic, operand)
        if (opTable.find(tokens[0]) != opTable.end()) {
            inst.mnemonic = tokens[0];
            inst.operand = tokens[1];
        } else {
            inst.label = tokens[0];
            inst.mnemonic = tokens[1];
        }
    } else if (tokens.size() == 3) {
        // Three tokens: label, mnemonic, operand
        inst.label = tokens[0];
        inst.mnemonic = tokens[1];
        inst.operand = tokens[2];
    }

    return inst;
}

// Simplified pass1 using new parsing
void pass1(const string& inputFile) {
    ifstream inFile(inputFile);
    ofstream intermediateFile("intermediate.txt");
    
    if (!inFile.is_open()) {
        cout << "Error: Cannot open input file" << endl;
        return;
    }

    string location = "0000", startAddr = "0000";
    string line;
    
    // Process first line (START directive)
    getline(inFile, line);
    Instruction inst = parseInstruction(line);
    
    if (inst.mnemonic == "START") {
        startAddr = inst.operand.empty() ? "0000" : inst.operand;
        location = startAddr;
        intermediateFile << startAddr << " " << inst.label << " " 
                        << inst.mnemonic << " " << inst.operand << endl;
    }

    // Process remaining lines
    while (getline(inFile, line)) {
        inst = parseInstruction(line);
        if (inst.mnemonic.empty()) continue;
        
        string currentLoc = location;

        // Handle symbol definition
        if (!inst.label.empty()) {
            if (symbolTable.find(inst.label) != symbolTable.end()) {
                cout << "Error: Duplicate symbol '" << inst.label << "'" << endl;
                return;
            }
            symbolTable[inst.label] = location;
        }

        // Location counter logic (simplified)
        if (inst.mnemonic == "END") break;
        
        location = addHex(location, 
            (opTable.count(inst.mnemonic) ? "3" : 
             inst.mnemonic == "WORD" ? "3" : 
             inst.mnemonic == "RESW" ? to_string(stoi(inst.operand) * 3) : 
             inst.mnemonic == "RESB" ? inst.operand : 
             inst.mnemonic == "BYTE" ? 
                (inst.operand[0] == 'C' ? to_string(inst.operand.length() - 3) : 
                 inst.operand[0] == 'X' ? to_string((inst.operand.length() - 3 + 1) / 2) : "0") 
             : "0"), false);

        intermediateFile << currentLoc << " " << inst.label << " " 
                        << inst.mnemonic << " " << inst.operand << endl;
    }

    programLength = decToHex(hexToDec(location) - hexToDec(startAddr), 6);
    
    inFile.close();
    intermediateFile.close();
}
// Pass 2: Generate object code
void pass2() {
    ifstream intermediateFile("intermediate.txt");
    ofstream objectFile("object.txt");
    
    if (!intermediateFile.is_open()) {
        cout << "Error: Cannot open intermediate file" << endl;
        return;
    }

    string line;
    TextRecord textRecord;
    string startAddr;
    
    // Process first line (START directive)
    getline(intermediateFile, line);
    Instruction inst = parseInstruction(line);
    
    // Write header record
    startAddr = inst.operand.empty() ? "000000" : inst.operand;
    objectFile << "H" << setw(6) << left << (inst.label.empty() ? "PROG" : inst.label)
               << setfill('0') << setw(6) << right << startAddr
               << setw(6) << programLength << endl;
    
    textRecord.start = startAddr;
    textRecord.length = 0;
    textRecord.objectCode = "";

    // Process remaining lines
    while (getline(intermediateFile, line)) {
        inst = parseInstruction(line);
        if (inst.mnemonic.empty()) continue;

        string objectCode = "";

        if (inst.mnemonic == "END") {
            break;
        }

        // Generate object code based on instruction type
        if (opTable.find(inst.mnemonic) != opTable.end()) {
            objectCode = opTable[inst.mnemonic];
            if (!inst.operand.empty()) {
                string addr = getSymbolAddress(inst.operand);
                if (addr == "-1") {
                    cout << "Error: Undefined symbol '" << inst.operand << "'" << endl;
                    return;
                }
                objectCode += addr;
            } else {
                objectCode += "0000";
            }
        } else if (inst.mnemonic == "BYTE") {
            if (inst.operand[0] == 'C') {
                for (size_t i = 2; i < inst.operand.length() - 1; i++) {
                    objectCode += decToHex(int(inst.operand[i]), 2);
                }
            } else if (inst.operand[0] == 'X') {
                objectCode = inst.operand.substr(2, inst.operand.length() - 3);
                if (objectCode.length() % 2 != 0) {
                    objectCode = "0" + objectCode;
                }
            }
        } else if (inst.mnemonic == "WORD") {
            objectCode = decToHex(stoi(inst.operand), 6);
        } else if (inst.mnemonic == "RESW" || inst.mnemonic == "RESB") {
            // Write current text record if exists
            if (textRecord.length > 0) {
                objectFile << "T" << setfill('0') << setw(6) << textRecord.start
                          << setw(2) << hex << textRecord.length
                          << textRecord.objectCode << endl;
                textRecord.length = 0;
                textRecord.objectCode = "";
            }
            continue;
        }

        // Handle text record
        if (textRecord.length + (objectCode.length() / 2) > T_RECORD_MAX) {
            objectFile << "T" << setfill('0') << setw(6) << textRecord.start
                      << setw(2) << hex << textRecord.length
                      << textRecord.objectCode << endl;
            textRecord.length = 0;
            textRecord.objectCode = "";
            textRecord.start = inst.address;
        }

        if (textRecord.length == 0) {
            textRecord.start = inst.address;
        }
        textRecord.objectCode += objectCode;
        textRecord.length += objectCode.length() / 2;
    }

    // Write final text record if exists
    if (textRecord.length > 0) {
        objectFile << "T" << setfill('0') << setw(6) << textRecord.start
                  << setw(2) << hex << textRecord.length
                  << textRecord.objectCode << endl;
    }

    // Write end record
    objectFile << "E" << setfill('0') << setw(6) << startAddr << endl;

    intermediateFile.close();
    objectFile.close();
}

int main(int argc, char* argv[]) {
    const string inputFile = "given_input.txt";

    initializeAssembler();
    pass1(inputFile);
    pass2();

    return 0;
}