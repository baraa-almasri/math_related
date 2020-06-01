#name of the output file
#this compiles the object files into an executable file
output: main.o SquareMatrix.o
	clang++ -v main.o SquareMatrix.o -o matrixProgram

#creating object file of the main.cpp
main.o: main.cpp
	clang++ -c main.cpp

#creating object file of the SquareMatrix.hpp

SquareMatrix.hpp.gch:
	clang++ -c SquareMatrix.hpp
#creating object file of the SquareMatrix.cpp
SquareMatrix.o:
	clang++ -c SquareMatrix.cpp


#Note that the (-c) option in gcc or clang compiles the ".cpp"
#file into an object file i.e ".o" file

#the action clean clears the directory as seen
clean:
	rm *.o
# use gcc instead
gcc:
	g++ main.cpp SquareMatrix.hpp SquareMatrix.cpp -o matrixProgram