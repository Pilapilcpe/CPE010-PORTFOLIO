#include "Supplementary.h"
#include <iostream>

int main() {

    Printer<Job> printer;

    Job job1(1, "Loreen", 7);
    Job job2(2, "Marion", 10);
    Job job3(3, "Guillian",3);


    printer.add(job1);
    printer.add(job2);
    printer.add(job3);
    printer.process();

    return 0;
}