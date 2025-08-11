#include "JobTracker.h"
#include <iostream>
using namespace std;

int main() {
    Company usc("University of Southern California", "Los Angeles, CA", "https://usc.edu");

    Application app(usc, "Research Assistant", "2025-05-01");
    app.addEvent(new ResumeSubmissionEvent("2025-05-02", "Submitted via USC careers portal"));
    app.addEvent(new InterviewEvent("2025-05-04", "Zoom interview with faculty advisor", InterviewFormat::VIDEO));
    app.addEvent(new OfferEvent("2025-05-10", "Offer extended via email", 42000.00));

    app.updateStatus("Offer Received");
    app.printSummary();

    return 0;
}

