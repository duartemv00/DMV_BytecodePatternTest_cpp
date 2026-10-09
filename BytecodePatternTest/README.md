# Bytecode Pattern
Instead of hard-coding behaviour in C++, write a list of simple instructions (called bytecode) stored as data. At runtime a small **virtual machine (VM)** reads and executes those instructions.

## How to
1. **Instruction Set**:
2. **Bytecode**:
3. **Virtual Machine**: A loop reads each byte
4. **Stack**: Used to pass values. Instructions push and pop operands, so a single instruction doesn't need complicated arguments.

## Advantages
- **Behavior as Data**: Designers can add content without recompiling.
- **Sandboxing**: Scripts can only do what the instructions set allow, so they can't crash the game or touch arbitrary memory.
- **Compact and Fast**: The bytecode is a flat array that is cache-friendly.

## Costs
- Building a small language that tends to grow in scope.
- Usually needs a front end (Text format or Visual editor) that compiles to bytecode, because writting raw bytes by hand is painful.
- Debugging is harder because you can't step through scripts in your normal C++ debugger.

## Rules
In a system like these, rules should be clearly defined to know how the system should react to posible errors:
1. Values in the stack will only be removed after checking that the stack has enough value to perform the operation. That check will be performed in the switch.
2. The operation is responsible of checking if the entity exist, so the values will be removed even if the operation can't be applied because of a non-existent entity.
3. There can't be negative values for in the stack. Push functionality ensures this.
4. Pop and other get functions can return -1 to represent an invalid call, as Push will ensure that negatives values will not get to the stack.

## List of functionalities
| Instruction   | Pops            | Pushes      | Description                     |
|---------------|-----------------|-------------|---------------------------------|
| `INT_LITERAL` | —               | value       | Pushes the next byte as a value |
| `SET_HEALTH`  | entity, amount  | —           | Sets an entity's health         |
| `GET_HEALTH`  | entity          | health      | Gets an entity's health         |
| `ADD`         | a, b            | a + b       | Adds two values                 |
| `DIVIDE`      | a, b            | a / b       | Divides a by b                  |

## Use example
| Instruction      | Stack after     | What the values are                                |
|------------------|-----------------|----------------------------------------------------|
| `INT_LITERAL 0`  | [0]             | input: entity id                                   |
| `INT_LITERAL 10` | [0, 10]         | input                                              |
| `INT_LITERAL 5`  | [0, 10, 5]      | input                                              |
| `ADD`            | [0, 15]         | pops 10 and 5, pushes 15, a result that's now an input |
| `SET_HEALTH`     | []              | pops 15 (amount) and 0 (entity), pushes nothing    |
