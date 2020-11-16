#include "reflex.cpp"
#include <iostream>
#include <string>
using std::string;

TaskInterface taskInterface;
Reflex<Tnstruct> refFactory({{"task", taskInterface},
                             {
                                 "inc",
                             },
                             {}});
