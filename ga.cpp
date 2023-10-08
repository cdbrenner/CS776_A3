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
    options.extinction_interval = 1000;
    options.convergence_resolution = 0.0008;
    
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

            //TEST
            // std::cout << "TEST::GA.cpp -> chromosome_length = " << options.chromosome_length << std::endl;
 
            //TEST
            //OPTIONS CANNOT EQUAL ODD NUMBER OR SEGMENT FAULT!!!
            options.population_size = 10;
            options.max_generations = 50;
            //REAL
            //OPTIONS CANNOT EQUAL ODD NUMBER OR SEGMENT FAULT!!!
            // options.population_size = 500;
            // options.max_generations = 5000;
            options.probability_mutation = 0.1;
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
    //REAL: COMMENTED OUT FOR TESTING XOVER_MUTATE TEST FUNCTION
    if(report_option == 1)
    {
        std::ofstream out(options.output_file);
        out << "GEN,\t\tMIN,\t\t\tAVE,\t\t\tMAX,\t\t\tCONV,\t\tSEMI,\t\tSUPER,\t\tL_L,\t\tL_W,\t\tL_a,\t\tK_L,\t\tK_W,\t\tK_A,\t\tH_L,\t\tH_W,\t\tH_A,\t\tB1_L,\t\tB1_W,\t\tB1_A,\t\tB2_L,\t\tB2_W,\t\tB2_A,\t\tB3_L,\t\tB3_W,\t\tB3_A,\n";
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
    {
        add_dynamic_element_to_end(parent->get_transform_data()[i], parent->get_transform_data()[i][0], i);
        parent->get_transform_data()[i][0]++;;
        add_dynamic_element_to_end(parent->get_transform_data()[i], parent->get_transform_data()[i][0], i);
        parent->get_transform_data()[i][0]++;;
        add_dynamic_element_to_end(parent->get_transform_data()[i], parent->get_transform_data()[i][0], -1); // -1 INDICATES NO XOVER (1ST GENERATION CHARACTERISTIC)
        parent->get_transform_data()[i][0]++;;
    }

    try
    {
        parent->evaluate(eval_option, 1, options.random_seed, 0);
        parent->evaluate_o(eval_option, 2, options.random_seed, 0);
    }
    catch(double variable_value[])
    {
        throw(variable_value);
    }

    parent->stats();

    if(report_option == 1)
        parent->report(0, 1);
    
    //OBJECTIVE OPERATIONS REPORT COMMENTED OUT
    // parent->stats_o();
    // parent->report_o(0, 1);
}

void GA::run(int eval_option, int report_option)
{
    for(int i = 1; i < options.max_generations; i++)
    {
        //TEST
        // std::cout << "GA::RUN(TOP): before test init" << std::endl;

        //UNIT TEST OBJECTS
        Individual *test = new Individual[options.population_size];
        for(int i = 0; i < options.population_size; i++)
        {
            test[i].init_chromosome_array(options.chromosome_length);
            test[i].copy_individual_data(parent->get_members()[i]);
        }
    

        //TEST: CURRENT TEST!!!!
        std::cout << "\n\nGA::RUN(TOP): GEN = " << i << std::endl << std::endl;
        // std::cout << "GA::RUN(TOP): PARENT POPULATION" << std::endl;
        // parent->print_pop();
        // if(grandparent != nullptr)
        // {
        //     std::cout << "GA::RUN(): GRANDPARENT POPULATION" << std::endl;
        //     grandparent->print_pop();
        // }

        parent->generation(child, i);
        
        // TEST: CURRENT TEST!!!
        // std::cout << "GA::RUN(BELOW GEN): PARENT POPULATION" << std::endl;
        // parent->print_pop();
        // std::cout << "GA::RUN(BELOW GEN): CHILD POPULATION" << std::endl;
        // child->print_pop();

        //TEST
        // char temp_c;
        // std::cin >> temp_c;

        try
        {
            child->evaluate(eval_option, 1, options.random_seed, i*options.population_size);
            child->evaluate_o(eval_option, 2, options.random_seed, i*options.population_size);
        }
        catch(double variable_value[])
        {
            throw(variable_value);
        }
        
        //TEST
        // std::cout << "GA::RUN(BELOW EVAL CHILD): PARENT POPULATION" << std::endl;
        // parent->print_pop();
        // std::cout << "CHILD TRANSFORM DATA LENGTH [0] = " << parent->get_child_transform_data()[0][0] << std::endl;
        std::cout << "GA::RUN(ABOVE SET CHILD TRANSFORM)" << std::endl;

        child->set_transform_data(parent->get_child_transform_data());
        
        //TEST
        std::cout << "GA::RUN(BELOW SET CHILD TRANSFORM)" << std::endl;
        // std::cout << "GA::RUN(BELOW SET TRANSFORM): PARENT POPULATION" << std::endl;
        // parent->print_pop();

        parent->CHC_generation(child);
        
        //TEST
        std::cout << "GA::RUN(BELOW CHC)" << std::endl;
        

        //UNIT TEST
        for(int i = 0; i < options.population_size; i++)
        {
            verify_string_equivalence(&parent->get_members()[i],&test[i],"GA::RUN, AFTER CHC GENERATION");
        }

        // MAIN TEST! MAIN TEST! MAIN TEST! MAIN TEST! MAIN TEST! MAIN TEST! MAIN TEST! MAIN TEST! MAIN TEST!
        // MAIN TEST! MAIN TEST! MAIN TEST! MAIN TEST! MAIN TEST! MAIN TEST! MAIN TEST! MAIN TEST! MAIN TEST!
        // if(grandparent != nullptr)
        // {
        //     std::cout << "GA::RUN(): PARENT POPULATION" << std::endl;
        //     parent->print_pop();
        //     std::cout << "GA::RUN(): PARENT XOVER_MUTATE DATA" << std::endl;
        //     parent->print_xover_mut_data();
        //     std::cout << std::endl;
        // }   


        //TEST
        if(grandparent != nullptr)
        {
            std::cout << "GA::RUN(BELOW CHC): GRANDPARENT POPULATION" << std::endl;
            grandparent->print_pop();
        }
        // TEST
        std::cout << "GA::RUN(BELOW CHC): PARENT POPULATION" << std::endl;
        parent->print_pop();
        std::cout << "GA::RUN(BELOW CHC): PARENT XOVER_MUTATE DATA" << std::endl;
        parent->print_xover_mut_data();
        std::cout << std::endl;

        // std::cout << "GA::RUN(BELOW CHC): PARENT POPULATION - MANUAL" << std::endl;
        // for(int i = 0; i < options.population_size; i++)
        // {
        //     for(int j = 0; j < options.chromosome_length; j++)
        //     {
        //         if(j == 0)
        //             std::cout << "MEM["<<i<<"]: " << parent->get_members()[i].get_chromosome()[j];
        //         else
        //             std::cout << parent->get_members()[i].get_chromosome()[j];
        //     }
        //     std::cout << std::endl;
        // }

        //CURRENT TEST
        std::cout << std::endl;
        std::cout << "GA::RUN(BELOW CHC): CHILD POPULATION" << std::endl;
        child->print_pop();
        std::cout << "GA::RUN(BELOW CHC): CHILD XOVER_MUTATE DATA" << std::endl;
        child->print_xover_mut_data();
        std::cout << std::endl;

        //TEST
        // std::cout << "GEN = " << i << std::endl;
        // char temp_c;
        // std::cin >> temp_c;

        verify_xover_mutation_mechanism(parent, child, grandparent, i);

        child->stats();

        if(report_option == 1)
            child->report(i, 1);

        //OBJECTIVE OPERATIONS REPORT COMMENTED OUT
        // child->stats_o();
        // child->report_o(i, 1);

        // TEST
        std::cout << "GA::RUN(): BEFORE GRANDPARENT = PARENT" << std::endl;
        
        grandparent = new Population(*parent);
        
        // TEST
        std::cout << "GA::RUN(): AFTER GRANDPARENT = PARENT" << std::endl;

        //TEST
        // std::cout << "GA::RUN(): AT GRANDPARENT = PARENT" << std::endl;
        // std::cout << "GA::RUN(): PARENT POPULATION" << std::endl;
        // parent->print_pop();
        // std::cout << "GA::RUN(): GRANDPARENT POPULATION" << std::endl;
        // grandparent->print_pop();
        
        Population *temp_pop = parent;
        parent = child;
        child = temp_pop;

        // extinction_check();

        delete[] test;
    }

    // report_cleanup();

    //TEST
    // std::cout << "END OF RUN" << std::endl;
}

void GA::extinction_check()
{
    double convergence = parent->get_convergence();
    double convergence_check = convergence - 1;

    convergence_check < options.convergence_resolution ? extinction_counter++ : 0;
    
    //TEST
    // std::cout << extinction_counter << std::endl;

    extinction_counter == options.extinction_interval ? extinction_event() : void();
}

void GA::extinction_event()
{
    extinction_counter = 0;
    
    //TEST
    // std::cout << "EXTINCTION EVENT! EXTINCTION EVENT! EXTINCTION EVENT! EXTINCTION EVENT! EXTINCTION EVENT!" << std::endl;


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