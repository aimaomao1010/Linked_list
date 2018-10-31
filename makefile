export GTEST_DIR=~/googletest/googletest
export COV_OUTPUT=./cov_output
my_test: libgtest.a test_case.c linked_list.c Gtest_main.c makefile
	
	g++ -isystem ${GTEST_DIR}/include -pthread test_case.c linked_list.c Gtest_main.c libgtest.a -o my_test -g --coverage
	

libgtest.a:
	g++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -pthread -c ${GTEST_DIR}/src/gtest-all.cc 
	ar -rv libgtest.a gtest-all.o
report:
	lcov -rc lcov_branch_coverage=1 -c -i -d . -o .coverage.base
	lcov -rc lcov_branch_coverage=1 -c -d . -o .coverage.run
	lcov -rc lcov_branch_coverage=1 -d . -a .coverage.base -a .coverage.run -o .coverage.total
	genhtml --branch-coverage -o ${COV_OUTPUT} .coverage.total
	rm -f .coverage.base .coverage.run .coverage.tota
clean:
	rm -rf *.o my_test
