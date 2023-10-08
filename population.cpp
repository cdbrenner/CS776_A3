//TESTS IN REPORT(), STATS()
#include "population.h"
#include "test.h"

Population::Population()
{
    child_transform_data = new int*[options.population_size];
    for(int i = 0; i < options.population_size; i++)
    {
        child_transform_data[i] = new int[2]{2,0};
    }
    
    transform_data = new int*[options.population_size];
    for(int i = 0; i < options.population_size; i++)
    {
        transform_data[i] = new int[2]{2,1};
    }
 
    average = min = max = sum_fitness = convergence = -1;
    for(int i = 0; i < options.population_size; i++)
    {
        member_chosen_count[i] = 0;
    }
}

//FOR PROGRAMS REQUIRING ONLY A SINGLE INITIAL POPULATION
Population::Population(Options options)
{
    this->options = options;
    
    child_transform_data = new int*[options.population_size];
    for(int i = 0; i < options.population_size; i++)
    {
        child_transform_data[i] = new int[2]{2,0};
    }
    
    transform_data = new int*[options.population_size];
    for(int i = 0; i < options.population_size; i++)
    {
        transform_data[i] = new int[2]{2,1};
    }
 
    average = min = max = sum_fitness = convergence = -1;
    members = new Individual[this->options.population_size];
    for(int i = 0; i < this->options.population_size; i++)
    {
        members[i].set_chromosome_length(this->options.chromosome_length);
        members[i].init(options.random_seed, i);
    }
}

//FOR PROGRAMS REQUIRING MULTIPLE INITIAL POPULATIONS
Population::Population(Options options, int srand_offset)
{
    this->options = options;

    child_transform_data = new int*[options.population_size];
    for(int i = 0; i < options.population_size; i++)
    {
        child_transform_data[i] = new int[2]{2,0};
    }
    
    transform_data = new int*[options.population_size];
    for(int i = 0; i < options.population_size; i++)
    {
        transform_data[i] = new int[2]{2,1};
    }
 
    average = min = max = sum_fitness = convergence = -1;
    members = new Individual[this->options.population_size];
    for(int i = 0; i < this->options.population_size; i++)
    {
        members[i].set_chromosome_length(this->options.chromosome_length);
        members[i].init(options.random_seed, srand_offset*options.population_size + i);
    }
}

Population::Population(Population& rhs)
{
    options = rhs.options;
    members = new Individual[options.population_size];
    for(int i = 0; i < options.population_size; i++)
    {
        members[i].init_chromosome_array(options.chromosome_length);
        members[i].copy_individual_data(rhs.get_members()[i]);
    }
}

Population::~Population()
{
    if(members != nullptr)
        delete[] members;
    
    if(max_fitness_dimensions != nullptr)
        delete max_fitness_dimensions;

    if(child_transform_data != nullptr)
    {
        for(int i = 0; i < options.population_size; i++)
        {
            if(child_transform_data[i] != nullptr)
                delete[] child_transform_data[i];
        }
        delete[] child_transform_data;
    }

    if(transform_data != nullptr)
    {
        for(int i = 0; i < options.population_size; i++)
        {
            if(transform_data[i] != nullptr)
                delete[] transform_data[i];
        }
        delete[] transform_data;
    }

    // if(parent_1 != nullptr)
    //     delete parent_1;

    // if(parent_2 != nullptr)
    //     delete parent_2;

    // if(child_1 != nullptr)
    //     delete child_1;

    // if(child_2 != nullptr)
    //     delete child_2;
}

void Population::set_options(Options options)
{
    this->options = options;
}

//FOR PROGRAMS REQUIRING ONLY A SINGLE INITIAL POPULATION
void Population::set_members()
{
    members = new Individual[this->options.population_size];
    for(int i = 0; i < this->options.population_size; i++)
    {
        members[i].set_chromosome_length(this->options.chromosome_length);
        members[i].init(options.random_seed, i);
    }
}

//FOR PROGRAMS REQUIRING MULTIPLE INITIAL POPULATIONS
void Population::set_members(int srand_offset)
{
    members = new Individual[this->options.population_size];
    for(int i = 0; i < this->options.population_size; i++)
    {
        members[i].set_chromosome_length(this->options.chromosome_length);
        members[i].init(options.random_seed, srand_offset*options.population_size + i);
    }
}

void Population::copy_members(const Population &copy)
{
    for(int i = 0; i < options.population_size; i++)
        members[i] = copy.members[i];
}

void Population::copy_population(const Population &copy)
{
    copy_members(copy);
    set_transform_data(copy.transform_data);
    set_child_transform_data(copy.child_transform_data);

}

void Population::set_transform_data(int** data)
{
    //TEST
    // std::cout << "POP::SET_TRANSFORM" << std::endl;
    // std::cout << "PASSED DATA[0][0] = " << data[0][0] << std::endl;
    if(transform_data != nullptr)
    {
        for(int i = 0; i < options.population_size; i++)
        {
            if(transform_data[i] != nullptr)
                delete[] transform_data[i];
        }
        delete[] transform_data;
        transform_data = nullptr;
    }
    
    transform_data = new int*[options.population_size];

    for(int i = 0; i < options.population_size; i++)
    {
        transform_data[i] = new int[data[i][0]];
        for(int j = 0; j < data[i][0]; j++)
            transform_data[i][j] = data[i][j];
    }
}

void Population::set_transform_data_by_row(int* data, int row)
{
    for(int i = 0; i < data[0]; i++)
    {
        transform_data[row][i] = data[i];
    }
}

void Population::set_child_transform_data(int** data)
{
    //TEST
    // std::cout << "POP::SET_TRANSFORM" << std::endl;
    // std::cout << "PASSED DATA[0][0] = " << data[0][0] << std::endl;
    if(child_transform_data != nullptr)
    {
        for(int i = 0; i < options.population_size; i++)
        {
            if(child_transform_data[i] != nullptr)
                delete[] child_transform_data[i];
        }
        delete[] child_transform_data;
        child_transform_data = nullptr;
    }

    child_transform_data = new int*[options.population_size];
    for(int i = 0; i < options.population_size; i++)
    {   
        child_transform_data[i] = new int[data[i][0]];
        for(int j = 0; j < data[i][0]; j++)
        {
            child_transform_data[i][j] = data[i][j];
        }
    }
}

void Population::set_child_transform_data_by_row(int* data, int row)
{
    for(int i = 0; i < data[0]; i++)
    {
        child_transform_data[row][i] = data[i];
    }
}

void Population::set_is_parent(bool parent_status)
{
    is_parent = parent_status;
}

Individual* Population::get_members()
{
    return members;
}

int** Population::get_transform_data()
{
    return transform_data;
}

int** Population::get_child_transform_data()
{
    return child_transform_data;
}

double Population::get_convergence()
{
    return convergence;
}

void Population::get_member_chosen_stats()
{
    double total = 0;
    for(int i = 0; i < options.population_size; i++)
    {
        total += member_chosen_count[i];
    }

    std::cout << "total = " << total << std::endl;

    for(int i = 0; i < options.population_size; i++)
    {
        std::cout << "Member[" << i << "] fitness-frac = " << proportional_fitnesses[i] << std::endl;
        std::cout << "Member[" << i << "] occurence rate = " << member_chosen_count[i]/total << std::endl;
    }
}

double Population::get_sum_fitness()
{
    return sum_fitness;
}

Options Population::get_options()
{
    return options;
}

bool Population::get_is_parent()
{
    return is_parent;
}

//CHOICE CHOOSES WHICH OBJECTIVE FUNCTION TO EVALUATE
void Population::evaluate(int choice, int choice_2, int random_seed, int srand_offset)
{
    double fitness = -1;
    for(int i = 0; i < options.population_size; i++)
    {
        try
            {fitness = eval(members[i], choice, choice_2, random_seed, srand_offset + i,
                                    options.variable_count, options.bit_length, options.scaler, options.max_variable_value,
                                                                                    options.penalty_weight_1, options.penalty_weight_2);}
        catch(double variable_value[])
            {throw(variable_value);}
        
        members[i].set_fitness(fitness);
    }
}

//CHOICE CHOOSES WHICH OBJECTIVE FUNCTION TO EVALUATE
void Population::evaluate_o(int choice, int choice_2, int random_seed, int srand_offset)
{
    double objective_value = -1;
    for(int i = 0; i < options.population_size; i++)
    {
        try
            {objective_value = eval_o(members[i], choice, choice_2, random_seed, srand_offset + i,
                                            options.variable_count, options.bit_length, options.scaler, options.max_variable_value,
                                                                                            options.penalty_weight_1, options.penalty_weight_2);}
        catch(double variable_value[])
            {throw(variable_value);}

        members[i].set_objective_value(objective_value);
    }
}

void Population::stats()
{
    sum_fitness = convergence = 0;
    min = max = members[0].get_fitness();
    max_fitness_member_index = 0;
    double fitness = -1;
    for(int i = 0; i < options.population_size; i++)
    {
        fitness = members[i].get_fitness();

        sum_fitness += fitness;

        if(fitness < min)
        {
            min = fitness;
        }
        if(fitness > max)
        {
            max = fitness;
            max_fitness_member_index = i;
        }
    }
    average = sum_fitness/options.population_size;

    //MAYBE THE NUMBER OF ITERATIONS IN THIS SEARCH FOR SUPER INDIVIDUALS COULD BE REDUCED HEURISTICALLY 
    for(int i = 0; i < options.population_size; i++)
    {
        double scale = members[i].get_fitness()/average;

        //TEST
        // std::cout << "members[i].get_fitness() = " << members[i].get_fitness() << std::endl;
        // std::cout << "average = " << average << std::endl;
        // std::cout << "scale = " << scale << std::endl;

        if(scale >= 1.2 && scale < 2)
            semi_super_individuals++;
        else if(scale >= 2)
            super_individuals++;

        if(convergence < scale)
        {
            convergence = scale;
        }
    }

    //TEST
    // std::cout << "convergence = " << convergence << std::endl;
}

//NEEDS TO BE UPDATED WITH IF STATEMENTS RATHER THAN ? STATEMENS, LIKE IN stats() ABOVE
void Population::stats_o()
{
    sum_objective = 0;
    min_objective = max_objective = members[0].get_objective_value();
    double objective_value = -1;
    for(int i = 0; i < options.population_size; i++)
    {
        objective_value = members[i].get_objective_value();

        sum_objective += objective_value;
        objective_value < min_objective ? min_objective = objective_value : 0;
        objective_value > max_objective ? max_objective = objective_value : 0;

        //MAX_FITNESS_MEMBER_INDEX NEEDS TO BE CHANGED THROUGH PROGRAM MODIFICATION TO MAX_OBJECTIVE_MEMBER_INDEX
        // objective_value > max_objective ? max_fitness_member_index = i : 0;
    }
    average_objective = sum_objective/options.population_size;
}

//SET OPTION = 1 IF AVERAGING IS NOT REQUIRED
void Population::report(int generation, int option)
{
    //TEST
    // char temp;
    // std::cout << "max_fitness_member_index = "  << max_fitness_member_index << std::endl;
    // std::cout << "variables[0] = " << members[max_fitness_member_index].get_dimensions()[0] << std::endl;
    // std::cin >> temp;

    //NON-AVERAGING REPORT
    if(options.GA_iteration == 0 || option == 1)
    {
        std::ofstream out(options.output_file, std::ios::app);
        out << std::fixed << std::setprecision(options.print_precision) << add_whitespace(generation, options.max_generations, true)
                << generation << ",\t\t" << min << ",\t\t" << average << ",\t\t" << max
                    << ",\t\t" << std::setprecision(5) << convergence << ",\t" << semi_super_individuals << ",\t\t\t" << super_individuals
                        << ",\t\t\t" << std::setprecision(options.print_precision) << 1.5 * (members[max_fitness_member_index].get_dimensions()[0] + options.living_width_offset)
                            << ",\t\t" << members[max_fitness_member_index].get_dimensions()[0] + options.living_width_offset
                                << ",\t\t" << 1.5* pow(members[max_fitness_member_index].get_dimensions()[0] + options.living_width_offset, 2)
                                    << ",\t\t" << members[max_fitness_member_index].get_dimensions()[1] + options.kitchen_length_offset
                                        << ",\t\t" << members[max_fitness_member_index].get_dimensions()[2] + options.kitchen_width_offset
                                            << ",\t\t" << members[max_fitness_member_index].get_dimensions()[1] + options.kitchen_length_offset * (members[max_fitness_member_index].get_dimensions()[2] + options.kitchen_width_offset)
                                                <<",\t\t" << "5.5"
                                                    << ",\t\t" << members[max_fitness_member_index].get_dimensions()[3] + options.hall_width_offset
                                                        << ",\t\t" << 5.5 * (members[max_fitness_member_index].get_dimensions()[3] + options.hall_width_offset)
                                                            << ",\t\t" << 1.5 * (members[max_fitness_member_index].get_dimensions()[4] + options.bed_1_width_offset)
                                                                << ",\t\t" << members[max_fitness_member_index].get_dimensions()[4] + options.bed_1_width_offset
                                                                    << ",\t\t" << 1.5 * pow(members[max_fitness_member_index].get_dimensions()[4] + options.bed_1_width_offset, 2)
                                                                        << ",\t\t" << 1.5 * (members[max_fitness_member_index].get_dimensions()[5] + options.bed_2_width_offset)
                                                                            << ",\t\t" << members[max_fitness_member_index].get_dimensions()[5] + options.bed_2_width_offset
                                                                                << ",\t\t" << 1.5 * pow(members[max_fitness_member_index].get_dimensions()[5] + options.bed_2_width_offset, 2)
                                                                                    << ",\t\t" << 1.5 * (members[max_fitness_member_index].get_dimensions()[6] + options.bed_3_width_offset)
                                                                                        << ",\t\t" << members[max_fitness_member_index].get_dimensions()[6] + options.bed_3_width_offset
                                                                                            << ",\t\t" << 1.5 * pow(members[max_fitness_member_index].get_dimensions()[6] + options.bed_3_width_offset, 2) << std::endl;
            out.close();
    }
    //AVERAGING REPORT
    else
    {
        std::string temp;
        std::string min_prev_str;
        std::string ave_prev_str;
        std::string max_prev_str;
        std::ifstream in(options.input_file);

        //FINDS BOTTOM LINE OF CURRENT REPORT
        for(int i = 0; i < generation + 1; i++)
        {
            getline(in,temp);
        }

        getline(in,temp,',');
        getline(in,min_prev_str,',');
        getline(in,ave_prev_str,',');
        getline(in,max_prev_str,',');
        double min_prev = strtod(min_prev_str.c_str(), NULL);
        double ave_prev = strtod(ave_prev_str.c_str(), NULL);
        double max_prev = strtod(max_prev_str.c_str(), NULL);

        std::ofstream out(options.output_file, std::ios::app);
        out << std::fixed << std::setprecision(options.print_precision) << generation << ",\t\t" << min + min_prev << ",\t\t" << average + ave_prev << ",\t\t" << max + max_prev << "," << std::endl;
        out.close();
    }
}

//SET OPTION = 1 IF AVERAGING IS NOT REQUIRED
void Population::report_o(int generation, int option)
{
    if(options.GA_iteration == 0 || option == 1)
    {
        std::ofstream out(options.output_file_o, std::ios::app);
        out << std::fixed << std::setprecision(options.print_precision_o) << generation << ",\t\t" << min_objective << ",\t\t" << average_objective << ",\t\t" << max_objective << "," << std::endl;
        out.close();
    }
    else
    {
        std::string temp;
        std::string min_prev_str;
        std::string ave_prev_str;
        std::string max_prev_str;
        std::ifstream in(options.input_file_o);
        for(int i = 0; i < generation + 1; i++)
        {
            getline(in,temp);
        }
        getline(in,temp,',');
        getline(in,min_prev_str,',');
        getline(in,ave_prev_str,',');
        getline(in,max_prev_str,',');
        double min_prev = atof(min_prev_str.c_str());
        double ave_prev = atof(ave_prev_str.c_str());
        double max_prev = atof(max_prev_str.c_str());

        std::ofstream out(options.output_file_o, std::ios::app);
        out << std::fixed << std::setprecision(options.print_precision_o) << generation << ",\t\t" << min_objective + min_prev << ",\t\t" << average_objective + ave_prev << ",\t\t" << max_objective + max_prev << "," << std::endl;
        out.close();
    }
}

void Population::generation(Population*& child, int srand_offset)
{
    //TEST
    // std::cout << "POP::GEN(): Gen = " << srand_offset << std::endl;
    // std::cout << "POP::GEN(): sum fitness = " << sum_fitness << std::endl << std::endl;
    // std::cout << "POP::GEN(): members[0].print_ind() = "; members[0].print_ind(); std::cout << "fitness = " << members[0].get_fitness() << std::endl << std::endl;
    // std::cout << "POP::GEN(): members[1].print_ind() = "; members[1].print_ind(); std::cout << "fitness = " << members[1].get_fitness() << std::endl << std::endl;
    // std::cout << "POP::GEN(): members[2].print_ind() = "; members[2].print_ind(); std::cout << "fitness = " << members[2].get_fitness() << std::endl << std::endl;
    // std::cout << "POP::GEN(): members[3].print_ind() = "; members[3].print_ind(); std::cout << "fitness = " << members[3].get_fitness() << std::endl << std::endl;

    // if(parent_1 != nullptr)
    // {
    //     delete parent_1;
    //     parent_1 = nullptr;
    // }

    // if(parent_2 != nullptr)
    // {
    //     delete parent_2;
    //     parent_2 = nullptr;
    // }

    // if(child_1 != nullptr)
    // {
    //     delete child_1;
    //     child_1 = nullptr;
    // }

    // if(child_2 != nullptr)
    // {
    //     delete child_2;
    //     child_2 = nullptr;
    // }

    int parent_index_1 = 0;
    int parent_index_2 = 0;
    int child_index_1 = 0;
    int child_index_2 = 0;

    Individual *parent_1, *parent_2, *child_1, *child_2;
;
    for(int i = 0; i < options.population_size; i += 2)
    {   
        parent_index_1 = proportional_selection(srand_offset*options.population_size + i);

        // ADDED THE k OFFSET FOR SRAND() BECAUSE OCCASIONALLY GETTING HELD UP IN THIS LOOP, PROBABLY DUE TO TIME(NULL) SEED
        // THIS LOOP STOPS ASEXUAL SELECTION
        int k = 0;
        while(parent_index_2 == parent_index_1)
        {
            parent_index_2 = proportional_selection(srand_offset*options.population_size + i + 1 + k);
            k++;
        }

        child_index_1 = i;
        child_index_2 = i+1;

        //POINTER VERSION
        parent_1 = &members[parent_index_1];
        parent_2 = &members[parent_index_2];
        
        //POINTER VERSION
        child_1 = &(child->members[child_index_1]);
        child_2 = &(child->members[child_index_2]);

        //UNIT TEST OBJECTS
        Individual test_1_p1(*parent_1);
        Individual test_2_p2(*parent_2);

        xover_mutate(parent_1, parent_2, child_1, child_2, srand_offset*options.population_size + i);

        //UNIT TESTING
        verify_string_equivalence(parent_1, &test_1_p1, "POP::GENERATION, AFTER AFTER XOVER_MUTATE CALL");
        verify_string_equivalence(parent_2, &test_2_p2, "POP::GENERATION, AFTER AFTER XOVER_MUTATE CALL");

        // child_1->get_transform_data()[options.m_isParent_index] = 0;
        // child_2->get_transform_data()[options.m_isParent_index] = 0;
        // child_1->get_transform_data()[options.m_parent_1_index] = parent_index_1;
        // child_1->get_transform_data()[options.m_parent_2_index] = parent_index_2;
        // child_2->get_transform_data()[options.m_parent_1_index] = parent_index_2;
        // child_2->get_transform_data()[options.m_parent_2_index] = parent_index_1;
        child_1->set_transform_data_by_element(options.m_isParent_index, 0);
        child_2->set_transform_data_by_element(options.m_isParent_index, 0);
        child_1->set_transform_data_by_element(options.m_parent_1_index, parent_index_1);
        child_1->set_transform_data_by_element(options.m_parent_2_index, parent_index_2);
        child_2->set_transform_data_by_element(options.m_parent_1_index, parent_index_2);
        child_2->set_transform_data_by_element(options.m_parent_2_index, parent_index_1);

        //TEST
        std::cout << "\nPOP::GEN: BEFORE SETTING CHILD->TRANSFORM_DATA: MUTATE DATA\n";
        for(int j = 0; j < child_1->get_mutate_count(); j++)
        {
            if(j == 0)
                std::cout << "CHILD ["<<i<<"] MUTATE DATA: " << child_1->get_mutate_data()[j] << " ";
            else
                std::cout << child_1->get_mutate_data()[j] << " ";
        }
        std::cout << std::endl;
        for(int j = 0; j < child_2->get_mutate_count(); j++)
        {
            if(j == 0)
                std::cout << "CHILD ["<<i+1<<"] MUTATE DATA: " << child_2->get_mutate_data()[j] << " ";
            else
                std::cout << child_2->get_mutate_data()[j] << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;

        for(int j = 0; j < child_1->get_mutate_count(); j++)
        {
            // child_1->get_transform_data()[j + options.m_meta_length] = child_1->get_mutate_data()[j];
            int temp = child_1->get_mutate_data()[j];
            child_1->set_transform_data_by_element(j + options.m_meta_length, temp);
            // add_dynamic_element_to_end(child_1->get_transform_data(),child_1->get_transform_data()[0],temp);
            child_1->get_transform_data()[0]++;
        }

        for(int j = 0; j < child_2->get_mutate_count(); j++)
        {
            // child_2->get_transform_data()[j + options.m_meta_length] = child_2->get_mutate_data()[j];
            int temp = child_2->get_mutate_data()[j];
            child_2->set_transform_data_by_element(j + options.m_meta_length, temp);
        }

        //TEST
        std::cout << "POP::GEN: CHILD 1 TRANSFORM DATA LENGTH = " << child_1->get_transform_data()[0] << std::endl;
        std::cout << "POP::GEN: CHILD 2 TRANSFORM DATA LENGTH = " << child_2->get_transform_data()[0] << std::endl;

        set_child_transform_data_by_row(child_1->get_transform_data(), i);
        set_child_transform_data_by_row(child_2->get_transform_data(), i + 1);

        //TEST
        std::cout << "\nPOP::GEN: AFTER SETTING CHILD TRANSFORM DATA\n";
        // std::cout << "POP::GEN: POP::CHILD["<<i<<"] TRANSFORM DATA LENGTH = " << get_child_transform_data()[i][0] << std::endl;
        // std::cout << "POP::GEN: POP::CHILD["<<i+1<<"] TRANSFORM DATA LENGTH = " << get_child_transform_data()[i+1][0] << std::endl;
        for(int j = 0; j < get_child_transform_data()[i][0]; j++)
        {
            if(j == 0)
                std::cout << "CHILD ["<<i<<"]: " << get_child_transform_data()[i][j] << " ";
            else if(j < get_child_transform_data()[i][0] - 1)
                std::cout << get_child_transform_data()[i][j] << " ";
            else
                std::cout << get_child_transform_data()[i][j] << std::endl;
        }
        for(int j = 0; j < get_child_transform_data()[i+1][0]; j++)
        {
            if(j == 0)
                std::cout << "CHILD ["<<i+1<<"]: " << get_child_transform_data()[i+1][j] << " ";
            else if(j < get_child_transform_data()[i+1][0] - 1)
                std::cout << get_child_transform_data()[i+1][j] << " ";
            else
                std::cout << get_child_transform_data()[i+1][j] << std::endl;
        }
        std::cout << std::endl;
        std::cout << std::endl;

        parent_1 = nullptr;
        parent_2 = nullptr;
        child_1 = nullptr;
        child_2 = nullptr;
    }
}

int Population::proportional_selection(int srand_offset)
{
    srand(options.random_seed + srand_offset);
    double random_fraction = (double)rand()/RAND_MAX;
    double limits[options.population_size];
    limits[0] = members[0].get_fitness()/sum_fitness;

    for(int i = 1; i < options.population_size; i++)
        limits[i] = limits[i-1] + members[i].get_fitness()/sum_fitness;

    // //TEST
    // for(int i = 0; i < options.population_size; i++)
    // {
    //     if(i == 0)
    //         std::cout << "limits["<<i<<"] = " << limits[i] <<" ";
    //     else
    //         std::cout << limits[i] <<" ";
    // }
    // std::cout << std::endl;

    for(int i = 0; i < options.population_size; i++)
    {
        if(random_fraction <= limits[i])
            return i;
    }

    return -1;
}

void Population::xover_mutate(Individual* parent_1, Individual* parent_2, Individual* child_1, Individual* child_2, int srand_offset)
{
    // Individual temp_parent_1(*parent_1);
    // Individual temp_parent_2(*parent_2);
    //FOR UNIT TEST
    Individual test_1_p1(*parent_1);
    Individual test_2_p2(*parent_2);
    //TEST
    // std::cout << "POP::XOVER_MUTATE: Before child = parent" << std::endl;
    // std::cout << "parent_1 =  "; parent_1->print_ind();
    // std::cout << "parent_2 =  "; parent_2->print_ind();
    // std::cout << "test_1_p1 = "; test_1_p1.print_ind();
    // std::cout << "test_2_p2 = "; test_2_p2.print_ind();
    // std::cout << "child_1 =  "; child_1->print_ind();
    // std::cout << "child_2 =  "; child_2->print_ind();
    // std::cout << std::endl;
   
    for(int i = 0; i < options.chromosome_length; i++)
    {
        child_1->get_chromosome()[i] = parent_1->get_chromosome()[i];
        child_2->get_chromosome()[i] = parent_2->get_chromosome()[i];
        // child_1->get_chromosome()[i] = temp_parent_1.get_chromosome()[i];
        // child_2->get_chromosome()[i] = temp_parent_2.get_chromosome()[i];
    }

    //TEST
    // std::cout << "POP::XOVER_MUTATE: After child = parent" << std::endl;
    // std::cout << "parent_1 =  "; parent_1->print_ind();
    // std::cout << "parent_2 =  "; parent_2->print_ind();
    // std::cout << "test_1_p1 = "; test_1_p1.print_ind();
    // std::cout << "test_2_p2 = "; test_2_p2.print_ind();
    // std::cout << "child_1 =  "; child_1->print_ind();
    // std::cout << "child_2 =  "; child_2->print_ind();
    // std::cout << std::endl;

    verify_string_equivalence(parent_1, &test_1_p1, "POP::XOVER_MUTATE, AFTER SETTING CHILD = PARENT");
    verify_string_equivalence(parent_2, &test_2_p2, "POP::XOVER_MUTATE, AFTER SETTING CHILD = PARENT");

    //REAL
    int index = -1;
    if(flip(options.probability_x, options.random_seed, srand_offset))
        index = one_point_xover(parent_1, parent_2, child_1, child_2, srand_offset);

    //REAL
    child_1->mutate(options.probability_mutation, options.random_seed, srand_offset);
    child_2->mutate(options.probability_mutation, options.random_seed, srand_offset + rand());

    //ADD IF !nullptr DELETE STATEMENT FOR CHILD->TRANSFORM_DATA
    // if(child_1->get_transform_data() != nullptr)
    // {
    //     delete[] child_1->get_transform_data();
    //     child_1->get_transform_data() = nullptr;
    // }
    // if(child_2->get_transform_data() != nullptr)
    // {
    //     delete[] child_2->get_transform_data();
    //     child_2->get_transform_data() = nullptr;
    // }

    //REAL
    // int child_1_transform_array_length = options.m_meta_length + child_1->get_mutate_count();
    // int child_2_transform_array_length = options.m_meta_length + child_2->get_mutate_count();
    //TEST
    int child_1_transform_array_length = options.m_meta_length;
    int child_2_transform_array_length = options.m_meta_length;

    child_1->init_transform_array(child_1_transform_array_length);
    child_2->init_transform_array(child_2_transform_array_length);

    child_1->get_transform_data()[0] = child_1_transform_array_length;
    child_2->get_transform_data()[0] = child_2_transform_array_length;

    child_1->get_transform_data()[options.m_xover_index] = index;
    child_2->get_transform_data()[options.m_xover_index] = index;
}

int Population::one_point_xover(Individual*& parent_1, Individual*& parent_2, Individual*& child_1, Individual*& child_2, int srand_offset)
{
    int index = random_index_in_range(0, options.chromosome_length, options.random_seed, srand_offset);

    for(int i = index + 1; i < options.chromosome_length; i++)
    {
            child_1->get_chromosome()[i] = parent_2->get_chromosome()[i];
            child_2->get_chromosome()[i] = parent_1->get_chromosome()[i];
    }

    return index;
}


void Population::CHC_generation(Population* child)
{
    Population *temp = new Population(options);
    int index = -1;
    for(int j = 0; j < options.population_size; j++)
    {
        double fitness = 0;
        for(int i = 0; i < options.population_size*2; i++)
        {
            if(i < options.population_size)
            {
                if(members[i].get_fitness() >= fitness)
                {
                    fitness = members[i].get_fitness();
                    index = i;
                }
            }
            else
            {
                if(child->members[i - options.population_size].get_fitness() >= fitness)
                {
                    fitness = child->members[i - options.population_size].get_fitness();
                    index = i;
                }
            }
        }

        if(index < options.population_size)
        {
            temp->members[j].copy_individual_data(members[index]);
            temp->set_transform_data_by_row(transform_data[index],j);
            temp->transform_data[j][options.m_isParent_index] = 1;
            members[index].set_fitness(-1);
        }
        else
        {
            temp->members[j].copy_individual_data(child->members[index - options.population_size]);
            temp->set_transform_data_by_row(child_transform_data[index - options.population_size],j);
            child->members[index - options.population_size].set_fitness(-1);
        }
    }

    // child = temp;
    // delete child;
    // child = new Population(options);
    child->copy_population(*temp);

    //TEST
    // std::cout << "POP::CHC(END): after child copy temp" << std::endl;
    // std::cout << "POP::CHC(END): child members" << std::endl;
    for(int i = 0; i < options.population_size; i++)
    {
        verify_string_equivalence(&child->get_members()[i], &temp->get_members()[i], "CHC TEST FOR CHILD = TEMP");
    }
    // char temp_c;
    // std::cin >> temp_c;

}
// void Population::CHC_generation(Population* child)
// {
//     Population temp(options);
//     int index = -1;
//     for(int j = 0; j < options.population_size; j++)
//     {
//         double fitness = 0;
//         for(int i = 0; i < options.population_size*2; i++)
//         {
//             if(i < options.population_size)
//             {
//                 if(members[i].get_fitness() >= fitness)
//                 {
//                     fitness = members[i].get_fitness();
//                     index = i;
//                 }
//             }
//             else
//             {
//                 if(child->members[i - options.population_size].get_fitness() >= fitness)
//                 {
//                     fitness = child->members[i - options.population_size].get_fitness();
//                     index = i;
//                 }
//             }
//         }

//         if(index < options.population_size)
//         {
//             temp.members[j] = members[index];
//             for(int i = 0; i < transform_data[j][0]; i++)
//             {
//                 temp.transform_data[j][i] = transform_data[index][i];
//             }
//             temp.transform_data[j][options.m_isParent_index] = 1;
//             members[index].set_fitness(-1);
//         }
//         else
//         {
//             temp.members[j] = child->members[index - options.population_size];
//             for(int i = 0; i < child_transform_data[j][0]; i++)
//             {
//                 temp.transform_data[j][i] = child_transform_data[index - options.population_size][i];
//             }
//             child->members[index - options.population_size].set_fitness(-1);
//         }
//     }

//     // child = temp;
//     // delete child;
//     // child = new Population(options);
//     child->copy_population(temp);

//     //TEST
//     std::cout << "POP::CHC(END): after child copy temp" << std::endl;
//     std::cout << "POP::CHC(END): child members" << std::endl;
//     for(int i = 0; i < options.population_size; i++)
//     {
//         verify_string_equivalence(&child->get_members()[i], &temp.get_members()[i], "CHC TEST FOR CHILD = TEMP");
//     }
//     // char temp_c;
//     // std::cin >> temp_c;

// }

//TEST
void Population::print_pop()
{
    for(int i = 0; i < options.population_size; i++)
    {
        std::cout << "MEM_"<<i<<": ";
        members[i].print_ind();
    }
    std::cout << std::endl;
}

void Population::print_xover_mut_data()
{
    if(transform_data != nullptr)
    {
        for(int i = 0; i < options.population_size; i++)
        {
            for(int j = 0; j < get_transform_data()[i][0]; j++)
            {
                if(j == 0)
                    std::cout << "MEM_" << i << ": " << get_transform_data()[i][j] << " ";
                else
                    std::cout << get_transform_data()[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
}