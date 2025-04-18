#ifndef JOBTRACKER_H
#define JOBTRACKER_H

#include <string>
#include <vector>

// base class 
class ApplicationEvent {
protected:
    std::string date_;    
    std::string notes_;  

public:
    ApplicationEvent(const std::string& date,
                     const std::string& notes);
    virtual ~ApplicationEvent();

    // Returns the event type as a string 
    virtual std::string getType()   const = 0;

    // Prints details of the event
    virtual void        printEvent() const = 0;

    // Accessors for common data
    std::string getDate()  const;
    std::string getNotes() const;
};
//records when a resume was submitted to a company
____
class ResumeSubmissionEvent : public ApplicationEvent {
public:
    ResumeSubmissionEvent(const std::string& date,
                          const std::string& notes);

    std::string getType()   const;  
    void        printEvent() const;
};
// records an interview, with format 
//______
enum class InterviewFormat { PHONE, VIDEO, ONSITE };

class InterviewEvent : public ApplicationEvent {
    InterviewFormat format_;  
public:
    InterviewEvent(const std::string& date,
                   const std::string& notes,
                   InterviewFormat format);

    std::string getType()   const;  
    void        printEvent() const;

    InterviewFormat getFormat() const;
};
// records a job offer, including offered salary
//_______
class OfferEvent : public ApplicationEvent {
    double salary_;  
public:
    OfferEvent(const std::string& date,
               const std::string& notes,
               double salary);

    std::string getType()   const;  
    void        printEvent() const;

    double getSalary() const;
};

//shows the company which you applied to
//contains name, location, and website, with getters/setters and a print method
//____
class Company {
private:
    std::string name_;      
    std::string location_;  
    std::string website_;   

public:
    Company(const std::string& name,
            const std::string& location,
            const std::string& website);

    //retrieve or update company details
    std::string getName()     const;
    void        setName(const std::string&);

    std::string getLocation() const;
    void        setLocation(const std::string&);

    std::string getWebsite()  const;
    void        setWebsite(const std::string&);

    //print company information
    void printInfo() const;
};

// tracks individual application, status, and events
// holds the Company, position title, date applied, current status, and a list of polymorphic ApplicationEvent pointers.
// ______
class Application {
private:
    Company                        company_;       
    std::string                    position_;      
    std::string                    dateApplied_;   
    std::string                    status_;        
    std::vector<ApplicationEvent*> events_;      

public:
    Application(const Company&     company,
                const std::string& position,
                const std::string& dateApplied);

    ~Application();  

    //adds a new event (resume submission, interview, offer, etc.)
    void addEvent(ApplicationEvent* e);

    //updates the application status string
    void updateStatus(const std::string& newStatus);

    //gets current status
    std::string getStatus() const;

    //prints a summary of the application and its events
    void printSummary() const;

    //access the main fields
    const Company&     getCompany()     const;
    const std::string& getPosition()    const;
    const std::string& getDateApplied() const;
};

#endif // JOBTRACKER_H
