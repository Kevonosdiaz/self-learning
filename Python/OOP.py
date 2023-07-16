# Creating a student class

class Student:
    def __init__(self, name, major, gpa, id, on_probation): # A constructor, basically
        self.name = name # The specific object (self)'s name will be the inputted name
        self.major = major
        self.gpa = gpa
        self.id = id
        self.on_probation = on_probation

