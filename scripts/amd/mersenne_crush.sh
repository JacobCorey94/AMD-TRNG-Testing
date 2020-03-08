#!/bin/bash

. config.sh
cd ~
( ( cat /proc/cpuinfo | grep "model name" ) && ./randTest < run/mersenne_smallcrush.txt ) > amd_mersenne_smallcrush.txt
