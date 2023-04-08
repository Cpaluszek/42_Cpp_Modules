#!/bin/bash
# [Reverse Polish Notation - RPN - Online Calculator](https://www.dcode.fr/reverse-polish-notation)

echo ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"

echo ./RPN "7 7 * 7 -"
./RPN "7 7 * 7 -"

echo ./RPN "1 2 * 2 / 2 * 2 4 - +"
./RPN "1 2 * 2 / 2 * 2 4 - +"

echo "...... ERRORS ......"
echo ./RPN "(1 + 1)"
./RPN "(1 + 1)"

echo ./RPN "9 0 /"
./RPN "9 0 /"

echo ./RPN "9 +"
./RPN "9 +"

echo ./RPN "9 7"
./RPN "9 7"
