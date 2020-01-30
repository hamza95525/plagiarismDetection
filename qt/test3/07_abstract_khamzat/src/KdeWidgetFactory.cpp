//
// Created by student on 25.11.2019.
//
#include "ButtonKdeWidget.h"
#include "CheckBoxKdeWidget.h"
#include "ListKdeWidget.h"
#include "KdeWidgetFactory.h"
 KdeWidgetFactory::KdeWidgetFactory(int kdeVersion) {
    this->kdeVersion = kdeVersion;
}
std::shared_ptr<Widget> KdeWidgetFactory::create(std::string type) {
    if(type=="Button")
        return std::make_shared<ButtonKdeWidget>(this->kdeVersion);
    else if(type=="Check")
        return std::make_shared< CheckBoxKdeWidget>(this->kdeVersion);
    else if(type=="List")
        return std::make_shared<ListKdeWidget>(this->kdeVersion);
}
