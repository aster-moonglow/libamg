
#define AMG_INCLUDE_IMPLEMENTATION
#define AMG_INCLUDE_UNITTESTS
#include "amg/test_runner.h"

int main(int argc, const char **argv)
{
	AMG_TEST_RUNNER runner;
	amg_init_test_runner(&runner);
	return amg_unittest_all(&runner);
}
