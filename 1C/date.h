#include <string>


bool Leap(int year) {
    return (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0));
}

int numberOfDay(int day, int month, int year) {
    const int daysInYear[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    bool leap = month >= 3 && Leap(year);
    return daysInYear[month - 1] + day + leap;
}

class Date {
 public:
    Date(int year, int month, int day) {
        d = day;
        m = month;
        y = year;
    }

    bool IsLeap() const {
        return Leap(y);
    }

    std::string ToString() const {
        std::string resd = std::string(2 - std::to_string(d).length(), '0') + std::to_string(d);
        std::string resm = std::string(2 - std::to_string(m).length(), '0') + std::to_string(m);
        std::string resy = std::string(4 - std::to_string(y).length(), '0') + std::to_string(y);
        return resd + '.' + resm + '.' + resy;
    }

    Date DaysLater(int days) const {
        const int daysInYear[] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
        const int daysInYearL[] = {31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};
        Date newDate(y, m, d);
        int resNumber = days + numberOfDay(d, m, y);
        if (resNumber > 365) {
            newDate.y += resNumber / 365;
            resNumber %= 365;
            for (int i = y; i < newDate.y; i++) {
                if (Leap(i)) {
                    resNumber--;
                }
            }
        }
        int k = 0;
        if (Leap(newDate.y)) {
            while (k < 12 && resNumber > daysInYearL[k]) {
                k++;
            }
            if (k > 0)
                resNumber -= daysInYearL[k - 1];
        } else {
            while (k < 12 && resNumber > daysInYear[k]) {
                k++;
            }
            if (k > 0)
                resNumber -= daysInYear[k - 1];
        }
        newDate.m = k + 1;
        newDate.d = resNumber;
        return newDate;
    }

    int DaysLeft(const Date& date) const {
        const int daysInYear[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
        if (y == date.y) {
            return numberOfDay(date.d, date.m, date.y) - numberOfDay(d, m, y);
        } else {
            int res = numberOfDay(date.d, date.m, date.y) + 365 - numberOfDay(d, m, y) + IsLeap();
            for (int i = y; i < Leap(date.y); i++) {
                res += 365 + Leap(i);
            }
            return res;
        }
    }
 private:
    int d, m, y;
};