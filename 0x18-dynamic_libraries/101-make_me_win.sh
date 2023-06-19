#!/bin/bash
wget -P /tmp https://github.com/chris-zano/alx-low_level_programming/blob/master/0x18-dynamic_libraries/101-make_me_win.o
export LD_PRELOAD=/tmp/101-make_me_win.o
