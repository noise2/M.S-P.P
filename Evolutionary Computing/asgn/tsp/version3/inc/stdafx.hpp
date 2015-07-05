#ifndef STDAFX_HPP
#define STDAFX_HPP

#ifdef __unix__
#   define OS_UNIX
#else
#   define OS_WIN
#   warning "The compilation of this source in any other OS than UNIX may cause many errors!"
#endif

#ifdef __GNUC__
#   define __unused __attribute__((unused))
#else
#   define __unused
#endif

#include <time.h>
#include <cstdlib>
#include <random>
using namespace std;

#define get_rand(min, range)((min) + rand() % (range))
#define frand()             (double(rand()) / RAND_MAX)
#ifdef OS_UNIX
#   define dynamic_seed     (time(NULL) + rand() + getpid() * 100)
#else
#   define dynamic_seed     (time(NULL) + rand())
#endif
#define updateseed()        srand(dynamic_seed)

#ifdef __GNUC__
#	define __deprecated(func) func __attribute__ ((deprecated))
#elif defined(_MSC_VER)
#	define __deprecated(func) __declspec(deprecated) func
#else
#	pragma message("WARNING: You need to implement `__deprecated` for this compiler!")
#	define __deprecated(func) func
#endif

#define __PROMT_FAILED "[\u2613]"
#define __PROMT_PASSED "[\u221A]"

// for disabling `warning: deprecated conversion from string constant to ‘char*’`
#pragma GCC diagnostic ignored "-Wwrite-strings"

#endif // STDAFX_HPP
