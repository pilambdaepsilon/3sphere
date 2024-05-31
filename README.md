![plot](./README_images/3sphere.jpg)

# 3sphere
Want to calculate 3D spherical volumes but have access to only radii? Look no further! `3sphere` uses the parametrization of Foo et al. to calculate the volume of a 3-sphere given its radius in a 
user-friendly way. It can be used to calculate the volume of a single 3-sphere (given a single sphere radius) or several 3-spheres (given a list of 3-sphere radii) in any unit.

### System Requirements:
   - Linux: 
      -- c++ compiler: intel or gnu
   - Windows:
      -- c++ compiler: intel or gnu
   - MacOS:
      -- c++ compiler: intel or gnu
### Installation:
   - You must use a command line interface and c++ compiler to install 3sphere. To do so, follow the steps below:
     1. clone the git repo with the command: `git clone git@github.com:pilambdaepsilon/3sphere`
     2. move into the git repo with the command: `cd 3sphere`
     3. option1: if `make` is available on your system, use the Makefile with the command: `make`
     4. option2:directly compile the code with the command: `g++ src/foo.cc -o 3sphere`
     
### Usage:
3sphere can be used in two main ways:
1. Interactively through the command line, by running it without arguments:
   
   a. Running without command line options
   
   `./3sphere`
   
   will minimally calculate the volume of any radii provided. You will need to provide a list of radii (with arbitrary units or unitless), separated by commas, or a single radius. For example, the list of radii can be of the format

   `1.14, 3 in., 9.0 km, 5.88843m, 2Angstrom`

   b. Running interactively while providing an output file command line option
   
   `./3sphere -o [OUTPUT FILE NAME]`
   
   will run `3sphere` in interactive mode and save the output to a file (where `[OUTPUT FILE NAME]` should be replaced by the desired file name)
   
3. By providing a file with a list of radii
   
   `./3sphere -f [INPUT FILE NAME]`
   
   where `[INPUT FILE NAME]` should be of the following format:
   
   Column 1: radius
   
   Column 2: unit (if the quantity is unitless, use any placeholder unit, such "NA"). Similarly, the results will be saved to a file if provided with a `-o` command line option.
