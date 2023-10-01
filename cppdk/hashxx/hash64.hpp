#ifndef XX_HASH_64_HPP
#define XX_HASH_64_HPP

#ifndef XXH_INLINE_ALL
#define XXH_INLINE_ALL
#include "detail/xxhash.h"
#endif

#include <cstdint>

namespace cppdk {

class hash64 {
public:
	static uint64_t hash64sum(const char *input, uint64_t len) {
		return hash64sum_with_seed(input, len, 0);
	}
	
	static uint64_t hash64sum_with_seed(const char *input, uint64_t len, uint64_t seed) {
		return XXH64(input, len, seed);
	}
public:
	hash64(uint64_t seed = 0) {
		reset(seed);
	}
	
	~hash64() = default;
	
	hash64(const hash64&) = default;
	
	hash64& operator=(const hash64&) = default;
	
	hash64(hash64&&) = default;
	
	bool reset(uint64_t seed) {
		return XXH64_reset(&m_xxh64_state, seed) == XXH_OK;
	}
	
	bool update(const void* input, uint64_t len) {
		return XXH64_update(&m_xxh64_state, input, len) == XXH_OK;
	}
	
	uint64_t sum() {
		return XXH64_digest(&m_xxh64_state);
	}
private:
	XXH64_state_t m_xxh64_state;
}; //class hash64

} //namespace cppdk

#endif // XX_HASH_64_HPP