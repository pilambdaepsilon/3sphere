/* Check for definition of pi, or define it */
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
#define REMOVE_SPACES(x) x.erase(remove(x.begin(), x.end(), ' '), x.end());

/*============== UNIT CONVERSION natural units where c = hBAR = kB  = 1 ===========*/
const double pi = M_PI;
char formatting_buffer[1024];




class Foo_et_al
{
  public:
 
    //! An enum.
    /*! More detailed enum description. */
    enum TEnum { 
                 TVal1, /*!< Enum value TVal1. */  
                 TVal2, /*!< Enum value TVal2. */  
                 TVal3  /*!< Enum value TVal3. */  
               } 
         //! Enum pointer.
         /*! Details. */
         *enumPtr, 
         //! Enum variable.
         /*! Details. */
         enumVar;  
    //! Returns the volume of a 3sphere
    /*!
      \param number_of_spheres is an integer argument for the number of spheres we are calculating the volume for.
      \param radius is a double precision float for the radius of the spheres.
      \return The test results
      \sa QTstyle_Test(), ~QTstyle_Test(), testMeToo() and publicVar()
    */
    static double get_volume(double radius){
       if(radius < 0.0){cerr << "!!! WARNING - Inside get_volume - negative radius provided !!!\n";}
       return 4./3 * pi * radius * radius * radius;
    }
   
    //Use this function to check whether input strings are digits or not
    static bool is_integer(const string digit_string){
       return digit_string.find_first_not_of( "0123456789" ) == string::npos;
    }

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

    static char* get_command_option(char ** begin, char ** end, const string & option)
    {
        char ** itr = find(begin, end, option);
        if (itr != end && ++itr != end)
        {
            return *itr;
        }
        return 0;
    }
    
    static bool check_for_command_option(char** begin, char** end, const string& option)
    {
        return find(begin, end, option) != end;
    }
    
    //! A constructor.
    /*!
      A more elaborate description of the constructor.
    */
    Foo_et_al();
 
    //! A destructor.
    /*!
      A more elaborate description of the destructor.
    */
   ~Foo_et_al();
    
    //! A normal member taking two arguments and returning an integer value.
    /*!
      \param a an integer argument.
      \param s a constant character pointer.
      \return The test results
      \sa QTstyle_Test(), ~QTstyle_Test(), testMeToo() and publicVar()
    */
    int testMe(int a,const char *s);
       
   
    //! A public variable.
    /*!
      Details.
    */
    int publicVar;
       
    //! A function variable.
    /*!
      Details.
    */
    int (*handler)(int a,int b);
};
