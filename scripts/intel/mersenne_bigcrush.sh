#!/bin/bash

. config.sh
cd ~
( ( cat /proc/cpuinfo | grep "model name" ) && ./randTest < run/mersenne_bigcrush.txt ) > intel_mersenne_bigcrush.txt
