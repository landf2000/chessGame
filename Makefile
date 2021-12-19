XX = g++
CXXFLAGS = -std=c++14 -Wall -Werror=vla -MMD
EXEC = chess
OBJECTS =   main.o game.o empty.o piece.o board.o rook.o knight.o bishop.o queen.o king.o pawn.o graphics.o window.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
