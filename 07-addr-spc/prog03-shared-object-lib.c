// This is the source code for a simple dynamic link library
// (also known as shared object in Unixes).
// The library exports a single function: mylib_func

int printf(const char * fstr, ...);

int mylib_func(int a) {
	printf(">> Executing mylib_func(%d)\n", a);
	return a + 8;
}
