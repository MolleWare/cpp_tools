
#include <iostream>
#include <string>



//                    █████       ████ 
//                  ███░░░███    ░░███ 
//  █████ █████    ███   ░░███    ░███ 
// ░░███ ░░███    ░███    ░███    ░███ 
//  ░███  ░███    ░███    ░███    ░███ 
//  ░░███ ███     ░░███   ███     ░███ 
//   ░░█████       ░░░█████░   ██ █████
//    ░░░░░          ░░░░░░   ░░ ░░░░░ 


// multiple tests

// #define DEBUG <- will use this when adding the debug options feature.
// TODO : add log messages for DEBUG and INFO

template<typename T>
bool loop_test(T test)
{
	if(test)
		return 0; // test successful
	return 1;     // test failed
}

template<typename T, typename... Args>
bool loop_test(T test, Args... args)
{
	if(!test)
		return 1;   // test failed
	return loop_test(args...);
};

#define TEST(name, ...) \
{\
	bool result = loop_test(true, __VA_ARGS__); \
	error_counter += result; \
	std::cout << (result ? "\033[31mFailed\033[0m" : "\033[32mOk    \033[0m") << " : "  << name << "    " << __FILE__ << ":" << __LINE__ << "  " << __func__ << std::endl; \
	result = false; \
}


// group tests
#define GROUP_TEST(func) \
{ \
	int tmp_counter = func(); \
	if(tmp_counter != 0) \
	{ \
		error_counter += tmp_counter; \
		std::cout << __FILE__ << ":" << __LINE__ << "\033[31m error_counter: " << tmp_counter << "\033[0m" << std::endl << std::endl; \
	} \
}

#define END_TESTS(error_counter) \
{ \
	if(error_counter == 0) \
	{ \
		std::cout << "All tests successful!" << std::endl; \
	} \
	else \
	{ \
		std::cout << "\033[31mTotal errors: " << error_counter << "\033[0m" << std::endl; \
	} \
}

