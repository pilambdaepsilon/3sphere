/* Import all relevant libraries and set namespaces*/
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#ifndef M_PI
#define M_PI           3.14159265358979323846
#endif
using namespace std;

//Define a macro for removing white spaces from strings, useful for parsing units out of command line interface
#define REMOVE_SPACES(x) x.erase(remove(x.begin(), x.end(), ' '), x.end());

//set constants and other useful quantities
const double pi = M_PI;
//make a buffer for printing formatted strings to file
char formatting_buffer[1024];




