#include "constants_and_libraries.hh"

//Main class containing functions and quantities within the Foo et al. parametrization
class Foo_et_al
{
  public:
 
    //! Returns the volume of a single 3-sphere
    /*!
      \param radius is a double precision float for the radius of the sphere.
      \returnis 4./3 * pi * radius*radius*radius
    */
    static double get_volume(double radius){
       if(radius < 0.0){cerr << "!!! WARNING - Inside get_volume - negative radius provided !!!\n";}
       return 4./3 * pi * radius * radius * radius;
    }
   
};

//Main class containing functions and quantities within the Foo et al. parametrization
class Files_and_strings
{
  public:
 
    //! Determines whether a string is an integer, useful for counting the number of spheres
    /*!
      \param digit_string is an arbitrary string containing information
      \returns the first index in the string that is not an integer
    */
    static bool is_integer(const string digit_string){
       return digit_string.find_first_not_of( "0123456789" ) == string::npos;
    }

    //! Splits and separates strings based on some delimiter
    /*!
      \param s is an arbitary string you want to separate into a vector
      \param delimiter is the character used to delimit separate quantities in the string
      \returns a vector of strings, with each element being a quantity separeted by the delimiter in the original string
    */
    static vector<string> split(const string& s, char delimiter)                                                                                                                          
    {                                                                                                                                                                                             
       vector<string> splits;                                                                                                                                                           
       string split;                                                                                                                                                                         
       istringstream ss(s);                                                                                                                                                                  
       while (getline(ss, split, delimiter))                                                                                                                                                 
       {                                                                                                                                                                                          
          splits.push_back(split);                                                                                                                                                                
       }                                                                                                                                                                                          
       return splits;                                                                                                                                                                             
    }

    //! retrieves string after command line options used at runtime
    /*!
      \param begin (char**) is the first character of the string that matches the "option"
      \param begin (char**) is the last character of the string that matches the "option"
      \param option is a string consisting of the command line option we want to retrieve
    */
    static char* get_command_option(char ** begin, char ** end, const string & option)
    {
        char ** itr = find(begin, end, option);
        if (itr != end && ++itr != end)
        {
            return *itr;
        }
        return 0;
    }
    
    //! checks whether a command line option is used at runtime
    /*!
      \param begin (char**) is the first character of the string that matches the "option"
      \param begin (char**) is the last character of the string that matches the "option"
      \param option is a string consisting of the command line option we want to retrieve
      \returns true if the string is of finite size
    */
    static bool check_for_command_option(char** begin, char** end, const string& option)
    {
        return find(begin, end, option) != end;
    }
};
