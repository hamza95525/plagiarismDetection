//
// Created by student on 25.11.2019.
//
#include "ButtonGnomeWidget.h"
#include "CheckBoxGnomeWidget.h"
#include "ListGnomeWidget.h"
#include "GnomeWidgetFactory.h"
GnomeWidgetFactory::GnomeWidgetFactory(int gnomeVersion) {
    this->gnomeVersion = gnomeVersion;
}
std::shared_ptr<Widget> GnomeWidgetFactory::create(std::string type) {
    if(type=="Button")
        return std::make_shared<ButtonGnomeWidget>(this->gnomeVersion);
    else if(type=="Check")
        return std::make_shared< CheckBoxGnomeWidget>(this->gnomeVersion);
    else if(type=="List")
        return std::make_shared<ListGnomeWidget>(this->gnomeVersion);
}
