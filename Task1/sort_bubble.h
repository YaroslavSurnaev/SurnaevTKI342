#ifndef SORT_BUBBLE_H
#define SORT_BUBBLE_H

#include <vector>
#include <string>

class BubbleSorter
{
public:
    std::string title() const;
    void execute(std::vector<int>& data);
    long long getCmpCount() const;
    long long getMoveCount() const;
    void clearCounters();

private:
    long long cmpCount = 0;
    long long moveCount = 0;
    bool isLess(int x, int y);
    void exchange(std::vector<int>& data, int p, int q);
};

#endif
