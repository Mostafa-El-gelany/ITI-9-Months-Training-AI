from abc import ABC, abstractmethod
class Shape(ABC):
    @abstractmethod
    def area(self):
        pass

    @abstractmethod
    def perimeter(self):
        pass

    def __str__(self):
        return f"Shape(type= Shape)"
    def __eq__(self,other):
        return self.area()==other.area()
    def __add__(self,other):
        return CombinedShape(self,other)

class Rectangle(Shape):
    def __init__(self, width, height):
        self.width = width
        self.height = height

    def area(self):
        return self.width * self.height

    def perimeter(self):
        return 2 * (self.width + self.height)

    def __str__(self):
        return f"Rectangle: area={self.area()}, perimeter={self.perimeter()}"

class Circle(Shape):
    def __init__(self, radius):
        self.radius = radius

    def area(self):
        return 3.14 * self.radius ** 2

    def perimeter(self):
        return 2 * 3.14 * self.radius

    def __str__(self):
        return f"Circle: area={self.area()}, perimeter={self.perimeter()}"

class Triangle(Shape):
    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c

    def area(self):
        s = (self.a + self.b + self.c) / 2
        return (s * (s - self.a) * (s - self.b) * (s - self.c)) ** 0.5

    def perimeter(self):
        return self.a + self.b + self.c

    def __str__(self):
        return f"Triangle: area={self.area()}, perimeter={self.perimeter()}"

class CombinedShape(Shape):
    def __init__(self,shape1, shape2):
        self.total_area = shape1.area() + shape2.area()
        self.total_perimeter = shape1.perimeter() + shape2.perimeter()
    def area(self):
        return self.total_area
    def perimeter(self):
        return self.total_perimeter
    def __str__(self):
        return f"CombinedShape: area={self.area()}, perimeter={self.perimeter()}"


c=Circle(3)
r1=Rectangle(5,4)
r2=Rectangle(4,5)
t=Triangle(3,4,5)


print(r1==r2) 
print(r1==t)

g=c+t


shapes = [c, r1, r2, t, g]
for shape in shapes:
    print(shape)



'''
✅ Problem 2 — Shape Hierarchy
Create an abstract class Shape with:
abstract methods:
area()
perimeter()
implement str() to return the shape type (e.g., "Shape(type=Rectangle)")
Subclasses:
Rectangle(width, height)
Circle(radius)
Triangle(a, b, c)
Requirements:
Each subclass must override str() to return:
Shape name
Area
Perimeter
Example: "Rectangle: area=12.0, perimeter=14.0"
Implement the equality magic method eq(self, other) → Two shapes are equal if their area is the same.
Implement the addition magic method add(self, other) → Return a new object of a class CombinedShape with total area = sum of both shapes.
Create a list of mixed shapes.
Test:
Equality between two shapes
Adding two shapes
Printing all shapes using str()
'''