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

InterviewEvent::InterviewEvent(const string& date, const string& notes, InterviewFormat format)
    : ApplicationEvent(date, notes), format_(format) {}

string InterviewEvent::getType() const {
    return "Interview";
}

InterviewEvent::InterviewEvent(const string& date, const string& notes, InterviewFormat format)
    : ApplicationEvent(date, notes), format_(format) {}

string InterviewEvent::getType() const {
    return "Interview";
}

void InterviewEvent::printEvent() const {
    cout << "Interview (";

    if (format_ == InterviewFormat::PHONE) {
        cout << "Phone";
    } else if (format_ == InterviewFormat::VIDEO) {
        cout << "Video";
    } else if (format_ == InterviewFormat::ONSITE) {
        cout << "Onsite";
    } else {
        cout << "Unknown";
    }

    cout << ") on " << date_ << ". Notes: " << notes_ << endl;
}

InterviewFormat InterviewEvent::getFormat() const {
    return format_;
}

OfferEvent::OfferEvent(const string& date, const string& notes, double salary)
    : ApplicationEvent(date, notes), salary_(salary) {}

string OfferEvent::getType() const {
    return "Offer";
}

void OfferEvent::printEvent() const {
    cout << "Job offer received on " << date_
         << ". Salary: $" << salary_
         << ". Notes: " << notes_ << endl;
}

double OfferEvent::getSalary() const {
    return salary_;
}


//application class  

Application::Application(const Company& company, const string& position, const string& dateApplied)
    : company_(company), position_(position), dateApplied_(dateApplied), status_("Pending") {}

Application::~Application() {
    for (ApplicationEvent* e : events_) {
        delete e;
    }
}

void Application::addEvent(ApplicationEvent* e) {
    events_.push_back(e);
}

void Application::updateStatus(const string& newStatus) {
    status_ = newStatus;
}

string Application::getStatus() const {
    return status_;
}

void Application::printSummary() const {
    cout << "Application to " << company_.getName()
         << " for position: " << position_
         << " (Applied on " << dateApplied_ << ")" << endl;
    cout << "Status: " << status_ << endl;
    cout << "Events:" << endl;
    for (const ApplicationEvent* e : events_) {
        e->printEvent();
    }
}

const Company& Application::getCompany() const {
    return company_;
}

const string& Application::getPosition() const {
    return position_;
}

const string& Application::getDateApplied() const {
    return dateApplied_;
}
