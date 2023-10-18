#!/bin/bash

. config.sh
cd ~
( ( cat /proc/cpuinfo | grep "model name" ) && ./randTest < run/mersenne_crush.txt ) > intel_mersenne_crush.txt
