/* Implements the Foo et al. parametrization for calculating the volume of a 3-sphere using the radius */

#include "constants.hh"

int main(int argc, char* argv[]){
   //Foo_et_al fooetal; 
   cout << "Single radius detected\n";
   cout <<"   ____          __              \n";
   cout <<"  |_  /___ ___  / /  ___ _______ \n";
   cout <<" _/_ <(_-</ _ \\/ _ \\/ -_) __/ -_)\n";
   cout <<"/____/___/ .__/_//_/\\__/_/  \\__/ \n"; 
   cout <<"        /_/                      \n";
   cout <<"Calculate the Volume of a 3-sphere given its radius\n\n\n";
   cout <<"How many spheres would you like to calculate the volume for?: ";
   string number_of_spheres;
   cin >> number_of_spheres;
//   cout << '\n' << int(number_of_spheres) << '\n';
   if(Foo_et_al::is_integer(number_of_spheres)){

       int int_number_of_spheres = stoi(number_of_spheres);

       if(int_number_of_spheres == 1){
          double sphere_radius = 0.0;
          cout << "Enter sphere radius: ";
          cin >> sphere_radius; 
          cout << sphere_radius << '\n';
          cout << "Calculating volume of sphere... \n";
       }
       else if(int_number_of_spheres > 1){
          string sphere_radii;
          cout << "Enter sphere radii -- separated by commas: ";
          getline(cin >> ws, sphere_radii);
          REMOVE_SPACES(sphere_radii)
          //cout << sphere_radii << '\n';
          vector <string> sphere_radii_vec = Foo_et_al::split(sphere_radii, ',');
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
             double Volume = Foo_et_al::get_volume(current_radius);
             cout << "[" << i << "]: " << current_radius << " " << unit << " --- " << Volume << " " << unit << '\n';
          }
          cout << "Calculating volume of [" << number_of_spheres << "] 3-spheres... \n";
       }
       else{
          cout << "Aborting. Please enter a positive integer for the number of spheres\n";
       }
   }
   else{
      cout << "Aborting. Please enter an integer number of spheres to continue \n";
      return 1;
   }


   return 0;
}
