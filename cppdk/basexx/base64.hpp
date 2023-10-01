#ifndef __BASE64__HPP__
#define __BASE64__HPP__

#include "detail/cppcodec/base64_rfc4648.hpp"

namespace cppdk {
namespace basexx {
	using base64 = cppcodec::base64_rfc4648;
} // basexx
} // cppdk

#endif // __BASE64__HPP__
