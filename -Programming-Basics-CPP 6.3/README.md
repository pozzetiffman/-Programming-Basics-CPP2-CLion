Описание проекта

Данный проект представляет собой многофайловую C++ программу для работы с геометрическими фигурами. Программа демонстрирует принципы объектно-ориентированного программирования (ООП), такие как наследование и полиморфизм, и организована в виде многофайловой структуры для удобства разработки и расширения.

Структура проекта

Проект состоит из нескольких файлов и директорий, содержащих заголовочные и исходные файлы для классов фигур:

    •    Figure — базовый класс для всех фигур.
    •    Triangle — класс для треугольников и его специализированных видов (прямоугольный, равнобедренный, равносторонний).
    •    The_quadrilateral — класс для четырёхугольников и его производных (прямоугольник, квадрат, параллелограмм, ромб).
    •    main.cpp — основной файл программы, содержащий функцию main.

Классы и их описание

Базовый класс Figure

Класс Figure содержит основную информацию о фигуре: её название и количество сторон. Предоставляет виртуальные методы print_info() для вывода информации о фигуре.

Производные классы

    1.    Triangle — базовый класс для треугольников, наследуется от Figure.
    •    Специализированные классы:
    •    A_right_angled_riangle — прямоугольный треугольник.
    •    Isosceles_triangle — равнобедренный треугольник.
    •    An_equilateral_triangle — равносторонний треугольник.
    2.    The_quadrilateral — базовый класс для четырёхугольников, наследуется от Figure.
    •    Специализированные классы:
    •    Rectangle — прямоугольник.
    •    Square — квадрат.
    •    Parallelogram — параллелограмм.
    •    Rhomb — ромб.

Принцип работы

    1.    Программа создает массив указателей на объекты различных фигур.
    2.    В цикле проходит по каждому объекту, вызывает метод print_info(), который отображает информацию о фигуре: название, стороны, углы и другие характеристики.
    3.    После завершения работы все выделенные объекты освобождаются.
