'''.Задача: Расчет общей суммы расходов для пользователей с заданными критериями.

У вас есть список пользователей с информацией о их расходах за определенные периоды времени. Вам нужно выполнить следующие шаги:

Отфильтровать пользователей по заданным критериям.
Для каждого пользователя рассчитать общую сумму его расходов.
Получить общую сумму расходов всех отфильтрованных пользователей.'''

# ЗАПУСК python3 2test.py

from functools import reduce

users = [
    {"name": "Alice", "expenses": [100, 50, 75, 200]},
    {"name": "Bob", "expenses": [50, 75, 80, 100]},
    {"name": "Charlie", "expenses": [200, 300, 50, 150]},
    {"name": "David", "expenses": [100, 200, 300, 400]},
    {"name": "Eve", "expenses": [150, 60, 90, 120]},
    {"name": "Frank", "expenses": [80, 200, 150, 100]},
    {"name": "Grace", "expenses": [300, 400, 250, 500]},
    {"name": "Hannah", "expenses": [120, 60, 70, 90]},
    {"name": "Ivy", "expenses": [500, 300, 250, 150]},
    {"name": "Jack", "expenses": [75, 100, 50, 150]},
    {"name": "Kim", "expenses": [100, 90, 80, 60]},
    {"name": "Liam", "expenses": [120, 200, 180, 160]},
    {"name": "Mia", "expenses": [400, 500, 450, 300]},
    {"name": "Noah", "expenses": [90, 80, 100, 150]},
    {"name": "Olivia", "expenses": [60, 90, 110, 140]},
    {"name": "Paul", "expenses": [200, 300, 150, 100]},
    {"name": "Quincy", "expenses": [100, 120, 130, 140]},
    {"name": "Rachel", "expenses": [90, 60, 50, 80]},
    {"name": "Sam", "expenses": [500, 400, 350, 600]},
    {"name": "Tina", "expenses": [150, 200, 300, 250]},
]

# Фильтрация пользователей по расходам
def filter_users(ex_small, ex_huge):
    return list(filter(lambda user: ex_small <= sum(user["expenses"]) <= ex_huge, users))

# Рассчитываем общую сумму расходов для каждого пользователя
def total(users):    
    return list(map(lambda user: (user["name"], sum(user["expenses"])), users))

print("введите диапозое по которому будет проходить фильтрация")
filtered_users = filter_users(int(input()), int(input()))
total_expenses = total(filtered_users)
overall_expense = reduce(lambda acc, x: acc + x[1], total_expenses, 0)

print("Отфильтрованные пользователи:", filtered_users)
print("Общие расходы отфильтрованных пользователей:", total_expenses)
print("Общая сумма расходов:", overall_expense)


