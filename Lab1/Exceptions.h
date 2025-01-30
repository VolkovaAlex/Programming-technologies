#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

// Базовый класс для исключений
class KeeperException : public std::exception {
protected:
    std::string message;
public:
    KeeperException(const std::string& msg) : message(msg) {}
    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};

// Исключение: Попытка удаления из пустого контейнера
class EmptyContainerException : public KeeperException {
public:
    EmptyContainerException() : KeeperException("Error: Attempt to remove an element from an empty container.") {}
};

// Исключение: Недостаточно памяти для добавления нового элемента
class MemoryAllocationException : public KeeperException {
public:
    MemoryAllocationException() : KeeperException("Error: Not enough memory to add a new element.") {}
};

// Исключение: Попытка доступа к несуществующему элементу
class IndexOutOfRangeException : public KeeperException {
public:
    IndexOutOfRangeException() : KeeperException("Error: Attempt to access an element outside the container's bounds.") {}
};

#endif // EXCEPTIONS_H