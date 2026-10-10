
#include <map>
#include <set>
#include "Public/VM.h"
#include "Public/Globals.h"

/*
 * Using the Bytecode Patterns we can create a simple Virtual Machine that interprets bytecode.
 * As the goal of this pattern is to simplify design giving a high level of abstraction, the final
 * objective of this project is to build a visual scripting app that can generate bytecode,
 * so that the VM can interpret it.
 */

int main(int argc, char* argv[])
{
    setNumberOfWarriors(5);
    
    // Initialize the warriors array
    for (int i = 0; i < getNumberOfWarriors(); i++)
    {
        warriors[i] = new Warrior(); // Create a warrior
    }

    // Create a new VM
    VM* vm = new VM();

    // Create a set of instructions
    char bytecode_stealHealth[] = {
        INT_LITERAL, 1,
        INT_LITERAL, 1,
        GET_HEALTH,
        INT_LITERAL, 10,
        SUBSTRACT,
        SET_HEALTH,
        INT_LITERAL, 0,
        INT_LITERAL, 0,
        GET_HEALTH,
        INT_LITERAL, 10,
        INT_LITERAL, 2,
        DIVIDE,
        ADD,
        SET_HEALTH
    };
    
    // Send the bytecode instructions to the VM
    vm->interpreter(bytecode_stealHealth, sizeof(bytecode_stealHealth));

    std::printf("Warrior 1 health: %d\n", warriors[0]->getHealth() );
    std::printf("Warrior 2 health: %d\n", warriors[1]->getHealth() );
    
    return 0;
}
