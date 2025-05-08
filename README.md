# 🚀 CS348 C Language Processor Project

This repository contains eight modular assignments from **CS348: Implementation of Programming Languages**, where I progressively built a simplified C-like language processor from scratch. The project covers everything from writing assembly code to building a full lexer, parser, and a machine-independent code generator for a subset of C called **microC**.

## 🧭 Table of Contents
- [Overview](#overview)
- [Project Structure](#project-structure)
- [How to Run](#how-to-run)
- [Project Modules](#project-modules)
  - [Assembly Programming Tasks](#assembly-programming-tasks)
  - [Simulated Cache in NASM](#simulated-cache-in-nasm)
  - [Two-Pass Assembler in C](#two-pass-assembler-in-c)
  - [Lexer for nanoC](#lexer-for-nanoc)
  - [Lexer for microC](#lexer-for-microc)
  - [Parser for microC](#parser-for-microc)
  - [Calculator with Lexer & Parser](#calculator-with-lexer--parser)
  - [Machine-Independent Code Generation](#machine-independent-code-generation)
- [Author](#author)

## 📖 Overview

This project represents a comprehensive implementation of language processing components, starting with foundational assembly programming and progressing through increasingly complex tasks, culminating in a full compiler implementation for microC. Each module builds upon knowledge from previous assignments, creating a complete understanding of language processor implementation.

## 📁 Project Structure

```
cs348-c-language-processor/
├── Assignment1_Assembly_Programs/
├── Assignment2_Cache_Simulation/
├── Assignment3_TwoPass_Assembler/
├── Assignment4_Lexer_nanoC/
├── Assignment5_Lexer_microC/
├── Assignment6_Parser_microC/
├── Assignment7_Calculator_Lexer_Parser/
├── Assignment8_Code_Generation_microC/
└── README.md
```

## ▶️ How to Run

1. **Clone this repository**:
   ```bash
   git clone https://github.com/yourusername/cs348-c-language-processor.git
   ```

2. **Navigate to any assignment**:
   ```bash
   cd Assignment4_Lexer_nanoC
   ```

3. **Build and run using Makefile**:
   ```bash
   make
   ./a.out
   ```

   For parser/codegen assignments, ensure flex and bison are installed.

## 📦 Project Modules

### 🧮 **Assignment 1 – Assembly Programming Tasks**

**Language**: NASM (x86 Assembly)

**Tasks implemented**:
- **Leap Year Filter**: Print all non-leap years in a user-defined range.
- **Character Categorization**: Count and classify characters from a document into alphabets, digits, and special characters.
- **ASCII Shift**: Rotate each alphabet in a string to its next ASCII character (with wrap-around logic).

**Focus**: Logical implementation of control structures and string/character handling in assembly.

### 🧮 **Assignment 2 – Simulated Cache in NASM**

**Goal**: Implement a 2-way set associative cache in NASM.

**Features**:
- 4 sets × 2 blocks/set with cache lookup and write logic handled using memory segments.
- FIFO replacement on write misses.
- Cache hit/miss detection.

**Output includes**:
- Status of read/write operations.
- Updated state of the cache.

### 🧮 **Assignment 3 – Two-Pass Assembler in C**

**Language**: C

**Implementation**:
- Created a full assembler that processes simplified assembly code in two passes:
  - **Pass 1**: Build symbol table, resolve labels and addresses.
  - **Pass 2**: Generate object code using intermediate representation.
- Supported instructions like MOV, ADD, SUB, JMP, LDA, STA, CALL, RET, etc.
- Optional one-pass assembler attempted for bonus.

**I/O**:
- Input: Assembly file
- Output: Object file + intermediate info

### 🧮 **Assignment 4 – Lexer for nanoC (Flex)**

**Language**: nanoC (stripped-down C99 with int, char, void types only)

**Implementation**:
- Built with Flex
- Tokenized identifiers, numbers, punctuators, operators, and keywords.
- Supported single-line and multi-line comments.

**Outputs**:
- Token stream file.
- Symbol/Literal table

**Delivered with**: test.nc input file, Makefile, and token classification logic.

### 🧮 **Assignment 5 – Lexer for microC (Flex)**

**Language**: microC - a slightly more expressive subset of C

**Features**:
- Supports floating points, booleans, and additional operators
- Binary/Hex constants
- All major token categories: identifiers, constants, punctuators

**Two implementations**:
- **Iterative Lexer**: Uses yylex() loop and token switch cases.
- **Non-Iterative Lexer**: Token classification using inline print logic.

**Outputs**:
- List of tokens with types
- Symbol table of identifiers and constants

### 🧮 **Assignment 6 – Parser for microC (Bison)**

**Implementation**:
- Created a full grammar parser for microC using Bison
- Covered expressions, loops, conditionals, return statements, and nested scopes.
- Replaced {} blocks with begin/end as per microC syntax.

**Grammar includes**:
- Expressions (arithmetic, logical, conditional)
- Declarations and compound blocks
- Conditionals, loops (for), and returns

**Features**:
- Prints grammar reductions
- Builds a symbol table during parsing

**I/O**:
- Input: .mc file
- Output: Rule-by-rule trace and symbol mapping

### 🧮 **Assignment 7 – Calculator with Lexer & Parser**

**Implementation**:
- Built a multi-functional calculator using Lex + Bison

**Supports custom expressions**:
- **Arithmetic Expressions**: expr(3+5*2-4**2/2) → 5
- **Binary to Decimal**: bintodec(1101) → 13
- **Binary to Hex**: bintohex(10101001) → A9
- **Hex to Binary**: hextobin(2F) → 00101111
- **Hex to Decimal**: hextodec(FF) → 255

**Features**:
- Tokenized function names, operators, and numbers.
- Evaluated conversions via parsing logic and printing results.

### 🧮 **Assignment 8 – Machine-Independent Code Generation**

**Goal**: Translate microC to 3-address code (TAC)

**Implementation**:
- Implemented semantic actions in Bison grammar:
  - Generate quad array entries: op, arg1, arg2, result
  - Maintain symbol tables with scope handling

**Code supports**:
- All standard expressions, function calls, and basic control flow
- Generation of temporaries, labels, backpatching

**Tools**:
- emit(), gentemp(), makelist(), backpatch() utilities
- Separate symbol tables for global/function/local scopes

**Output**: Generated quads with labels and translated C logic

## 👨‍💻 Author

Sushant Kumar  
Course: CS348 – Implementation of Programming Languages  
Institution: IIT Guwahati  
Year: 2025
