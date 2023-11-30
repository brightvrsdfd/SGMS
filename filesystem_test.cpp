#include "filesystem.h"

int main() {
    FileSystem fileSystem;

    // Test course operations
    Course* course1 = fileSystem.createCourse("Math", "Mr. Smith");
    Course* course2 = fileSystem.createCourse("Physics", "Dr. Johnson");

    fileSystem.addStudentToCourse("Math", "Mr. Smith", "Alice");
    fileSystem.addStudentToCourse("Physics", "Dr. Johnson", "Bob");

    fileSystem.printCourseInfo("Math", "Mr. Smith");
    fileSystem.printCourseInfo("Physics", "Dr. Johnson");

    fileSystem.gradeStudent("Math", "Mr. Smith", "Alice", 85);
    fileSystem.gradeStudent("Physics", "Dr. Johnson", "Bob", 90);

    fileSystem.printCourseInfo("Math", "Mr. Smith");
    fileSystem.printCourseInfo("Physics", "Dr. Johnson");

    // Test assignment operations
    Assignment* assignment1 = fileSystem.createAssignment("Math", "Mr. Smith", "Homework1");
    Assignment* assignment2 = fileSystem.createAssignment("Physics", "Dr. Johnson", "Lab1");

    fileSystem.addStudentToAssignment("Math", "Mr. Smith", "Homework1", "Alice");
    fileSystem.addStudentToAssignment("Physics", "Dr. Johnson", "Lab1", "Bob");

    fileSystem.printAssignmentInfo("Math", "Mr. Smith", "Homework1");
    fileSystem.printAssignmentInfo("Physics", "Dr. Johnson", "Lab1");

    fileSystem.gradeStudentInAssignment("Math", "Mr. Smith", "Homework1", "Alice", 90);
    fileSystem.gradeStudentInAssignment("Physics", "Dr. Johnson", "Lab1", "Bob", 85);

    fileSystem.printAssignmentInfo("Math", "Mr. Smith", "Homework1");
    fileSystem.printAssignmentInfo("Physics", "Dr. Johnson", "Lab1");

    // Test deleting course and assignment
    fileSystem.deleteCourse("Math", "Mr. Smith");
    fileSystem.deleteAssignment("Physics", "Dr. Johnson", "Lab1");

    return 0;
}
