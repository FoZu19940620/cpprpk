#include <iostream>
#include <string>
#include <cppdk/json/json.hpp>

using namespace cppdk::json;

int main() {
    // Create JSON object
    Value jsonValue;

    // Add properties
    jsonValue["name"] = "John";
    jsonValue["age"] = 30;
    jsonValue["city"] = "New York";

    // Serialize to string
    StreamWriterBuilder writerBuilder;
    std::string jsonString = writeString(writerBuilder, jsonValue);

    std::cout << "JSON string: " << jsonString << std::endl;

    // Parse JSON string
    CharReaderBuilder readerBuilder;
    Value parsedJson;
    std::istringstream jsonStream(jsonString);
    std::string parseErrors;

    bool parsingSuccessful = parseFromStream(readerBuilder, jsonStream, &parsedJson, &parseErrors);

    if (parsingSuccessful) {
        std::cout << "Parsing successful!" << std::endl;

        // Access properties
        std::string name = parsedJson["name"].asString();
        int age = parsedJson["age"].asInt();
        std::string city = parsedJson["city"].asString();

        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "City: " << city << std::endl;
    } else {
        std::cout << "Parsing failed! Error message: " << parseErrors << std::endl;
    }

    return 0;
}