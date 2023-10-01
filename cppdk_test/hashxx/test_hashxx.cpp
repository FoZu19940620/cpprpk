#include <cppdk/hashxx/hash32.hpp>
#include <cppdk/hashxx/hash64.hpp>

#include <stdio.h>

int main()
{
	unsigned int h32_1 = cppdk::hash32::hash32sum("12345678", 8);
	unsigned int h32_2 = cppdk::hash32::hash32sum("12345678", 8);
	cppdk::hash32 clsHash32;
	clsHash32.update("12345678", 8);
	unsigned int h32_3 = clsHash32.sum();
	printf("h32_1 : %u\n", h32_1);
	printf("h32_2 : %u\n", h32_2);
	printf("h32_3 : %u\n", h32_3);
	
	unsigned int h64_1 = cppdk::hash64::hash64sum("12345678", 8);
	unsigned int h64_2 = cppdk::hash64::hash64sum("12345678", 8);
	cppdk::hash64 clsHash64;
	clsHash64.update("12345678", 8);
	unsigned int h64_3 = clsHash64.sum();
	printf("h64_1 : %u\n", h64_1);
	printf("h64_2 : %u\n", h64_2);
	printf("h64_3 : %u\n", h64_3);
	
	return 0;
}