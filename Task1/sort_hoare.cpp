#include "sort_hoare.h"

std::string HoareSorter::title() const { return "Хоара"; }

long long HoareSorter::getCmpCount() const { return cmpCount; }
long long HoareSorter::getMoveCount() const { return moveCount; }

void HoareSorter::clearCounters()
{
    cmpCount = 0;
    moveCount = 0;
}

bool HoareSorter::isLess(int x, int y)
{
    cmpCount++;
    return x < y;
}

std::vector<int> HoareSorter::recursiveSort(const std::vector<int>& part)
{
    if (part.empty())
        return std::vector<int>();
    if (part.size() == 1)
        return std::vector<int>(1, part[0]);

    std::size_t midIndex = part.size() / 2;
    int support = part[midIndex];

    std::vector<int> leftPart;
    std::vector<int> rightPart;

    for (std::size_t k = 0; k < part.size(); k++)
    {
        if (k == midIndex)
            continue;

        if (isLess(part[k], support))
            leftPart.push_back(part[k]);
        else
            rightPart.push_back(part[k]);
        moveCount++;
    }

    std::vector<int> merged = recursiveSort(leftPart);
    merged.push_back(support);

    std::vector<int> rightSorted = recursiveSort(rightPart);
    merged.insert(merged.end(), rightSorted.begin(), rightSorted.end());

    return merged;
}

void HoareSorter::execute(std::vector<int>& data)
{
    data = recursiveSort(data);
}
