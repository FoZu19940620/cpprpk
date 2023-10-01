#include <iostream>
#include <cppdk/xml/xml.hpp>

int main() {
    cppdk::xml::XMLDocument xmlDoc;

    // Create root
    cppdk::xml::XMLNode* rootNode = xmlDoc.NewElement("Root");
    xmlDoc.InsertEndChild(rootNode);

    // Create child node and set attri
    cppdk::xml::XMLElement* element1 = xmlDoc.NewElement("Element1");
    element1->SetAttribute("name", "Value1");
    rootNode->InsertEndChild(element1);

    // add text in child node
    cppdk::xml::XMLText* text1 = xmlDoc.NewText("Text1");
    element1->InsertEndChild(text1);

    // create other child node
    cppdk::xml::XMLElement* element2 = xmlDoc.NewElement("Element2");
    rootNode->InsertEndChild(element2);

    // save to file
    cppdk::xml::XMLError result = xmlDoc.SaveFile("example.xml");

    if (result == cppdk::xml::XML_SUCCESS) {
        std::cout << "Xml File Save Success." << std::endl;
    } else {
        std::cout << "Xml File Save Fail." << std::endl;
    }

    return 0;
}