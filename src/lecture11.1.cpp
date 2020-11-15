/**
 * @file lecture11.1.cpp
 * @brief Lecture 11.1
 * exploring the multi aray library in boost
 * @assignment Lecture 11.1
 * @author Liam Cannon
 * @credit https://theboostcpplibraries.com/boost.program_options
 * @credit 
 * @date 11/15/2020
 * 
*/
#include <boost/multi_array.hpp>
#include <boost/program_options.hpp>
#include <cassert>
#include <iostream>

using namespace std;
using namespace boost::program_options;

void createArray(int x, int y, int z);

int main(int argc, const char *argv[])
{
    try
    {
        options_description desc{"Options"};
        desc.add_options()("help, h", "Help Menu")("x", value<int>()->default_value(1), "X Val")("y", value<int>()->default_value(1), "Y Val")("z", value<int>()->default_value(1), "Z Val");
        variables_map vm;
        store(parse_command_line(argc, argv, desc), vm);
        int x, y, z;
        if (vm.count("help"))
            cout << desc << endl;
        else
        {
            if (vm.count("x"))
            {
                x = vm["x"].as<int>();
            }
            if (vm.count("y"))
            {
                y = vm["y"].as<int>();
            }
            if (vm.count("z"))
            {
                z = vm["z"].as<int>();
            }
        }
        createArray(x, y, z);

    }    // from https://theboostcpplibraries.com/boost.program_options
    catch(const error &ex) {
        cerr << ex.what() << endl;
    }
}

void createArray(int x, int y, int z)
{
    cout << "X: " << x << " Y: " << y << " Z: " << z << endl;
    typedef boost::multi_array<int, 3> array_type;
    typedef array_type::index index;
    // this is from the example for multi arrays 

    // this loop should print z layers of an xy grid
    // this was my take on how to display a 3D array in a terminal
    for(index i = 0; i != z; i++) {
        for(index j = 0; j != y; j++) {
            cout << "[]";
            for(index k = 1; k != x; k++) {
                cout << "[]";
            }
            cout << endl;
        }
        cout << endl;
    }
}
