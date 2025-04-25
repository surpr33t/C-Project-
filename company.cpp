#include "JobTracker.h"
#include <iostream>

Company::Company(const string& name, const string& location, const string& website)
    : name_(name), location_(location), website_(website) {}

string Company::getName() const {
    return name_;
}

void Company::setName(const string& name) {
    name_ = name;
}

string Company::getLocation() const {
    return location_;
}

void Company::setLocation(const string& location) {
    location_ = location;
}

string Company::getWebsite() const {
    return website_;
}

void Company::setWebsite(const string& website) {
    website_ = website;
}

void Company::printInfo() const {
    cout << "Company: " << name_ << endl;
    cout << "Location: " << location_ << endl;
    cout << "Website: " << website_ << endl;
}
