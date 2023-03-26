#!/bin/bash
echo ./convert 0
./convert 0
echo ---------------------------------
echo ./convert a
./convert a

echo ---------------------------------
echo ./convert nan
./convert nan

echo ---------------------------------
echo ./convert 42.0f
./convert 42.0f


echo ---------------------------------
echo ./convert inff
./convert inff