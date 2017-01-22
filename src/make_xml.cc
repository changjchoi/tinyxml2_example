#include "tinyxml2.h"
#include <vector>

int main() {
  tinyxml2::XMLDocument xmlDoc;
  tinyxml2::XMLNode* pRoot = xmlDoc.NewElement("Root");
  xmlDoc.InsertFirstChild(pRoot);

  tinyxml2::XMLElement* pElement = xmlDoc.NewElement("IntValue");
  pElement->SetText(10);
  pRoot->InsertEndChild(pElement);

  pElement = xmlDoc.NewElement("FloatValue");
  pElement->SetText(0.5f);
  pRoot->InsertEndChild(pElement);

  pElement = xmlDoc.NewElement("Date");
  pElement->SetAttribute("day", 26);
  pElement->SetAttribute("month", "April");
  pElement->SetAttribute("year", 2014);
  pElement->SetAttribute("dateFormat", "26/04/2014");
  pRoot->InsertEndChild(pElement);

  std::vector<int> vecList = {1,2,3,4,5,6,7,8,9};

  pElement = xmlDoc.NewElement("List");
  for (const auto& item : vecList) {
    tinyxml2::XMLElement* pListElement = xmlDoc.NewElement("Item");
    pListElement->SetText(item);
    pElement->InsertEndChild(pListElement);
  }
  pElement->SetAttribute("itemCount", static_cast<int>(vecList.size()));
  pRoot->InsertEndChild(pElement);
  tinyxml2::XMLError eResult = xmlDoc.SaveFile("SavedData.xml");
  //XMLCheckResult(eResult);
  return 0;
}
