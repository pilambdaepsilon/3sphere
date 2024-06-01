/* Implements the Foo et al. parametrization 
* for calculating the volume of a 3-sphere using 
* the radius 
* 
* written by Pedro L. Espino (pespino@berkeley.edu)
* (2024)
*/

#include "classes.hh"
#include <stdio.h>

int main(int argc, char* argv[]){
   cout << "\n";
   cout <<"   ____          __              \n";
   cout <<"  |_  /___ ___  / /  ___ _______ \n";
   cout <<" _/_ <(_-</ _ \\/ _ \\/ -_) __/ -_)\n";
   cout <<"/____/___/ .__/_//_/\\__/_/  \\__/ \n"; 
   cout <<"        /_/                      \n";
   cout <<"Calculate the Volume of a 3-sphere given its radius\n\n\n";

   //Create a boolean for tracking whether we need to output to a file
   bool outfile = false;
   //make a global scope object for the output file, useful for conditional writing
   FILE *fout;
   //Check if the user called for the -o command option for file output
   if(Files_and_strings::check_for_command_option(argv, argv+argc, "-o")){
      //Create a variable for the filename
      char * filename_out;
      //get the output filename command line option and open the file
      filename_out = Files_and_strings::get_command_option(argv, argv + argc, "-o");
      fout = fopen(filename_out, "w");
      //If the option is called, ensure the user provides a file name, warn otherwise
      try{string filename_out_string = filename_out;}
      catch (const std::exception& e){cout << "Please ensure a filename is provided \n"; return 1;}
      //set the outfile boolean to true
      outfile = true;
      cout << "Outputting to file " << filename_out << '\n';
   }


   /*====================================
   ============== HELP MODE =============
   =====================================*/
   //print a help message to screen if -h option is given
   if(Files_and_strings::check_for_command_option(argv, argv+argc, "-h")){
        cout << "3sphere usage:\n" << "-h: print this help message\n" << "-f: provide a filename containing sphere radii\n" <<"-o: name of the output file holding Volume calculations\n" 
             << "- run without options for interactive mode\n\n";
   }

   /*====================================
   ========== INTERACTIVE MODE ==========
   =====================================*/
   //check for runtime conditions that indicate interactive mode (no arguments or only the -o option)
   else if((argc == 1) or (argc==3 and outfile)){
      //make a string for the user input interactive mode
      string sphere_radii;
      //ask for user input
      cout << "Enter sphere radii -- separated by commas: ";
      getline(cin >> ws, sphere_radii);
      //parse the user provided string by first removing all white spaces
      REMOVE_SPACES(sphere_radii)
      //parse the user provied string by then separating by commas into a vector
      vector <string> sphere_radii_vec = Files_and_strings::split(sphere_radii, ',');
      //update the user on the parsed information from their input
      cout << "\nDetected [" << sphere_radii_vec.size() << "] 3-sphere radii... \n\n";
      cout << "Sphere number   ---   Radius      ---   Volume    ---     Unit\n";
      //if we are writing to file, print some header information into the file
      if (outfile){fprintf(fout,"#Sphere number   ---   Radius      ---   Volume    ---     Unit\n");}

      /***************************************************
       * loop over the parsed radii provided by the user *
      ***************************************************/
      for (int i = 0; i < sphere_radii_vec.size(); i++){
         //focus on the current radius in the list of radii provided,
         //extract a float numerical value from each radius string (drops unit)
         string current_radius_str = sphere_radii_vec[i];
         double current_radius = stof(current_radius_str);
         
         //capture the user provided units
         //find the first string element that is not a float for capturing units
         string unit = " ";
         int first_unit_index = sphere_radii_vec[i].find_first_not_of( "0123456789." );
         //if unit is not blank, then append a ^3 to it for the volume unit
         if(first_unit_index > 0){unit = current_radius_str.substr(first_unit_index,current_radius_str.size()-1) + "^3";}

         //Calculate the volume for the current radius
         double current_Volume = Foo_et_al::get_volume(current_radius);
         //print the results to screen, and if we are printing to a file, then output the info to the file as well
         printf("[%11d]   ---   %.5e --- %.5e --- %10s\n", i+1, current_radius, current_Volume, &unit[0]);
         if (outfile){fprintf(fout, "[%11d]   ---   %.5e --- %.5e --- %10s\n", i+1, current_radius, current_Volume, &unit[0]);}
      }
      //close the output file if we opened it
      if(outfile){fclose(fout);}
   }//end interactive mode

   /*====================================
   ============= FILE MODE ==============
   =====================================*/
   //Check for runtime conditions that indicate input file mode (-f option given)
   else if(Files_and_strings::check_for_command_option(argv, argv+argc, "-f")){
      //retrieve the input filename from the command line options
      char * filename_in = Files_and_strings::get_command_option(argv, argv + argc, "-f");
      //Update the user on the info provided at runtime
      cout << "Reading radii from file " << filename_in << "\n";
      //open the input file for reading
      ifstream input_file;
      input_file.open(filename_in);
      //warn if the file the user provided is not found
      if (!input_file){cout << "Input file not found" << '\n';return 1;}

      //make variables for reading and parsing input file information
      string line;
      vector<double> radii_from_file;
      vector<string> units_from_file;
      //while the file is open, read in and store the info into vectors
      while(!input_file.eof()){
         double radius; string unit;
         input_file >> radius >> unit;
         radii_from_file.push_back(radius);
         if(unit.size() == 0){unit = " ";}
         units_from_file.push_back(unit);
      }
      //close the input file
      input_file.close();

      //Update the user on info about the calculation, if the output file option is selected, output the info to a file as well
      cout << "\nDetected [" << radii_from_file.size()-1 << "] 3-sphere radii from file... \n\n";
      cout << "Sphere number   ---   Radius      ---   Volume    ---     Unit\n";
      if (outfile){fprintf(fout,"#Sphere number   ---   Radius      ---   Volume    ---     Unit\n");}
      /***************************************************
       * loop over the parsed radii provided by the user *
      ***************************************************/
      for (int i = 0; i < radii_from_file.size()-1; i++){
         //focus on the current radius in the list of radii provided,
         //extract a float numerical value from each radius string (drops unit)
         double current_radius = radii_from_file[i];
         
         //Calculate the volume for the current radius
         double current_Volume = Foo_et_al::get_volume(current_radius);
         //print the results to screen, and if we are printing to a file, then output the info to the file as well
         printf("[%11d]   ---   %.5e --- %.5e --- %10s^3\n", i+1, current_radius, current_Volume, &units_from_file[i][0]);
         if (outfile){fprintf(fout, "[%11d]   ---   %.5e --- %.5e --- %10s^3\n", i+1, current_radius, current_Volume, &units_from_file[i][0]);}
      }
      //close the output file if we opened it
      if(outfile){fclose(fout);}
   }//end file mode

   return 0;
}
