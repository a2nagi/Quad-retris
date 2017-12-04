CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror=vla -MMD -g
EXEC = quadris
OBJECTS = main.o model/Cell.o model/Grid.o model/Subject.o view/TextDisplay.o view/graphicsdisplay.o view/window.o controller/Block.o controller/IBlock.o controller/JBlock.o controller/LBlock.o controller/OBlock.o controller/SBlock.o controller/TBlock.o controller/ZBlock.o controller/Level.o controller/Level0.o controller/Level1.o controller/Level2.o controller/Level3.o controller/Level4.o controller/Controller.o 
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
