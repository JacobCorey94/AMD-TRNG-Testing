#!/bin/bash

. config.sh
cd ~
( ( cat /proc/cpuinfo | grep "model name" ) && ./randTest < run/rdrand_smallcrush.txt ) > amd_rdrand_smallcrush.txt
