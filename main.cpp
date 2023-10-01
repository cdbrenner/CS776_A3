#include "ga.h"
#include "test.h"

int main(int argc, char* argv[])
{

    int count = 0;
    for(int j = 0; j < 3; j++)
    {
        GA ga(argc, argv, 6, j);

        try
            {ga.init(6);}
        catch(double variable_value[])
        {
            switch((int)variable_value[0])
            {
                case 1:
                    std::cout << "Living room max width exceeded @ "<<variable_value[1]<<". Exiting..."<< std::endl;
                    return EXIT_FAILURE;
                case 2:
                    std::cout << "Kitchen max length exceeded @ "<<variable_value[1]<<". Exiting..."<< std::endl;
                    return EXIT_FAILURE;
                case 3:
                    std::cout << "Kitchen max width exceeded @ "<<variable_value[1]<<". Exiting..."<< std::endl;
                    return EXIT_FAILURE;
                case 4:
                    std::cout << "Hall max width exceeded @ "<<variable_value[1]<<". Exiting..."<< std::endl;
                    return EXIT_FAILURE;
                case 5:
                    std::cout << "Bed 1 max width exceeded @ "<<variable_value[1]<<". Exiting..."<< std::endl;
                    return EXIT_FAILURE;
                case 6:
                    std::cout << "Bed 2 max width exceeded @ "<<variable_value[1]<<". Exiting..."<< std::endl;
                    return EXIT_FAILURE;
                case 7:
                    std::cout << "Bed 3 max width exceeded @ "<<variable_value[1]<<". Exiting..."<< std::endl;
                    return EXIT_FAILURE;
            }
        }

        try
            {ga.run(6);}
        catch(double variable_value[])
        {
            switch((int)variable_value[0])
            {
                case 1:
                    std::cout << "Living room max width exceeded @ "<<variable_value[1]<<". Exiting..."<< std::endl;
                    return EXIT_FAILURE;
                case 2:
                    std::cout << "Kitchen max length exceeded @ "<<variable_value[1]<<". Exiting..."<< std::endl;
                    return EXIT_FAILURE;
                case 3:
                    std::cout << "Kitchen max width exceeded @ "<<variable_value[1]<<". Exiting..."<< std::endl;
                    return EXIT_FAILURE;
                case 4:
                    std::cout << "Hall max width exceeded @ "<<variable_value[1]<<". Exiting..."<< std::endl;
                    return EXIT_FAILURE;
                case 5:
                    std::cout << "Bed 1 max width exceeded @ "<<variable_value[1]<<". Exiting..."<< std::endl;
                    return EXIT_FAILURE;
                case 6:
                    std::cout << "Bed 2 max width exceeded @ "<<variable_value[1]<<". Exiting..."<< std::endl;
                    return EXIT_FAILURE;
                case 7:
                    std::cout << "Bed 3 max width exceeded @ "<<variable_value[1]<<". Exiting..."<< std::endl;
                    return EXIT_FAILURE;
            }
        }
        
        count++;
    }

    // std::cout << count << std::endl;

    // for(int i = 1; i <= 1; i++)
    // {
    //     GA ga(argc, argv, i, count - 1);

    //     report_averager(count, ga.options.output_file, ga.options.ave_file, ga.options.print_precision, ga.options.population_size);
    //     report_averager(count, ga.options.output_file_o, ga.options.ave_file_o, ga.options.print_precision_o, ga.options.population_size);
    // }

    // max_floorplanning_objective_value(atof(argv[1]),atof(argv[2]),atof(argv[3]));

}