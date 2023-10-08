//TESTS IN SETUP_OPTIONS(), EXTNCTION_CHECK(), EXTINCTION_EVENT()
#include "ga.h"

GA::GA(int argc, char *argv[], int eval_option, int iterator)
{
    setup_options(argc, argv, eval_option, iterator);
}

GA::~GA()
{
    if(options.bit_length != nullptr)
        delete options.bit_length;

    if(options.scaler != nullptr)
        delete options.scaler;

    if(options.max_variable_value != nullptr)
        delete options.max_variable_value;

    // if(grandparent != nullptr)
    //     delete grandparent;

    // if(parent != nullptr)
    //     delete parent;

    // if(child != nullptr)
    //     delete child;

    // if(m_temp != nullptr)
    //     delete m_temp;
}

void GA::setup_options(int argc, char *argv[], int eval_option, int iterator)
{
    std::stringstream ss1;
    std::stringstream ss2;
    std::string temp1;
    std::string temp2;
    int previous_iterator = iterator - 1;
    ss1 << iterator;
    ss1 >> temp1;
    ss2 << previous_iterator;
    ss2 >> temp2;

    options.GA_iteration = iterator;
    options.random_seed = time(NULL) + iterator;
    options.extinction_interval = 1;
    options.convergence_resolution_threshold = 0.0015;
    options.super_individual_threshold = 1.004;
    options.semi_super_individual_threshold = 1.002;
    
    //FLOORPLANNING
    options.penalty_weight_1 = 2;
    options.penalty_weight_2 = 2;
    options.variable_count = 7;

    options.living_width_bit_length = 6;
    options.kitchen_length_bit_length = 7;
    options.kitchen_width_bit_length = 7;
    options.hall_width_bit_length = 5;
    options.bed_1_width_bit_length = 4;
    options.bed_2_width_bit_length = 6;
    options.bed_3_width_bit_length = 6;
                                            //RESOLUTION:
    options.living_width_scaler = 11.81255; // 0.08
    options.kitchen_length_scaler = 10.584; // 0.09
    options.kitchen_width_scaler = 10.584;  // 0.09
    options.hall_width_scaler = 12.4;       // 0.08
    options.bed_1_width_scaler = 11.3;      // 0.09
    options.bed_2_width_scaler = 14.5385;   // 0.07
    options.bed_3_width_scaler = 15.75;     // 0.06

    options.living_width_max_value = 5.33333;
    options.kitchen_length_max_value = 12;
    options.kitchen_width_max_value = 12;
    options.hall_width_max_value = 2.5;
    options.bed_1_width_max_value = 1.33;
    options.bed_2_width_max_value = 4.33333;
    options.bed_3_width_max_value = 4.0;

    options.living_width_offset = 8;
    options.kitchen_length_offset = 6;
    options.kitchen_width_offset = 6;
    options.hall_width_offset = 3.5;
    options.bed_1_width_offset = 10;
    options.bed_2_width_offset = 9;
    options.bed_3_width_offset = 8;


    options.bit_length = new int[7]{options.living_width_bit_length, options.kitchen_length_bit_length, options.kitchen_width_bit_length,
                                        options.hall_width_bit_length, options.bed_1_width_bit_length, options.bed_2_width_bit_length,
                                            options.bed_3_width_bit_length};

    options.scaler = new double[7]{options.living_width_scaler, options.kitchen_length_scaler, options.kitchen_width_scaler,
                                        options.hall_width_scaler, options.bed_1_width_scaler, options.bed_2_width_scaler,
                                            options.bed_3_width_scaler};

    options.max_variable_value = new double[7]{options.living_width_max_value, options.kitchen_length_max_value, options.kitchen_width_max_value,
                                                options.hall_width_max_value, options.bed_1_width_max_value, options.bed_2_width_max_value,
                                                    options.bed_3_width_max_value};

    switch(eval_option)
    {
        case 1:
            options.chromosome_length = 27;
            options.population_size = 50;
            options.max_generations = 100;
            options.probability_mutation = 0.001;
            options.probability_x = 0.9;
            options.input_file = "output_deJong_F1_" + temp2 + ".txt";
            options.input_file_o = "output_deJong_F1_O_" + temp2 + ".txt";
            options.output_file = "output_deJong_F1_" + temp1 + ".txt";
            options.output_file_o = "output_deJong_F1_O_" + temp1 + ".txt";
            options.ave_file = "output_deJong_F1_AVE.txt";
            options.ave_file_o = "output_deJong_F1_O_AVE.txt";
            options.print_precision = 2;
            options.print_precision_o = 5;
            break;
        case 2:
            options.chromosome_length = 22;
            options.population_size = 50;
            options.max_generations = 100;
            options.probability_mutation = 0.05;
            options.probability_x = 0.99;
            options.input_file = "output_deJong_F2_" + temp2 + ".txt";
            options.input_file_o = "output_deJong_F2_O_" + temp2 + ".txt";
            options.output_file = "output_deJong_F2_" + temp1 + ".txt";
            options.output_file_o = "output_deJong_F2_O_" + temp1 + ".txt";
            options.ave_file = "output_deJong_F2_AVE.txt";
            options.ave_file_o = "output_deJong_F2_O_AVE.txt";
            options.print_precision = 2;
            options.print_precision_o = 5;
            break;
        case 3:
            options.chromosome_length = 45;
            options.population_size = 500;
            options.max_generations = 1000;
            options.probability_mutation = 0.05;
            options.probability_x = .9;
            options.input_file = "output_deJong_F3_" + temp2 + ".txt";
            options.input_file_o = "output_deJong_F3_O_" + temp2 + ".txt";
            options.output_file = "output_deJong_F3_" + temp1 + ".txt";
            options.output_file_o = "output_deJong_F3_O_" + temp1 + ".txt";
            options.ave_file = "output_deJong_F3_AVE.txt";
            options.ave_file_o = "output_deJong_F3_O_AVE.txt";
            options.print_precision = 2;
            options.print_precision_o = 2;
            break;
        case 4:
            options.chromosome_length = 210;
            options.population_size = 500;
            options.max_generations = 1000;
            options.probability_mutation = 0.05;
            options.probability_x = 0.99;
            options.input_file = "output_deJong_F4_" + temp2 + ".txt";
            options.input_file_o = "output_deJong_F4_O_" + temp2 + ".txt";
            options.output_file = "output_deJong_F4_" + temp1 + ".txt";
            options.output_file_o = "output_deJong_F4_O_" + temp1 + ".txt";
            options.ave_file = "output_deJong_F4_AVE.txt";
            options.ave_file_o = "output_deJong_F4_O_AVE.txt";
            options.print_precision = 5;
            options.print_precision_o = 2;
            break;
        case 5:
            options.chromosome_length = 32;
            options.population_size = 50;
            options.max_generations = 100;
            options.probability_mutation = 0.05;
            options.probability_x = 0.99;
            options.input_file = "output_deJong_F5" + temp2 + ".txt";
            options.input_file_o = "output_deJong_F5_O_" + temp2 + ".txt";
            options.output_file = "output_deJong_F5" + temp1 + ".txt";
            options.output_file_o = "output_deJong_F5_O_" + temp1 + ".txt";
            options.ave_file = "output_deJong_F5_AVE.txt";
            options.ave_file_o = "output_deJong_F5_O_AVE.txt";
            options.print_precision = 5;
            options.print_precision_o = 5;
            break;
        case 6:
            options.chromosome_length = 0;
            for(int i = 0; i < options.variable_count; i++)
            {
                options.chromosome_length += options.bit_length[i];
            }

            //REAL
            //OPTIONS CANNOT EQUAL ODD NUMBER OR SEGMENT FAULT!!!
            options.population_size = 500;
            options.max_generations = 5000;
            options.probability_mutation = 0.6;
            options.probability_x = 0.99;
            options.input_file = "output_floorPlanning_" + temp2 + ".txt";
            options.input_file_o = "output_floorPlanning_" + temp2 + "_ObjFnc.txt";
            options.output_file = "output_floorPlanning_" + temp1 + ".txt";
            options.output_file_o = "output_floorPlanning_" + temp1 + "_ObjFnc.txt";
            options.ave_file = "output_floorPlanning_AVE.txt";
            options.ave_file_o = "output_floorPlanning_AVE_ObjFnc.txt";
            options.print_precision = 2;
            options.print_precision_o = 2;
            break;
    }
}

void GA::init(int eval_option, int report_option)
{
    if(report_option == 1)
    {
        std::ofstream out(options.output_file);
        out << "GEN,\t\tMIN,\t\t\t\tAVE,\t\t\t\tMAX,\t\t\t\tCONV,\t\t\tSEMI,\t\tSUPER,\tT_SEMI,\tT_SUPER,\tL_L,\t\t\tL_W,\t\tL_a,\t\tK_L,\t\tK_W,\t\tK_A,\t\tH_L,\t\tH_W,\t\tH_A,\t\tB1_L,\t\tB1_W,\t\tB1_A,\t\tB2_L,\t\tB2_W,\t\tB2_A,\t\tB3_L,\t\tB3_W,\t\tB3_A,\n";
        out.close();
    }
    
    //NOTE THAT OBJECTIVE LOGGING HAS BEEN COMMENTED OUT FOR FLOORPLANNING EVALUATIONS FOR THE TIME BEING
    // std::ofstream out_2(options.output_file_o);
    // out_2 << "GEN,\t\tMIN,\t\t\tAVE,\t\t\tMAX,\t\t\tCONV,\t\tSEMI,\t\tSUPER,\t\tL_L,\t\tL_W,\t\tL_a,\t\tK_L,\t\tK_W,\t\tK_A,\t\tH_L,\t\tH_W,\t\tH_A,\t\tB1_L,\t\tB1_W,\t\tB1_A,\t\tB2_L,\t\tB2_W,\t\tB2_A,\t\tB3_L,\t\tB3_W,\t\tB3_A,\n";
    // out_2.close();

    extinction_counter = 0;
    parent = new Population(options);
    child = new Population(options);
    m_temp = new Population(options);

    for(int i = 0; i < options.population_size; i++)
        parent->init_transform_data(i);

    try
    {
        parent->evaluate(eval_option, 1, options.random_seed, 0);
        parent->evaluate_o(eval_option, 2, options.random_seed, 0);
    }
    catch(double variable_value[])
    {
        throw(variable_value);
    }

    parent->stats(total_super_individuals, total_semi_super_individuals);

    if(report_option == 1)
        parent->report(0, 1, total_super_individuals, total_semi_super_individuals);
    
    //OBJECTIVE OPERATIONS REPORT COMMENTED OUT
    // parent->stats_o();
    // parent->report_o(0, 1);
}

void GA::run(int eval_option, int report_option)
{
    bool extinction = false;

    for(int i = 1; i < options.max_generations; i++)
    {
        //TEST: PRINTS GENERATION FOR CLARITY
        // std::cout << "\n\nGENERATION = " << i << std::endl << std::endl;

        int srand_offset = i*options.population_size;

        // UNIT TEST OBJECTS
        Individual *test = new Individual[options.population_size];
        for(int i = 0; i < options.population_size; i++)
            test[i].copy_individual_data(parent->get_members()[i]);
    
        parent->generation(child, i);
        
        try
        {
            child->evaluate(eval_option, 1, options.random_seed, srand_offset);
            child->evaluate_o(eval_option, 2, options.random_seed, srand_offset);
        }
        catch(double variable_value[])
        {
            throw(variable_value);
        }

        //SET THE CHILD'S TRANSFORM_DATA WITH THE PARENTS CHILD_TRANSFORM_DATA
        for(int j = 0; j < options.population_size; j++)
        {
            for(int k = 0; k < parent->get_child_transform_data(j)[0]; k++)
            {
                child->get_transform_data(j)[k] = parent->get_child_transform_data(j)[k];
            }
        }

        parent->CHC_generation(child, m_temp);

        // UNIT TESTS: STRING EQUIVALENCE
        for(int j = 0; j < options.population_size; j++)
        {
            verify_string_equivalence(&parent->get_members()[j],&test[j],"GA::RUN, AFTER CHC GENERATION");
        }

        // UNIT TEST: XOVER MUTATE MECHANISM
        verify_xover_mutation_mechanism(parent, child);

        child->stats(total_super_individuals, total_semi_super_individuals);

        if(report_option == 1)
            child->report(i, 1, total_super_individuals, total_semi_super_individuals);

        //OBJECTIVE OPERATIONS REPORT COMMENTED OUT
        // child->stats_o();
        // child->report_o(i, 1);

        //TEST: PRINT POPULATION AND TRANSFORM DATA
        // if(extinction)
        // {
        //     // std::cout << "\nPOP::RUN(BELOW REPORT)" << std::endl;
        //     // print_population_data();

        //     //TEST
        //     char temp;
        //     std::cin >> temp;
        //     extinction = false;
        // }
        
        Population *temp = parent;
        parent = child;
        child = temp;

        extinction = extinction_check(eval_option, options.random_seed, srand_offset);

        delete[] test;
    }

    // report_cleanup();
}

bool GA::extinction_check(int eval_option, int random_seed, int srand_offset)
{
    double convergence = parent->get_convergence();
    double convergence_check = convergence - 1;

    convergence_check < options.convergence_resolution_threshold ? extinction_counter++ : extinction_counter = 0;
    
    //TEST
    // std::cout << extinction_counter << std::endl;

    return extinction_counter == options.extinction_interval ? extinction_event(eval_option, options.random_seed, srand_offset) : false;
}

//IF USING CHC, FITTEST MEMBER IS AT TOP OF PARENT - OTHERWISE NEED TO REWRITE EXTINCTION_EVENT
bool GA::extinction_event(int eval_option, int random_seed, int srand_offset)
{
    //TEST
    std::cout << "EXTINCTION EVENT!" << std::endl;

    extinction_counter = 0;
    
    for(int i = 1; i < options.population_size; i++)
    {
        parent->get_members()[i].init(random_seed, srand_offset + i);
        parent->init_transform_data(i);
    }

    try
    {
        parent->evaluate(eval_option, 1, options.random_seed, srand_offset);
        // parent->evaluate_o(eval_option, 2, options.random_seed, srand_offset);
    }
    catch(double variable_value[])
    {
        throw(variable_value);
    }

    parent->stats(total_super_individuals, total_semi_super_individuals);
    // parent->stats_o();

    return true;
}

void GA::report_cleanup()
{
    if(options.GA_iteration != 0)
    {
        std::remove(options.input_file.c_str());
        std::remove(options.input_file_o.c_str());
    }
}

const Options GA::get_options()
{
    return options;
}

void GA::print_population_data()
{
        std::cout << "PARENT POPULATION" << std::endl;
        parent->print_pop();
        std::cout << "PARENT TRANSFORM DATA" << std::endl;
        parent->print_xover_mut_data();
        std::cout << "\nCHILD POPULATION" << std::endl;
        child->print_pop();
        std::cout << "CHILD TRANSFORM DATA" << std::endl;
        child->print_xover_mut_data();
        std::cout << std::endl;
}