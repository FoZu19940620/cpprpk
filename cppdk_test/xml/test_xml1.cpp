#include <iostream>
#include <cppdk/xml/xml.hpp>

using namespace cppdk::xml;

int main() {
    XMLDocument xmlDoc;

    // Create root
    XMLNode* rootNode = xmlDoc.NewElement("Root");
    xmlDoc.InsertEndChild(rootNode);

    // Create child node and set attri
    XMLElement* element1 = xmlDoc.NewElement("Element1");
    element1->SetAttribute("name", "Value1");
    rootNode->InsertEndChild(element1);

    // add text in child node
    XMLText* text1 = xmlDoc.NewText("Text1");
    element1->InsertEndChild(text1);

    // create other child node
    XMLElement* element2 = xmlDoc.NewElement("Element2");
    rootNode->InsertEndChild(element2);

    // save to file
    XMLError result = xmlDoc.SaveFile("example.xml");

    if (result == XML_SUCCESS) {
        std::cout << "Xml File Save Success." << std::endl;
    } else {
        std::cout << "Xml File Save Fail." << std::endl;
    }

    return 0;
}