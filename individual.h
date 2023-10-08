#pragma once
#include "helpers.h"

class Individual
{
    private:
        int *chromosome = nullptr;
        int chromosome_length;
        // int *mutate_data = nullptr;
        int mutate_data[100];
        int mutate_count;
        double fitness;
        double objective_value;

        // TRANSFORMATION DATA CONTAINS IS USED TO TEST WHETHER THE XOVER & MUTATE MECHANISMS WORKED CORRECTLY
        // LENGTH OF TRANSFORM_DATA IS ALWAYS THE FIRST ELEMENT (transform_data[0])
        int *transform_data = nullptr;
        int transform_data_length;
        
        //floorplanning
        int dimension_count;
        double *dimensions = nullptr;
        
        // VARIABLES FOR TESTING PROBABILITY ACCURACY
        // double mutation_count = 0;
        // double total_mutation_attempts = 0;

    public:

        Individual();
        Individual(int);
        Individual(const Individual& rhs);
        ~Individual();

        void set_chromosome_length(int);
        void set_chromosome_element(int index, int value);
        void set_fitness(double);
        void set_objective_value(double);
        void set_dimensions(double* dynamic_dimensions_data, int dimensions_count);
        void set_transform_data_by_element(int index, int value);

        int* get_chromosome();
        int get_chromosome_length();
        int* get_mutate_data();
        int get_mutate_count();
        int*& get_transform_data();
        double get_fitness();
        double get_objective_value();
        int get_dimension_count();
        double* get_dimensions();
        
        //FUNCTIONS FOR TESTING PROBABILITY ACCURACY
        double get_mutation_percentage();

        void init(int random_seed, int srand_offset);
        void init_chromosome_array(int chromosome_length);
        void init_transform_array(int transform_length);
        void mutate(double probability, int random_seed, int srand_offset);
        void copy_individual_data(const Individual& individual_copy);

        //TEST
        void print_ind();
        void print_transform_data();
};