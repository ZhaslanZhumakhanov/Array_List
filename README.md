## Практика - "List"
## Курс 1. Семестр 2.
### Список на основе массива

Очевидно, можно реализовать список на основе непрерывного куска памяти - обычного массива. В этом случае мы как разработчики списка скроем от пользователя машинерию по выделению памяти при добавлении новых элементов в массив или по очистке памяти. Основная сложность тут состоит в том, чтобы как можно реже вызывать операции по довыделению памяти и не поймать ошибку, когда ОС не может выдать нам непрерывный кусок памяти большого размера.

Вам придется использовать механизмы перевыделения памяти `realloc`.