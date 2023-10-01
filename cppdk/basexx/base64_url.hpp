#ifndef __BASE64_URL__HPP__
#define __BASE64_URL__HPP__

#include "detail/cppcodec/base64_url_unpadded.hpp"

namespace cppdk {
namespace basexx {
	using base64_url = cppcodec::base64_url_unpadded;
} // basexx
} // cppdk

#endif // __BASE64_URL__HPP__
