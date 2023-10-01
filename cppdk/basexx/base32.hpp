#ifndef __BASE32__HPP__
#define __BASE32__HPP__

#include "detail/cppcodec/base32_rfc4648.hpp"

namespace cppdk {
namespace basexx {
	using base32 = cppcodec::base32_rfc4648;
} // basexx
} // cppdk
#endif // __BASE32__HPP__
