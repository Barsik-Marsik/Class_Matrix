# Class-Matrix
Class Matrix for initialization an integer matrix
В этой задаче вам надо разработать класс Matrix для представления целочисленной матрицы. Более подробно, класс Matrix должен иметь:

    конструктор по умолчанию, который создаёт матрицу с нулём строк и нулём столбцов
    конструктор от двух целочисленных параметров: num_rows и num_cols, — которые задают количество строк и столбцов матрицы соответственно
    метод Reset, принимающий два целочисленных параметра, которые задают новое количество строк и столбцов матрицы соответственно; метод Reset меняет размеры матрицы на заданные и обнуляет все её элементы
    константный метод At, который принимает номер строки и номер столбца (именно в этом порядке; нумерация строк и столбцов начинается с нуля) и возвращает значение в соответствущей ячейке матрицы
    неконстантный метод At с такими же параметрами, но возвращающий ссылку на значение в соответствущей ячейке матрицы
    константные методы GetNumRows и GetNumColumns, которые возвращают количество строк и столбцов матрицы соответственно

Если количество строк или количество столбцов, переданное в конструктор класса Matrix или метод Reset, оказалось отрицательным, то должно быть выброшено стандартное исключение out_of_range.

Это же исключение должен бросать метод At, если переданная в него ячейка выходит за границы матрицы.

Кроме того, для класса Matrix должны быть определены следующие операторы:

    оператор ввода из потока istream; формат ввода простой — сначала задаётся количество строк и столбцов (именно в этом порядке), а затем все элементы матрицы: сначала элемент первой строки и первого столбца, затем элемент первой строки и второго столбца и так далее
    оператор вывода в поток ostream; он должен выводить матрицу в том же формате, в каком её читает оператор ввода, — в первой строке количество строк и столбцов, во второй — элементы первой строки, в третьей — элементы второй строки и т.д.
    оператор проверки на равенство (==): он должен возвращать true, если сравниваемые матрицы имеют одинаковый размер и все их соответствующие элементы равны между собой, в противном случае он должен возвращать false.
    оператор сложения: он должен принимать две матрицы и возвращать новую матрицу, которая является их суммой; если переданные матрицы имеют разные размеры этот оператор должен выбрасывать стандартное исключение invalid_argument.

Примечание

Матрицы с нулём строк или нулём столбцов считаются пустыми. Любые две пустые матрицы равны. Сумма двух пустых матриц также является пустой матрицей.