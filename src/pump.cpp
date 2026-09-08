#include "pump.h"

pump::pump()
{
    running = false;
}
void pump::start()
{
    running = true;
}
void pump::stop()
{
    running = false;
}
bool pump::isrunning()
{
    return running;
}
