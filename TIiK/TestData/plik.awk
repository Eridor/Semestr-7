#!/usr/bin/awk -f
BEGIN {licz = 0} {print "(" $licz "," $1 ")"; licz++;}
