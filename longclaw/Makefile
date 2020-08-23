#name of the output file
#this compiles the object files into an executable file
longclaw: longclaw.o Matrix.o SquareMatrix.o 
	clang++ -v longclaw.o Matrix.o SquareMatrix.o -o longclaw

#creating object file of the main.cpp
longclaw.o: longclaw.cpp
	clang++ -c longclaw.cpp

#creating object file of Matrix.hpp
Matrix.h.gch: Matrix.h
	clang++ -c Matrix.hpp

#creating object file of Matrix.cpp
Matrix.o: Matrix.cpp
	clang++ -c Matrix.cpp

#creating object file of SquareMatrix.hpp
SquareMatrix.h.gch: SquareMatrix.h
	clang++ -c SquareMatrix.hpp

#creating object file of SquareMatrix.cpp
SquareMatrix.o: SquareMatrix.cpp
	clang++ -c SquareMatrix.cpp


#Note that the (-c) option in gcc or clang compiles the ".cpp"
#file into an object file i.e ".o" file

#the action clean clears the directory as seen
clean:
	rm *.o
# or use gcc instead
gcc:
	g++ longclaw.cpp AuxFunctions.h Matrix.h Matrix.cpp SquareMatrix.h SquareMatrix.cpp -o matrixProgram
