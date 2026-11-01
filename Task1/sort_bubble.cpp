#include "sort_bubble.h"

std::string BubbleSorter::title() const { return "Обычный"; }

long long BubbleSorter::getCmpCount() const { return cmpCount; }
long long BubbleSorter::getMoveCount() const { return moveCount; }

void BubbleSorter::clearCounters()
{
    cmpCount = 0;
    moveCount = 0;
}

bool BubbleSorter::isLess(int x, int y)
{
    cmpCount++;
    return x < y;
}

void BubbleSorter::exchange(std::vector<int>& data, int p, int q)
{
    std::swap(data[p], data[q]);
    moveCount++;
}

void BubbleSorter::execute(std::vector<int>& data)
{
    int len = static_cast<int>(data.size());
    for (int pass = 0; pass < len - 1; pass++)
    {
        for (int pos = 0; pos < len - 1 - pass; pos++)
        {
            if (isLess(data[pos + 1], data[pos]))
                exchange(data, pos, pos + 1);
        }
    }
}
