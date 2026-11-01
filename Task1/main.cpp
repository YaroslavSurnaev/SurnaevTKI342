#include "sort_bubble.h"
#include "sort_insertion.h"
#include "sort_hoare.h"

#include <iostream>
#include <random>
#include <chrono>
#include <locale.h>
#include <iomanip>

using namespace std;

bool checkOrdered(const vector<int>& data)
{
    for (size_t k = 1; k < data.size(); k++)
        if (data[k] < data[k - 1])
            return false;
    return true;
}

vector<int> makeRandomVector(int count, int lowBound, int highBound)
{
    vector<int> result(count);
    mt19937 engine(std::random_device{}());
    uniform_int_distribution<int> distribution(lowBound, highBound);

    for (int k = 0; k < count; k++)
        result[k] = distribution(engine);

    return result;
}

template <typename Sorter>
double measureAndReport(Sorter& sorter, const vector<int>& source)
{
    vector<int> working = source;
    sorter.clearCounters();

    auto t0 = chrono::high_resolution_clock::now();
    sorter.execute(working);
    auto t1 = chrono::high_resolution_clock::now();

    double elapsedMs = chrono::duration<double, milli>(t1 - t0).count();

    cout << left << setw(20) << sorter.title()
        << " | сравнений: " << setw(9) << sorter.getCmpCount()
        << " | перестановок: " << setw(9) << sorter.getMoveCount()
        << " | время: " << fixed << setprecision(3) << setw(10) << elapsedMs << " мс"
        << " | отсортирован: " << (checkOrdered(working) ? "да" : "НЕТ") << '\n';

    return elapsedMs;
}

int main()
{
    setlocale(LC_ALL, "RU");

    const int elementCount = 10000;
    const int lowBound = -100;
    const int highBound = 100;

    vector<int> source = makeRandomVector(elementCount, lowBound, highBound);

    cout << "Размер массива: " << elementCount
        << ", диапазон: [" << lowBound << "; " << highBound << "]\n\n";

    BubbleSorter bubbleSorter;
    InsertionSorter insertionSorter;
    HoareSorter hoareSorter;

    double bubbleMs = measureAndReport(bubbleSorter, source);
    double insertionMs = measureAndReport(insertionSorter, source);
    double hoareMs = measureAndReport(hoareSorter, source);

    cout << "\nСамый быстрый метод: ";
    if (hoareMs <= insertionMs && hoareMs <= bubbleMs)
        cout << hoareSorter.title() << '\n';
    else if (insertionMs <= bubbleMs)
        cout << insertionSorter.title() << '\n';
    else
        cout << bubbleSorter.title() << '\n';

    return 0;
}
