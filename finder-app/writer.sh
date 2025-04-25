#!/bin/bash

#Accepts the following arguments:
    # the first argument is a full path to a file (including filename) on the filesystem, referred to below as writefile;
    # the second argument is a text string which will be written within this file, referred to below as writestr
#Exits with value 1 error and print statements if any of the arguments above were not specified
#Creates a new file with name and path writefile with content writestr, overwriting any existing file and creating the path if it doesn’t exist. 
#Exits with value 1 and error print statement if the file could not be created.

if [ -z "$1" ] || [ -z "$2" ]; then
  echo "ERROR: Missing arguments!"
  exit 1
fi

writefile=$1
writestr=$2

dir_path=$(dirname "${writefile}")
file_name=$(basename "${writefile}")

mkdir -p ${dir_path}
cd ${dir_path} 
touch ${file_name}
echo "${writestr}" > ${writefile}

