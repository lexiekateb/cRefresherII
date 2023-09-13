run-tests-coverage: build
	./transpose inputs.txt outputs.txt
	gcov prog.c

build: remove
	gcc -fprofile-arcs -ftest-coverage -g prog.c -o transpose

run-test-leak: build
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./transpose inputs.txt outputs.txt

remove:
	rm -f *~
	rm -f transpose
	rm -f *.gcda *.gcno *.gcov