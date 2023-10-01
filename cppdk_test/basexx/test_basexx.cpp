#include <iostream>
#include <cppdk/basexx/base32.hpp>
#include <cppdk/basexx/base64.hpp>
#include <cppdk/basexx/base64_url.hpp>
#include <cppdk/basexx/base64_url_padded.hpp>

int main() {
    // Create a sample string
    std::string input = "Hello, world!";
	
//-------------------- base32 --------------------------------------------------

    // Base32-encode the string
    std::string encoded_32 = cppdk::basexx::base32::encode(input);

    // Print the encoded_32 string
    std::cout << "encoded_32 string: " << encoded_32 << std::endl;

    // Base32-decode the string
    std::string decoded_32 = cppdk::basexx::base32::decode<std::string>(encoded_32);

    // Print the decoded_32 string
    std::cout << "decoded_32 string: " << decoded_32 << std::endl;
	
//-------------------- base64 --------------------------------------------------

    // Base64-encode the string
    std::string encoded_64 = cppdk::basexx::base64::encode(input);

    // Print the encoded_64 string
    std::cout << "encoded_64 string: " << encoded_64 << std::endl;

    // Base64-decode the string
    std::string decoded_64 = cppdk::basexx::base64::decode<std::string>(encoded_64);

    // Print the decoded_64 string
    std::cout << "decoded_64 string: " << decoded_64 << std::endl;

//-------------------- base64_url --------------------------------------------------

    // base64_url-encode the string
    std::string encoded_64_url = cppdk::basexx::base64_url::encode(input);

    // Print the encoded_64_url string
    std::cout << "encoded_64_url string: " << encoded_64_url << std::endl;

    // base64_url-decode the string
    std::string decoded_64_url = cppdk::basexx::base64_url::decode<std::string>(encoded_64_url);

    // Print the decoded_64_url string
    std::cout << "decoded_64_url string: " << decoded_64_url << std::endl;
	
//-------------------- base64_url_padded ---------------------------------------------
    // base64_url_padded-encode the string
    std::string encoded_64_url_padded = cppdk::basexx::base64_url_padded::encode(input);

    // Print the encoded_64_url_padded string
    std::cout << "encoded_64_url_padded string: " << encoded_64_url_padded << std::endl;

    // base64_url_padded-decode the string
    std::string decoded_64_url_padded = cppdk::basexx::base64_url_padded::decode<std::string>(encoded_64);

    // Print the decoded_64_url_padded string
    std::cout << "decoded_64_url_padded string: " << decoded_64_url_padded << std::endl;
	
    return 0;
}