# 🎓 Student Record Management System (C)

A **Student Record Management System** implemented in **C language** using **Doubly Linked Lists** and **File Handling**.

This project allows you to **add, display, delete, search, update, reverse, and store student records** efficiently.  
It demonstrates concepts of **dynamic memory allocation**, **linked list traversal**, and **persistent file storage** in C.

---

## 🧠 Features

✅ **Add Student Record**
- Adds a new student in *sorted order by roll number*.
- Automatically maintains order using the `add_middle()` function.

✅ **Display All Records**
- Displays all student records in forward order.

✅ **Delete a Record**
- Deletes a specific student by roll number (`delete_node()`).
- Option to delete all records (`delete_all()`), which also updates the file.

✅ **Search**
- Searches and displays details of a student by roll number.

✅ **Update**
- Updates an existing student’s details (name or marks).

✅ **Reverse Print**
- Prints the list in reverse order without modifying the links.

✅ **File Handling**
- **`save()`** writes all records to `data.txt`.  
- **`load()`** loads records automatically at program start.
- Data persists even after program termination.

---

## 🧩 Menu Options

