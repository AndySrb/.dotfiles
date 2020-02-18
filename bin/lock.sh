#!/bin/bash
setxkbmap -layout us
scrot /tmp/screen.png
#convert /tmp/screen.png -scale 10% -scale 1000% /tmp/screen.png
#convert /tmp/screen.png -paint 3 -modulate80 /tmp/screen.png
convert /tmp/screen.png -paint 3 /tmp/screen.png
[[ -f ~/.i3/lock.png ]] && convert /tmp/screen.png  ~/.config/i3/lock.png -gravity center -composite -matte /tmp/screen.png
mocp -P
i3lock -u -e -i /tmp/screen.png
