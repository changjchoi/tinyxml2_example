#include "tinyxml2.h"
#include <vector>

int main() {
  tinyxml2::XMLDocument xmldoc;
  // Insert first child
  tinyxml2::XMLNode* root = xmldoc.NewElement("Root");
  xmldoc.InsertFirstChild(root);
  // <IntValue>10</IntValue>
  tinyxml2::XMLElement* element = xmldoc.NewElement("IntValue");
  element->SetText(10);
  root->InsertEndChild(element);
  // <FloatValue>0.5</FloatValue>
  element = xmldoc.NewElement("FloatValue");
  element->SetText(0.5f);
  root->InsertEndChild(element);
  // <Date day="23" month="January" year="2017" dateFormat="23/01/2017">
  element = xmldoc.NewElement("Date");
  element->SetAttribute("day", 23);
  element->SetAttribute("month", "January");
  element->SetAttribute("year", 2017);
  element->SetAttribute("dateFormat", "23/01/2017");
  root->InsertEndChild(element);
  // Vector
  std::vector<int> vecList = {1,2,3,4,5,6,7,8,9};
  element = xmldoc.NewElement("List");
  for (const auto& item : vecList) {
    tinyxml2::XMLElement* pListElement = xmldoc.NewElement("Item");
    pListElement->SetText(item);
    element->InsertEndChild(pListElement);
  }
  element->SetAttribute("itemCount", static_cast<int>(vecList.size()));
  root->InsertEndChild(element);
  // Save to File
  tinyxml2::XMLError eResult = xmldoc.SaveFile("SavedData.xml");
  //XMLCheckResult(eResult);
  return 0;
}
