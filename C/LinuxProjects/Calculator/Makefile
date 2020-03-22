Main: CalculatorMain.o inputParsing.o
	gcc CalculatorMain.o inputParsing.o -o Main

inputParsing.o: InputCapture/inputParsing.c InputCapture/inputParsing.h
	gcc -c InputCapture/inputParsing.c -o inputParsing.o

CalculatorMain.o:  CalculatorMain.c InputCapture/inputParsing.h
	gcc -c CalculatorMain.c -o CalculatorMain.o

clean:
	rm inputParsing.o CalculatorMain.o


