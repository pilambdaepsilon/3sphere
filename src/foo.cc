/* Implements the Foo et al. parametrization for calculating the volume of a 3-sphere using the radius */

#include "constants.hh"

int main(int argc, char* argv[]){
   //Foo_et_
   cout << "\n";
   cout <<"   ____          __              \n";
   cout <<"  |_  /___ ___  / /  ___ _______ \n";
   cout <<" _/_ <(_-</ _ \\/ _ \\/ -_) __/ -_)\n";
   cout <<"/____/___/ .__/_//_/\\__/_/  \\__/ \n"; 
   cout <<"        /_/                      \n";
   cout <<"Calculate the Volume of a 3-sphere given its radius\n\n\n";

   bool outfile = false;
   char * filename_out;
   if(Foo_et_al::check_for_command_option(argv, argv+argc, "-o")){
      filename_out = Foo_et_al::get_command_option(argv, argv + argc, "-o");
      try{string filename_out_string = filename_out;}
      catch (const std::exception& e){cout << "Please ensure a filename is provided \n";}
      outfile = true;
      cout << "Outputting to file " << filename_out << '\n';
   }
   ofstream output_file(filename_out);

   if((argc == 1) or (argc==3 and outfile)){
             string sphere_radii;
             cout << "Enter sphere radii -- separated by commas: ";
             getline(cin >> ws, sphere_radii);
             REMOVE_SPACES(sphere_radii)
             //cout << sphere_radii << '\n';
             vector <string> sphere_radii_vec = Foo_et_al::split(sphere_radii, ',');
             cout << "\nDetected [" << sphere_radii_vec.size() << "] 3-sphere radii... \n\n";
             cout << "Sphere number   ---   Radius      ---   Volume    ---     Unit\n";
             if (outfile){
                output_file << "#Sphere number   ---   Radius      ---   Volume    ---     Unit\n";
             }
             for (int i = 0; i < sphere_radii_vec.size(); i++){
                //focus on the current radius in the list of radii provided
                string current_radius_str = sphere_radii_vec[i];
                double current_radius = stof(current_radius_str);
                
                //find the first string element that is not a float for capturing units
                int first_unit_index = sphere_radii_vec[i].find_first_not_of( "0123456789." );
                string unit = " ";
   //             if(first_unit_index <= 0){cout << stof(current_radius_str) << '\n';}
                if(first_unit_index > 0){
                   unit = current_radius_str.substr(first_unit_index,current_radius_str.size()-1) + "^3";
                }
                double current_Volume = Foo_et_al::get_volume(current_radius);
                //cout << "[" << i << "]: " << current_radius << " " << unit << " --- " << Volume << " " << unit << '\n';
                printf("[%11d]   ---   %.5e --- %.5e --- %10s\n", i+1, current_radius, current_Volume, &unit[0]);
                if (outfile){
                   sprintf(formatting_buffer, "[%11d]   ---   %.5e --- %.5e --- %10s\n", i+1, current_radius, current_Volume, &unit[0]);
                   output_file << formatting_buffer;
                }
             }
          output_file.close();
          }
     else if(Foo_et_al::check_for_command_option(argv, argv+argc, "-h")){
        cout << "3sphere usage:\n" << "-h: print this help message\n" << "-f: provide a filename containing sphere radii\n" <<"-o: name of the output file holding Volume calculations\n" 
             << "- run without options for interactive mode\n\n";
     }
     else if(Foo_et_al::check_for_command_option(argv, argv+argc, "-f")){
        char * filename_in = Foo_et_al::get_command_option(argv, argv + argc, "-f");
        cout << "Reading radii from file " << filename_in << "\n";
        ifstream input_file;
        input_file.open(filename_in);
	if (!input_file){
		cout << "Input file not found" << '\n';
                return 1;
	}
	string line;
	
        vector<double> radii_from_file;
        vector<string> units_from_file;
	while(!input_file.eof()){
           double radius; string unit;
           input_file >> radius >> unit;
           radii_from_file.push_back(radius);
           if(unit.size() == 0){unit = " ";}
           units_from_file.push_back(unit);
	}
        cout << "\nDetected [" << radii_from_file.size()-1 << "] 3-sphere radii from file... \n\n";
        cout << "Sphere number   ---   Radius      ---   Volume    ---     Unit\n";
        if (outfile){
           output_file << "#Sphere number   ---   Radius      ---   Volume    ---     Unit\n";
        }
        for (int i = 0; i < radii_from_file.size()-1; i++){
           //focus on the current radius in the list of radii provided
           double current_radius = radii_from_file[i];
           
           //find the first string element that is not a float for capturing units
           double current_Volume = Foo_et_al::get_volume(current_radius);
           printf("[%11d]   ---   %.5e --- %.5e --- %10s^3\n", i+1, current_radius, current_Volume, &units_from_file[i][0]);
           if (outfile){
              sprintf(formatting_buffer, "[%11d]   ---   %.5e --- %.5e --- %10s^3\n", i+1, current_radius, current_Volume, &units_from_file[i][0]);
              output_file << formatting_buffer;
           }
        }
          output_file.close();
     }

   return 0;
}
