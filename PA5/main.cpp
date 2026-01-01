#include "DBsystem.h"

int main()
{
    DBsystem db;

    // Add 15 students
    db.addStudent(Student(1, "Alice", "Senior", "Computer Science", 3.9, 101));
    db.addStudent(Student(2, "Bob", "Junior", "Mathematics", 3.5, 102));
    db.addStudent(Student(3, "Charlie", "Sophomore", "Computer Science", 3.8, 101));
    db.addStudent(Student(4, "David", "Freshman", "Mathematics", 3.2, 102));
    db.addStudent(Student(5, "Eve", "Senior", "Computer Science", 3.6, 101));
    db.addStudent(Student(6, "Frank", "Sophomore", "Mathematics", 3.4, 102));
    db.addStudent(Student(7, "Grace", "Freshman", "Computer Science", 3.7, 101));
    db.addStudent(Student(8, "Henry", "Junior", "Mathematics", 3.3, 102));
    db.addStudent(Student(9, "Ivy", "Sophomore", "Computer Science", 3.9, 101));
    db.addStudent(Student(10, "Jack", "Freshman", "Mathematics", 3.1, 102));
    db.addStudent(Student(11, "Kate", "Senior", "Computer Science", 3.5, 101));
    db.addStudent(Student(12, "Liam", "Junior", "Mathematics", 3.2, 102));
    db.addStudent(Student(13, "Mallory", "Sophomore", "Computer Science", 3.8, 101));
    db.addStudent(Student(14, "Natalie", "Freshman", "Mathematics", 3.4, 102));
    db.addStudent(Student(15, "Oliver", "Senior", "Computer Science", 3.6, 101));


    // Display students
    db.displayAllStudents();

    // Add 15 faculty
    db.addFaculty(Faculty(101, "Dr. Smith", "Professor", "Computer Science"));
    db.addFaculty(Faculty(102, "Dr. Johnson", "Associate Professor", "Mathematics"));
    db.addFaculty(Faculty(103, "Dr. Williams", "Assistant Professor", "Computer Science"));
    db.addFaculty(Faculty(104, "Dr. Brown", "Associate Professor", "Mathematics"));
    db.addFaculty(Faculty(105, "Dr. Davis", "Professor", "Computer Science"));
    db.addFaculty(Faculty(106, "Dr. Wilson", "Assistant Professor", "Mathematics"));
    db.addFaculty(Faculty(107, "Dr. Taylor", "Associate Professor", "Computer Science"));
    db.addFaculty(Faculty(108, "Dr. Anderson", "Assistant Professor", "Mathematics"));
    db.addFaculty(Faculty(109, "Dr. Thomas", "Professor", "Computer Science"));
    db.addFaculty(Faculty(110, "Dr. Harris", "Associate Professor", "Mathematics"));
    db.addFaculty(Faculty(111, "Dr. Garcia", "Assistant Professor", "Computer Science"));
    db.addFaculty(Faculty(112, "Dr. Martin", "Associate Professor", "Mathematics"));
    db.addFaculty(Faculty(113, "Dr. Lee", "Professor", "Computer Science"));
    db.addFaculty(Faculty(114, "Dr. Walker", "Assistant Professor", "Mathematics"));
    db.addFaculty(Faculty(115, "Dr. Perez", "Associate Professor", "Computer Science"));
    

    // Display faculty
    db.displayAllFaculty();

    // Find and delete a student
    Student *s = db.findStudent(1);
    if (s)
    {
        std::cout << "Found Student: " << *s << std::endl;
        db.deleteStudent(1);
    }

    // Try to find the deleted student
    s = db.findStudent(1);
    if (!s)
    {
        std::cout << "Student with ID 1 has been deleted." << std::endl;
    }

    // Find and delete a faculty
    Faculty *f = db.findFaculty(101);
    if (f)
    {
        std::cout << "Found Faculty: " << *f << std::endl;
        db.deleteFaculty(101);
    }

  

    

    return 0;
}
