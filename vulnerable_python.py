# vulnerable_python.py

# Demonstrates:
# - Command injection
# - Unsafe use of eval

# Example attacks (next 2):

# Command injection
# Input:
# file.txt; ls
# or
# file.txt && whoami

# Eval exploitation
# Input:
# __import__('os').system('ls')

import os

print("=== Vulnerable Python Demo ===")

name = input("Enter your name: ")
print("Hello,", name)

# Vulnerability #1: Command Injection
filename = input("Enter a filename to view: ")

# UNSAFE: user input directly concatenated into shell command
os.system("cat " + filename)

# Vulnerability #2: Unsafe eval
expression = input("Enter a math expression: ")

# UNSAFE: arbitrary Python execution
result = eval(expression)

print("Result:", result)
