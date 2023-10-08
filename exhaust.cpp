#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include <iomanip>
#define LOADING_VALUE 100000000

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        std::cout << "Must provide resolution for search as 2nd command line argument" << std::endl;
        return EXIT_FAILURE;
    }

    double resolution = strtod(argv[1], NULL);

    double living_width = 8;
    double kitchen_length = 6;
    double kitchen_width = 6;
    double hall_width = 3.5;
    double bed_1_width = 10;
    double bed_2_width = 9;
    double bed_3_width = 8;

    double living_area;
    double kitchen_area;
    double hall_area;
    double bed_1_area;
    double bed_2_area;
    double bed_3_area;
    
    double objective_function;
    double objective = 0;
    double fitness = 0;
    double max_fitness = 0;

    double dimensions[6];
    dimensions[0] = living_width;
    dimensions[1] = kitchen_length;
    dimensions[2] = hall_width;
    dimensions[3] = bed_1_width;
    dimensions[4] = bed_2_width;
    dimensions[5] = bed_3_width;;

    long long iteration = 0;

    for(int a = 0; a < 12/resolution; a++)
    {
        living_area = 1.5*pow(living_width,2);
        if(living_area >= 120 && living_area <= 300)
        {
            for(int b = 0; b < 12; b++)
            {
                kitchen_area = kitchen_length * kitchen_width;
                if(kitchen_area >= 50 && kitchen_area <= 120)
                {
                    for(int d = 0; d < 25/resolution; d++)
                    {
                        hall_area = 5.5 * hall_width;
                        if(hall_area >= 19 && hall_area <= 72)
                        {
                            for(int e = 0; e < 7/resolution; e++)
                            {
                                bed_1_area = 1.5*pow(bed_1_width,2);
                                if(bed_1_area >= 100 && bed_1_area <= 180)
                                {
                                    for(int f = 0; f < 11/resolution; f++)
                                    {
                                        bed_2_area = 1.5*pow(bed_2_width,2);
                                        if(bed_2_area >= 100 && bed_2_area <= 180)
                                        {
                                            for(int g = 0; g < 10/resolution; g++)
                                            {
                                                bed_3_area = 1.5*pow(bed_3_width,2);
                                                if(bed_3_area >= 100 && bed_3_area <= 180)
                                                {
                                                    objective_function = living_area + 2*kitchen_area + hall_area + bed_1_area + bed_2_area + bed_3_area;
                                                    fitness = 50000 - objective_function;
                                                    if(fitness > max_fitness)
                                                    {
                                                        max_fitness = fitness;
                                                        objective = objective_function;
                                                        dimensions[0] = living_width;
                                                        dimensions[1] = kitchen_length;
                                                        dimensions[2] = hall_width;
                                                        dimensions[3] = bed_1_width;
                                                        dimensions[4] = bed_2_width;
                                                        dimensions[5] = bed_3_width;
                                                    }
                                                }
                                                iteration++;
                                                if(iteration%LOADING_VALUE == 0)
                                                    std::cout << "iteration: " << iteration << std::endl;

                                                bed_3_width += resolution;
                                            }
                                        }
                                        iteration++;
                                        if(iteration%LOADING_VALUE == 0)
                                            std::cout << "iteration: " << iteration << std::endl;
                                            
                                        bed_2_width += resolution;
                                    }
                                }
                                iteration++;
                                if(iteration%LOADING_VALUE == 0)
                                    std::cout << "iteration: " << iteration << std::endl;
                                
                                bed_1_width += resolution;
                            }
                        }
                        iteration++;
                        if(iteration%LOADING_VALUE == 0)
                            std::cout << "iteration: " << iteration << std::endl;
                        
                        hall_width += resolution;
                    }
                }
                iteration++;
                if(iteration%LOADING_VALUE == 0)
                    std::cout << "iteration: " << iteration << std::endl;
                
                kitchen_length += resolution;
            }
        }
        iteration++;
        if(iteration%LOADING_VALUE == 0)
            std::cout << "iteration: " << iteration << std::endl;
        
        living_width += resolution;
    }

    std::string res;
    std::stringstream ss;
    ss << resolution;
    ss >> res;

    std::ofstream out("exhaustive_floorplanning_" + res + ".csv");
    out << "FITNESS & OBJECTIVE,,\n";
    out << "max_fitness, " << std::fixed << std::setprecision(2) << max_fitness << ",\n";
    out << "min_objective, " << std::fixed << std::setprecision(2) << objective << ",\n\n";
    out << "LENGTHS & WIDTHS,,\n";
    out << "living length, " << 1.5*dimensions[0] << ",\n";
    out << "living width, " << dimensions[0] << ",\n";
    out << "kitchen length, " << dimensions[1] << ",\n";
    out << "kitchen width, " << "6" << ",\n";
    out << "hall length, " << "5.5" << ",\n";
    out << "hall width, " << dimensions[2] << ",\n";
    out << "bed_1 length, " << 1.5*dimensions[3] << ",\n";
    out << "bed_1 width, " << dimensions[3] << ",\n";
    out << "bed_2 length, " << 1.5*dimensions[4] << ",\n";
    out << "bed_2 width, " << dimensions[4] << ",\n";
    out << "bed_3 length, " << 1.5*dimensions[5] << ",\n";
    out << "bed_3 width, " << dimensions[5] << std::endl << std::endl;
    out << "AREAS,,\n";
    out << "Living Area, " << 1.5 * pow(dimensions[0], 2) << std::endl;
    out << "Kitchen Area, " << 6 * dimensions[1] << std::endl;
    out << "Hall Area, " << 5.5 * dimensions[2] << std::endl;
    out << "Bed_1 Area, " << 1.5 * pow(dimensions[3], 2) << std::endl;
    out << "Bed_2 Area, " << 1.5 * pow(dimensions[4], 2) << std::endl;
    out << "Bed_3 Area, " << 1.5 * pow(dimensions[5], 2) << std::endl;
    out.close();

}