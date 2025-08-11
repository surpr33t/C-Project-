#ifndef JOBTRACKER_H
#define JOBTRACKER_H

#include <string>
#include <vector>
using namespace std;

// ===== Base Class =====
class ApplicationEvent {
protected:
    string date_;
    string notes_;

public:
    ApplicationEvent(const string& date, const string& notes);
    virtual ~ApplicationEvent();

    virtual string getType() const = 0;
    virtual void printEvent() const = 0;

    string getDate() const;
    string getNotes() const;
};

// ===== Derived Event Classes =====
class ResumeSubmissionEvent : public ApplicationEvent {
public:
    ResumeSubmissionEvent(const string& date, const string& notes);
    string getType() const override;
    void printEvent() const override;
};

enum class InterviewFormat { PHONE, VIDEO, ONSITE };

class InterviewEvent : public ApplicationEvent {
private:
    InterviewFormat format_;
public:
    InterviewEvent(const string& date, const string& notes, InterviewFormat format);
    string getType() const override;
    void printEvent() const override;
    InterviewFormat getFormat() const;
};

class OfferEvent : public ApplicationEvent {
private:
    double salary_;
public:
    OfferEvent(const string& date, const string& notes, double salary);
    string getType() const override;
    void printEvent() const override;
    double getSalary() const;
};

// ===== Company Class =====
class Company {
private:
    string name_;
    string location_;
    string website_;
public:
    Company(const string& name, const string& location, const string& website);
    string getName() const;
    void setName(const string&);
    string getLocation() const;
    void setLocation(const string&);
    string getWebsite() const;
    void setWebsite(const string&);
    void printInfo() const;
};

// ===== Application Class =====
class Application {
private:
    Company company_;
    string position_;
    string dateApplied_;
    string status_;
    vector<ApplicationEvent*> events_;
public:
    Application(const Company& company, const string& position, const string& dateApplied);
    ~Application();

    void addEvent(ApplicationEvent* e);
    void updateStatus(const string& newStatus);
    string getStatus() const;
    void printSummary() const;

    const Company& getCompany() const;
    const string& getPosition() const;
    const string& getDateApplied() const;
};

#endif // JOBTRACKER_H

