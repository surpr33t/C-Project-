#include "JobTracker.h"
#include <iostream>

//base class 
ApplicationEvent::ApplicationEvent(const string& date, const string& notes)
    : date_(date), notes_(notes) {}

ApplicationEvent::~ApplicationEvent() {}

string ApplicationEvent::getDate() const {
    return date_;
}

string ApplicationEvent::getNotes() const {
    return notes_;
}

