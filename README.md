# Job Application Tracker (C++)

**Author:** Surpreet Kaur  

## Overview  
A C++ object-oriented program that tracks job applications, their statuses, and associated events such as resume submissions, interviews, and offers. Demonstrates the use of classes, inheritance, polymorphism, encapsulation, and dynamic memory management.

The project models a **real-world job application process** by linking companies, applications, and events in a clean, maintainable structure.

## Features  
- **Company Profiles** — store name, location, and website  
- **Application Tracking** — position title, application date, current status  
- **Event Recording** — resume submissions, interviews (phone, video, onsite), and job offers  
- **Polymorphic Event Printing** — each event prints with custom formatting based on its type  
- **Status Updates** — change and display application progress  
- **Dynamic Memory Management** — safely stores and cleans up event history  

## How It Works  
- `Company` holds details about the organization.  
- `Application` ties a company to a specific job position and manages associated events.  
- `ApplicationEvent` is a base class with three derived types:  
  - `ResumeSubmissionEvent`  
  - `InterviewEvent` (with interview format enum)  
  - `OfferEvent` (with salary data)  
- The program uses a vector of polymorphic pointers to store different event types and print them dynamically.

## Quick Start  
Clone the repository:  
```bash
git clone https://github.com/<your-username>/job-application-tracker.git
cd job-application-tracker
```
## Compile the project: 
```bash
g++ main.cpp JobTracker.cpp -o jobtracker
```
## Run the program:
```bash
./jobtracker
```
## Example Output: 
```bash
Application to University of Southern California for position: Research Assistant (Applied on 2025-05-01)
Status: Offer Received
Events:
Resume submitted on 2025-05-02. Notes: Submitted via USC careers portal
Interview (Video) on 2025-05-04. Notes: Zoom interview with faculty advisor
Job offer received on 2025-05-10. Salary: $42000. Notes: Offer extended via email
```
## Notes 
```bash
Easily extendable — new event types can be added with minimal changes.
Demonstrates OOP principles in a practical use case.
Separation of interface (.h) and implementation (.cpp) for maintainability.
```
