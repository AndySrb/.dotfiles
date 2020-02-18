#!/bin/bash
mem_free =$(free -m | grep Mem | awk '{print $2}' | echo $(expr `xargs $1` / 100))
mem_used =$(free -m | grep Mem | awk '{print $3}' | echo $(expr `xargs $1` / 100))
