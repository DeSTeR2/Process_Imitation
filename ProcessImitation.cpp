#include <iostream>
#include "Processor.h"
using namespace std;

int main()
{
    Processor pr;
    pr.Command("move R1 -123 0");
    pr.Command("move R0 R1 0");
    pr.Command("swap R1 1415 0");
}
