#include <iostream>
#include <iomanip>

using namespace std;

class Time
{
    int hour;
    int min;
    int sec;
    bool isTwentyFour;

    void set_hour(int h) { if (h >= 0 && h <= 23) hour = h; else hour = 6; }
    void set_min(int m) { if (m >= 0 && m <= 59) min = m; else hour = 6;}
    void set_sec(int s) { if (s >= 0 && s <= 59) sec = s; else hour = 6;}
    void set_istwentyFour(bool t) { isTwentyFour = t; }

    int get_hour() { return hour; }
    int get_min() { return min; }
    int get_sec() { return sec; }
    bool get_istwentyFour() { return isTwentyFour; }

public:
    void set_twentyFourMode() { set_istwentyFour(true); }
    void set_twelveMode() { set_istwentyFour(false); }

    Time()
    {
        set_hour(6);
        set_min(6);
        set_sec(6);
        set_istwentyFour(true);
    }
    Time(int h, int m, int s)
    {
        set_hour(h);
        set_min(m);
        set_sec(s);
        set_istwentyFour(true);
    }

    void show()
    {
        int h = get_hour();
        int m = get_min();
        int s = get_sec();
        string am_pm = "";

        if (!get_istwentyFour())
        {
            if (h > 12) am_pm = "PM";
            else am_pm = "AM";
            h %= 12;
        }
        cout << "\n" << setfill('0') << setw(2) << h % 12 << ":"  << setfill('0') << setw(2) << m << ":"  << setfill('0') << setw(2) << s << " " << am_pm << "\n\n";
    }
};

int main()
{
    Time t1(-13, 45, 30);
    t1.show();
    t1.set_twelveMode();
    t1.show();
    Time t2;
    t2.show();
}