#include <fstream>
#include <chrono>
#include <functional>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

const char three_a = 3 - 'a';

template<typename TimePoint>
class basic_time_meter
{
    function<TimePoint()> get_now_;
    function<double(TimePoint, TimePoint)> get_sec_;

    TimePoint begin_;
    TimePoint stop_;
    bool stopped_;

public:
    template<typename GetNow, typename GetSec>
    basic_time_meter(GetNow&& gn, GetSec&& gs) : get_now_(std::forward<GetNow>(gn)), get_sec_(std::forward<GetSec>(gs)),
                                                 begin_(get_now_()), stopped_(false) { }

    double seconds() const
    {
        if (stopped_)
            return get_sec_(begin_, stop_);
        return get_sec_(begin_, get_now_());
    }

    double restart()
    {
        const TimePoint now = get_now_();
        double result = seconds(now);
        stopped_ = false;
        begin_ = now;
        return result;
    }

    double stop()
    {
        if (stopped_)
            return seconds();
        stop_ = get_now_();
        stopped_ = true;
        return seconds(stop_);
    }

    void start()
    {
        if (!stopped_)
            return;
        stopped_ = false;
        begin_ += get_now_() - stop_;
    }

    bool stopped() const
    {
        return stopped_;
    }

private:
    double seconds(TimePoint now) const
    {
        if (stopped_)
            return get_sec_(begin_, stop_);
        return get_sec_(begin_, now);
    }
};

class time_meter : public basic_time_meter<chrono::high_resolution_clock::time_point>
{
    using time_point = chrono::high_resolution_clock::time_point;

    static double get_seconds(time_point p1, time_point p2)
    {
        return static_cast<double>((p2 - p1).count()) / chrono::high_resolution_clock::period::den;
    }

public:
    time_meter() : basic_time_meter<time_point>(chrono::high_resolution_clock::now, get_seconds) { }
};

// **********************

void ___CaesarEncryptOneThread___(std::string* s)
{
    for (char& c : *s)
        c = 'a' + (c + 3 - 'a') % 26;
}


void part(char * s, int length) {
    for (int i = 0; i < length; i++) {
        *s = 'a' + (*s + three_a) % 26;
        s++;
    }
}

void CaesarEncrypt(std::string* s) {
    int n = 8;
    int ln = s->length() / n;
    std::vector<std::thread> t;
    t.reserve(n);
    for (int i = 0; i < n - 1; i++) {
        t.emplace_back(&part, s->data() + i * ln, ln);
    }

    t.emplace_back(&part, s->data() + (n - 1) * ln, ln + s->length() % n);

    for (auto &k : t) {
        k.join();
    }

}

int main()
{
#if 1
    ofstream output_file("input.txt");
    for (int i = 0; i < 2000000; i++) {
        output_file << static_cast<char>('a' + rand() % 26);
    }
#else
    ifstream input_file("input.txt");

    ofstream output_file("output.txt");
    string s;
    input_file >> s;
    string s2 = s;

    time_meter tm;
    ___CaesarEncryptOneThread___(&s2);
    const double one_thread_result = tm.seconds();

    tm.restart();
    CaesarEncrypt(&s);
    const double result = tm.seconds();

    const double x = result / one_thread_result;

    if (x > 0.75)
        output_file << "So sloooooow\n\n" << "time / time_one_thread = " << result << " " << one_thread_result << endl;
    else
        output_file << "\n\ncool nice\n\n" << result << " " << one_thread_result << endl;

    return 0;

#endif
}