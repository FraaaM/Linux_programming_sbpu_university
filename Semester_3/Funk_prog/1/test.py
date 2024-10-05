
# ЗАПУСК python3 test.py

students = [
    {"name": "Alice", "age": 20, "grades": [85, 90, 88, 92]},
    {"name": "Bob", "age": 22, "grades": [78, 89, 76, 85]},
    {"name": "Charlie", "age": 21, "grades": [92, 95, 88, 94]},
    {"name": "David", "age": 23, "grades": [65, 75, 70, 68]},
    {"name": "Eve", "age": 20, "grades": [88, 91, 87, 90]},
    {"name": "Frank", "age": 22, "grades": [72, 85, 80, 77]},
    {"name": "Grace", "age": 21, "grades": [93, 90, 89, 92]},
    {"name": "Hannah", "age": 23, "grades": [80, 85, 88, 84]},
    {"name": "Ivy", "age": 19, "grades": [95, 97, 93, 96]},
    {"name": "Jack", "age": 24, "grades": [60, 65, 62, 68]},
    {"name": "Kim", "age": 20, "grades": [89, 91, 87, 92]},
    {"name": "Liam", "age": 22, "grades": [79, 82, 85, 80]},
    {"name": "Mia", "age": 21, "grades": [91, 92, 93, 94]},
    {"name": "Noah", "age": 23, "grades": [67, 72, 70, 68]},
    {"name": "Olivia", "age": 20, "grades": [87, 89, 85, 88]},
    {"name": "Paul", "age": 22, "grades": [82, 85, 79, 83]},
    {"name": "Quincy", "age": 21, "grades": [90, 92, 89, 91]},
    {"name": "Rachel", "age": 23, "grades": [75, 80, 78, 82]},
    {"name": "Sam", "age": 19, "grades": [98, 95, 96, 99]},
    {"name": "Tina", "age": 24, "grades": [63, 68, 65, 66]},
]

def filter_students(students, age=None, subjects=None):
    """
    Фильтрация студентов по возрасту и/или списку предметов.

    Args:
        students: Список словарей с информацией о студентах.
        age: Возраст для фильтрации (необязательный).
        subjects: Список предметов для фильтрации (необязательный).

    Returns:
        Отфильтрованный список словарей с информацией о студентах.
    """
    if age is not None:
        students = list(filter(lambda student: student["age"] == age, students))
    if subjects is not None:
        students = list(filter(lambda student: all(grade in student["grades"] for grade in subjects), students))
    return students

def calculate_average_grades(students):
    """
    Вычисление среднего балла для каждого студента и общего среднего балла по всем студентам.

    Args:
        students: Список словарей с информацией о студентах.

    Returns:
        Список кортежей (имя студента, средний балл) и общий средний балл.
    """
    average_grades = [(student["name"], sum(student["grades"]) / len(student["grades"])) for student in students]
    total_average = sum(average_grade for _, average_grade in average_grades) / len(students)
    return average_grades, total_average

def find_top_students(students):
    """
    Найти студента (или студентов) с самым высоким средним баллом.

    Args:
        students: Список словарей с информацией о студентах.

    Returns:
        Список имен студентов с самым высоким средним баллом.
    """
    average_grades, _ = calculate_average_grades(students)
    highest_average = max(average_grade for _, average_grade in average_grades)
    return [name for name, average_grade in average_grades if average_grade == highest_average]

# Примеры использования

# Фильтрация студентов в возрасте 20 лет
filtered_students = filter_students(students, age=20)
print("Студенты в возрасте 20 лет:", filtered_students)

# Фильтрация студентов по предметам с оценками 85, 90, 88
filtered_students = filter_students(students, subjects=[85, 90, 88])
print("Студенты с оценками 85, 90, 88:", filtered_students)

# Вычисление среднего балла для каждого студента и общего среднего балла
average_grades, total_average = calculate_average_grades(students)
print("Средние баллы студентов:", average_grades)
print("Общий средний балл:", total_average)

# Найти студента (или студентов) с самым высоким средним баллом
top_students = find_top_students(students)
print("Студенты с самым высоким средним баллом:", top_students)	
