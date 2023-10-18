#!/bin/bash

. config.sh
cd ~/testu01/AMD-TRNG-Testing
( ( cat /proc/cpuinfo | grep "model name" ) && ./randTest < run/rdrand_bigcrush.txt ) > intel_rdrand_bigcrush.txt
