#CC=g++
CC=icc

3sphere: src/foo.cc src/constants_and_libraries.hh
	@echo "Compiling 3sphere..."
	$(CC) src/foo.cc -o 3sphere
	@echo "Success! Please use ./3sphere -h for usage information"
clean:
	rm -f 3sphere
