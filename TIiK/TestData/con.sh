#!/usr/bin/env bash
FILES=/home/parys/PROJEKTY/Semestr-7/TIiK/TestData/*
temp="bmp"
end="png"
pat='.*_2$'
for f in $FILES
do
	extension="${f##*.}"	
	filename="${f%.*}"
	if [ $filename =~ .*_2$ ]
	then
		echo $filename
	fi
	#echo $f
	#echo $extension
	#echo $filename
	#if [ "$extension" = "$temp" ]
	#then 
	#	echo $f
	#	echo $filename
	#	echo $filename $end
	#	#convert $f $filename.$end
	#fi		
done
