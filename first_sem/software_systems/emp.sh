#!/bin/bash

displayMenu() {
	echo "Employee Record Menu"
	echo "------------------------"
	echo "1. Add Employee Record"
	echo "2. Delete Employee Record"
	echo "3. Search Employee Record"
	echo "4. Display Employee Record"
	echo "5. Sort Employee Records"
	echo "6. List All Employees"
	echo "7. Exit"
	echo "------------------------"
	echo "Enter your choice:"
}

addRecord() {
	echo "Enter Employee Name:"
	read name
	echo "Enter Employee Number:"
	read emp_number
	echo "Enter Telephone Number:"
	read tel_number
	echo "$name,$emp_number,$tel_number" >>employee_records.txt
	echo "Employee Record added successfully!"
}

deleteRecord() {
	echo "Enter Employee Number to delete:"
	read emp_number
	sed -i "/^.*,${emp_number},/d" employee_records.txt
}

searchRecord() {
	echo "Enter Employee Number to search:"
	read emp_number
	grep "^.*,${emp_number}," employee_records.txt
}

displayRecord() {
	echo "Enter Employee Number to display:"
	read emp_number
	grep "^.*,${emp_number}," employee_records.txt
}

sortRecords() {
	sort -t',' -k2 -n employee_records.txt
}

listRecords() {
	cat employee_records.txt
}

while true; do
	displayMenu
	read choice

	case $choice in
	1) addRecord ;;
	2) deleteRecord ;;
	3) searchRecord ;;
	4) displayRecord ;;
	5) sortRecords ;;
	6) listRecords ;;
	7)
		echo "Exiting..."
		exit 0
		;;
	*) echo "Invalid choice. Please try again." ;;
	esac

	echo "----------------------------------------"

done
