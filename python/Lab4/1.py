from abc import ABC, abstractmethod
class Employee(ABC):
    def __init__(self, name, base_salary):
        self.name = name
        self.base_salary = base_salary
    @abstractmethod
    def calculate_total_salary(self):
        pass
    
    def __str__(self):
        return f"Employee(name={self.name}, base_salary={self.base_salary})"
    def __lt__(self, other):
        return self.calculate_total_salary() < other.calculate_total_salary()

class Developer(Employee):
    def __init__(self,name, base_salary, num_bugs_fixed):
        super().__init__(name, base_salary)
        self.num_bugs_fixed = num_bugs_fixed
        self.bonus = num_bugs_fixed * 40

    def calculate_total_salary(self):
        return self.base_salary + self.bonus
    def __str__(self):
        total_salary = self.calculate_total_salary()
        return f"Developer: {self.name}, total_salary = {total_salary}"

class Manager(Employee):
    def __init__(self,name, base_salary, num_projects):
        super().__init__(name, base_salary)
        self.num_projects = num_projects
        self.bonus = num_projects * 1200

    def calculate_total_salary(self):
        return self.base_salary + self.bonus
    def __str__(self):
        total_salary = self.calculate_total_salary()
        return f"Manager: {self.name}, total_salary = {total_salary}"

'''
Day 05 Lab Tasks
✅ Problem 1 — Employee Salary System
Create an abstract class Employee with:
attributes: name, base_salary
abstract method: calculate_total_salary()
override the str() method to return a readable description of the employee: "Employee(name=..., base_salary=...)"
Subclasses:
Developer
attribute: num_bugs_fixed
bonus = num_bugs_fixed * 40
Manager
attribute: num_projects
bonus = num_projects * 1200
Requirements:
Implement str() in each subclass so that:
Developer prints: "Developer: name, total_salary = X"
Manager prints: "Manager: name, total_salary = X"
Implement the comparison magic method lt(self, other) → compare employees based on their total salary.
Create at least 3 mixed employees.
Sort them using Python’s sorted() and print the results using str().
'''

d1=Developer('Alice',40000, 10)
d2=Developer('Bob',45000, 5)
m1=Manager('Charlie',60000, 3)
m2=Manager('David',55000, 4)

employees = [d1, d2, m1, m2]

sorted_employees = sorted(employees)


print("Employees sorted by total salary:")
for emp in sorted_employees:
    print(emp)