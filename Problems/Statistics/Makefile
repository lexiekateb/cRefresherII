run-tests-coverage: build
	./stats inputs.txt outputs.txt
	gcov prog.c

build: remove
	gcc -fprofile-arcs -ftest-coverage -g prog.c -lm -o stats

run-test-leak: build
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./stats inputs.txt outputs.txt

remove:
	rm -f *~
	rm -f stats
	rm -f *.gcda *.gcno *.gcov