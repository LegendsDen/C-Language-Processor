# 🔧 CS348 C Language Processor Project

This repository contains eight modular assignments from **CS348: Implementation of Programming Languages**, where I progressively built a simplified C-like language processor from scratch. The project covers everything from writing assembly code to building a full lexer, parser, and a machine-independent code generator for a subset of C called **microC**.

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

## 📦 Assignments

<details>
<summary><b>🧮 Assignment 1 – Assembly Programming Tasks</b></summary>

### Language: NASM (x86)

#### Tasks implemented:
- Print all non-leap years in a user-defined range.
- Count alphabets, digits, and special symbols in a document.
- Replace each character in a string with its next ASCII character using rollover logic.
</details>

<details>
<summary><b>🧠 Assignment 2 – Simulated Cache in NASM</b></summary>

### Goal: Implement a 2-way set associative cache in NASM.

#### Features:
- 4 sets × 2 blocks/set.
- FIFO replacement on write misses.
- Simulates cache hits and misses based on memory address input.
</details>

<details>
<summary><b>🛠️ Assignment 3 – Two-Pass Assembler in C</b></summary>

### Language: C

Implements a two-pass assembler for a simplified instruction set:
- Pass 1: Symbol Table and label resolution.
- Pass 2: Object code generation.

Optional: One-pass assembler for bonus.
</details>

<details>
<summary><b>🔤 Assignment 4 – Lexer for nanoC (Flex)</b></summary>

### Language: nanoC (stripped-down C99)

Built with Flex

#### Outputs:
- Token stream file.
- Symbol/Literal table

Includes a Makefile and test programs like factorial, array max, Fibonacci.
</details>

<details>
<summary><b>📘 Assignment 5 – Lexer for microC (Flex)</b></summary>

A more expressive lexer for microC, supporting:
- Floating points
- Binary/Hex constants
- All major token categories: identifiers, constants, punctuators

#### Two implementations:
- Iterative
- Non-iterative

Outputs token classification and symbol table.
</details>

<details>
<summary><b>📐 Assignment 6 – Parser for microC (Bison)</b></summary>

### Grammar includes:
- Expressions (arithmetic, logical, conditional)
- Declarations and compound blocks
- Conditionals, loops (for), and returns

#### Outputs:
- Symbol Table
- Grammar reduction trace

Integrates with lexer from Assignment 5.
</details>

<details>
<summary><b>🧾 Assignment 7 – Calculator with Lexer & Parser</b></summary>

Supports custom expressions:
- expr(...), bintodec(...), bintohex(...), hextobin(...), hextodec(...)

Fully functional interpreter using Lex + Bison.

Implements grammar and evaluation logic for arithmetic and conversion expressions.
</details>

<details>
<summary><b>⚙️ Assignment 8 – Machine-Independent Code Generation</b></summary>

Extends microC parser to generate 3-Address Code (TAC):
- Quad array with fields: op, arg1, arg2, result

Manages symbol tables for:
- Variables, arrays, pointers
- Functions and local scopes

Sample output includes generated quads with labels and translated C logic.
</details>

## 👨‍💻 Author

[Your Name]  
Course: CS348 – Implementation of Programming Languages  
Institution: [Your University Name]  
Year: 2024–2025
