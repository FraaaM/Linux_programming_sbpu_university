'''1.Задача: Вычисление статистики успеваемости студентов.

Предположим, у нас есть список словарей, представляющих данные о студентах и их оценках в разных предметах. Каждый словарь содержит информацию о имени студента, его возрасте и списке оценок (целых чисел) по разным предметам.

Мы хотим решить следующие задачи:

Фильтрация данных: Отфильтровать студентов определенного возраста и/или с определенным списком предметов.

Преобразование данных: Вычислить средний балл для каждого студента и общий средний балл по всем студентам.

Агрегация данных: Найти студента (или студентов) с самым высоким средним баллом. '''
# ЗАПУСК python3 test.py

from functools import reduce

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
    if age is not None:
        students = list(filter(lambda student: student["age"] == age, students))
    if subjects is not None:
        students = list(filter(lambda student: all(grade in student["grades"] for grade in subjects), students))
    return students

def calculate_average_grades(students):
    average_grades = list(map(lambda student: (student["name"], sum(student["grades"]) / len(student["grades"])), students))
    total_average = reduce(lambda acc, x: acc + x[1], average_grades, 0) / len(students)
    return average_grades, total_average

def find_top_students(students):
    average_grades, _ = calculate_average_grades(students)
    highest_average = max(map(lambda x: x[1], average_grades))
    return list(filter(lambda x: x[1] == highest_average, average_grades))

age_input = int(input("Введите возраст студентов: "))
filtered_students = filter_students(students, age=age_input)
print(f"Студенты в возрасте {age_input} лет:", filtered_students)

subjects_input = input("Введите оценки студентов (через запятую): ")
#Преобразуем введенные оценки в список чисел
subjects = list(map(int, subjects_input.split(',')))
filtered_students = filter_students(students, subjects=subjects)
print(f"Студенты с оценками {subjects}:", filtered_students)


average_grades, total_average = calculate_average_grades(students)
print("Средние баллы студентов:", average_grades)
print("Общий средний балл:", total_average)

top_students = find_top_students(students)
print("Студенты с самым высоким средним баллом:", top_students)

