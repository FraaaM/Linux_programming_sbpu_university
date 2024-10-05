

# ЗАПУСК python3 2test.py

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


def calculate_total_expenses(users, criteria=None):
    """
    Расчет общей суммы расходов для пользователей с заданными критериями.

    Args:
        users: Список словарей с информацией о пользователях.
        criteria: Словарь с критериями фильтрации (необязательный).

    Returns:
        Общая сумма расходов для всех отфильтрованных пользователей.
    """

    filtered_users = users
    if criteria:
        filtered_users = list(filter(lambda user: all(
            user[key] == value if callable(value) else user[key] == value(user[key]) 
            for key, value in criteria.items()
        ), filtered_users))

    total_expenses = 0
    for user in filtered_users:
        total_expenses += sum(user["expenses"])

    return total_expenses

# Пример использования:
# Рассчитать общую сумму расходов для пользователей с именем, начинающимся с "A"
total_expenses_a = calculate_total_expenses(users, criteria={"name": lambda name: name.startswith("A")})
print("Общая сумма расходов для пользователей с именем, начинающимся с 'A':", total_expenses_a)

# Рассчитать общую сумму расходов для всех пользователей
total_expenses_all = calculate_total_expenses(users)
print("Общая сумма расходов для всех пользователей:", total_expenses_all)
