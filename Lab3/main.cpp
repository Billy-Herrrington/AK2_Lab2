#include <iostream>
#include <getopt.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct localArgs {
    int verbose;
    int my_list[4];
    int my_boolean;
    string my_file;
} local_arguments;

static const char *optString = "v:l:b:f:h?";

static const struct option longOpts[] = {
        { "verbose", required_argument, nullptr, 'v'},
        { "help", no_argument, nullptr, 'h'},
        { "list", optional_argument, nullptr, 'l'},
        { "boolean", optional_argument, nullptr, 'b'},
        { "file", optional_argument, nullptr, 'f'},
        {nullptr, no_argument, nullptr, 0}
};

void display_usage()
{
    puts("List of valid keys: "
         "\nArguments"
         "\nverbose - enable verbose mode of program; "
         "\nhelp - display help "
         "\nlist - list of values "
         "\nboolean - optional flag "
         "\nfile - file to save the result");
    exit ( EXIT_FAILURE );
}
void display_args()
{
    cout << "local_arguments.verbose = " << local_arguments.verbose << endl;
    cout << "local_arguments.list = " << local_arguments.my_list[0] << ", " <<
         local_arguments.my_list[1] << ", " <<
         local_arguments.my_list[2] << ", " <<
         local_arguments.my_list[3] << "." << endl;
    cout << "local_arguments.boolean = " << local_arguments.my_boolean << endl;
    cout << "local_arguments.file = " << local_arguments.my_file << endl;
}
int main( int argc, char *argv[] )
{
    int opt = 0;
    int longIndex = 0;
    local_arguments.verbose = 2;
    local_arguments.my_list[0] = 1;
    local_arguments.my_list[1] = 2;
    local_arguments.my_list[2] = 3;
    local_arguments.my_list[3] = 4;
    local_arguments.my_boolean = 1;
    local_arguments.my_file = "log.txt";
    int counter = 0;
    opt = getopt_long( argc, argv, optString, longOpts, &longIndex );
    //vlbfh?
    while( opt != -1 ) {
        switch( opt ) {
            case 'v':
                local_arguments.verbose = atoi(optarg);
                break;
            case 'l':
                local_arguments.my_list[0] = optarg[0] - '0';
                local_arguments.my_list[1] = optarg[2] - '0';
                local_arguments.my_list[2] = optarg[4] - '0';
                local_arguments.my_list[3] = optarg[6] - '0';
                break;
            case 'b':
                local_arguments.my_boolean = atoi(optarg);
                break;
            case 'f':
                local_arguments.my_file = optarg;
                break;
            case 'h':
                display_usage();
                break;
            case '?':
                break;
            default:
                break;
        }
        opt = getopt_long( argc, argv, optString, longOpts, &longIndex );
    }
    if (local_arguments.verbose <= 1 or local_arguments.verbose >= 5 ){
        cout << "verbose is out of range" << endl;
        return EXIT_FAILURE;
    }
    display_args();
    return EXIT_SUCCESS;
}
