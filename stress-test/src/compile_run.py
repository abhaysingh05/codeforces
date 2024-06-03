import subprocess
import os
from src.color_print import cprint

# Compile C++ file
def compile(file_path):
    # Ensure the file is a C++ file
    if not file_path.endswith(".cpp"):
        return -1
    
    # Get the base file name without extension
    file = ".".join(file_path.split(".")[:-1])
    
    # Compilation command
    cmd = f"g++ -std=c++17 -DONLINE_JUDGE \"{file_path}\" -o \"{file}.out\""
    
    # Print compilation status
    print('\nCompiling ', end = '')
    cprint(file_path, clr = "purple")
    
    # Run the compilation command
    subprocess.run(cmd, check=True, shell=True)
    print('Compilation done')

# Run compiled file and return output
def run(file_path, std_input=None):
    # Ensure the file is a C++ file
    if not file_path.endswith(".cpp"):
        return -1
    
    # Get the base file name without extension
    file = ".".join(file_path.split(".")[:-1])
    
    # Execution command
    cmd = f"./{file}.out"
    
    # Run the command and capture the output
    return subprocess.run(cmd, input=std_input, capture_output=True, shell=True, text=True, check=True)
