#include "sort_insertion.h"

std::string InsertionSorter::title() const { return "Вставками"; }

long long InsertionSorter::getCmpCount() const { return cmpCount; }
long long InsertionSorter::getMoveCount() const { return moveCount; }

void InsertionSorter::clearCounters()
{
    cmpCount = 0;
    moveCount = 0;
}

bool InsertionSorter::isLess(int x, int y)
{
    cmpCount++;
    return x < y;
}

int InsertionSorter::locateInsertIndex(const std::vector<int>& ordered, int value)
{
    int lo = 0;
    int hi = static_cast<int>(ordered.size());

    while (lo < hi)
    {
        int center = lo + (hi - lo) / 2;
        if (isLess(value, ordered[center]))
            hi = center;
        else
            lo = center + 1;
    }
    return lo;
}

void InsertionSorter::execute(std::vector<int>& data)
{
    std::vector<int> result;

    for (std::size_t k = 0; k < data.size(); k++)
    {
        int current = data[k];
        int index = locateInsertIndex(result, current);
        result.insert(result.begin() + index, current);
        moveCount++;
    }

    data = result;
}
