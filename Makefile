all: lesson.x
lesson.x: main.cpp
	g++-14 main.cpp -std=c++23 -o lesson.x
clean:
	rm -f *.o lesson.x
run:
	./lesson.x
