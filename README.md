# Monty Language Interpreter

A custom interpreter for Monty Bytecode files. Monty 0.98 is a scripting language that is first compiled into Monty byte codes (just like Python). It relies on a unique stack, with specific instructions to manipulate it.

## Table of Contents
- [About the Project](#about-the-project)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Compilation](#compilation)
- [Usage](#usage)
- [Supported Opcodes](#supported-opcodes)
- [Brainfuck Projects](#brainfuck-projects)
- [Authors](#authors)

---

## About the Project

This interpreter is designed as a stack/queue-based interpreter implementing standard Monty Bytecode commands. It manages a doubly linked list structure supporting both **LIFO** (Stack) and **FIFO** (Queue) operations.

---

## Getting Started

### Prerequisites

You need a C compiler (like `gcc`) and `make` (optional) installed on your system.

### Compilation

To compile all the `.c` files in the repository, run:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=c99 *.c -o monty
```

---

## Usage

Run the interpreter with a path to a Monty bytecode file:

```bash
./monty path/to/file.m
```

### Example Monty File (`test.m`)
```text
push 1
push 2
push 3
pall
```

Running the file:
```bash
$ ./monty test.m
3
2
1
```

---

## Supported Opcodes

The interpreter supports the following operations:

| Opcode | Description |
|---|---|
| `push <int>` | Pushes an integer onto the stack. |
| `pall` | Prints all values on the stack, starting from the top. |
| `pint` | Prints the value at the top of the stack. |
| `pop` | Removes the top element of the stack. |
| `swap` | Swaps the top two elements of the stack. |
| `add` | Adds the top two elements of the stack. |
| `nop` | Does nothing. |
| `sub` | Subtracts the top element from the second top element. |
| `div` | Divides the second top element by the top element. |
| `mul` | Multiplies the second top element with the top element. |
| `mod` | Computes the modulo of the second top element by the top element. |
| `pchar` | Prints the character at the top of the stack. |
| `pstr` | Prints the string starting at the top of the stack. |
| `rotl` | Rotates the stack to the top (first element becomes last). |
| `rotr` | Rotates the stack to the bottom (last element becomes first). |
| `stack` | Sets the data format to a stack (LIFO - default behavior). |
| `queue` | Sets the data format to a queue (FIFO). |

---

## Brainfuck Projects

The `bf/` directory contains Brainfuck scripts that perform simple operations:
- `1000-school.bf`: Prints `School` followed by a new line.
- `1001-add.bf`: Adds two digits digit-by-digit.
- `1002-mul.bf`: Multiplies two digits.
- `1003-mul.bf`: Multiplies two digits and prints the result.

You can run them with any standard Brainfuck interpreter.
