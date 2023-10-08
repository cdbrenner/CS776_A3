#pragma once
#include <sstream>
#include "population.h"
#include "test.h"

class GA
{
    private:
        Population *parent = nullptr;
        Population *child = nullptr;
        Population *m_temp = nullptr;
        Options options;
        int extinction_counter;

        //IN ORDER TO RUN XOVER_MUTATION MECHANISM TEST IN CHC MODEL, A GRANDPARENT IS REQUIRED
        Population *grandparent = nullptr;

    public:
        GA(int argc, char *argv[], int eval_option, int iterator);
        ~GA();

        void setup_options(int argc, char *argv[], int eval_option, int iterator);

        void init(int eval_option, int report_option);
        void run(int eval_option, int report_option);
        void extinction_check();
        void extinction_event();
        void report_cleanup();

        const Options get_options();
};