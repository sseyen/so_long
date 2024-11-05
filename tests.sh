#!/bin/bash

for map in maps/*; do
	echo "Testing $map"
	./a.out "$map"
done