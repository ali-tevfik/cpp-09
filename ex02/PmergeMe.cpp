#include "PmergeMe.hpp"

void PmergeMe::deqMerge(std::deque<int>& deq, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = deq[l + i];
    for (j = 0; j < n2 ; j++)
        R[j] = deq[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            deq[k] = L[i];
            i++;
        }
        else {
            deq[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        deq[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        deq[k] = R[j];
        j++;
        k++;
    }
}

void PmergeMe::vecMerge(std::vector<int>& vec, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    std::vector<int> L(n1), R(n2);

    for (i = 0; i < n1; i++)
        L[i] = vec[l + i];
    for (j = 0; j < n2 ; j++)
        R[j] = vec[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vec[k] = L[i];
            i++;
        }
        else {
            vec[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vec[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        vec[k] = R[j];
        j++;
        k++;
    }
}

void PmergeMe::deqSort(std::deque<int>& deq, int begin, int end) {
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    deqSort(deq, begin, mid);
    deqSort(deq, mid + 1, end);
    deqMerge(deq, begin, mid, end);
}

void PmergeMe::vecSort(std::vector<int>& vec, int begin, int end) {
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    vecSort(vec, begin, mid);
    vecSort(vec, mid + 1, end);
    vecMerge(vec, begin, mid, end);
}

PmergeMe::PmergeMe(std::vector<int>& vec, std::deque<int>& deq) {
    std::cout << "Before sorting: ";
    for (std::vector<int>::size_type i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    vecSort(vec, 0, vec.size() - 1);

    std::cout << "After sorting: ";
    for (std::vector<int>::size_type i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;


    std::cout << "before deq sorting: ";
    for (std::deque<int>::size_type i = 0; i < deq.size(); i++) {
        std::cout << deq[i] << " ";
    }
    std::cout << std::endl;

    deqSort(deq, 0, deq.size() - 1);

    std::cout << "after deq sorting: ";
    for (std::deque<int>::size_type i = 0; i < deq.size(); i++) {
        std::cout << deq[i] << " ";
    }
    std::cout << std::endl;

}

PmergeMe::~PmergeMe() {
}

