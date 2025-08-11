#include "JobTracker.h"
#include <iostream>
using namespace std;

// ===== ApplicationEvent =====
ApplicationEvent::ApplicationEvent(const string& date, const string& notes)
    : date_(date), notes_(notes) {}
ApplicationEvent::~ApplicationEvent() {}
string ApplicationEvent::getDate() const { return date_; }
string ApplicationEvent::getNotes() const { return notes_; }

// ===== ResumeSubmissionEvent =====
ResumeSubmissionEvent::ResumeSubmissionEvent(const string& date, const string& notes)
    : ApplicationEvent(date, notes) {}
string ResumeSubmissionEvent::getType() const { return "Resume Submission"; }
void ResumeSubmissionEvent::printEvent() const {
    cout << "Resume submitted on " << date_ << ". Notes: " << notes_ << endl;
}

// ===== InterviewEvent =====
InterviewEvent::InterviewEvent(const string& date, const string& notes, InterviewFormat format)
    : ApplicationEvent(date, notes), format_(format) {}
string InterviewEvent::getType() const { return "Interview"; }
void InterviewEvent::printEvent() const {
    cout << "Interview (";
    if (format_ == InterviewFormat::PHONE) cout << "Phone";
    else if (format_ == InterviewFormat::VIDEO) cout << "Video";
    else if (format_ == InterviewFormat::ONSITE) cout << "Onsite";
    else cout << "Unknown";
    cout << ") on " << date_ << ". Notes: " << notes_ << endl;
}
InterviewFormat InterviewEvent::getFormat() const { return format_; }

// ===== OfferEvent =====
OfferEvent::OfferEvent(const string& date, const string& notes, double salary)
    : ApplicationEvent(date, notes), salary_(salary) {}
string OfferEvent::getType() const { return "Offer"; }
void OfferEvent::printEvent() const {
    cout << "Job offer received on " << date_
         << ". Salary: $" << salary_
         << ". Notes: " << notes_ << endl;
}
double OfferEvent::getSalary() const { return salary_; }

// ===== Company =====
Company::Company(const string& name, const string& location, const string& website)
    : name_(name), location_(location), website_(website) {}
string Company::getName() const { return name_; }
void Company::setName(const string& name) { name_ = name; }
string Company::getLocation() const { return location_; }
void Company::setLocation(const string& location) { location_ = location; }
string Company::getWebsite() const { return website_; }
void Company::setWebsite(const string& website) { website_ = website; }
void Company::printInfo() const {
    cout << "Company: " << name_ << "\nLocation: " << location_
         << "\nWebsite: " << website_ << endl;
}

// ===== Application =====
Application::Application(const Company& company, const string& position, const string& dateApplied)
    : company_(company), position_(position), dateApplied_(dateApplied), status_("Pending") {}
Application::~Application() {
    for (ApplicationEvent* e : events_) delete e;
}
void Application::addEvent(ApplicationEvent* e) { events_.push_back(e); }
void Application::updateStatus(const string& newStatus) { status_ = newStatus; }
string Application::getStatus() const { return status_; }
void Application::printSummary() const {
    cout << "Application to " << company_.getName()
         << " for position: " << position_
         << " (Applied on " << dateApplied_ << ")\n";
    cout << "Status: " << status_ << "\nEvents:\n";
    for (const ApplicationEvent* e : events_) e->printEvent();
}
const Company& Application::getCompany() const { return company_; }
const string& Application::getPosition() const { return position_; }
const string& Application::getDateApplied() const { return dateApplied_; }
