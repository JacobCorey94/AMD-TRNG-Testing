#!/bin/bash

. config.sh
cd ~
( ( cat /proc/cpuinfo | grep "model name" ) && ./randTest < run/mersenne_smallcrush.txt ) > intel_mersenne_smallcrush.txt
