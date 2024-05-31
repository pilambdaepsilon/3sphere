3sphere: src/foo.cc src/constants.hh
	echo "Compiling 3sphere"
	g++ src/foo.cc -o 3sphere
	echo "Success! Please use ./3sphere -h for usage information"
clean:
	rm -f 3sphere
