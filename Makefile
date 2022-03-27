CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror=vla
OBJECTS = main.o echo.o textprocess.o
EXEC = a4q3

${EXEC}: echo.o main.o textprocess.o
		${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

main.o: main.cc echo.h 

textprocess.o: textprocess.h textprocess.cc

echo.o: echo.cc echo.h

.PHONY: clean

clean:
		rm ${OBJECTS} ${EXEC}

