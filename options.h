#pragma once
#include <iostream>

struct Options
{
    std::string input_file;
    std::string input_file_o;
    std::string output_file;
    std::string output_file_o;
    std::string ave_file;
    std::string ave_file_o;
    int GA_iteration;
    int print_precision;
    int print_precision_o;
    int evaluation_mode;
    long int random_seed;
    int population_size;
    int chromosome_length;
    int max_generations;
    double probability_x;
    double probability_mutation;
    
    //FLOORPLANNING OPTIONS
    int variable_count;
    int* bit_length = nullptr;
    double* scaler = nullptr;
    double* max_variable_value = nullptr;
    int penalty_weight_1;
    int penalty_weight_2;

};