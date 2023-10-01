#include <iostream>
#include "../../cppdk/basexx/detail/cppcodec/base64_default_rfc4648.hpp"

int main() {
    // Create a sample string
    std::string input = "Hello, world!";

    // Base64-encode the string
    std::string encoded = cppcodec::base64_rfc4648::encode(input);

    // Print the encoded string
    std::cout << "Encoded string: " << encoded << std::endl;

    // Base64-decode the string
    std::string decoded = cppcodec::base64_rfc4648::decode<std::string>(encoded);

    // Print the decoded string
    std::cout << "Decoded string: " << decoded << std::endl;

    return 0;
}