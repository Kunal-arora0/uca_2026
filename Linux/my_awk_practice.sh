#!/bin/bash
# my_awk_practice.sh
# Practice script: cut, grep, and awk on Employees.txt

echo "=== Task 1: Basic Field Extraction ==="
cut -d',' -f1,2 Employees.txt | tr ',' ' '
echo

echo "=== Task 2: Filtering by Row (Engineering only) ==="
grep "Engineering" Employees.txt
echo

echo "=== Task 3: Basic Arithmetic (Gross Pay) ==="
awk -F',' '{pay = $3 * $4; print $1 " gross pay: $" pay}' Employees.txt
echo

echo "=== Task 4: Built-in Variables (NR and NF) ==="
awk -F',' '{ print NR " (" NF " fields): " $0 }' Employees.txt
echo

echo "=== Task 5: Grand Finale (BEGIN/END + Conditionals) ==="
awk -F',' 'BEGIN{total=0} $2=="Engineering"{total += $3*$4} END{print "Total Engineering Payroll: $" total}' Employees.txt
