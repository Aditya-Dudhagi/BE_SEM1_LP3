// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract StudentData {
    struct Student {
        uint id;
        string name;
        uint age;
    }

    Student[] public students;

    fallback() external payable {}

    function addStudent(string memory _name, uint _age) public {
        uint studentId = students.length;
        students.push(Student(studentId, _name, _age));
    }

    function getStudent(uint _id) public view returns (uint, string memory, uint) {
        require(_id < students.length, "Student ID does not exist.");
        Student memory student = students[_id];
        return (student.id, student.name, student.age);
    }

    function getStudentCount() public view returns (uint) {
        return students.length;
    }
}