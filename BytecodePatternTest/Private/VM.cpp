
#include "../Public/VM.h"
#include "../Public/Log.h"
#include "../Public/Globals.h"

void VM::interpreter(char bytecode[], size_t size)
{
    for (int i = 0; i < size; i++)
    {
        char instruction = bytecode[i];

        switch(instruction) {
            case INT_LITERAL: // Add new value to the stack
            {
                int value = bytecode[++i]; // takes the operand (next) and skips it.
                push(value);
                break;
            }
                
            case SET_HEALTH: // Uses the last value to set the HEALTH of the entity corresponding to previous-to-last value
            {    
                if(!checkNeededStackSize(2)) break;

                int amountHealth = pop();
                int entityToSetHealth = pop();
                setHealth(entityToSetHealth, amountHealth);
                break;
            }

            case GET_HEALTH: // Swaps last stack value (read as entity) for the HEALTH of that entity
            {    
                if(!checkNeededStackSize(1)) break;

                int entityToGetHealth = pop();
                push(getHealth(entityToGetHealth));
                break;
            } 

            case SET_STRENGTH: // Uses the last value to set the STRENGTH of the entity corresponding to previous-to-last value
            {
                if(!checkNeededStackSize(2)) break;
                
                int amountStrength = pop();
                int entityToSetStrength = pop();
                setStrength(entityToSetStrength, amountStrength);
                break;
            }

            case GET_STRENGTH: // Swaps last stack value (read as entity) for the STRENGTH of that entity
            {    
                if(!checkNeededStackSize(1)) break;    

                int entityToGetStrength = pop();
                push(getStrength(entityToGetStrength));
                break;
            }
                
            case SET_AGILITY: // Uses the last value to set the AGILITY of the entity corresponding to previous-to-last value
            {
                if(!checkNeededStackSize(2)) break;
            
                int amountAgility = pop();
                int entityToSetAgility = pop();
                setAgility(entityToSetAgility, amountAgility);
                break;
            }

            case GET_AGILITY:
            {
                if(!checkNeededStackSize(1)) break;
                
                int entityToGetAgility = pop();
                push(getAgility(entityToGetAgility));
                break;
            }

            case PLAY_SOUND:
            {
                playSound(pop());
                break;
            }
                
            case SPAWN_PARTICLE:
            {
                spawnParticles(pop());
                break;
            }
                
            case ADD:
            {
                int a = pop();
                int b = pop();
                push(a + b);
                break;
            }

            case SUBSTRACT:
            {
                int a = pop();
                int b = pop();
                push(b - a);
                break;
            }
                
            case DIVIDE:
            {
                int a = pop();
                int b = pop();
                push(b / a);
                break;
            }
                
            default: 
            {
                break;
            }
        }
    }
}

bool VM::checkNeededStackSize(int needSize){
    if(stackSize_ < needSize)
    {
        LOG_ERROR("Stack doesn't have enough values for the operation.");
        return false;
    }
    return true;
}

bool VM::push(int value)
{
    // Check for stack overflow
    if(stackSize_ > MAX_STACK_SIZE){ // last value needs to enter
        LOG_ERROR("Stack size out of bounds");
        return false;
    } 

    if(value < 0){ // last value needs to enter
        LOG_ERROR("Negative values cannot be added to the stack");
        return false;
    } 

    stack_[stackSize_++] = value; // Push value onto stack, then increment
    return true;
}

int VM::pop()
{
    // Make sure stack is not empty
    if(stackSize_ <= 0) {
        LOG_ERROR("Not enough values to take from the stack");
        return -1;
    }
    return stack_[--stackSize_]; // Decrement stack and take last value from it
}




bool VM::setHealth(int entity, int health)
{
    if (entity >= getNumberOfWarriors() || entity < 0 || health < 0){
        LOG_ERROR("Can't find entity to set Health, because Entity value is out of bounds");
        return false;
    }

    warriors[entity]->setHealth(health); return true;
}

int VM::getHealth(int entity)
{
    if (entity >= getNumberOfWarriors() || entity < 0){
        LOG_ERROR("Can't find entity to get Health from, because Entity value is out of bounds");
        return -1;
    }
    return warriors[entity]->getHealth();
}




bool VM::setStrength(int entity, int strength)
{
    if (entity >= getNumberOfWarriors() || entity < 0 || strength < 0){
        LOG_ERROR("Can't find entity to set Strength, because Entity value is out of bounds");
        return false;
    }
    warriors[entity]->setStrength(strength); return true;
}

int VM::getStrength(int entity)
{
    if (entity >= getNumberOfWarriors() || entity < 0){
        LOG_ERROR("Can't find entity to get Strength from, because Entity value is out of bounds");
        return -1;
    }
    return warriors[entity]->getStrength();
}




bool VM::setAgility(int entity, int agility)
{
    if (entity >= getNumberOfWarriors() || entity < 0 || agility < 0){
        LOG_ERROR("Can't find entity to set Agility, because Entity value is out of bounds");
        return false;
    }
    warriors[entity]->setAgility(agility); return true;
}

int VM::getAgility(int entity)
{
    if (entity >= getNumberOfWarriors() || entity < 0){
        LOG_ERROR("Can't find entity to get Agility from, because Entity value is out of bounds");
        return -1;
    }
    return warriors[entity]->getAgility();
}




void VM::playSound(int soundId)
{
    // Add code here
}

void VM::spawnParticles(int particleId)
{
    // Add code here
}
