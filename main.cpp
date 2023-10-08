#include "ga.h"
#include "test.h"

//AFTER TESTING REPORT CLEANUP FROM GA.CPP NEEDS TO BE COMMENTED BACK IN 
int main(int argc, char* argv[])
{
    // int count = 0;
    for(int j = 0; j < 1; j++)
    {
        //TEST
        std::cout << "MAIN::RUN = " << j << std::endl << std::endl;

        GA ga(argc, argv, 6, j);

        try
            {ga.init(6, 0);}
        catch(double variable_value[])
        {

            //TEST
            std::cout << "INIT " << j << std::endl;

            switch((int)variable_value[0] + 1)
            {
                case 1:
                    std::cout << "Living room max width ("<<ga.get_options().max_variable_value[0]<<") exceeded @ "<<variable_value[1]<<". Exiting..."<< std::endl;
                    return EXIT_FAILURE;
                case 2:
                    std::cout << "Kitchen max length ("<<ga.get_options().max_variable_value[1]<<") exceeded @ "<<variable_value[1]<<". Exiting..."<< std::endl;
                    return EXIT_FAILURE;
                case 3:
                    std::cout << "Kitchen max width ("<<ga.get_options().max_variable_value[2]<<") exceeded @ "<<variable_value[1]<<". Exiting..."<< std::endl;
                    return EXIT_FAILURE;
                case 4:
                    std::cout << "Hall max width ("<<ga.get_options().max_variable_value[3]<<") exceeded @ "<<variable_value[1]<<". Exiting..."<< std::endl;
                    return EXIT_FAILURE;
                case 5:
                    std::cout << "Bed 1 max width ("<<ga.get_options().max_variable_value[4]<<") exceeded @ "<<variable_value[1]<<". Exiting..."<< std::endl;
                    return EXIT_FAILURE;
                case 6:
                    std::cout << "Bed 2 max width ("<<ga.get_options().max_variable_value[5]<<") exceeded @ "<<variable_value[1]<<". Exiting..."<< std::endl;
                    return EXIT_FAILURE;
                case 7:
                    std::cout << "Bed 3 max width ("<<ga.get_options().max_variable_value[6]<<") exceeded @ "<<variable_value[1]<<". Exiting..."<< std::endl;
                    return EXIT_FAILURE;
            }
        }

        try
            {ga.run(6, 0);}
        catch(double variable_value[])
        {

            //TEST
            std::cout << "RUN " << j << std::endl; 

            switch((int)variable_value[0] + 1)
            {
                case 1:
                    std::cout << "Living room max width ("<<ga.get_options().max_variable_value[0]<<") exceeded @ "<<variable_value[1]<<". Exiting..."<< std::endl;
                    return EXIT_FAILURE;
                case 2:
                    std::cout << "Kitchen max length ("<<ga.get_options().max_variable_value[1]<<") exceeded @ "<<variable_value[1]<<". Exiting..."<< std::endl;
                    return EXIT_FAILURE;
                case 3:
                    std::cout << "Kitchen max width ("<<ga.get_options().max_variable_value[2]<<") exceeded @ "<<variable_value[1]<<". Exiting..."<< std::endl;
                    return EXIT_FAILURE;
                case 4:
                    std::cout << "Hall max width ("<<ga.get_options().max_variable_value[3]<<") exceeded @ "<<variable_value[1]<<". Exiting..."<< std::endl;
                    return EXIT_FAILURE;
                case 5:
                    std::cout << "Bed 1 max width ("<<ga.get_options().max_variable_value[4]<<") exceeded @ "<<variable_value[1]<<". Exiting..."<< std::endl;
                    return EXIT_FAILURE;
                case 6:
                    std::cout << "Bed 2 max width ("<<ga.get_options().max_variable_value[5]<<") exceeded @ "<<variable_value[1]<<". Exiting..."<< std::endl;
                    return EXIT_FAILURE;
                case 7:
                    std::cout << "Bed 3 max width ("<<ga.get_options().max_variable_value[6]<<") exceeded @ "<<variable_value[1]<<". Exiting..."<< std::endl;
                    return EXIT_FAILURE;
            }
        }
        catch(std::string xover_mutate_test)
        {
            std::cout << xover_mutate_test << std::endl;
            
            //TEST
            // char temp;
            // std::cin >> temp;
            // sleep(2);

            //REAL
            return EXIT_FAILURE;
        }
        
        // count++;
    }

    //TEST
    // std::cout << "OUTSIDE OF RUN: END OF PROGRAM" << std::endl;

    // std::cout << count << std::endl;

    // for(int i = 1; i <= 1; i++)
    // {
    //     GA ga(argc, argv, i, count - 1);

    //     report_averager(count, ga.options.output_file, ga.options.ave_file, ga.options.print_precision, ga.options.population_size);
    //     report_averager(count, ga.options.output_file_o, ga.options.ave_file_o, ga.options.print_precision_o, ga.options.population_size);
    // }

    // max_floorplanning_objective_value(atof(argv[1]),atof(argv[2]),atof(argv[3]));

}