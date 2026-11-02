// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract StudentData{
    struct Student{
        uint id;
        string name;
        uint age;
    }

    Student[] public students;

    function addStudent(uint id, string memory name, uint age) public {
        students.push(Student(id, name, age));
    }

    function getStudent(uint index) public view
    returns (Student memory){
        return students[index];
    }

    function totalStudents() public view 
    returns (uint){
        return students.length;
    }
}