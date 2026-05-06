## libamg

A library aimed at providing powerful and convenient things to ISO C89.

## libamg/pp/alu

Headers used to do mathematical computations using the macro preprocessor.

It has these properties:
* Token-based.
* Wide integer width
	* 128-bit or more on modern systems
	* 96-bit when minimizing macro count
* But also handles small/narrow integers efficiently
* Tunable macro-count vs expansion-speed trade-off.
(TODO: I'm forgetting stuff)

The point about it being _token-based_ is important.

It is somewhat trivial to write an addition macro that can expand to code that executes as C code:
```C
#define my__stringize(expr) #expr
#define my_stringize(expr) my__stringize(expr)

#define my_add(a,b) (a+b)
int main(int argc, const char **argv)
{
	// Prints "(1+2)"
	printf("%s\n", my_stringize(my_add(1,2)));
}
```

It is much less obvious how to write an addition macro that simply expands to the result, without any involvement from C:
```C
#include "amg/pp/alu/add.h"

#define my__stringize(expr) #expr
#define my_stringize(expr) my__stringize(expr)

int main(int argc, const char **argv)
{
	// Prints "3"
	printf("%s\n", my_stringize(amgpp_add(1,2)));
}
```

It is even more non-trivial to scale such an approach to large numbers, and to do so without consuming tremendous resources.

