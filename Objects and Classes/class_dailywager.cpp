#include <iostream>

using namespace std;

class DailyWager
{
    int hourRate;
    int extraHourRate;

    void setHourRate(int hr) { if (hr > 0) hourRate = hr; else hourRate = 0; }
    void setExtraHourRate(int ehr) { if (ehr > 0) extraHourRate = ehr; else extraHourRate = 0; }

    int getHourRate() { return hourRate; }
    int getExtraHourRate() { return extraHourRate; }

public:
    DailyWager()
    {
        setHourRate(500 + rand() + 1501);
        setExtraHourRate(1000 + rand() + 2501);
    }

    DailyWager(int hr, int ehr)
    {
        setHourRate(hr);
        setExtraHourRate(ehr);
    }

    int calculateWeeklyWage(int hoursWorked)
    {
        int wage = 0;
        if (hoursWorked > 40)
        {
            wage = (40 * hourRate) + ((hoursWorked - 40) * extraHourRate);
            cout << "40*" << hourRate << " + " << hoursWorked - 40 << "*" << extraHourRate;
        }
        else wage = (hoursWorked * hourRate);
        cout << " = ";
        return wage;
    }
};

int main()
{
    DailyWager w(500, 750);
    cout << "Weekly Wage: " << w.calculateWeeklyWage(45) << endl;
}