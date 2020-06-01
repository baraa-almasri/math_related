#name of the output file
#this compiles the object files into an executable file
matrixProgram: Main.o SquareMatrix.o BasicMatrix.o
	clang++ -v Main.o SquareMatrix.o BasicMatrix.o -o matrixProgram

#creating object file of the main.cpp
Main.o: Main.cpp
	clang++ -c Main.cpp

#creating object file of SquareMatrix.hpp
SquareMatrix.hpp.gch: SquareMatrix.hpp
	clang++ -c SquareMatrix.hpp

#creating object file of SquareMatrix.cpp
SquareMatrix.o: SquareMatrix.cpp
	clang++ -c SquareMatrix.cpp

#creating object file of BasicMatrixIO.cpp
BasicMatrix.o: BasicMatrix.cpp
	clang++ -c BasicMatrix.cpp

#Note that the (-c) option in gcc or clang compiles the ".cpp"
#file into an object file i.e ".o" file

#the action clean clears the directory as seen
clean:
	rm *.o
# use gcc instead
gcc:
	g++ main.cpp SquareMatrix.hpp SquareMatrix.cpp -o matrixProgram