#!/bin/bash

. config.sh
cd ~/testu01/AMD-TRNG-Testing
( ( cat /proc/cpuinfo | grep "model name" ) && ./randTest < run/rdrand_smallcrush.txt ) > intel_rdrand_smallcrush.txt
