#pragma once
#include <sstream>
#include "population.h"

class GA
{
    private:
    public:
        Population *parent;
        Population *child;
        Population *temp;
        Options options;

        GA(int argc, char *argv[], int eval_option, int iterator);
        ~GA();

        void setup_options(int argc, char *argv[], int eval_option, int iterator);

        void init(int eval_option);
        void run(int eval_option);
        void report_cleanup();
};