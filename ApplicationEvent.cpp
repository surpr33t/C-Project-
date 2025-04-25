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

//child class that says when it was submitted 
ResumeSubmissionEvent::ResumeSubmissionEvent(const string& date, const string& notes)
    : ApplicationEvent(date, notes) {}

string ResumeSubmissionEvent::getType() const {
    return "Resume Submission";
}

void ResumeSubmissionEvent::printEvent() const {
    cout << "Resume submitted on " << date_ << ". Notes: " << notes_ << endl;
}
