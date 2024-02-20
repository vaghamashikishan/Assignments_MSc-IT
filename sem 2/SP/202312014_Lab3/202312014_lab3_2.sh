#!/bin/bash

if [ $# -ne 1 ]; then
  echo "Usage: $0 <directory_path>"
  exit 1
fi

directory_path=$1

# Validate the given directory path
if [ ! -d "$directory_path" ]; then
  echo "Error: $directory_path is not a valid directory."
  exit 1
fi

# Recursively list all files in the directory and its subdirectories
# and count them using wc -l
file_count=$(ls -R "$directory_path" | wc -l)

# Subtract 1 from the count to exclude the first line, which is the directory name itself
file_count=$((file_count - 1))

echo "Total number of files in $directory_path and its subdirectories: $file_count"

