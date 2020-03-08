#!/bin/bash

. config.sh
cd ~
( ( cat /proc/cpuinfo | grep "model name" ) && ./randTest < run/rdrand_bigcrush.txt ) > amd_rdrand_bigcrush.txt
