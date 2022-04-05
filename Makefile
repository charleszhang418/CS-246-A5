
# CXX = g++
# CXXFLAGS = -std=c++14 -Wall -Werror=vla
# OBJECTS = main.o command.o block.o difficulty.o cell.o observer.o subject.o
# EXEC = a5

# ${EXEC}: main.o command.o block.o difficulty.o
# 		${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

# main.o: main.cc command.h 

# command.o: command.cc command.h

# block.o: block.cc block.h

# difficulty.o: difficulty.cc difficulty.h

# cell.o: cell.cc cell.h observer.h subject.h

# observer.o: observer.cc observer.h

# subject.o: subject.cc subject.h

# .PHONY: clean

# clean:
# 		rm ${OBJECTS} ${EXEC}




CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla
EXEC = biquadris
OBJECTS = main.o command.o block.o difficulty.o cell.o board.o  textoutput.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

