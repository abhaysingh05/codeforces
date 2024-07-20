#!/bin/bash

# Navigate to the directory
cd "$1"

# Compile the C++ file
g++ "$2" -o "${2%.*}" -DLOCAL

# Prompt for input
echo "Input:"
input=$(cat)

# Prompt for expected output
echo "Expected Output:"
expected_output=$(cat)

# Measure the execution time and run the compiled program
start=$(date +%s%N)
output=$(echo "$input" | ./"${2%.*}")
end=$(date +%s%N)

# Print the output
echo "Output:"
echo "$output"

# Calculate elapsed time in seconds
elapsed=$(echo "scale=9; ($end - $start) / 1000000000" | bc)

# Display the runtime
echo "Time measured: $elapsed seconds."

# Compare the actual output with the expected output
diff <(echo "$output") <(echo "$expected_output") > diff_output.txt

if [ -s diff_output.txt ]; then
    echo "Wrong Answer"
else
    echo "Accepted"
fi

# Clean up
rm "${2%.*}" diff_output.txt
