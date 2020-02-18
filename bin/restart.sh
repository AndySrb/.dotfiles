#!/bin/bash


echo -n 'Do you want to restart your pc
         (Y)es, (N)o
         :' 
read options
 
         case $options  in

         Y|y)
#		 sudo  systemctl disable logmein-hamachi &&
	sudo reboot
         ;;
         N|n) exit
         ;;
 *) exit
 esac

