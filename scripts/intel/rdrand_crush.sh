#!/bin/bash

. config.sh
cd ~
( ( cat /proc/cpuinfo | grep "model name" ) && ./randTest < run/rdrand_crush.txt ) > intel_rdrand_crush.txt
