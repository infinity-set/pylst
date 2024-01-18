# pylst - Basic Python-Style List Implementation in C

## Overview

Welcome to the `pylst` repository! This C program provides a simple implementation of a Python-style list, allowing dynamic string appending. It serves as a practical resource for understanding linked lists, memory management, and string manipulation in the C programming language.

## Table of Contents

- [Why Use This Script](#why-use-this-script)
- [Prerequisites](#prerequisites)
- [Languages and Utilities Used](#languages-and-utilities-used)
- [Environments Used](#environments-used)
- [Data Structures](#data-structures)
- [Usage](#usage)

## Why Use This Script

This project introduces a basic Python-style list in C, providing insights into linked list implementation and dynamic string appending. It's suitable for learners aiming to grasp fundamental concepts of memory management, pointers, and basic data structures.

## Prerequisites

Before using this C program, ensure that you have the following:

- A C compiler installed on your system.
- Basic understanding of C programming, including linked lists and memory allocation concepts.

## Languages and Utilities Used

- **C**
- **Visual Studio Code**

[<img  alt="C Logo Icon" width="45px" src="https://upload.wikimedia.org/wikipedia/commons/1/18/C_Programming_Language.svg" />][C]
[<img alt="Visual Code Icon" width="45px" src="https://upload.wikimedia.org/wikipedia/commons/9/9a/Visual_Studio_Code_1.35_icon.svg" />][vscode]

[C]: https://learn.microsoft.com/en-us/cpp/c-language/
[vscode]: https://code.visualstudio.com/

## Environments Used

- **Windows**

[<img align="left" alt="Microsoft Icon" width="35px" src="https://upload.wikimedia.org/wikipedia/commons/3/34/Windows_logo_-_2012_derivative.svg" />][windows]

[windows]: https://www.microsoft.com/

<br /><br />

## Data Structures

### List Node Structure (`lst_node`)

- `char *data`: Pointer to the string data.
- `int length`: Length of the string.
- `int alloc`: Allocated memory for the string.
- `struct lst_node *next`: Pointer to the next node.

### Python-Style List Structure (`pylist`)

- `lst_node *head`: Pointer to the head of the list.
- `lst_node *tail`: Pointer to the tail of the list.
- `int count`: Number of elements in the list.

## Functions and Usage

### `pylist_new()`

Creates a new empty Python-style list.

### `pylist_append(pylist *self, const char *string)`

Appends a string to the Python-style list.

### `pylist_print(pylist *self)`

Prints the contents of the Python-style list.

### `pylist_del(pylist *self)`

Deletes the entire Python-style list.

### `pylist_len(pylist *self)`

Returns the length of the Python-style list.

### `pylist_index(pylist *self, const char *string)`

Finds the index of a string in the Python-style list.

## Usage

The `main` function in the provided C code demonstrates the creation, appending, printing, and deletion of the Python-style list (`pylist`).

 <div align="center">
<br/>
<img src="https://github.com/infinity-set/pystr/assets/142350896/cacb5493-8531-40ed-91c4-5c308a2bcd04" height="100%" width="100%" alt="Main function code displayed in C"/>
<br />   
 </div>

 <div align="center">
<br/>
<img src="https://github.com/infinity-set/pystr/assets/142350896/490d8c2b-570d-4e2a-ab71-fd2a8cff6196" height="100%" width="100%" alt="Output of the execution displayed."/>
<br />   
 </div>

<br />

Feel free to explore and modify the code according to your needs.

#

⬅️ **[Home](https://github.com/infinity-set)**
