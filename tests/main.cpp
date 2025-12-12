

#include "test.hh"


int test_case_one()
{
	int error_counter = 0;
	{
		int foo = 0;

		TEST("test 1", foo == 0, foo+1 == 1, foo == 0, foo== 0, foo == 0);
		TEST("test 2", foo == 0, foo+1 == 1, foo == 0, foo== 0, foo == 0);
		TEST("test 3", foo == 0, foo+1 == 1, foo == 0, foo== 0, foo == 1); // should fail
		TEST("test 4", foo == 0, foo+1 == 1, foo == 0, foo== 0, foo == 0);
		TEST("test 5", foo == 0, foo+1 == 1, foo == 0, foo== 0, foo == 0);
		TEST("test end", foo == 0, foo+1 == 1, foo == 0, foo== 0, foo == 0);

	}
	// std::cout << "error_counter in test_case_one: " << error_counter << std::endl;
	
	return error_counter;
}


int test_case_two()
{
	int error_counter = 0;

	{

		int foo = 0;

		TEST("test 1", foo == 0, foo == 0);
		TEST("test 2", foo == 1);	// should fail
		foo++;
		TEST("test 3", foo == 1);
		TEST("test 4", foo == 0);	//	should fail
	}
	// std::cout << "error_counter in test_case_two: " << error_counter << std::endl;

	return error_counter;
}

int main(int, char**)
{
	int error_counter = 0;

	GROUP_TEST(test_case_one);
	GROUP_TEST(test_case_two);

	END_TESTS(error_counter);

	return 0;
}
