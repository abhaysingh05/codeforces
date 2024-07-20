#!/bin/bash

# Navigate to the directory
cd "$1"

# Compile the C++ file
g++ "$2" -o "${2%.*}" -DLOCAL

# Read input from the user until EOF (Ctrl+D)
input=$(cat)

# Print "Output:" before running the program
echo "Output:"

# Measure the execution time and run the compiled program
start=$(date +%s%N)
output=$(echo "$input" | ./"${2%.*}")
end=$(date +%s%N)

# Print the output
echo "$output"

# Calculate elapsed time in seconds
elapsed=$(echo "scale=9; ($end - $start) / 1000000000" | bc)

# Display the runtime
echo "Time measured: $elapsed seconds."

# Clean up
rm "${2%.*}"
