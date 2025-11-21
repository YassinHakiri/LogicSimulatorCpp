# Logic Simulator C++

[![C++](https://img.shields.io/badge/C++-11-blue.svg)](https://isocpp.org/)
[![License](https://img.shields.io/badge/License-CC%20BY--SA%203.0-lightgrey.svg)](https://creativecommons.org/licenses/by-sa/3.0/)

> A complete digital logic circuit simulator implemented in C++ using Object-Oriented Programming principles.

## 📋 Table of Contents

- [About](#about)
- [Features](#features)
- [Project Structure](#project-structure)
- [Installation](#installation)
- [Usage](#usage)
- [Circuit File Format](#circuit-file-format)
- [Examples](#examples)
- [Development Steps](#development-steps)
- [Author](#author)

## 🎯 About

This project is a logic circuit simulator developed as part of the HAE916E course (Master 2 EEA/2022) at the University of Montpellier. The simulator allows users to:

- Define digital logic circuits using basic gates (AND, OR, NOT, etc.)
- Connect gates through nodes
- Compute circuit outputs for given inputs
- Load circuit definitions from text files
- Generate truth tables for gates and complete circuits

## ✨ Features

- **Node System**: Representation of circuit connection points with value tracking
- **Logic Gates**: Implementation of fundamental gates:
  - AND
  - OR
  - NOT
  - Extensible to NAND, NOR, XOR, etc.
- **Circuit Simulation**: Complete circuit evaluation with automatic propagation
- **File-Based Configuration**: Load circuits and inputs from text files
- **Truth Table Generation**: Automatic truth table computation for gates and circuits
- **Object-Oriented Design**: Clean inheritance hierarchy with virtual functions

## 📁 Project Structure

```
LogicSimulatorCpp/
├── Step I - Nodes/
│   ├── Problem I.1 - Write the Class itself/
│   └── Problem I.2 - Make it usable for the project/
│       ├── src/
│       │   ├── main.cpp
│       │   ├── node.h
│       │   └── node.cpp
│       └── Debug/
├── Step II - Gates/
│   ├── Problem II.1 - Write the Gate base class/
│   ├── Problem II.2 - GateAND inheriter/
│   └── Problem II.3 - Other inheriters/
│       ├── src/
│       │   ├── Gate.h / Gate.cpp
│       │   ├── GateAND.h / GateAND.cpp
│       │   ├── GateOR.h / GateOR.cpp
│       │   └── GateNOT.h / GateNOT.cpp
│       └── Debug/
├── Step III - Circuit/
│   ├── Problem III.1 - The circuit class/
│   │   ├── src/
│   │   │   ├── circuit.h / circuit.cpp
│   │   │   └── main.cpp
│   │   └── Debug/
│   └── Problem III.2 - Truth table for the circuit/
└── Step IV - Files/
    ├── src/
    │   ├── gates.txt
    │   ├── inputs.txt
    │   └── main.cpp
    └── Debug/
```

## 🔧 Installation

### Prerequisites

- C++ compiler (g++ recommended)
- Make or Eclipse CDT (optional)
- Git

### Windows (MSYS2)

```bash
# Install MSYS2 and g++
# Follow the tutorial: http://dl.eea-fds.umontpellier.fr/CppInstall/tuto-install-Cpp.mp4

# Clone the repository
git clone https://github.com/YassinHakiri/LogicSimulatorCpp.git
cd LogicSimulatorCpp
```

### Linux / macOS

```bash
# Install g++ (if not already installed)
sudo apt-get install g++  # Ubuntu/Debian
# or
brew install gcc          # macOS

# Clone the repository
git clone https://github.com/YassinHakiri/LogicSimulatorCpp.git
cd LogicSimulatorCpp
```

### Compilation

```bash
# Navigate to the desired step
cd "Step IV - Files/src"

# Compile
g++ -o simulator main.cpp node.cpp Gate.cpp GateAND.cpp GateOR.cpp GateNOT.cpp circuit.cpp

# Run
./simulator
```

## 🚀 Usage

### Basic Circuit Creation (Programmatic)

```cpp
#include "circuit.h"
#include "GateAND.h"
#include "GateOR.h"
#include "GateNOT.h"

int main() {
    circuit Circ;
    
    // Add gates
    Circ.gates.push_back(new GateAND(Node("I1"), Node("I2"), Node("A")));
    Circ.gates.push_back(new GateOR(Node("I3"), Node("I4"), Node("B")));
    Circ.gates.push_back(new GateNOT(Node("A"), Node("O1")));
    
    // Define inputs
    Circ.inputs.push_back(Node("I1", true));
    Circ.inputs.push_back(Node("I2", false));
    Circ.inputs.push_back(Node("I3", true));
    Circ.inputs.push_back(Node("I4", true));
    
    // Define outputs
    Circ.outputs.push_back(Node("O1"));
    
    // Compute
    Circ.compute();
    
    return 0;
}
```

### Using File-Based Configuration

```cpp
int main() {
    circuit Circ;
    
    // Load circuit definition
    Circ.load_gates_from_file("gates.txt");
    
    // Load and compute inputs
    Circ.load_inputs_from_file("inputs.txt");
    
    return 0;
}
```

## 📄 Circuit File Format

### Gates File (`gates.txt`)

```
INPUT I1 I2 I3 I4 I5 I6
OUTPUT O1 O2 O3
AND A I1 I2
OR B I3 I4
AND C B I5
OR O1 A C
NOT O2 C
OR O3 C I6
```

**Format:**
- `INPUT`: List of input node names
- `OUTPUT`: List of output node names
- `GATE_TYPE OUTPUT_NODE INPUT_NODE1 [INPUT_NODE2 ...]`

### Inputs File (`inputs.txt`)

```
3
110011
101010
111110
```

**Format:**
- First line: Number of test cases
- Following lines: Binary values for each input (one character per input)

## 💡 Examples

### Example Circuit

```
    I1 ──┐
         AND── A ──┐
    I2 ──┘         │
                   OR── O1
    I3 ──┐         │
         OR── B ───┘
    I4 ──┘
```

### Truth Table Output

```
Input: I1=1, I2=1, I3=0, I4=0
Gates Status:
7GateAND << I1:1 I2:1 >> A:1
6GateOR << I3:0 I4:0 >> B:0
6GateOR << A:1 B:0 >> O1:1
Output: O1=1
```

## 🛠️ Development Steps

The project was developed in four main stages:

### Step I: Nodes
- Implementation of the `Node` class
- Support for value tracking and computed state
- Basic display functionality

### Step II: Gates
- Base `Gate` class with virtual functions
- Inheritance for specific gates (AND, OR, NOT)
- Truth table generation
- Optimized design with minimal code duplication

### Step III: Circuit
- `Circuit` class for managing complete circuits
- Automatic output computation algorithm
- Internal signal propagation
- Circuit truth table generation

### Step IV: Files
- File parsing for circuit definition
- Multiple input test cases
- Integration of all components

## 👨‍💻 Author

**YASSIN HAKIRI**
- Master 2 SEIE
- University of Montpellier, France
- Course: HAE916E - C++ Language (2022)

### Instructors
- **Mikhaël MYARA** - mikhael.myara@umontpellier.fr
- **Pierre GROC** - pierre.groc@lirmm.fr

## 📜 License

This work is licensed under a [Creative Commons Attribution-ShareAlike 3.0 Unported License](https://creativecommons.org/licenses/by-sa/3.0/).

## 🙏 Acknowledgments

- EEA Department, University of Montpellier
- Original course materials and practical work guidelines

---

> *"Most computer problems come from the keyboard-to-chair interface."* - Klaus Klages
