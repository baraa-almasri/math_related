#name of the output file
#this compiles the object files into an executable file
longclaw: main.o SquareMatrix.o 
	clang++ -v main.o SquareMatrix.o -o longclaw

#creating object file of the main.cpp
main.o: main.cpp
	clang++ -c main.cpp

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
	rm *.gch
# or use gcc instead
gcc:
	g++ Main.cpp AuxFunctions.h AuxFunctions.cpp SquareMatrix.h SquareMatrix.cpp -o matrixProgram
