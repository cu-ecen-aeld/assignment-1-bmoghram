#!/bin/bash

# Accepts the following runtime arguments: 
    #the first argument is a path to a directory on the filesystem, referred to below as filesdir; 
    #the second argument is a text string which will be searched within these files, referred to below as searchstr
# Exits with return value 1 error and print statements if any of the parameters above were not specified
# Exits with return value 1 error and print statements if filesdir does not represent a directory on the filesystem
# Prints a message "The number of files are X and the number of matching lines are Y" 
    #X is the number of files in the directory and all subdirectories 
    #Y is the number of matching lines found in respective files,
      # where a matching line refers to a line which contains searchstr (and may also contain additional content).

if [ -z "$1" ] || [ -z "$2" ]; then
  echo "ERROR: Missing arguments!"
  exit 1
fi

filesdir=$1
searchstr=$2

if [ ! -d "$1" ]; then
  echo "ERROR: directory doesn't exists!"
  exit 1
fi

num_files=$(find $filesdir -type f  | wc -l)
num_match_lines=$(grep -R $searchstr $filesdir | wc -l)

echo "The number of files are $num_files and the number of matching lines are $num_match_lines" 

