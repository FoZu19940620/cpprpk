#define XXH_INLINE_ALL
#include "../../cppdk/hashxx/detail/xxhash.h"

#include <stdio.h>

int main()
{
	unsigned int h32_1 = XXH32("12345678", 8, 0);
	unsigned int h32_2 = XXH32("12345678", 8, 0);
	XXH32_state_t m_xxh32_state;
	XXH32_reset(&m_xxh32_state, 0);
	XXH32_update(&m_xxh32_state, "12345678", 8);
	unsigned int h32_3 = XXH32_digest(&m_xxh32_state);
	printf("h32_1 : %u\n", h32_1);
	printf("h32_2 : %u\n", h32_2);
	printf("h32_3 : %u\n", h32_3);
	
	unsigned int h64_1 = XXH64("12345678", 8, 0);
	unsigned int h64_2 = XXH64("12345678", 8, 0);
	XXH64_state_t m_xxh64_state;
	XXH64_reset(&m_xxh64_state, 0);
	XXH64_update(&m_xxh64_state, "12345678", 8);
	unsigned int h64_3 = XXH64_digest(&m_xxh64_state);
	printf("h64_1 : %u\n", h64_1);
	printf("h64_2 : %u\n", h64_2);
	printf("h64_3 : %u\n", h64_3);
	return 0;
}