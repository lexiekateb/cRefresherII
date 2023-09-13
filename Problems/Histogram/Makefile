run-tests-coverage: build
	./histogram inputs.txt outputs.txt
	gcov prog.c

build: remove
	gcc -fprofile-arcs -ftest-coverage -g prog.c -o histogram

run-test-leak: build
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./histogram inputs.txt outputs.txt

remove:
	rm -f *~
	rm -f histogram
	rm -f *.gcda *.gcno *.gcov