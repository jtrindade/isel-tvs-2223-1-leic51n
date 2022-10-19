// Process initial address space defined from the executable file.
// (Also shared objects defined as explicit dependencies.)

#include <stdio.h>
#include <unistd.h>

const char cdata[3*1024*1024] = { 3 };  // .rodata
char idata[5*1024*1024] = { 5 };        // .data
char zdata[7*1024*1024];                // .bss

int func(int a, int b) {                // .text
   return a + b; 
}

int main() {                            // .text
	printf(":: RUNNING %d ::\n", getpid());
   zdata[0] = 7;

   int cc = cdata[0];
   int ci = idata[0];
   int cz = zdata[0];

   int x = func(3, 4);
   printf("%d %d %d %d\n", cc, ci, cz, x);

   printf("cdata (.rodata): %p\n", cdata);
   printf("idata (.data)  : %p\n", idata);
   printf("zdata (.bss)   : %p\n", zdata);
   printf("main  (.text)  : %p\n", main);

   getchar();
   return 0;
}

