#ifndef SORT_HOARE_H
#define SORT_HOARE_H

#include <vector>
#include <string>

class HoareSorter
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
    std::vector<int> recursiveSort(const std::vector<int>& part);
};

#endif
