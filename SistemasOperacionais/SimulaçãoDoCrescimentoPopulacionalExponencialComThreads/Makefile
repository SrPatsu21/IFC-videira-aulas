Libs = -pthread -lm

Build: ./main.c
	echo "Building...\n"
	gcc ${Libs} ./main.c -o ./main.out
	echo "Ready"

Run: Build
	echo "start run"
	./main.out 1.0 2.0 10 5
RunTime: Build
	echo "start run on time"
	time ./main.out 1.lf 2.0lf 10 5