g++ -c board/board.cpp game/game.cpp ui/console/ConsoleUI.cpp ui/gui/gui.cpp utils/utils.cpp main.cpp -Isfml/include/ -DSFML_STATIC
g++ main.o board.o ConsoleUI.o gui.o game.o utils.o -o main -Lsfml/lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -o chess.exe
./chess.exe gui