#ifndef JOBTRACKER_H
#define JOBTRACKER_H

#include <string>
#include <vector>
using namespace std; 

// base class 
class ApplicationEvent {
protected:
    string date_;    
    string notes_;  

public:
    ApplicationEvent(const string& date,
                     const string& notes);
    virtual ~ApplicationEvent();

    // Returns the event type as a string 
    virtual string getType()   const = 0;

    // Prints details of the event
    virtual void        printEvent() const = 0;

    // Accessors for common data
    string getDate()  const;
    string getNotes() const;
};
//records when a resume was submitted to a company
____
class ResumeSubmissionEvent : public ApplicationEvent {
public:
    ResumeSubmissionEvent(const string& date,
                          const string& notes);

    std::string getType()   const;  
    void        printEvent() const;
};
// records an interview, with format 
//______
enum class InterviewFormat { PHONE, VIDEO, ONSITE };

class InterviewEvent : public ApplicationEvent {
    InterviewFormat format_;  
public:
    InterviewEvent(const string& date,
                   const string& notes,
                   InterviewFormat format);

    string getType()   const;  
    void        printEvent() const;

    InterviewFormat getFormat() const;
};
// records a job offer, including offered salary
//_______
class OfferEvent : public ApplicationEvent {
    double salary_;  
public:
    OfferEvent(const string& date,
               const string& notes,
               double salary);

    string getType()   const;  
    void        printEvent() const;

    double getSalary() const;
};

//shows the company which you applied to
//contains name, location, and website, with getters/setters and a print method
//____
class Company {
private:
    string name_;      
    string location_;  
    string website_;   

public:
    Company(const string& name,
            const string& location,
            const string& website);

    //retrieve or update company details
    string getName()     const;
    void        setName(const string&);

    string getLocation() const;
    void        setLocation(const string&);

    string getWebsite()  const;
    void        setWebsite(const string&);

    //print company information
    void printInfo() const;
};

// tracks individual application, status, and events
// holds the Company, position title, date applied, current status, and a list of polymorphic ApplicationEvent pointers.
// ______
class Application {
private:
    Company                        company_;       
    string                    position_;      
    string                    dateApplied_;   
    string                    status_;        
    vector<ApplicationEvent*> events_;      

public:
    Application(const Company&     company,
                const string& position,
                const string& dateApplied);

    ~Application();  

    //adds a new event (resume submission, interview, offer, etc.)
    void addEvent(ApplicationEvent* e);

    //updates the application status string
    void updateStatus(const string& newStatus);

    //gets current status
    string getStatus() const;

    //prints a summary of the application and its events
    void printSummary() const;

    //access the main fields
    const Company&     getCompany()     const;
    const string& getPosition()    const;
    const string& getDateApplied() const;
};

#endif // JOBTRACKER_H
