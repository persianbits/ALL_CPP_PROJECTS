#include <iostream>
#include <fstream>
using namespace std;
/*

The given code is a C++ program which calculates an employee's weekly salary based on their hourly rate of pay and the number of hours worked per week. It also takes into consideration overtime remuneration and taxes.

*/
#ifndef WEEKLY_SALARY_CALCULATOR_H
#define WEEKLY_SALARY_CALCULATOR_H
class WeeklySalaryCalculator
{
public:
    WeeklySalaryCalculator() {}
    virtual ~WeeklySalaryCalculator() {}

    void printEmployeeInformation(const string& first_name, const string& last_name, double weekly_wage_after_tax, ofstream& outputFile)
    {
        string name_combine = first_name + " " + last_name;
        cout << "Hello " << name_combine << ", you've worked FULL-TIME this week and you received $" << weekly_wage_after_tax << " after tax." << endl;
        outputFile << "Employment Status: Full-Time" << endl;
        outputFile << "Weekly Wage (After Tax): $" << weekly_wage_after_tax << endl;
    }

    void calculateWeeklySalary()
    {
        string first_name;
        string last_name;
        double hours_of_work_per_week;
        double hourly_wage_rate;
        double tax_rate = 0.21;
        double overtime_pay_rate = 1.5;

        ofstream outputFile("output.txt");  // Open the output file for writing

        if (outputFile.is_open())
        {
            cout << "WHAT IS YOUR FIRST NAME? ";
            cin >> first_name;
            outputFile << "First Name: " << first_name << endl;

            cout << "WHAT IS YOUR LAST NAME? ";
            cin >> last_name;
            outputFile << "Last Name: " << last_name << endl;

            cout << "HOW MUCH DO YOU GET PER HOUR? ";
            cin >> hourly_wage_rate;
            outputFile << "Hourly Wage Rate: " << hourly_wage_rate << endl;

            cout << "HOW MANY HOURS DID YOU WORK THIS WEEK? ";
            cin >> hours_of_work_per_week;
            outputFile << "Hours of Work: " << hours_of_work_per_week << endl;

            double total_earned_before_tax = hourly_wage_rate * hours_of_work_per_week;
            double total_wage_tax = total_earned_before_tax * tax_rate;
            double weekly_wage_after_tax = total_earned_before_tax - total_wage_tax;

            double overtime_hours = hours_of_work_per_week - 40;
            double overtime_earned_before_tax = overtime_hours * overtime_pay_rate;
            double overtime_tax = overtime_earned_before_tax * tax_rate;
            double overtime_wage_after_tax = overtime_earned_before_tax - overtime_tax;
            double fulltime_overtime_wage_after_tax = weekly_wage_after_tax + overtime_wage_after_tax;

            if (hours_of_work_per_week > 0 && hours_of_work_per_week <= 20)
            {
                cout << "Hello " << first_name << " " << last_name << ", you've worked PART-TIME this week and you received $" << weekly_wage_after_tax << " after tax." << endl;
                outputFile << "Employment Status: Part-Time" << endl;
                outputFile << "Weekly Wage (After Tax): $" << weekly_wage_after_tax << endl;
            }
            else if (hours_of_work_per_week > 20 && hours_of_work_per_week <= 40)
            {
                printEmployeeInformation(first_name, last_name, weekly_wage_after_tax, outputFile);
            }
            else if (hours_of_work_per_week > 40 && hours_of_work_per_week <= 105)
            {
                cout << "Hello " << first_name << " " << last_name << ", you've worked FULL-TIME with OVERTIME this week and you received $" << fulltime_overtime_wage_after_tax << " after tax." << endl;
outputFile << "Employment Status: Full-Time with Overtime" << endl;
outputFile << "Weekly Wage (After Tax): $" << fulltime_overtime_wage_after_tax << endl;
}
else {
cout << "Invalid try again!!!" << endl;
}
outputFile.close(); // Close the output file
}
else {
cout << "Failed to open the output file." << endl;
}
}
};
#endif // WEEKLY_SALARY_CALCULATOR_H
int main() {
WeeklySalaryCalculator calculator;
calculator.calculateWeeklySalary();
return 0;
}
