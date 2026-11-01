#ifndef SORT_INSERTION_H
#define SORT_INSERTION_H

#include <vector>
#include <string>

class InsertionSorter
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
    int locateInsertIndex(const std::vector<int>& ordered, int value);
};

#endif
