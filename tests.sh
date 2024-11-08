#!/bin/bash

for map in maps/*; do
	echo "Testing $map"
	./so_long "$map"
done