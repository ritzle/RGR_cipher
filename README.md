# Шифратор

Консольное приложение "Шифратор" предоставляет пять различных методов шифрования:

1. Афинный шифр
2. Шифр Вернама
3. Шифр Бэкона
4. Шифр RSA
5. Скиталла

## Особенности

- Поддержка пяти различных алгоритмов шифрования
- Возможность шифрования и дешифрования текста как с консоли так и с файла
- Простой и интуитивно понятный интерфейс

## Как использовать

1. Клонируйте репозиторий:

   git clone https://github.com/ваш-аккаунт/RGR_cipher.git
   
2. Перейдите в директорию проекта:

   cd .../RGR_cipher
   
3. Запустите фаил start.bat(убедитесь что у вас устоновлен cmake)

4. В консоли выберите необходимый алгоритм шифрования и следуйте инструкциям.

## Алгоритмы шифрования

### 1. Афинный шифр

Афинный шифр - это симметричный шифр, который использует линейную функцию для преобразования открытого текста в зашифрованный. Он определяется двумя числами: коэффициентом a и сдвигом b.

### 2. Шифр Вернама

Шифр Вернама, также известный как однократный блокнот, является абсолютно стойким шифром при условии, что ключ используется только один раз и имеет такую же длину, что и открытый текст.

### 3. Шифр Бэкона

Шифр Бэкона - это простой шифр подстановки, в котором каждая буква открытого текста заменяется группой из пяти битов.

### 4. Шифр RSA

RSA - это асимметричный криптографический алгоритм, основанный на вычислительной сложности задачи факторизации больших целых чисел.

### 5. Скиталла

Скиталла - это простой шифр перестановки, который использовался в древней Спарте. Он состоит в обертывании сообщения вокруг цилиндрического стержня и записи сообщения вертикально.