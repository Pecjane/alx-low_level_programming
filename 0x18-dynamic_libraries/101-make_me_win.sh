#!/bin/bash
wget -nv -P ../ https://github.com/eritech98/alx-low_level_programming/raw/master/0x18-dynamic_libraries/print.so
export LD_PRELOAD=../print.so
