#!/bin/bash

. config.sh
cd ~
( ( cat /proc/cpuinfo | grep "model name" ) && ./randTest < run/mersenne_bigcrush.txt ) > amd_mersenne_bigcrush.txt
