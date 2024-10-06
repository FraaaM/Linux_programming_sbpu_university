''' 3.Задача: Работа с большой базой данных заказов и клиентов.

Предположим, у вас есть большая база данных заказов и клиентов, представленных в виде списков словарей. Вам нужно выполнить следующие операции:

Фильтрация заказов: Отфильтровать заказы только для определенного клиента с заданным идентификатором клиента.
Подсчет суммы заказов: Подсчитать общую сумму всех заказов для данного клиента.
Подсчет средней стоимости заказов: Найти среднюю стоимость заказов для данного клиента.'''

from functools import reduce

orders = [
    {"order_id": 1, "customer_id": 101, "amount": 150.0},
    {"order_id": 2, "customer_id": 102, "amount": 200.0},
    {"order_id": 3, "customer_id": 101, "amount": 75.0},
    {"order_id": 4, "customer_id": 103, "amount": 100.0},
    {"order_id": 5, "customer_id": 101, "amount": 50.0},
    {"order_id": 6, "customer_id": 104, "amount": 300.0},
    {"order_id": 7, "customer_id": 105, "amount": 250.0},
    {"order_id": 8, "customer_id": 102, "amount": 400.0},
    {"order_id": 9, "customer_id": 103, "amount": 180.0},
    {"order_id": 10, "customer_id": 106, "amount": 500.0},
    {"order_id": 11, "customer_id": 101, "amount": 90.0},
    {"order_id": 12, "customer_id": 107, "amount": 120.0},
    {"order_id": 13, "customer_id": 102, "amount": 60.0},
    {"order_id": 14, "customer_id": 104, "amount": 310.0},
    {"order_id": 15, "customer_id": 105, "amount": 240.0},
    {"order_id": 16, "customer_id": 103, "amount": 130.0},
    {"order_id": 17, "customer_id": 106, "amount": 80.0},
    {"order_id": 18, "customer_id": 101, "amount": 45.0},
    {"order_id": 19, "customer_id": 107, "amount": 170.0},
    {"order_id": 20, "customer_id": 102, "amount": 220.0},
]

print("выберите одного из покупателей", list(set(map(lambda id: (id["customer_id"]), orders))))
customer_id = int(input())

# Фильтрация заказов по идентификатору клиента
customer_orders = list(filter(lambda order: order["customer_id"] == customer_id, orders))

# Подсчет общей суммы заказов
total_amount = reduce(lambda acc, order: acc + order["amount"], customer_orders, 0)

# Подсчет средней стоимости заказов
average_amount = total_amount / len(customer_orders) if len(customer_orders) > 0 else 0

print(f"Заказы клиента {customer_id}: {customer_orders}")
print(f"Общая сумма заказов: {total_amount}")
print(f"Средняя стоимость заказов: {average_amount}")










































'''1. customer_orders = list(filter(lambda order: order["customer_id"] == customer_id, orders))

Эта строка кода выполняет фильтрацию заказов по идентификатору клиента. Давайте разберем ее шаг за шагом:

• filter(lambda order: order["customer_id"] == customer_id, orders):
  * filter(...): Функция filter() применяется для фильтрации элементов из итерируемого объекта (в нашем случае, это список orders) на основе заданного условия.
  * lambda order: order["customer_id"] == customer_id: Это лямбда-функция, которая задает условие фильтрации. 
    * lambda order:: Ключевое слово lambda определяет анонимную функцию (без имени).
    * order:: Параметр функции (в нашем случае, это словарь с информацией о заказе).
    * order["customer_id"] == customer_id: Условие фильтрации. Проверяется, равен ли идентификатор клиента в заказе (order["customer_id"]) заданному идентификатору клиента (customer_id). 
  * Результат filter() - это итератор (генератор), содержащий только те заказы, для которых условие истинно (т.е. заказы с нужным customer_id).

• list(...): Функция list() преобразует итератор, возвращаемый filter(), в обычный список. Это необходимо, чтобы получить доступ к элементам списка по индексу. 

В итоге, переменная customer_orders содержит список словарей с заказами, принадлежащими заданному клиенту.

2. total_amount = reduce(lambda acc, order: acc + order["amount"], customer_orders, 0)

Эта строка кода подсчитывает общую сумму заказов для отфильтрованного списка customer_orders:

• reduce(lambda acc, order: acc + order["amount"], customer_orders, 0):
  * reduce(...): Функция reduce() применяется для сворачивания (редуцирования) итерируемого объекта (в нашем случае, customer_orders) с помощью заданной функции. 
  * lambda acc, order: acc + order["amount"]: Лямбда-функция, которая задает правило сворачивания: 
    * acc: Аккумулятор - переменная, в которой накапливается результат (изначально она равна 0).
    * order: Текущий элемент списка. 
    * acc + order["amount"]: К аккумулятору добавляется сумма из текущего заказа.
  * customer_orders: Список заказов для клиента, который будет сворачиваться.
  * 0: Начальное значение аккумулятора.

В итоге, total_amount содержит общую сумму заказов клиента.

3. average_amount = total_amount / len(customer_orders) if len(customer_orders) > 0 else 0

Эта строка кода вычисляет среднюю стоимость заказов:

• len(customer_orders) > 0: Проверяет, не пустой ли список заказов.
• total_amount / len(customer_orders): Деление общей суммы на количество заказов (если список не пустой), чтобы получить среднее значение.
• else 0: Если список пустой (нет заказов для клиента), средняя стоимость равна 0.'''
