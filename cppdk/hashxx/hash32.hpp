#ifndef XX_HASH_32_HPP
#define XX_HASH_32_HPP

#ifndef XXH_INLINE_ALL
#define XXH_INLINE_ALL
#include "detail/xxhash.h"
#endif

#include <cstdint>

namespace cppdk {

class hash32 {
public:
	static uint32_t hash32sum(const char *input, uint32_t len) {
		return hash32sum_with_seed(input, len, 0);
	}
	
	static uint32_t hash32sum_with_seed(const char *input, uint32_t len, uint32_t seed) {
		return XXH32(input, len, seed);
	}
public:
	hash32(uint32_t seed = 0) {
		reset(seed);
	}
	
	~hash32() = default;
	
	hash32(const hash32&) = default;
	
	hash32& operator=(const hash32&) = default;
	
	hash32(hash32&&) = default;
	
	bool reset(uint32_t seed) {
		return XXH32_reset(&m_xxh32_state, seed) == XXH_OK;
	}
	
	bool update(const void* input, uint32_t len) {
		return XXH32_update(&m_xxh32_state, input, len) == XXH_OK;
	}
	
	uint32_t sum() {
		return XXH32_digest(&m_xxh32_state);
	}
private:
	XXH32_state_t m_xxh32_state;
}; //class hash32

} //namespace cppdk

#endif // XX_HASH_32_HPP