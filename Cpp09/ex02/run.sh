#!/bin/bash
#  ./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`
# above command do not work with duplicate detection

echo ./PmergeMe 5 4 3 2 1
./PmergeMe 5 4 3 2 1

echo
echo ./PmergeMe 9 6 2 3 8 4 1 0
./PmergeMe 9 6 2 3 8 4 1 0

echo "------ Errors ------"
echo ./PmergeMe -1 2
./PmergeMe -1 2

echo ./PmergeMe 2222222222222222222222 12
./PmergeMe 2222222222222222222222 12

echo ./PmergeMe 1 1
./PmergeMe 1 1
