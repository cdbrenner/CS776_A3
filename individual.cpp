//TESTS IN MUTATE - & TEST FUNCTIONS EXIST

#include "individual.h"

Individual::Individual()
{
    chromosome_length = -1;
    fitness = -1;
}

Individual::Individual(int length)
{
    chromosome_length = length;
    fitness = -1;
}

Individual::Individual(const Individual& rhs)
{
    chromosome_length = rhs.chromosome_length;

    if(chromosome_length != 0)
    {
        chromosome = new int[chromosome_length];
        for(int i = 0; i < chromosome_length; i++)
            chromosome[i] = rhs.chromosome[i];
    }
    
    fitness = rhs.fitness;
    objective_value = rhs.objective_value;
    dimension_count = rhs.dimension_count;

    if(dimension_count != 0)
    {
        dimensions = new double[dimension_count];
        for(int i = 0; i < dimension_count; i++)
        {
            dimensions[i] = rhs.dimensions[i];
        }
    }
}

Individual::~Individual()
{
    if(chromosome != nullptr)
        delete[] chromosome;

    if(dimensions != nullptr)
        delete[] dimensions;

    // if(mutate_data != nullptr)
    // {
    //     //TEST
    //     // std::cout << "DESTRUCTOR: DELETE MUTATA_DATA" << std::endl;
    //     delete[] mutate_data;
    // }

    if(transform_data != nullptr)
    {
        //TEST
        // std::cout << "DESTRUCTOR: DELETE transform_data" << std::endl;
        delete[] transform_data;
    }
}

void Individual::set_chromosome_length(int length)
{
    chromosome_length = length;
}

void Individual::set_chromosome_element(int index, int value)
{
    chromosome[index] = value;
}

void Individual::set_fitness(double fitness)
{
    this->fitness = fitness;
}

void Individual::set_objective_value(double objective_value)
{
    this->objective_value = objective_value;
}

void Individual::set_dimensions(double* data, int count)
{
    dimension_count = count;
    dimensions = new double[count];

    for(int i = 0; i < count; i++)
    {
        dimensions[i] = data[i];
    }
}

void Individual::set_transform_data_by_element(int index, int value)
{
    add_dynamic_element_to_end(transform_data,index+1,value);
}

int* Individual::get_chromosome()
{
    return chromosome;
}

int Individual::get_chromosome_length()
{
    return chromosome_length;
}

int* Individual::get_mutate_data()
{
    return mutate_data;
}

int Individual::get_mutate_count()
{
    return mutate_count;
}

int*& Individual::get_transform_data()
{
    return transform_data;
}

double Individual::get_fitness()
{
    return fitness;
}

double Individual::get_objective_value()
{
    return objective_value;
}

int Individual::get_dimension_count()
{
    return dimension_count;
}

double* Individual::get_dimensions()
{
    return dimensions;
}

void Individual::init(int random_seed, int srand_offset)
{
    chromosome = new int[chromosome_length];
    for(int i = 0; i < chromosome_length; i++)
    {
        chromosome[i] = flip(0.5f, random_seed, srand_offset*chromosome_length + i);
    }

    transform_data = new int[1]{1};
}

void Individual::init_chromosome_array(int length)
{
    chromosome_length = length;
    
    if(chromosome == nullptr)
        chromosome = new int[length];
}

void Individual::init_transform_array(int length)
{
    transform_data_length = length;
    
    if(chromosome == nullptr)
        transform_data = new int[length];
}

void Individual::mutate(double probability, int random_seed, int srand_offset)
{

    mutate_count = 0;
    // if(mutate_data != nullptr)
    // {
    //     //TEST
    //     // std::cout << "INSIDE DYNAMIC DELETE" << std::endl;

    //     delete[] mutate_data;
    //     mutate_data = nullptr;
    // }
    // int mutation_data_length;

    for(int i = 0; i < chromosome_length; i++)
    {
        if(flip(probability, random_seed, srand_offset*chromosome_length + i))
        {
            chromosome[i] = 1 - chromosome[i];
            mutate_data[mutate_count] = i;
            mutate_count++;
        }
    }

    //TEST
    // std::cout << "CHROM LENGTH: " << get_chromosome_length() << std::endl; 
}

void Individual::copy_individual_data(const Individual& rhs)
{
    chromosome_length = rhs.chromosome_length;


    for(int i = 0; i < chromosome_length; i++)
    {
        chromosome[i] = rhs.chromosome[i];
    }

}

//TEST
void Individual::print_ind()
{
    // int one = 0;
    // int zero = 0;
    for(int i = 0; i < chromosome_length; i++)
    {
        if(i != chromosome_length - 1)
        {
            std::cout << chromosome[i];
            // chromosome[i] == 1 ? one++ : zero++;
        }
        else
        {
            // chromosome[i] == 1 ? one++ : zero++;
            std::cout << chromosome[i] << std::endl;
        }
    }
    // std::cout << "1s: " << (float)one/chromosome_length << std::endl;
    // std::cout << "0s: " << (float)zero/chromosome_length << std::endl;
}

void Individual::print_transform_data()
{
    //TEST
    std::cout << "PRINT_TRANSFORM_DATA: TRANSFORM_DATA[0] = " << transform_data[0] << std::endl;

    for(int i = 0; i < transform_data[0]; i++)
    {
        std::cout << transform_data[i] << " ";
    }
    std::cout << std::endl;
}

//FOR TESTING
// double Individual::get_mutation_percentage()
// {
//     return mutation_count/total_mutation_attempts;
// }