// Sample program that uses a dynamic link library (shared object)
// by explicitly loading it in runtime with dlopen

#include <stdio.h>
#include <unistd.h>
#include <dlfcn.h>

int main() {
	printf(":: RUNNING %d ::\n", getpid());
	
	getchar();
	
	void * lib = dlopen("./prog03-mylib.so", RTLD_LOCAL | RTLD_NOW);

	int (*func)(int a);
	*((void**)&func) = dlsym(lib, "mylib_func");  // *((void**)&func) is the same as func but with a syntactic trick to avoid a warning

	int res = func(23);
	printf("res: %d\n", res);

	getchar();
	
	dlclose(lib);

	return 0;
}
