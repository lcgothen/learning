#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee : public Person {
public:
    // get info
    int get_weekly_hours();
    float get_hours_booked();

    // change info
    void book_time(float requested_time);
    void update_weekly_hours(int new_weekly_hours);

private:
int total_weekly_hours_;
float hours_booked_;
};

#endif // EMPLOYEE_H