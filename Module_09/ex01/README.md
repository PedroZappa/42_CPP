# RPN Calculator

<!-- mtoc-start -->

* [Overview](#overview)
* [Implementation Details](#implementation-details)
  * [Class Structure](#class-structure)
* [Usage](#usage)
  * [Example](#example)
* [Supported Operations](#supported-operations)
* [Error Handling](#error-handling)
* [Limitations](#limitations)
* [Algorithm](#algorithm)

<!-- mtoc-end -->
## Overview

The RPN (Reverse Polish Notation) calculator is a command-line program that evaluates mathematical expressions written in Reverse Polish Notation. In this notation, operators follow their operands, which eliminates the need for parentheses and creates an unambiguous representation of mathematical expressions.

## Implementation Details

The program is implemented in C++ and consists of the following files:
- `main.cpp`: Contains the entry point of the program
- `RPN.cpp`: Contains the implementation of the RPN calculator
- `printer.cpp`: Contains utility functions for printing error messages
- `RPN.hpp`: Contains the class declaration for the RPN calculator
- `Ansi.h`: Contains ANSI color codes for formatted output

___

### Class Structure

The `RPN` class uses a stack to process and evaluate RPN expressions. It includes:

- **Public methods**:
  - `parseInput(std::string input)`: Processes the input string and calculates the result

- **Private methods**:
  - `trimSpaces(std::string &str)`: Removes leading and trailing spaces
  - `isStringValid(std::string elem)`: Validates that the input contains only valid characters
  - `calculate(std::string expr)`: Performs the calculation based on the RPN expression
  - `doOp(const char &op)`: Executes a single operation
  - `ops(const int &operand1, const int &operand2, const char &op)`: Performs the actual arithmetic operation

## Usage

```
./RPN "expression"
```

### Example
```
./RPN "21 21 +"
```

This will calculate 21 + 21 and output the result (42).

## Supported Operations

The calculator supports the following operations:
- Addition (`+`)
- Subtraction (`-`)
- Multiplication (`*`)
- Division (`/`)

## Error Handling

The program handles various error conditions:
- Empty input
- Invalid input characters
- Insufficient operands for an operation
- Division by zero
- Invalid expression format

When an error occurs, an appropriate error message is displayed in red text.

## Limitations

- Only supports integers less than 10 as input operands
- Does not handle brackets or decimal numbers
- Each token (number or operator) must be separated by a space

## Algorithm

The RPN calculator uses a stack-based algorithm:
1. Process the input string from left to right
2. If a token is a number, push it onto the stack
3. If a token is an operator, pop the required number of operands from the stack, perform the operation, and push the result back onto the stack
4. After processing all tokens, the result should be the only value left on the stack

This implementation follows the standard approach for evaluating Reverse Polish Notation expressions, which is both efficient and straightforward.

Citations:
[1] https://ppl-ai-file-upload.s3.amazonaws.com/web/direct-files/33783262/68a58e90-d079-412a-8cd4-e4fe991e5e43/main.cpp
[2] https://ppl-ai-file-upload.s3.amazonaws.com/web/direct-files/33783262/ac10f50d-8a57-4417-8e92-e398ee4e1334/RPN.cpp
[3] https://ppl-ai-file-upload.s3.amazonaws.com/web/direct-files/33783262/5c8b8e28-c75a-47e0-b05c-4d8347b22c36/printer.cpp
[4] https://ppl-ai-file-upload.s3.amazonaws.com/web/direct-files/33783262/6b698bc2-c98a-4148-9339-bb9e82a7c427/RPN.hpp
[5] https://ppl-ai-file-upload.s3.amazonaws.com/web/direct-files/33783262/80f5c637-680c-43df-a77e-50598db41954/Ansi.h
[6] https://ppl-ai-file-upload.s3.amazonaws.com/web/direct-files/33783262/cbf5c3cf-26c7-4a62-b043-8b01742c5c7e/cpp09.en.subject.pdf
