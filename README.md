# 🔧 CS348 C Language Processor Project

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

### 🧮 Assignment 1 – Assembly Programming Tasks

**Language**: NASM (x86)

**Tasks implemented**:
- Print all non-leap years in a user-defined range.
- Count alphabets, digits, and special symbols in a document.
- Replace each character in a string with its next ASCII character using rollover logic.

### 🧠 Assignment 2 – Simulated Cache in NASM

**Goal**: Implement a 2-way set associative cache in NASM.

**Features**:
- 4 sets × 2 blocks/set.
- FIFO replacement on write misses.
- Simulates cache hits and misses based on memory address input.

### 🛠️ Assignment 3 – Two-Pass Assembler in C

**Language**: C

Implements a two-pass assembler for a simplified instruction set:
- Pass 1: Symbol Table and label resolution.
- Pass 2: Object code generation.

Optional: One-pass assembler for bonus.

### 🔤 Assignment 4 – Lexer for nanoC (Flex)

**Language**: nanoC (stripped-down C99)

Built with Flex

**Outputs**:
- Token stream file.
- Symbol/Literal table

Includes a Makefile and test programs like factorial, array max, Fibonacci.

### 📘 Assignment 5 – Lexer for microC (Flex)

A more expressive lexer for microC, supporting:
- Floating points
- Binary/Hex constants
- All major token categories: identifiers, constants, punctuators

**Two implementations**:
- Iterative
- Non-iterative

Outputs token classification and symbol table.

### 📐 Assignment 6 – Parser for microC (Bison)

**Grammar includes**:
- Expressions (arithmetic, logical, conditional)
- Declarations and compound blocks
- Conditionals, loops (for), and returns

**Outputs**:
- Symbol Table
- Grammar reduction trace

Integrates with lexer from Assignment 5.

### 🧾 Assignment 7 – Calculator with Lexer & Parser

Supports custom expressions:
- expr(...), bintodec(...), bintohex(...), hextobin(...), hextodec(...)

Fully functional interpreter using Lex + Bison.

Implements grammar and evaluation logic for arithmetic and conversion expressions.

### ⚙️ Assignment 8 – Machine-Independent Code Generation

Extends microC parser to generate 3-Address Code (TAC):
- Quad array with fields: op, arg1, arg2, result

Manages symbol tables for:
- Variables, arrays, pointers
- Functions and local scopes

Sample output includes generated quads with labels and translated C logic.

## 👨‍💻 Author

- Sushant Kumar 
- Course: CS348 – Implementation of Programming Languages  
- Institution: IIT Guwahati
- Year: 2025
