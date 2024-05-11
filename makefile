all: program

program: main.o GC_Parser.o GC_Solver.o
	@g++ -o program main.o GC_Parser.o GC_Solver.o

main.o: main.cpp GC_Parser.h GC_Solver.h
	@g++ -c main.cpp

GC_Parser.o: GC_Parser.cpp GC_Parser.h
	@g++ -c GC_Parser.cpp

GC_Solver.o: GC_Solver.cpp GC_Solver.h
	@g++ -c GC_Solver.cpp

clean:
	@rm -f *.o program